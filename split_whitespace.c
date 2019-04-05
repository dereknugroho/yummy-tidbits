/*

#################################################################################

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

#################################################################################

Usage:

$ gcc -Wall -Wextra -Werror split_whitespace.c
$ ./a.out "This is fun" | cat -e
$ This
  is
  fun
$

#################################################################################

Restrictions:
	- Program takes a single string
	- Some non-alphanumeric characters need to be escaped (e.g. "\! \!")
		- After execution, may encounter dquote> on the command line.
		  Just type a double quote and hit Enter

#################################################################################

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Determine if a character is a whitespace character
static int	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

// Count the number of words in a string
static int	word_count(char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (is_space(*s))
			s++;
		else
		{
			count++;
			while (*s && !is_space(*s))
				s++;
		}
	}
	return (count);
}

// Create a 2-d array that consists of the words in the given string
char		**split_whitespace(char *s)
{
	int		i = 0;
	int		j = 0;
	int		k;
	int		word_len = 0;
	char	**r;

	// Allocate memory for parent array
	if (!(r = (char **)malloc(sizeof(char *) * (word_count(s) + 1))))
		return (0);

	// Execute this block for each word in the string, for the entire string
	while (s[i] && j < word_count(s))
	{
		
		// Go to the beginning of the next word in the string
		while (s[i] && is_space(s[i]))
			i++;

		// Determine the length of the newly-encountered word
		while (s[i] && !is_space(s[i]))
		{
			word_len++;
			i++;
		}

		// Allocate memory for child array
		if (!(r[j] = (char *)malloc(sizeof(char) * (word_len + 1))))
			return (0);
		
		// Set specific value for each allocated byte in the child array
		k = 0;
		while (word_len)
		{
			r[j][k] = s[i - word_len];
			k++;
			word_len--;
		}
		r[j][k] = '\0';
		
		// Go to the next element in the parent array
		j++;
	}

	// Null-terminate the last element in the parent array
	r[j] = NULL;

	// Return the 2-d array
	return (r);
}

int		main(int ac, char **av)
{
	// Handle errors
	if (ac != 2)
	{
		printf("Invalid number of arguments! Terminating program.\n");
		return (0);
	}

	// Organize variables
	char	**str = split_whitespace(av[1]);
	int		i = 0;

	// Display info to user
	printf("Your original string: %s\n", av[1]);
	while (i <= word_count(av[1]))
	{
		printf("Word at index %d: %s\n", i, str[i]);
		i++;
	}

	// Ensure no leaks before ending program
	free(str);
	str = NULL;
	return (0);
}
