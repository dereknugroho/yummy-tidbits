/*

################################################################################

This is a program that takes a string and saves an array of its words. The
words are then displayed to the standard output. A word is a series of
characters separated by whitespace or by the start or end of the string.

For example:

Given the string "This is fun", the program will create this array:

["This", "is", "fun", NULL]

In the example above, each element is also an array (since a string is just
a null-terminated array of chars), so the parent array actually looks like this:

[['T', 'h', 'i', 's', '\0'], ['i', 's', '\0'], ['f', 'u', 'n', '\0']]

...and the child array at index 0 of the parent array looks like this:
['T', 'h', 'i', 's', '\0']

The program will then output the following:
This
is
fun

################################################################################

Restrictions:
	- The program takes a single string which must be contained in double
	  quotes, otherwise there may be undefined behaviour (see usage)
	- The following characters must be escaped: (", \, !)

################################################################################

Usage:

$ gcc -Wall -Wextra -Werror split_whitespace.c
$ ./a.out "This is fun"
  Your original string:
  
  This
  is
  fun
  
  Word at str[0]: This
  Char at str[0][0]: T (ascii 84)
  Char at str[0][1]: h (ascii 104)
  Char at str[0][2]: i (ascii 105)
  Char at str[0][3]: s (ascii 115)
  Char at str[0][4]:  (ascii 0)
  
  Word at str[1]: is
  Char at str[1][0]: i (ascii 105)
  Char at str[1][1]: s (ascii 115)
  Char at str[1][2]:  (ascii 0)
  
  Word at str[2]: fun
  Char at str[2][0]: f (ascii 102)
  Char at str[2][1]: u (ascii 117)
  Char at str[2][2]: n (ascii 110)
  Char at str[2][3]:  (ascii 0) 
$

################################################################################

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char	**split_whitespace(char *s);
static int	word_count(char *s);
static int	is_space(char c);

int			main(int ac, char **av)
{
	// Handle errors
	if (ac != 2)
	{
		printf("Invalid number of arguments! Terminating program.\n");
		exit(1);
	}

	// Organize variables
	char	**str = split_whitespace(av[1]);
	int		i = 0;
	size_t	j;

	// Display info to user
	printf("Your original string:\n\n");
	while (i < word_count(av[1]))
	{
		printf("%s\n", str[i]);
		i++;
	}
	i = 0;
	printf("\n");
	while (i < word_count(av[1]))
	{
		printf("Word at str[%d]: %s\n", i, str[i]);
		j = 0;
		while (j <= strlen(str[i]))
		{
			printf("Char at str[%d][%zu]: %c (ascii %d)\n", i, j, str[i][j],
				str[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}

	// Ensure no leaks before ending program
	free(str);
	str = NULL;
	return (0);
}

// Create a 2-d array that consists of the words in the given string
static char	**split_whitespace(char *s)
{
	int		i = 0;
	int		j = 0;
	int		k;
	int		temp = 0;
	int		word_len;
	char	**r;

	// Handle edge case where s is an empty string or only whitespace
	if (!s || !*s)
	{
		printf("Invalid string! Terminating program.\n");
		exit(1);
	}

	// Allocate memory for parent array
	if (!(r = (char **)malloc(sizeof(char *) * (word_count(s) + 1))))
		return (0);

	// Execute this block for each word in the string, for the entire string
	while (s[i] && j < word_count(s))
	{
		// Reset length of word with each iteration
		word_len = 0;

		// Go to the beginning of the next word in the string
		while (s[i] && is_space(s[i]))
		{
			i++;
			temp++;
		}

		// Determine the length of the newly-encountered word
		while (s[i] && !is_space(s[i]))
		{
			i++;
			word_len++;
		}

		// Allocate memory for child array
		if (!(r[j] = (char *)malloc(sizeof(char) * (word_len + 1))))
			return (0);
		
		// Set specific value for each allocated byte in the child array
		k = 0;
		while (temp < i)
			r[j][k++] = s[temp++];
		r[j][k] = 0;
			
		// Go to the next element in the parent array
		j++;
	}

	// Null-terminate the last element in the parent array
	r[j] = NULL;

	// Return the 2-d array
	return (r);
}

// Count the number of words in a string
static int	word_count(char *s)
{
	int	count = 0;
	int	i = 0;

	while (s[i])
	{
		if (is_space(s[i]))
			i++;
		else
		{
			count++;
			while (s[i] && !is_space(s[i]))
				i++;
		}
	}
	return (count);
}

// Determine if a character is whitespace
static int	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}
