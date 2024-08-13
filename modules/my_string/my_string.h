//#include "ds3231.h"
#include <string.h>
#include "mbed.h"
#include "arm_book_lib.h"
#include <stddef.h>

#ifndef _CADENAS_H_
#define _CADENAS_H_

#define MAX_LETRAS 50

uint32_t strlen_(const char* str);
bool strcmp_(const char* cad1, const char* cad2);
char* strcpy_(char* dst, char* src);
char* strncpy_(char* dst, const char* src, uint32_t len);
char* strndup_(const char* src, size_t n);
char* strtok_(char* str, const char* delimiters);
char* strchr_(const char* str, int character);

#endif // _CADENAS_H_