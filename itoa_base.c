/*
**
**  This program converts a number to a string in a specified base.
**
**  Usage:
**  $ gcc itoa_base.c -o yummy; ./yummy
**
*/

#include <stdio.h>
#include <stdlib.h>

char	*itoa_base(int value, int base);

// Entry point
int			main(void)
{
	int		value = 0;
	int		base = 10;

	printf("Enter a strictly positive value: ");
	scanf("%d", &value);
	if (value <= 0)
		return (printf("Invalid value! Terminating program.\n"));

	printf("Enter any base between 2 and 16 (inclusive): ");
	scanf("%d", &base);
	if (base < 2 || base > 16)
		return (printf("Invalid base! Terminating program.\n"));

	printf("The representation of the value %d in base %d is: %s\n", value, base, itoa_base(value, base));
	return (0);
}

// Convert an integer to a string in a specified base
char	*itoa_base(int value, int base)
{
	char	*ret = "";
	int		num = value;
	int		bytes = 0;
	
	// Count number of bytes to be allocated in memory
	while (num > 0)
	{
		bytes++;
		num /= base;
	}
	
  // Allocate memory
	num = value;
	ret = (char *)malloc(sizeof(char) * (bytes + 1));

	// Set specific value for each allocated byte
	ret[bytes] = 0;
	while (bytes--)
	{
		ret[bytes] = (num % base < 10) ? num % base + '0' :
			num % base + 'a' - 10;
		num /= base;
	}

	// Return allocated bytes
	return (ret);
}
