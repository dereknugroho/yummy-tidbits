/*

##################################################################

This is a program that converts a number to a string. Given a
value and a base, the program outputs the value in terms of the
specified base.

For example:

If value is 93126 and base is 16, the program will output 16BC6

##################################################################

Usage:
$ gcc -Wall -Wextra -Werror itoa_base.c
$ ./a.out 93126 16 | cat -e
$ 16BC6
$

##################################################################

Restrictions:
	- Program takes two ints:
		1) A base-10 value
		2) Any base between 2 and 16 (inclusive)
	- A negative sign is present only for negative base-10 values
	- Negative values for all other bases are treated as unsigned

##################################################################

*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char	*itoa_base(int value, int base)
{
	// Organize variables
	char	*ret;
	long	num = (value < 0) ? -(long)value : (long)value;
	int		bytes = 0;

	// Handle errors and edge cases
	if (base < 2 || base > 16)
	{
		printf("Invalid base! Terminating program.\n");
		exit(0);
	}
	if (value == 0)
	{
		ret = (char *)malloc(2);
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
		ret[bytes] = (num % base < 10) ? num % base + '0' : num % base + 'A' - 10;
		num /= base;
	}
	if (value < 0 && base == 10)
		ret[0] = '-';

	// Return string
	return (ret);
}

int		main(int ac, char **av)
{
	// Handle errors
	if (ac != 3)
	{
		printf("Invalid number of arguments! Terminating program.\n");
		return (0);
	}

	// Organize variables
	int		value = atoi(av[1]);
	int		base = atoi(av[2]);
	char	*final = itoa_base(value, base);

	// Display info to user
	if (value < 0 && base != 10)
		printf("Your unsigned value (base-10): %s\n", ++av[1]);
	else
		printf("Your value (base-10): %d\nYour base: %d\n", value, base);
	printf("Your final value (base-%d): %s\n", base, final);

	// Ensure no leaks before ending program
	free(final);
	final = NULL;
	return (0);
}
