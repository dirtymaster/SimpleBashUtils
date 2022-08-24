#ifndef SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_

#define S21_FLAGS    .b = 0, .e = 0, .n = 0, .s = 0, .t = 0, .v = 0,

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <getopt.h>

typedef struct flag {
    int b;
    int e;
    int n;
    int s;
    int t;
    int v;
} flags;

int cat_flags(int argc, char *argv[], flags *flag);
void read_file(char *argv[], flags *flag);

#endif  // SRC_CAT_S21_CAT_H_
