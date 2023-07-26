#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * handle_percent - Handles the conversion specifier '%%' (percent).
 * @buffer: The buffer to store the formatted string.
 * @buffer_index: Pointer to the index of buffer.
 *
 * Return: Number of characters printed.
 */
int handle_percent(char buffer[], int *buffer_index)
{
	if (*buffer_index == BUFFER_SIZE - 1)
	{
		buffer[*buffer_index] = '\0';
		write(1, buffer, *buffer_index);
		*buffer_index = 0;
	}
	buffer[*buffer_index] = '%';
	(*buffer_index)++;
	return (1);
}
