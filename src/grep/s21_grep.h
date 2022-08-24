#ifndef SRC_GREP_S21_GREP_H_
#define SRC_GREP_S21_GREP_H_

#define BUFFER_SIZE 5000

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>
#include <getopt.h>

struct flags {
    int e;
    int i;
    int v;
    int c;
    int l;
    int n;
    int h;
    int s;
    int f;
    int o;
};

void flag_parser(int argc, char **argv, struct flags *flags, char *patternE);
void processing(struct flags *flags, FILE *fp, regex_t reg, char *file);
void grep_file(struct flags *flags, char *pattern, char *file);
int f_flag(char *pattern, char *temp);
void grep(struct flags *flags, int argc, char **argv, char *temp);
void initStruct(struct flags *flags);

#endif  // SRC_GREP_S21_GREP_H_
