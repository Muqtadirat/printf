#include <stdio.h>
#include <stdarg.h>
#include "main.h"

#define BUFFER_SIZE 1024
/**
 * hexadecimal_uppercase - Handles the 'X' conversion specifier (hexadecimal uppercase).
 * @args: A va_list pointing to the arguments.
 * @buffer: The buffer to store the formatted string.
 * @buffer_index: The current index of the buffer.
 *
 * Return: The number of characters written to the buffer.
 */
int hexadecimal_uppercase(va_list *args, char buffer[], int *buffer_index)
{
	unsigned int num = va_arg(*args, unsigned int);
	int printed_chars = 0;
	char hex_chars[] = "0123456789ABCDEF";
	char hex_num[100];
	int i = 0;

	while (num > 0)
	{
		hex_num[i] = hex_chars[num % 16];
		num = num / 16;
		i++;
	}
	if (i == 0) /*Edge case for num = 0*/
	{
		if (*buffer_index == BUFFER_SIZE - 1)
		{
			buffer[*buffer_index] = '\0';
			printed_chars += write(1, buffer, *buffer_index);
			*buffer_index = 0;
		}
		buffer[(*buffer_index)++] = '0';
		printed_chars++;
	}
	else
	{
		while (i > 0)
		{
			i--;
			if (*buffer_index == BUFFER_SIZE - 1)
			{
				buffer[*buffer_index] = '\0';
				printed_chars += write(1, buffer, *buffer_index);
				*buffer_index = 0;
			}
			buffer[(*buffer_index)++] = hex_num[i];
			printed_chars++;
		}
	}
	return (printed_chars);
}
