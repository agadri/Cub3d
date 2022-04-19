/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegadri <adegadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:24:53 by adegadri          #+#    #+#             */
/*   Updated: 2022/04/19 15:36:09 by adegadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	get_map(t_data *data, char **av)
{
	int		res;
	char	*tmp;

	tmp = NULL;
	data->fd = open(av[1], O_RDONLY);
	data->line = strdup("");
	if (!data->line)
		return ;
	while (get_next_line(data->fd, &tmp) == 1 && res != -1)
	{
		tmp = ft_strjoin(tmp, "\n");
		res = printf("line : %s", tmp);
		data->line = ft_strjoin(data->line, tmp);
	}
	free(tmp);
	close(data->fd);
	data->map = ft_split(data->line, '\n');
}

int	main(int ac, char **av)
{
	t_data	data;
	t_img	img;

	
	if (ac != 2)
		return (0);
	get_map(&data, av);
	int i = 0;
	while (data.map[i])
	{
		printf("line1 : %s\n", data.map[i]);
		i++;
	}
}
