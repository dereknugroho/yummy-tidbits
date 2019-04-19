/*

################################################################################

This is a program that converts a number to a string. Given a value and a base,
the program outputs the value in terms of the specified base.

For example:

If value is 93126 and base is 16, the program will output 16bc6

################################################################################

Restrictions:
 - The program takes two ints:
	1) A base-10 value that fits inside a 4-byte int, given as a string
	2) Any integer base between 2 and 16 (inclusive), given as a string
 - Negative values exist only in base-10
 - Negative values for all other bases are treated as their positive equivalents

################################################################################

Usage:
$ gcc -Wall -Wextra -Werror itoa_base.c
$ ./a.out 93126 16
  Your value (base-10): 93126
  Your base: 16
  Your final value (base-16): 16bc6
$

################################################################################

*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static char	*itoa_base(int value, int base);
static int	valid_int(long num);

int			main(int ac, char **av)
{
	// Handle error: invalid number of arguments
	if (ac != 3)
	{
		printf("Invalid number of arguments! Terminating program.\n");
		exit(1);
	}

	// Handle error: value does not fit in a 4-byte integer
	if (!valid_int(atol(av[1])))
	{
		printf("Invalid value! Terminating program.\n");
		exit(1);
	}

	// Organize variables
	int		value = atoi(av[1]);
	int		base = atoi(av[2]);
	char	*final = itoa_base(value, base);

	// Display info to user
	if (value < 0 && base != 10)
		printf("Your value (base-10): %s\nYour base: %d\n", ++av[1], base);
	else
		printf("Your value (base-10): %d\nYour base: %d\n", value, base);
	printf("Your final value (base-%d): %s\n", base, final);

	// Ensure no leaks before ending program
	free(final);
	final = NULL;
	return (0);
}

static char	*itoa_base(int value, int base)
{
	// Organize variables
	char	*ret;
	long	num = (value < 0) ? -(long)value : (long)value;
	int		bytes = 0;

	// Handle error: invalid base
	if (base < 2 || base > 16)
	{
		printf("Invalid base! Terminating program.\n");
		exit(1);
	}
	if (value == 0)
	{
		if (!(ret = (char *)malloc(2)))
			return (0);
		ret[0] = '0';
		ret[1] = '\0';
		return (ret);
	}

	// Count bytes
	if (value < 0 && base == 10)
		bytes++;
	while (num > 0)
	{
		bytes++;
		num /= base;
	}

	// Reset key variable
	num = (value < 0) ? -(long)value : (long)value;

	// Allocate memory
	if (!(ret = (char *)malloc(sizeof(char) * (bytes + 1))))
		return (0);

	// Set specific value for each allocated byte
	ret[bytes] = 0;
	while (bytes--)
	{
		ret[bytes] = (num % base < 10) ? num % base + '0' :
			num % base + 'a' - 10;
		num /= base;
	}
	if (value < 0 && base == 10)
		ret[0] = '-';

	// Return string
	return (ret);
}

// Check if the value fits inside a 4-byte integer
static int	valid_int(long num)
{
	return (num >= -2147483648 && num <= 2147483647);
}
