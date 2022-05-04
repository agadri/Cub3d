#include "move.h"

int	key_hook(t_data *data)
{
	(void)data;
	/*if (data->key_w == true)
		ft_move_w(data, &data->player);//si touche W
	if (data->key_s == true)
		ft_move_s(data, &data->player);
	if (data->key_d == true)
		ft_move_d(data, &data->player);
	if (data->key_a == true)
		ft_move_a(data, &data->player);
	if (data->key_r == true)
		ft_rot_right(data);
	if (data->key_l == true)
		ft_rot_left(data);
	*/
	if (data->exit == 1)
		exit (0);
	/*
	if (data->key_w == false && data->key_s == false
		&& data->key_l == false && data->key_r == false
		&& data->key_a == false && data->key_d == false)//si rien casse un tour
		return (0);*/
	return (1);
}