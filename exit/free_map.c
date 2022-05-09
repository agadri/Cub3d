#include "free.h"


void	free_img(t_data *data)
{
	if (data->north.img)
		mlx_destroy_image(data->mlx, data->north.img);
	if (data->south.img != NULL)
		mlx_destroy_image(data->mlx, data->south.img);
	if (data->west.img != NULL)
		mlx_destroy_image(data->mlx, data->west.img);
	if (data->east.img != NULL)
		mlx_destroy_image(data->mlx, data->east.img);
	//mlx_destroy_display()
	// if (data->maintx.img != NULL)
	// 	mlx_destroy_image(data->mlx, data->maintx.img);
}

void	free_tab(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

void	free_map3(t_data *data)
{
	int	i;

	i = 0;
	while (i <= data->lenght - 1)
	{
		free(data->map3[i]);
		i++;
	}
	free(data->map3);
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}