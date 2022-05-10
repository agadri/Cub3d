#ifndef INIT_ALL_H
# define INIT_ALL_H
# include "../parse.h"

void	init_win(t_data *data);
void	init_data(t_data *data);
void	init_img(t_data *data);
void	init_player(t_data *data, int h, int w, char dir);
void	init_rgb(t_data *data);
void	set_plane(t_data *data, double dx, double dy);
void	set_dir(t_data *data, double x, double y);
void	west_east(t_data *data, char dir);
void	init_player(t_data *data, int h, int w, char dir);

#endif