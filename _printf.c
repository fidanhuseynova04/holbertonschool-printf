#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include "main.h"
/**
 * print_string - print string
 * @s: char
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
 * print_decimal - decimal print
 * @deyer: int
 * Return: Always 0.
 */
int print_decimal(int deyer)
{
	int printed = 0;
	unsigned int n;
	char buffer[1000000];

	if (deyer < 0)
	{
		write(1, "-", 1);
		printed++;
		n = -deyer;
	}
	else
	{
		n = deyer;
	}

