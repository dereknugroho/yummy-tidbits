/*
**
**  This program takes a non-negative integer and displays
**  the sum of all prime numbers less than or equal to it.
**
**  Usage:
**  $ gcc add_prime_sum.c -o yummy; ./yummy
**
**  Restriction:
**  - The program takes a single non-negative int whose
**    sum of primes does not exceed the maximum value
**    that fits in a 4-byte integer (i.e. the largest
**	  value that you can give the program is 225286)
**
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int   add_prime_sum(int num);
int		is_prime(int num);

// Entry point
int		main(void)
{
	int	num = 0;
	int	val = 0;

	printf("Enter any number between 0 and 225286 (inclusive): ");
	scanf("%d", &num);
	if (num < 0 || num > 225286)
		return (printf("Invalid value! Terminating program.\n"));
	val = add_prime_sum(num);
	printf("Sum of primes less than or equal to %d: %d\n", num, val);
	return (0);
}

// Calculate sum of all prime integers less than or equal to num
int   add_prime_sum(int num)
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
int		is_prime(int num)
{
	int	i = 2;

	if (num == 1)
		return (0);
	while (i < num)
		if (num % i++ == 0)
			return (0);
	return (1);
}
