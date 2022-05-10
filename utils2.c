#include "parse.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}