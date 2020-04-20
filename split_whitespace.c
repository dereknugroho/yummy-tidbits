/*
**
**  This is a program that takes a string and returns an array of its words.
**
**  Usage:
**  $ gcc split_whitespace.c -o yummy; ./yummy
**
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	**split_whitespace(char *s);
int   word_count(char *s);
int   is_space(char c);

int   main(void)
{
  int   i = 0;
  int   j = 0;
  char  *user_string = (char *)malloc(1024);

  printf("Please enter a string that contains 1023 characters or less: ");
  fgets(user_string, 1024, stdin);

  // Validate input
  if (strlen(user_string) > 1023)
    return (printf("Your string was too long!\n"));
  if (strlen(user_string) == 1)
    return (printf("You didn't enter anything!\n"));

  while (i < strlen(user_string)) {
    if (is_space(user_string[i]))
      j++;
    if (j == strlen(user_string))
      return (printf("There weren't any words in your string!\n"));
    i++;
  }

  // Display output
  char  **split_string = split_whitespace(user_string);
  i = 0;
  j = 0;

  printf("\nHere is your array of words:\n\n");
	while (i < word_count(user_string))
	{
		printf("Word at index [%d]: %s\n--------------------------\n", i, split_string[i]);
		j = 0;
		while (j <= strlen(split_string[i]))
		{
      if (j == strlen(split_string[i]))
        printf("Char at index [%d][%d]: NULL\n", i, j);
      else
			  printf("Char at index [%d][%d]: %c\n", i, j, split_string[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
	return (0);
}

// Create a 2-d array that consists of the words in the given string
char	**split_whitespace(char *s)
{
	int		i = 0;
	int		j = 0;
	int		k;
	int		temp = 0;
	int		word_len;
	char	**r;

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

		// Determine the length of the next word
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
int   word_count(char *s)
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
int   is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}
