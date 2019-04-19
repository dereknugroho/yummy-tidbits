/*

################################################################################

This is a program that takes a strictly positive integer and displays its
multiplication table.

See usage for an example.

################################################################################

Restrictions:
	- The program takes a single strictly positive int, given as a string
	- The product of the argument multiplied by any int between
	  1 and 9 (inclusive) cannot exceed the maximum value that fits in a
	  4-byte int (2147483647)

################################################################################

Usage:

$ gcc -Wall -Wextra -Werror table_mult.c
$ ./a.out 3
$ 1 x 3 = 3
  2 x 3 = 6
  3 x 3 = 9
  4 x 3 = 12
  5 x 3 = 15
  6 x 3 = 18
  7 x 3 = 21
  8 x 3 = 24
  9 x 3 = 27
$

################################################################################

*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static int	my_atoi(char *s);
static void	mult_table(int num);
static void	display_int(int num);
static void	my_putchar(char c);

int		main(int ac, char **av)
{
	// Handle errors
	if (ac != 2)
	{
		printf("Invalid number of arguments! Terminating program.\n");
		exit(1);
	}

	// Display the multiplication table
	mult_table(my_atoi(av[1]));
	return (0);
}

// This is a custom atoi() function which implements some error checking
static int	my_atoi(char *s)
{
	int	num = 0;

	while (*s)
	{
		num = num * 10 + (*s - '0');
		if ((*s < '0' || *s > '9') || (num < 0 || num > 2147483647))
		{
			printf("Invalid argument! Terminating program.\n");
			exit(1);
		}
		s++;
	}
	return (num);
}

// Display the multiplication table
static void	mult_table(int num)
{
	int	factor = 1;

	// Check if products fit inside a 4-byte int
	while (factor < 10)
	{
		if (num <= 0 || num >= 238609295)
		{
			printf("Invalid argument! Terminating program.\n");
			exit(1);
		}
		factor++;
	}
	factor = 1;
	while (factor < 10)
	{
		display_int(factor);
		write(1, " x ", 3);
		display_int(num);
		write(1, " = ", 3);
		display_int(factor * num);
		write(1, "\n", 1);
		factor++;
	}
}

// Display a strictly positive int
static void	display_int(int num)
{
	if (num <= 0)
	{
		printf("Invalid argument! Terminating program.\n");
		exit(1);
	}
	if (num > 9)
		display_int(num / 10);
	my_putchar(num % 10 + '0');
}

// Display a char
static void	my_putchar(char c)
{
	write(1, &c, 1);
}
