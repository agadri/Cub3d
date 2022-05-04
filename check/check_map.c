/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegadri <adegadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:50:37 by adegadri          #+#    #+#             */
/*   Updated: 2022/05/04 12:50:42 by adegadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

int	check_letter(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] != '0' && str[i] != '1' && \
		str[i] != 'N' && str[i] != 'S' && \
		str[i] != 'E' && str[i] != 'W')
		{
			printf("%s\n", "Error \n use of wrong character");
			return (0);
		}
		i++;
	}
	return (1);
}