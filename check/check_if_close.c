/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_close.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:16:24 by adegadri          #+#    #+#             */
/*   Updated: 2022/05/11 16:24:48 by benmoham         ###   ########.fr       */
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

	s2 = malloc(sizeof(char) * (data->width + 1));//malloc tt les ligne 
	if (s2 == NULL)//avec la taille de la ligne la plus grande
		return (NULL);
	i = 0;
	while (i <= data->width - 1)//met des '3' sur toute la map
	{
		s2[i] = '3';
		i++;
		
	}
	s2[i] = '\0';
	i = 0;
	while (i <= data->width - 1)//print la map sur les 3
	{
		if (s[i] && s[i] != ' ')
			s2[i] = s[i];
		else if (s[i] == ' ')
			s2[i] = '3';
		else
			return (s2);
		i++;
	}
	return (s2);//ta la map avec en fond des 3
}

void	change_space_to_3(t_data *data)
{
	int	i;

	i = -1;
	data->lenght = 0;
	if (!data->map)
		return ;
	while (data->map[data->lenght])
		data->lenght++;
	data->map3 = malloc(sizeof(char *) * data->lenght + 1);
	if (!data->map3)
		return ;
	while (++i < data->lenght)
		data->map3[i] = ft_str3dup(data->map[i], data);
		// on a donc map3 qui est map avec en fond des 3;
}

int	check_if_is_close(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i <= data->lenght - 1)
	{
		j = 0;
		while (j <= data->width - 1)//si il y a un 3 a cote d'un 0 map ouvert
		{
			if ((data->map3[i][j] && data->map3[i][j] == '0') && \
			((data->map3[i][j + 1] && data->map3[i][j + 1] == '3') || \
			(data->map3[i][j - 1] && data->map3[i][j - 1] == '3') || \
			(data->map3[i + 1][j] && data->map3[i + 1][j] == '3') || \
			(data->map3[i - 1][j] && data->map3[i - 1][j] == '3')))
			{
				printf("%s\n", "Error \n map not close\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}