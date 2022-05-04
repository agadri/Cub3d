/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_close.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegadri <adegadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:16:24 by adegadri          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/05/04 12:22:07 by adegadri         ###   ########.fr       */
=======
/*   Updated: 2022/05/03 21:39:06 by adegadri         ###   ########.fr       */
>>>>>>> 3bfef27084fba61b45a7df4d074dc7515720feed
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

char	*ft_str3dup(char *s, t_data *data)
{
	int		i;
	char	*s2;

	s2 = malloc(sizeof(char) * (data->width + 1));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (i <= data->width - 1)
	{
		s2[i] = '3';
		i++;
	}
	i = 0;
	while (i <= data->width - 1)
	{
		if (!s[i])
			s2[i] = '3';
		else if (s[i])
			s2[i] = s[i];
		i++;
	}
	//printf("check%s\n", s);
	s2[i] = '\0';
	return (s2);
}

void	change_space_to_3(t_data *data)
{
	int	i;

	i = 0;
	data->lenght = 0;
	if (!data->map)
		return ;
	while (data->map[data->lenght])
		data->lenght++;
	data->map3 = malloc(sizeof(char *) * data->lenght + 1);
	if (!data->map3)
		return ;
	i = 0;
	while (i <= data->lenght - 1)
	{
		data->map3[i] = ft_str3dup(data->map[i], data);
		printf("1 i = %d |%s|\n",i, data->map3[i]);
		i++;
	}
}

int	check_if_is_close(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i <= data->lenght - 1)
	{
		j = 0;
		while (j <= data->width - 1)
		{
			if ((data->map3[i][j] && data->map3[i][j] == '0') && \
			((data->map3[i][j + 1] && data->map3[i][j + 1] == '3') || \
			(data->map3[i][j - 1] && data->map3[i][j - 1] == '3') || \
			(data->map3[i + 1][j] && data->map3[i + 1][j] == '3') || \
			(data->map3[i - 1][j] && data->map3[i - 1][j] == '3')))
			{
				printf("c=%c x:%d y:%d", data->map3[i][j],i ,j);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}