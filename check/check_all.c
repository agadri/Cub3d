/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegadri <adegadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:17:35 by adegadri          #+#    #+#             */
/*   Updated: 2022/05/04 17:32:27 by adegadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

int	check_all(int ac, char **av, t_data *data)
{
	if (ac != 2)
		return (0);
	data->map = NULL;
	data->map3 = NULL;
	if (!get_map(data, av))
	{
		//wrong map;
		return (0);
	}
	data->width = size_width(data);
	data->lenght = size_lenght(data);
	if (data->width < 3 || data->lenght < 3)
	{
		//map trop petite free tt et close fd 
		return (0);
	}
	change_space_to_3(data);
	if (!check_if_is_close(data))
	{
		printf("Map not close\n");
		return (0);
	}
	return (1);
}