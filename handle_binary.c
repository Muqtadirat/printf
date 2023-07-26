#include <stdio.h>
#include <stdarg.h>
#include "main.h"

#define BUFFER_SIZE 1024
/**
 * handle_binary - Handles the 'b' conversion specifier (binary representation).
 * @args: A va_list pointing to the arguments.
 * @buffer: The buffer to store the formatted string.
 * @buffer_index: The current index of the buffer.
 *
 * Return: The number of characters written to the buffer.
 */
int handle_binary(va_list *args, char buffer[], int *buffer_index)
{
	unsigned int num = va_arg(*args, unsigned int);
	int printed_chars = 0;
	int binary_num[32]; /*Assuming 32-bit integer*/

	int i = 0;

	while (num > 0)
	{
		binary_num[i] = num % 2;
		num = num / 2;
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
		buffer[*buffer_index++] = '0';
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
			buffer[*buffer_index++] = binary_num[i] + '0';
			printed_chars++;
		}
	}
	return (printed_chars);
}
