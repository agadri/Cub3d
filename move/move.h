#ifndef MOVE_H
# define MOVE_H
# include "../parse.h"

void	move_w(t_data *data, t_play *player);
void	move_a(t_data *data, t_play *player);
void	move_s(t_data *data, t_play *player);
void	move_d(t_data *data, t_play *player);
void	rot_right(t_data *data);
void	rot_left(t_data *data);
int		key_press(int keycode, t_data *data);
int		key_release(int keycode, t_data *data);
int		key_hook(t_data *data);

#endif