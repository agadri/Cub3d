/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:54:03 by benmoham          #+#    #+#             */
/*   Updated: 2022/05/09 17:54:04 by benmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "free.h"

void	free_data(t_data *data)
{
	//if (data->line)
	//	free(data->line);
	if (data->fd)
		close (data->fd);
	if (data->map)
	{
		free_map(data);
		data->map = NULL;
	}
	if (data->map3)
	{
		free_map3(data);
		data->map3 = NULL;
	}
}

void	free_img(t_data *data)
{
	if (data->north.img)
	{
		mlx_destroy_image(data->mlx, data->north.img);
		printf("BBBBBB\n");
	}
	if (data->south.img != NULL)
		mlx_destroy_image(data->mlx, data->south.img);
	if (data->west.img != NULL)
	{
		printf("trrtrtr\n");
		mlx_destroy_image(data->mlx, data->west.img);
	}
	if (data->east.img != NULL)
		mlx_destroy_image(data->mlx, data->east.img);
	//mlx_destroy_display()
	//if (data->maintx.img != NULL)
	//	mlx_destroy_image(data->mlx, data->maintx.img);
}
