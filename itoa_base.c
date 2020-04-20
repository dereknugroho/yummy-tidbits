/*

################################################################################

This is a program that converts a number to a string. Given a value and a base,
this program displays the given value in terms of the specified base.

For example:

If value is 93126 and base is 14, the program will output 25d1c.

Note: There is no malloc error handling.

################################################################################

Usage:
$ gcc -Wall -Wextra -Werror itoa_base.c -o ./itoa_base
$ ./itoa_base
  Choose a strictly positive value: 93126
  Choose any base from 2 up to 16: 14
  The representation of the value 93126 in base 14 is: 25d1c
$

################################################################################

*/

#include <stdio.h>
#include <stdlib.h>

char	*itoa_base(int value, int base);

int			main(void)
{
	int		value = 0;
	int		base = 10;
	char	*result = "";

	printf("Enter a strictly positive value: ");
	scanf("%d", &value);
	if (value <= 0)
		return (printf("Invalid value! Terminating program.\n"));

	printf("Enter any base between 2 and 16 (inclusive): ");
	scanf("%d", &base);
	if (base < 2 || base > 16)
		return (printf("Invalid base! Terminating program.\n"));

	result = itoa_base(value, base);

	printf("The representation of the value %d in base %d is: %s\n", value, base, result);
	return (0);
}

char	*itoa_base(int value, int base)
{
	char	*ret = "";
	int		num = value;
	int		bytes = 0;
	
	// Count bytes
	while (num > 0)
	{
		bytes++;
		num /= base;
	}
	
	// Set some vars
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

	// Return allocated string
	return (ret);
}
