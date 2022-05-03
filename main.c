/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegadri <adegadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:24:53 by adegadri          #+#    #+#             */
/*   Updated: 2022/05/03 21:37:33 by adegadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	init_img(t_data *data)
{
	data->north.status = 0;
	data->south.status = 0;
	data->west.status = 0;
	data->east.status = 0;
}

void	init_data(t_data *data)
{
	data->line = NULL;
	data->fd = 0;
	data->map = NULL;
	data->map3 = NULL;
}

void	get_map(t_data *data, char **av)
{
	int		res;
	char	*tmp;

	tmp = NULL;
	res = 0;
	init_data(data);
	init_img(data);
	data->fd = open(av[1], O_RDONLY);
	data->line = strdup("");
	if (!data->line)
		return ;
	while (get_next_line(data->fd, &tmp) == 1 && res != -1)
	{
		tmp = ft_strjoin(tmp, "3\n");
		res = get_opt(data, tmp, 0);
		if (res != 1)
			data->line = ft_strjoin(data->line, tmp);
	}
	free(tmp);
	close(data->fd);
	data->map = ft_split(data->line, '\n');
}

int	main(int ac, char **av)
{
	t_data	data;
	//int	i = 0;

	if (ac != 2)
		return (0);
	data.map = NULL;
	data.map3 = NULL;
	get_map(&data, av);
	data.width = size_width(&data);
	data.lenght = size_lenght(&data);
	change_space_to_3(&data);
	//int i = 0;
	/*while (i <= data.lenght - 1)
	{
		printf("line1 %d: %s\n", i,data.map3[i]);
		i++;
	}*/
	if (!check_if_is_close(&data))
	{
		printf("Map not close\n");
		return (0);
	}


	//printf("line1 : %s\n", data.map3[i]);*/
}
