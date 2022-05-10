/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:24:53 by adegadri          #+#    #+#             */
/*   Updated: 2022/05/10 20:17:53 by benmoham         ###   ########.fr       */
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
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	return (0);
}

int check_temp(char *s)
{
	int i;

	i = 0;
	while(s[i])
	{
		if (s[i] != ' ' && s[i] != '\t' )
			return(0);
		i++;
	}
	
	return(1);
}

int	get_map(t_data *data, char **av)//obtenir la map
{
	int		res;
	char	*tmp;
	tmp = NULL;
	int status = 0;
	res = 0;
	init_data(data);// j'init ma structure etc
	init_win(data);
	init_img(data);
	data->fd = check_fd(av[1]);//prend le fd en le checkant
	data->line = ft_strdup("");//init line
	if (!data->line)
		return (0);
	int i = 0;
	while (get_next_line(data->fd, &tmp) == 1 && res != -1)// prend la map avec gnl
	{
		if (status == 0 && (check_temp(tmp) == 1))
			free(tmp);
		else if (check_temp(tmp) == 0 || status == 1)
		{
			tmp = ft_strjoinfree(tmp, " \n", 1);//ligne par ligne 
			res = get_opt(data, tmp, 0);// quand c'est pas une option copie pas
			if (res != 1)
			{
				data->line = ft_strjoinfree(data->line, tmp, 1);
				status = 1;
			}
			free(tmp);
		}
		i++;
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
		exit_opt(data, NULL);
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

int	mouse_hook(t_data *data)
{
	if (data->map3)
		free_map3(data);
	if (data->map)
		free_map(data);
	exit_opt(data, "Bye bye \n");
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
		exit_opt(&data, "Error\n map\n");
		return (0);// sinon pas bon tchao
	}
	init_pos_dir(&data);
	mlx_hook(data.win, 17, 1L << 17, mouse_hook, &data);
	mlx_loop_hook(data.mlx, loop_raycast, &data);//pour agir sur la window
	mlx_hook(data.win, 2, 1L << 0, key_press, &data);//quand t'appuie sur une touche
	mlx_hook(data.win, 3, 1L << 1, key_release, &data);
	mlx_do_sync(data.mlx);
	mlx_loop(data.mlx);//la boucle qui maindtiens la window
	free_map(&data);
	return (1);
}