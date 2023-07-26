#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

#define BUFFER_SIZE 1024

int _printf(const char *format, ...)
{
	int printed_chars = 0;
	char buffer[BUFFER_SIZE];
	int buffer_index = 0;
	va_list args;
	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'r':
					printed_chars += handle_reverse(&args, buffer, &buffer_index);
					break;
				case 'R':
					printed_chars += handle_rot13(&args, buffer, &buffer_index);
					break;
				case 'S':
					printed_chars += handle_special_string(&args, buffer, &buffer_index);
					break;
				case 'b':
					printed_chars += handle_binary(&args, buffer, &buffer_index);
					break;
				case 'u':
					printed_chars += handle_unsigned(&args, buffer, &buffer_index);
					break;
				case 'o':
					printed_chars += handle_octal(&args, buffer, &buffer_index);
					break;
				case 'x':
					printed_chars += handle_hexadecimal(&args, buffer, &buffer_index);
					break;
				case 'X':
					printed_chars += hexadecimal_uppercase(&args, buffer, &buffer_index);
					break;
				case '%':
					if (buffer_index == BUFFER_SIZE - 1)
					{
						buffer[buffer_index] = '\0';
						printed_chars += write(1, buffer, buffer_index);
						buffer_index = 0;
					}
					buffer[buffer_index++] = '%';
					printed_chars++;
					break;
				default:
					if (buffer_index == BUFFER_SIZE - 1)
					{
						buffer[buffer_index] = '\0';
						printed_chars += write(1, buffer, buffer_index);
						buffer_index = 0;
					}
					buffer[buffer_index++] = *format;
					printed_chars++;
					break;
			}
		}
		else
		{
			if (buffer_index == BUFFER_SIZE - 1)
			{
				buffer[buffer_index] = '\0';
				printed_chars += write(1, buffer, buffer_index);
				buffer_index = 0;
			}
			buffer[buffer_index++] = *format;
			printed_chars++;
		}
		format++;
	}
	if (buffer_index > 0)
	{
		buffer[buffer_index] = '\0';
		printed_chars += write(1, buffer, buffer_index);
	}
	va_end(args);
	return (printed_chars);
}
