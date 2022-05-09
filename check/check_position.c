/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:08:00 by adegadri          #+#    #+#             */
/*   Updated: 2022/05/09 17:12:36 by benmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

void	get_first_position(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	if (!data->map3)
		return ;
	
	while (i <= data->lenght - 1)
	{
		j = 0;
		while (j <= data->width - 1)
		{
			if (data->map3[i][j] && (data->map3[i][j]== 'N' || data->map3[i][j] == 'S' || \
			data->map3[i][j] == 'E' || data->map3[i][j] == 'W'))
			{
				data->pers.pos_x = i;
				data->pers.pos_y = j - 1;
				printf("\nx %d && y %d\n",j,i);
			}
			j++;
		}
		i++;
	}
}

void	get_first_dir(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (j <= data->lenght - 1)
	{
		i = 0;
		while (i <= data->width - 1)
		{
			if (data->map3[j][i] && (data->map3[j][i] == 'N' || \
			data->map3[j][i] == 'S' || data->map3[j][i] == 'E' || \
			data->map3[j][i] == 'W'))
				data->pers.dir_pers = data->map3[j][i];
			i++;
		}
		j++;
	}
}

void	translate_dir(t_data *data)
{
	if (data->pers.dir_pers == 'N')
	{
		data->pers.dir_x_pers = 0;
		data->pers.dire_y_pers = 1;
	}
	else if (data->pers.dir_pers == 'S')
	{
		data->pers.dir_x_pers = 0;
		data->pers.dire_y_pers = -1;
	}
	else if (data->pers.dir_pers == 'E')
	{
		data->pers.dir_x_pers = 1;
		data->pers.dire_y_pers = 0;
	}
	else if (data->pers.dir_pers == 'W')
	{
		data->pers.dir_x_pers = -1;
		data->pers.dire_y_pers = 0;
	}
}


void	init_pos_dir(t_data *data)
{
	get_first_position(data);
	get_first_dir(data);
	translate_dir(data);
}
