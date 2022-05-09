#include "free.h"

/*
	void	*mlx;
	void	*win;
	void	*img;

	char	*line;
	int		fd;
	char	**map;
	char	**map3;
	t_img	north;
	t_img	south;
	t_img	west;
	t_img	east;
*/



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
