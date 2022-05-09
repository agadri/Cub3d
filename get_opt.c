/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegadri <adegadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:18:40 by adegadri          #+#    #+#             */
/*   Updated: 2022/05/09 15:43:55 by adegadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	exit_opt(t_data *data, char *msg)
{
	printf("Error\n%s\n", msg);
	if (data->line != NULL)
	{
		free(data->line);
		data->line = NULL;
	}
	if (data->mlx)
	{
		printf("wwwwwwwwwww\n");
		free_img(data);
		free_data(data);
		mlx_destroy_display(data->mlx);
		//free(data->mlx);
	}
	if (data->map)
		return ;
		//ft_free_tab(data->map);
	//free_map(data);
	//free_map3(data);
	exit(1);
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
	//else if (!ft_strncmp(tmp[0], "F", 2))
		//res = take_rgb(&data->floor, tmp[1], data);
	if (res == 2)
	{
		free(line);
		free_tab(tmp);
		exit_opt(data, "Already load");
	}
	free_tab(tmp);
	return (res);
}
