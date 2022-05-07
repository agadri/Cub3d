#include "free.h"

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