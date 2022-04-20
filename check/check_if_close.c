/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_close.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegadri <adegadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:16:24 by adegadri          #+#    #+#             */
/*   Updated: 2022/04/20 16:45:41 by adegadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

int	check_line_close(t_data *data, int line)
{
	int	i;

	i = 0;
	while (data->map[line][i])
	{
		if (data->map[line][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_str3dup(char *s)
{
	int		i;
	int		len;
	char	*s2;

	len = 0;
	while (s[len])
		len++;
	s2 = malloc(sizeof(char) * (len + 1));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (s[i] == ' ')
			s2[i] = '3';
		else
			s2[i] = s[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

void	change_space_to_3(t_data *data)
{
	int	i;

	i = 0;
	while(data->map[i])
		i++;
	data->map3 = malloc(sizeof(char *) * i + 1);
	if (!data->map3)
		return ;
	i = 0;
	while (data->map[i])
	{
		data->map3[i] = ft_str3dup(data->map[i]);
		i++;
	}
}

int	check_if_is_close(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map3[i])
	{
		j = 0;
		while (data->map3[i][j])
		{
			if( (data->map3[i][j] && data->map3[i][j] == '0') && \
			((data->map3[i][j + 1] && data->map3[i][j + 1] == '3') || \
			(data->map3[i][j - 1] && data->map3[i][j - 1] == '3') || \
			(data->map3[i + 1][j] && data->map3[i + 1][j] == '3') || \
			(data->map3[i - 1][j] && data->map3[i - 1][j] == '3')))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}