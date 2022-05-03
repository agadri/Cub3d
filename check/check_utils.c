/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelgadri <adelgadri@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:16:24 by adegadri          #+#    #+#             */
/*   Updated: 2022/04/28 14:34:19 by adelgadri        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

int	nothing_in_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		//printf(".%d.", str[i]);
		if (str[i] != '3')
			return (1);
		i++;
	}
	//printf("\n");
	return (0);
}
