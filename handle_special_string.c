#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * handle_special_string - Handles the conversion specifier '%S' (special string).
 * @args: A va_list containing the argument to be printed.
 * @buffer: The buffer to store the formatted string.
 * @buffer_index: Pointer to the index of buffer.
 *
 * Return: Number of characters printed.
 */
int handle_special_string(va_list *args, char buffer[], int *buffer_index)
{
	char *str = va_arg(*args, char *);
	int printed_chars = 0;
	int i;

	for (i = 0; str[i]; i++)
	{
		if ((str[i] < 32 || str[i] >= 127))
		{
			if (*buffer_index == BUFFER_SIZE - 1)
			{
				buffer[*buffer_index] = '\0';
				write(1, buffer, *buffer_index);
				*buffer_index = 0;
			}
			buffer[*buffer_index] = '\\';
			(*buffer_index)++;
			printed_chars++;
			if (*buffer_index == BUFFER_SIZE - 1)
			{
				buffer[*buffer_index] = '\0';
				write(1, buffer, *buffer_index);
				*buffer_index = 0;
			}
			buffer[*buffer_index] = 'x';
			(*buffer_index)++;
			printed_chars++;
			if (*buffer_index == BUFFER_SIZE - 1)
			{
				buffer[*buffer_index] = '\0';
				write(1, buffer, *buffer_index);
				*buffer_index = 0;
			}
		buffer[*buffer_index] = (str[i] / 16 < 10) ? (str[i] / 16) + '0' : (str[i] / 16) - 10 + 'A';
			(*buffer_index)++;
			printed_chars++;

			if (*buffer_index == BUFFER_SIZE - 1)
			{
				buffer[*buffer_index] = '\0';
				write(1, buffer, *buffer_index);
				*buffer_index = 0;
			}
			buffer[*buffer_index] = (str[i] % 16 < 10) ? (str[i] % 16) + '0' : (str[i] % 16) - 10 + 'A';
			(*buffer_index)++;
			printed_chars++;
		}
		else
		{
			if (*buffer_index == BUFFER_SIZE - 1)
			{
				buffer[*buffer_index] = '\0';
				write(1, buffer, *buffer_index);
				*buffer_index = 0;
			}
			buffer[*buffer_index] = str[i];
			(*buffer_index)++;
			printed_chars++;
		}
	}
	return (printed_chars);
}
