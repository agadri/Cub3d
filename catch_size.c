/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegadri <adegadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:16:36 by adegadri          #+#    #+#             */
/*   Updated: 2022/05/04 19:31:53 by adegadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	size_width(t_data *data)//ligne la plus grande de la map
{
	int	i;
	int	width1;
	int	width2;

	i = 0;
	if (!data->map)
		return (0);
	width1 = ft_strlen(data->map[0]);
	while (data->map[i])
	{
		if (data->map[i])
			width2 = ft_strlen(data->map[i]);
		if (width1 < width2)
			width1 = width2;
		printf("width1 %d, width2 %d, str : %s\n", width1, width2,data->map[i]);
		i++;
	}
	return (width1);
}

int	size_lenght(t_data *data)//longueur de la map
{
	int	i;

	i = 0;
	if (!data->map)
		return (0);
	while (data->map[i])
		i++;
	return (i);
}