/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegadri <adegadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:24:53 by adegadri          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/05/04 17:55:27 by adegadri         ###   ########.fr       */
=======
/*   Updated: 2022/05/03 21:37:33 by adegadri         ###   ########.fr       */
>>>>>>> 3bfef27084fba61b45a7df4d074dc7515720feed
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	x(t_data *data)
{
	//ft_destroy_images(data);
	//ft_destroy_window(data);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	//ft_exit(vars, 0);
	return (0);
}

int	get_map(t_data *data, char **av)
{
	int		res;
	char	*tmp;

	tmp = NULL;
	res = 0;
	init_data(data);
	data->mlx = mlx_init();
	init_win(data);
	init_data(data);
	init_img(data);
	data->fd = check_fd(av[1]);
	data->line = strdup("");//mettre ft_strdup
	if (!data->line)
		return (0);
	while (get_next_line(data->fd, &tmp) == 1 && res != -1)
	{
		tmp = ft_strjoin(tmp, "\n");
		res = get_opt(data, tmp, 0);
		if (res != 1)
			data->line = ft_strjoin(data->line, tmp);
	}
	free(tmp);
	close(data->fd);
	data->map = ft_split(data->line, '\n');
	if (!data->map)
		return (0);
	return (1);
}

int	loop_raycast(t_data *data)
{
	key_hook(data);
	draw(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;
	//int	i = 0;

	if (!check_all(ac, av, &data))
		return (0);
<<<<<<< HEAD
	mlx_loop_hook(data.mlx, loop_raycast, &data);
	mlx_hook(data.win, 33, 131072, &x, &data);
	//mlx_hook(data.win, 2, 1L << 0, key_press, &data);
	//mlx_hook(data.win, 33, 131072, &ft_free, &data);
	mlx_do_sync(data.mlx);
	mlx_loop(data.mlx);
	return (1);
=======
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
>>>>>>> 3bfef27084fba61b45a7df4d074dc7515720feed
}
//a faire : la fenetre apparait mais disparait directement apres img->imgest cree donc je capte pas le probleme , d'ou proviens le segv