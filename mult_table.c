/*
**
**  This is a program that takes a strictly positive integer
**  and displays its multiplication table from 1 to 9.
**
**  Usage:
**  $ gcc mult_table.c -o yummy; ./yummy
**
*/

#include <stdio.h>

void	mult_table(int num);

// Entry point
int		main(void)
{
  int num = 0;
  
  printf("Enter any number between 1 and 268435455: ");
  scanf("%d", &num);

  if (num < 1 || num > 268435455)
    return (printf("Number outside of valid range! Terminating program.\n"));

  printf("Multiplication table for %d:\n", num);
  mult_table(num);

	return (0);
}

// Display the multiplication table
void  mult_table(int num)
{
	int factor = 1;
	
	while (factor < 10)
	{
    printf("%d * %d = %d\n", num, factor, num * factor);
		factor++;
	}
}
