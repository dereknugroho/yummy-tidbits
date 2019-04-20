/*

################################################################################

This is a program that takes a non-negative int and displays the sum of all
prime numbers less than or equal to it.

################################################################################

Usage:
$ gcc -Wall -Wextra -Werror add_prime_sum.c
$ ./a.out 12
  Sum of all primes less than or equal to 12:
  28
$

################################################################################

Restrictions:
	- The program takes a single non-negative int whose sum of primes does not
	  exceed the maximum value that fits in a 4-byte integer (i.e. the largest
	  value that the program can take is 225286)

################################################################################

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int	my_atoi(char *s);
static long	prime_sum(int num);
static int	is_prime(int num);
static void	display_num(long num);
static void	my_putchar(char c);
static int	valid_int(long num);

int		main(int ac, char **av)
{
	// Handle error: invalid number of arguments
	if (ac != 2)
	{
		printf("Invalid number of arguments! Terminating program.\n");
		exit(1);
	}

	// Display sum of prime numbers
	int		num = my_atoi(av[1]);
	long	sum = prime_sum(num);

	printf("Sum of primes less than or equal to %d:\n", num);
	display_num(sum);
	printf("\n");
	return (0);
}

// Custom atoi() implementation with specific error handling
static int	my_atoi(char *s)
{
	int	num = 0;

	while (*s)
	{
		if ((*s < '0' || *s > '9') || (num < 0 || num > 2147483647))
		{
			printf("Invalid number! Terminating program.\n");
			exit(1);
		}
		num = num * 10 + (*s++ - '0');
	}
	return (num);
}

// Calculate sum of all prime integers less than or equal to num
static long	prime_sum(int num)
{
	long	sum = 0;
	while (num > 1)
	{
		if (is_prime(num))
			sum += num;
		num--;
	}
	return (sum);
}

// Check whether a positive integer is a prime number
static int	is_prime(int num)
{
	int	i = 2;

	if (num == 1)
		return (0);
	while (i < num)
		if (num % i++ == 0)
			return (0);
	return (1);
}

// Display a long
static void	display_num(long num)
{
	// Handle error: num does not fit in a 4-byte integer
	if (!valid_int(num))
	{
		printf("Sum is too large! Max arg: 225286. Terminating program.\n");
		exit(1);
	}
	
	// Display the long
	if (num > 9)
		display_num(num / 10);
	my_putchar(num % 10 + '0');
}

// Check if the value fits inside a 4-byte integer
static int	valid_int(long num)
{
	return (num >= -2147483648 && num <= 2147483647);
}

// Display a char
static void	my_putchar(char c)
{
	write(1, &c, 1);
}
