/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_play.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:39:39 by benmoham          #+#    #+#             */
/*   Updated: 2022/05/10 17:45:36 by benmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_all.h"

void	set_plane(t_data *data, double dx, double dy)
{
	data->player.plane.x = dx;
	data->player.plane.y = dy;
}

void	set_dir(t_data *data, double x, double y)
{
	data->player.dir.x = x;
	data->player.dir.y = y;
}

void	west_east(t_data *data, char dir)
{
	if (dir == 'E')
	{
		set_dir(data, 0, 1);
		set_plane(data, 0.66, 0);
	}
	else if (dir == 'W')
	{	
		set_dir(data, 0, -1);
		set_plane(data, -0.66, 0);
	}
}

void	init_player(t_data *data, int h, int w, char dir)
{
	if (data->player.status == 0)
		exit_opt(data, "Player already set\n");
	if (dir == 'N')
	{
		set_dir(data, -1, 0);
		set_plane(data, 0, 0.66);
	}
	else if (dir == 'S')
	{
		set_dir(data, 1, 0);
		set_plane(data, 0, -0.66);
	}
	else if (dir == 'E' || dir == 'W')
		west_east(data, dir);
	data->player.pos.x = h + 0.5;
	data->player.pos.y = w + 0.5;
	data->player.status =0 ;
}
