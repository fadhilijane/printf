#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int _putchar(char c);
int _putstring(char *str);
int _putdigit(long num, int base);
int _printf(const char *format, ...);

#endif
