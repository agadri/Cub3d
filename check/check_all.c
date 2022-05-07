/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegadri <adegadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:17:35 by adegadri          #+#    #+#             */
/*   Updated: 2022/05/07 19:30:41 by adegadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

int	check_all(int ac, char **av, t_data *data)
{
	if (ac != 2)
		return (0);
	else if (!get_map(data, av))
	{
		//wrong map;
		printf("%s\n","Error \n when get map\n");
		return (0);
	}
	if (data->width < 3 || data->lenght < 3)
	{
		//map trop petite free tt et close fd
		printf("%s\n", "Error \n map to small\n");
		return (0);
	}
	change_space_to_3(data);
	if (!check_letter(data) || !check_if_is_close(data) || \
	!check_duplicate_position(data))
		return (0);
	return (1);
}
