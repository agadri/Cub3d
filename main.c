/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:24:53 by adegadri          #+#    #+#             */
/*   Updated: 2022/05/07 14:39:37 by benmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char        *ft_strjoinfree(char *s1, char *s2, int to_free)
{
    char    *array;

    array = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) +1 );
    strcpy(array, s1);
    strcpy(array + ft_strlen(s1), s2);
    if (to_free == 1  || to_free == 3)
        free(s1);
    if (to_free == 2  || to_free == 3)
        free(s2);
    return (array);
}

int	x(t_data *data)
{
	//ft_destroy_images(data);
	//ft_destroy_window(data);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	//ft_exit(vars, 0);
	return (0);
}

int	get_map(t_data *data, char **av)//obtenir la map
{
	int		res;
	char	*tmp;

	tmp = NULL;
	res = 0;
	init_data(data);// j'init ma structure etc
	init_win(data);
	init_data(data);
	init_img(data);
	data->fd = check_fd(av[1]);//prend le fd en le checkant
	data->line = ft_strdup("");//init line
	if (!data->line)
		return (0);
	while (get_next_line(data->fd, &tmp) == 1 && res != -1)// prend la map avec gnl
	{
		tmp = ft_strjoinfree(tmp, " \n", 1);//ligne par ligne 
		res = get_opt(data, tmp, 0);// quand c'est pas une option copie pas
		if (res != 1)
			data->line = ft_strjoinfree(data->line, tmp, 1);
		free(tmp);
	}
	free(tmp);
	close(data->fd);
	data->map = ft_split(data->line, '\n');// toute la ligne joint donc split
	free(data->line);
	if (!data->map)
		return (0);
	data->width = size_width(data);
	data->lenght = size_lenght(data);
	if (!check_letter(data) || \
	!check_duplicate_position(data))
	{
		free_map(data);
		return (0);
	}
	return (1);//on a la map 
}

int	loop_raycast(t_data *data)
{
	key_hook(data);
	draw(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;//j'init

	data.mlx = NULL;
	data.mlx = mlx_init();
	data.map = NULL;
	data.map3 = NULL;
	if (!check_all(ac, av, &data))
	{
		// je check la map
		return (0);// sinon pas bon tchao
	}
	mlx_loop_hook(data.mlx, loop_raycast, &data);//pour agir sur la window
	//mlx_hook(data.win, 2, 1L << 0, key_press, &data);//quand t'appuie sur une touche
	//mlx_hook(data.win, 33, 131072, &ft_free, &data);
	mlx_do_sync(data.mlx);
	mlx_loop(data.mlx);//la boucle qui maintiens la window
	free_map(&data);

	return (1);
}
