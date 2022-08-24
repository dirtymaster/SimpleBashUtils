CC=gcc

CFLAGS=-std=c11 -Wall -Wextra -g #-Werror

OS=$(shell uname)

build:
	$(CC) $(CFLAGS) s21_cat.c -o s21_cat

s21_cat: build
	bash s21_test_cat.sh

check:
	cppcheck --enable=all --suppress=missingIncludeSystem --inconclusive --check-config s21_cat.c
	cp ../../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../../materials/linters/cpplint.py --extensions=c s21_cat.c s21_cat.h
	rm CPPLINT.cfg
	make s21_cat
ifeq ($(OS), Darwin)
	leaks --atExit -- ./s21_cat
else
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt ./s21_cat 
endif

clean:
	rm -rf s21_cat s21_cat.dSYM *.o RESULT_VALGRIND.txt