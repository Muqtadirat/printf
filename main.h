#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>

#define BUFFER_SIZE 1024

int _printf(const char *format, ...);
int handle_rot13(va_list *args, char *buffer, int *buffer_index);
int handle_special_string(va_list *args, char *buffer, int *buffer_index);
int handle_binary(va_list *args, char *buffer, int *buffer_index);
int handle_unsigned(va_list *args, char *buffer, int *buffer_index);
int handle_octal(va_list *args, char *buffer, int *buffer_index);
int handle_hexadecimal(va_list *args, char *buffer, int *buffer_index);
int hexadecimal_uppercase(va_list *args, char *buffer, int *buffer_index);
int handle_reverse(va_list *args, char *buffer, int *buffer_index);
int handle_percent(char *buffer, int *buffer_index);

#endif /* MAIN_H */
