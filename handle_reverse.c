#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <string.h>

/**
 * handle_reverse - Handles the conversion specifier '%r' (reverse).
 * @args: A va_list containing the argument to be printed.
 * @buffer: The buffer to store the formatted string.
 * @buffer_index: Pointer to the index of buffer.
 *
 * Return: Number of characters printed.
 */
int handle_reverse(va_list *args, char buffer[], int *buffer_index)
{
	char *str = va_arg(*args, char *);
	int str_length = strlen(str);
	int i;

	for (i = str_length - 1; i >= 0; i--)
	{
		if (*buffer_index == BUFFER_SIZE - 1)
		{
			buffer[*buffer_index] = '\0';
			write(1, buffer, *buffer_index);
			*buffer_index = 0;
		}
		buffer[*buffer_index] = str[i];
		(*buffer_index)++;
	}
	return (str_length);
}
