#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * handle_unsigned - Handles the conversion specifier '%u' (unsigned decimal).
 * @args: A va_list containing the argument to be printed.
 * @buffer: The buffer to store the formatted string.
 * @buffer_index: Pointer to the index of buffer.
 *
 * Return: Number of characters printed.
 */
int handle_unsigned(va_list *args, char buffer[], int *buffer_index)
{
	unsigned int num = va_arg(*args, unsigned int);
	int printed_chars = 0;
	int num_length = 0;
	char num_str[20];

	int i = num_length - 1;

	if (num == 0)
	{
		num_str[num_length++] = '0';
	}
	else
	{
		while (num > 0)
		{
			num_str[num_length++] = num % 10 + '0';
			num /= 10;
		}
	}
	while (i >= 0)
	
	{
		if (*buffer_index == BUFFER_SIZE - 1)
		{
			buffer[*buffer_index] = '\0';
			write(1, buffer, *buffer_index);
			*buffer_index = 0;
		}
		buffer[*buffer_index] = num_str[i];
		(*buffer_index)++;
		printed_chars++;
		i--;
	}
	return (printed_chars);
}
