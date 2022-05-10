/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:18:40 by adegadri          #+#    #+#             */
/*   Updated: 2022/05/10 20:26:12 by benmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	exit_opt(t_data *data, char *msg)
{
	if (msg == NULL)
		(void)msg;
	//printf("Error\n%s\n", msg);
	if (data->mlx != NULL)
	{
		if (data->win != NULL)
		{
			free_img(data);
			mlx_destroy_window(data->mlx, data->win);
		}
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit(1);
}

void	add_rgb(long *res, t_color *s_key)
{
	s_key->r = (int)res[0];
	s_key->g = (int)res[1];
	s_key->b = (int)res[2];
	s_key->status = 1;
}

int	take_rgb(t_color *s_key, char *line, t_data *data)
{
	int		i;
	long	res[3];
	char	**tmp;

	i = -1;
	if (s_key->status == 1)
		return (2);
	tmp = ft_split(line, ',');
	if (!tmp)
		exit_opt(data, "Malloc failed");
	while (++i < 3)
	{
		res[i] = ft_atol(tmp[i]);
		if (res[i] < 0 || res[i] > 255 || ft_digit(tmp[i]) == 0)
		{	
			free_tab(tmp);
			return (-1);
		}
	}
	add_rgb(res, s_key);
	//ft_free_tab(tmp);
	//data->total_arg++;
	return (1);
}

int	get_texture(t_data *data, char *path, t_img *img)// obtient les textures et les trier
{
	int	i;

	i = 0;
	(void)data;
	if (img->status == 1)
		return (2);
	while (path[i])
	{
		if (ft_isspace(path[i]))
		{
			path[i] = '\0';
			break ;
		}
		i++;
	}
	img->img = mlx_xpm_file_to_image(data->mlx, path, &img->width, &img->height);
	if (!img->img)// on init les image /textures
		exit_opt(data, "1error texture\n");
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line, &img->endian);
	if (!img->addr)//chop l'adress
		exit_opt(data, "2error texture\n");
	img->status = 1;
	//data->total_arg++;
	return (1);
}

int	get_opt(t_data *data, char *line, int res)
{
	char	**tmp;

	tmp = NULL;
	tmp = ft_split(line, ' ');

	if (!tmp)
		exit_opt(data, "Malloc failed");
	if (!ft_strncmp(tmp[0], "NO", 3))
		res = get_texture(data, tmp[1], &data->north);
	else if (!ft_strncmp(tmp[0], "SO", 3))
		res = get_texture(data, tmp[1], &data->south);
	else if (!ft_strncmp(tmp[0], "WE", 3))
		res = get_texture(data, tmp[1], &data->west);
	else if (!ft_strncmp(tmp[0], "EA", 3))
		res = get_texture(data, tmp[1], &data->east);
	else if (!ft_strncmp(tmp[0], "F", 2))
		res = take_rgb(&data->floor, tmp[1], data);
	else if (!ft_strncmp(tmp[0], "C", 2))
		res = take_rgb(&data->ceiling, tmp[1], data);
	if (res == 2)
	{
		free(line);
		free_tab(tmp);
		exit_opt(data, "Already load");
	}
	free_tab(tmp);
	return (res);
}