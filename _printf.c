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
 * @value: operand
 * Return: Always 0.
 */
int print_decimal(int value)
{
	int i, j;
	char buffer[1000000];
	int printed = 0;
	unsigned int n;

	if (value < 0)
	{
		_putchar('-');
		printed++;
		n = -value;
	}
	else
	{
		n = value;
	}

	i = 0;

	do {
		buffer[i++] = '0' + (n % 10);
		n /= 10;
		printed++;
	} while (n > 0);
	for (j = i - 1; j >= 0; j--)
	{
		_putchar(buffer[j]);
	}
	return (printed);
}
/**
 * _printf - print string
 * @format: format
 * Return: letter count
 */
int _printf(const char *format, ...)
{
	va_list ptr;
	unsigned int j = 0, a = 0;

	if (!format)
		exit(98);
	if (*format == '%' && *(format + 1) == 0)
		exit(98);
	va_start(ptr, format);
	while (*(format + j))
	{
		if (*(format + j) == '%' && *(format + j + 1) == '%')
		{
			write(1, "%", 1);
			a++;
			j += 2;
		}
		else if (*(format + j) == '%' && *(format + j + 1) == 'c')
		{
			a = print_char(a, (char)va_arg(ptr, int));
			j += 2;
		}
		else if (*(format + j) == '%' && *(format + j + 1) == 's')
		{
			a = print_string(a, va_arg(ptr, char *));
			j += 2;
		}
		else if (*(format + j) == '%' && (*(format + j + 1) == 'd' ||
		*(format + j + 1) == 'i'))
		{
			a += print_decimal(a, va_arg(ptr, int));
			j += 2;
		}
		else
		{
			a++;
		write(1, (format + j), 1);
		j++;
		}
	}
	return (a);
}
