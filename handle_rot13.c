#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * handle_rot13 - Handles the conversion specifier '%R' (ROT13).
 * @args: A va_list containing the argument to be printed.
 * @buffer: The buffer to store the formatted string.
 * @buffer_index: Pointer to the index of buffer.
 *
 * Return: Number of characters printed.
 */
int handle_rot13(va_list *args, char buffer[], int *buffer_index)
{
	char *str = va_arg(*args, char *);
	int printed_chars = 0;
	int i;

	for (i = 0; str[i]; i++)
	{
		char ch = str[i];

		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		{
			char base = (ch >= 'a' && ch <= 'z') ? 'a' : 'A';
			char offset = (ch >= 'a' && ch <= 'z') ? 13 : 13;

			ch = ((ch - base) + offset) % 26 + base;
		}
		if (*buffer_index == BUFFER_SIZE - 1)
		{
			buffer[*buffer_index] = '\0';
			write(1, buffer, *buffer_index);
			*buffer_index = 0;
		}
		buffer[*buffer_index] = ch;
		(*buffer_index)++;
		printed_chars++;
	}
	return (printed_chars);
}
