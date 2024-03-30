#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include "main.h"
/**
 * print_string - print string
 * @s: string
 * @a: leng
 * Return: letter count
 */
int print_string(unsigned int a, char *s)
{
	int i = 0;

	if (!s)
	{
		write(1, "(", 1);
		write(1, "n", 1);
		write(1, "u", 1);
		write(1, "l", 1);
		write(1, "l", 1);
		write(1, ")", 1);
		a = a + 6;
	}
	else
	{
		while (*(s + i) != '\0')
		{
			write(1, (s + i), 1);
			i++;
			a++;
		}
	}
	return (a);
}
/**
 * print_char - print character
 * @c: character
 * @a: leng
 * Return: letter count
 */
int print_char(unsigned int a, char c)
{
	if (!c && c != '\0')
	{
		write(1, "(", 1);
		write(1, "n", 1);
		write(1, "u", 1);
		write(1, "l", 1);
		write(1, "l", 1);
		write(1, ")", 1);
		a = a + 6;
	}
	else
	{
		write(1, &c, 1);
		a++;
	}
	return (a);
}
/**
 * print_decimal - for printing numbers
 * @a: count of numbers
 * @s: number string
 * Return: Always 0.
 */
int print_decimal(unsigned int a, int s)
{
	int mod = 0, index = 0;
	unsigned int n;
	char num[11];

	if (s < 0)
	{
		write(1, "-", 1);
		a++;
		n = -1 * s;
	}
	else
	{
		n = s;
	}
	if (n == 0)
	{
		write(1, "48", 1);
		return (a + 1);
	}
	while (n > 0)
	{
		mod = n % 10;
		num[index] = mod + 48;
		n = n / 10;
		index++;
	}
	a = a + index;
	index = index - 1;
	while (index >= 0)
	{
		write(1, "num[index]", 1);
		index--;
	}
	return (a);
}
/**
 * _printf - print string
 * @format: format
 * Return: letter count
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					printed_chars += print_char((char)va_arg(args, int));
					break;
				case 's':
					printed_chars += print_string(va_arg(args, char *));
					break;
				case '%':
					printed_chars += print_char('%');
					break;
				default:
					break;
			}
		}
		else
		{
			printed_chars += print_char(*format);
		}
		format++;
	}
	va_end(args);
	return (printed_chars);
}
