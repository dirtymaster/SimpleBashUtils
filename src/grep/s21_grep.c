#include "s21_grep.h"

int main(int argc, char *argv[]) {
    struct flags flags = {0};
    char patternE[BUFFER_SIZE] = {0};
    flag_parser(argc, argv, &flags, patternE);
    if (argc >= 3)
        grep(&flags, argc, argv, patternE);
    return 0;
}

void flag_parser(int argc, char **argv, struct flags *flags, char *patternE) {
    int opt = 0;
    const char* s_options = "e:ivclnhsf:o";
    while ((opt = getopt(argc, argv, s_options)) != -1) {
        switch (opt) {
        case 'e':
            flags->e = 1;
            snprintf(patternE, BUFFER_SIZE, "%s", optarg);
            break;
        case 'i':
            flags->i = 1;
            break;
        case 'v':
            flags->v = 1;
            break;
        case 'c':
            flags->c = 1;
            break;
        case 'l':
            flags->l = 1;
            break;
        case 'n':
            flags->n = 1;
            break;
        case 'h':
            flags->h = 1;
            break;
        case 's':
            flags->s = 1;
            break;
        case 'f':
            flags->f = 1;
            snprintf(patternE, BUFFER_SIZE, "%s", optarg);
            break;
        case 'o':
            flags->o = 1;
            break;
        default:
            printf("error\n");
            break;
        }
    }
}

void processing(struct flags *flags, FILE *fp, regex_t reg, char *file) {  // обработка файла
  char text[BUFFER_SIZE] = {0};
  regmatch_t pmatch[1];  // подготавливаем слово к поиску
  int line_matches = 0, nline = 1;
  while (fgets(text, BUFFER_SIZE - 1, fp) != NULL) {
    int match = 0;
    int success = regexec(&reg, text, 1, pmatch, 0);  // ищем слово
    if (strchr(text, '\n') == NULL)
        strcat(text, "\n");
    if (success == 0 && !flags->v)
        match = 1;
    if (success == REG_NOMATCH && flags->v)
        match = 1;
    if (match && !flags->l && !flags->c && flags->n)
        printf("%d:", nline);
    if (match && !flags->l && !flags->c && !flags->o)
        printf("%s", text);
    if (match && flags->o) {
      for (int i = pmatch[0].rm_so; i < pmatch[0].rm_eo; i++) {
        printf("%c", text[i]);
      }
      printf("\n");
    }
    line_matches += match;
    nline++;
  }
  if (flags->l && line_matches > 0)
    printf("%s\n", file);
  if (flags->c && !flags->l)
    printf("%d\n", line_matches);
}

void grep_file(struct flags *flags, char *pattern, char *filename) {
  int cflags = REG_EXTENDED;
  regex_t reg;
  FILE *file;
  file = fopen(filename, "r");
  if (flags->i)
    cflags = REG_ICASE;
  if (file != NULL) {
    regcomp(&reg, pattern, cflags);
    processing(flags, file, reg, filename);
    regfree(&reg);
    fclose(file);
  }
}

int f_flag(char *pattern, char *filename) {  // обработка f флага
  FILE *file;
  file = fopen(filename, "r");
  int i = 0;
  if (file != NULL) {
    int ch;
    while ((ch = fgetc(file)) != EOF) {
      if (ch == 13 || ch == 10) pattern[i++] = '|';
      if (ch != 13 && ch != 10) pattern[i++] = ch;
    }
  } else {
    printf("error\n");
    i = -1;
  }
  if (pattern[i - 1] == '|')
    pattern[i - 1] = '\0';
  fclose(file);
  return i;
}

void grep(struct flags *flags, int argc, char **argv, char *buff) {
  char pattern[BUFFER_SIZE] = {0};
  int f_patt = 0;
  if (!flags->f && !flags->e)
    snprintf(pattern, BUFFER_SIZE, "%s", argv[optind++]);
  if (flags->f)
    f_patt = f_flag(pattern, buff);
  if (!flags->f && flags->e)
    snprintf(pattern, BUFFER_SIZE, "%s", buff);
  if (f_patt != -1) {
    int file_c = 0;
    if (argc - optind > 1) file_c = 1;
    for (int i = optind; i < argc; i++) {
      if (file_c && !flags->h && !flags->l) printf("%s:", argv[i]);
      grep_file(flags, pattern, argv[i]);
    }
  }
}
