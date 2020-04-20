/*
**
**  This program takes a string and displays it with the first letter
**  of each word capitalized and the rest of the word in lowercase.
**  Leading and trailing whitespace is removed and whitespace between
**  each word is forced to be a single space.
**
**  Usage:
**  $ gcc str_capitalizer.c -o yummy; ./yummy
**
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	str_cap(char *str);
int		is_space(char c);
int		is_upper(char c);
int		is_lower(char c);

int		main(void)
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
  printf("Here is your modified string: ");
  str_cap(user_string);
  return (0);
}

void	str_cap(char *s)
{
	int	i = 0;

	while (s[i] && is_space(s[i]))
		i++;
	while (s[i])
	{
		// Display original uppercase letter
		if (is_upper(s[i]) && (i == 0 || is_space(s[i - 1])))
      printf("%c", s[i]);
		// Display original lowercase letter
		else if (is_lower(s[i]) && (i != 0 && !is_space(s[i - 1])))
			printf("%c", s[i]);
		// Display a forced uppercase letter
		else if (is_lower(s[i]) && (i == 0 || is_space(s[i - 1])))
			printf("%c", s[i] - 32);
		// Display a forced lowercase letter
		else if (is_upper(s[i]) && (i != 0 && !is_space(s[i - 1])))
			printf("%c", s[i] + 32);
		else
      printf("%c", s[i]);
		i++;
	}
}

int		is_space(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int		is_upper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int		is_lower(char c)
{
	return (c >= 'a' && c <= 'z');
}
