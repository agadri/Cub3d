/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegadri <adegadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:20:47 by adegadri          #+#    #+#             */
/*   Updated: 2022/05/07 19:08:51 by adegadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_all.h"

void	init_pers(t_data *data)
{
	data->pers.pos_x = 0;
	data->pers.pos_y = 0;
	data->pers.dir_pers = '\0';
	data->pers.dir_x_pers = 0;
	data->pers.dire_y_pers = 0;
}
