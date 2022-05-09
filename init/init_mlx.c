/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegadri <adegadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:20:58 by adegadri          #+#    #+#             */
/*   Updated: 2022/05/07 19:43:06 by adegadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_all.h"

void	init_win(t_data *data)
{
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!data->win)
		exit_opt(data, "Loading window failed");
	//init_display(data);
}

void	init_data(t_data *data)
{
	data->win = NULL;
	data->line = NULL;
	data->fd = 0;
	data->map = NULL;
	data->map3 = NULL;
	data->exit = 0;
}

void	init_img(t_data *data)
{
	data->north.status = 0;
	data->south.status = 0;
	data->west.status = 0;
	data->east.status = 0;
}

void	init_first(t_data *data)
{
	init_win(data);
	init_data(data);
	init_img(data);
	init_pers(data);
}