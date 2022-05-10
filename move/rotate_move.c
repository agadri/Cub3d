#include "move.h"

void	rot_right(t_data *data)
{
	double		old_dirx;
	double		old_planex;

	old_dirx = data->player.dir.x;
	old_planex = data->player.plane.x;
	data->player.dir.x = data->player.dir.x * cos(-0.04)
		- data->player.dir.y * sin(-0.04);
	data->player.dir.y = old_dirx * sin(-0.04)
		+ data->player.dir.y * cos(-0.04);
	data->player.plane.x = data->player.plane.x * cos(0.04)
		- data->player.plane.y * sin(-0.04);
	data->player.plane.y = old_planex * sin(-0.04)
		+ data->player.plane.y * cos(-0.04);
}

void	rot_left(t_data *data)
{
	double		old_dirx;
	double		old_planex;

	old_dirx = data->player.dir.x;
	old_planex = data->player.plane.x;
	data->player.dir.x = data->player.dir.x * cos(0.04)
		- data->player.dir.y * sin(0.04);
	data->player.dir.y = old_dirx * sin(0.04)
		+ data->player.dir.y * cos(0.04);
	data->player.plane.x = data->player.plane.x * cos(0.04)
		- data->player.plane.y * sin(0.04);
	data->player.plane.y = old_planex * sin(0.04)
		+ data->player.plane.y * cos(0.04);
}