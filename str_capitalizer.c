/*

################################################################################

This is a program that takes one or more strings and for each string,
displays the entire string with the first letter of each word capitalized,
with the rest of the word in lowercase, assuming it is an alphabetical
character. Additionally, leading and trailing whitespace is removed from
each string, and whitespace between each word is forced to be a single
space

################################################################################

Usage:
$ gcc -Wall -Wextra -Werror str_capitalizer.c
$ ./a.out "  hEllo!!!42xd     w0rLD...   "
  Hello!!!42xd w0rld...
$

################################################################################

Restrictions:
	- The program must take at least a single argument

*/

#include <stdio.h>
#include <unistd.h>

void	str_cap(char *str);
int		is_space(char c);
int		is_upper(char c);
int		is_lower(char c);
void	ft_putchar(char c);

int		main(int ac, char **av)
{
	int	i = 1;

	if (ac != 1)
		while (av[i])
			str_cap(av[i++]);
	write(1, "\n", 1);
	return (0);
}

/*

1. Display original uppercase letter
	- First letter of string
	- First letter of a word
2. Display original lowercase letter
	- Not the first letter of a word
3. Display a forced uppercase letter
	- Lowercase first letter of a word
4. Display a forced lowercase letter
	- Uppercase non-first letter of a word
5. Display a non-alphabetical character

*/

void	str_cap(char *s)
{
	int	i = 0;

	while (s[i] && is_space(s[i]))
		i++;
	while (s[i])
	{
		// 1. Display original uppercase letter
		if (is_upper(s[i]) && (i == 0 || is_space(s[i - 1])))
			ft_putchar(s[i]);
		// 2. Display original lowercase letter
		else if (is_lower(s[i]) && (i != 0 && !is_space(s[i - 1])))
			ft_putchar(s[i]);
		// 3. Display a forced uppercase letter
		else if (is_lower(s[i]) && (i == 0 || is_space(s[i - 1])))
			ft_putchar(s[i] - 32);
		// 4. Display a forced lowercase letter
		else if (is_upper(s[i]) && (i != 0 && !is_space(s[i - 1])))
			ft_putchar(s[i] + 32);
		else
			ft_putchar(s[i]);
		i++;
	}
	// ft_putchar('\n');
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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
























