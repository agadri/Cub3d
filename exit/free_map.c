#include "free.h"

void	free_tab(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
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
		data->map3[i] = NULL;
		i++;
	}
	free(data->map3);
	data->map3 = NULL;
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		data->map[i] = NULL;
		i++;
	}
	free(data->map);
	data->map = NULL;
}