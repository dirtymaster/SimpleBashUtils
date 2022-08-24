#include "s21_cat.h"

int main(int argc, char *argv[]) {
    flags flag = {
        S21_FLAGS
    };
    cat_flags(argc, argv, &flag);
    while (optind < argc) {
        read_file(argv, &flag);
        optind++;
    }
    return 0;
}

int cat_flags(int argc, char *argv[], flags *flag) {  // парсинг
    int f;
    const char* f_options = "bEnsTvet";
    static struct option options[] = {
        {"number-nonblank", 0, 0, 'b'},
        {"number", 0, 0, 'n'},
        {"squeeze-blank", 0, 0, 's'},
        {0, 0, 0, 0},
    };
    while ((f = getopt_long(argc, argv, f_options, options, NULL)) != -1) {
        switch (f) {
        case 'b':
            flag->b = 1;
            break;
        case 'E':
            flag->e = 1;
            break;
        case 'n':
            flag->n = 1;
            break;
        case 's':
            flag->s = 1;
            break;
        case 'T':
            flag->t = 1;
            break;
        case 'v':
            flag->v = 1;
            break;
        case 'e':
            flag->e = 1;
            flag->v = 1;
            break;
        case 't':
            flag->t = 1;
            flag->v = 1;
            break;
        default:
            printf("error\n");
            break;
        }
        if (flag->b && flag->n) flag->n = 0;
    }
    return 0;
}

void read_file(char *argv[], flags *flag) {  // чтение файла и обработка флагов
    FILE *fp;
    fp = fopen(argv[optind], "r");
    if (fp != NULL) {
        int str_count = 1;
        int empty_str_count = 0;
        int last = '\n';
        while (!feof(fp)) {
            int c = fgetc(fp);
            if (c == EOF)
                break;
            if (flag->s && c == '\n' && last == '\n') {
                empty_str_count++;
                if (empty_str_count > 1) {
                    continue;
                }
            } else {
                empty_str_count = 0;
            }
            if (last == '\n' && ((flag->b && c != '\n') || flag->n))
                printf("%6d\t", str_count++);
            if (flag->t && c == '\t') {
                printf("^");
                c = 'I';
            }
            if (flag->e && c == '\n')
                    printf("$");
            if (flag->v) {
                if ((c >= 0 && c < 9) || (c > 10 && c < 32)
                || (c > 126 && c <= 160)) {
                    printf("^");
                    if (c > 126) {
                        c -= 64;
                    } else {
                    c += 64;
                    }
                }
            }
            printf("%c", c);
            last = c;
        }
        fclose(fp);
    } else {
        printf("Error\n");
        exit(1);
    }
}
