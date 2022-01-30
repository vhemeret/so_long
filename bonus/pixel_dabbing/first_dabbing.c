/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_dabbing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 15:45:47 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/30 20:25:23 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	first_dabbing(t_machine *data)
{
	int	x;
	int	y;
	char *nbr;

	y = -1;
	while (++y < data->map->height)
	{
		x = -1;
		while (++x < data->map->width)
		{
			dabbing_element(data, data->element->floor, x, y);
			if (data->map->map[y][x] == '1')
				dabbing_element(data, data->element->wall, x, y);
			if (data->map->map[y][x] == 'E')
				dabbing_element(data, data->element->door, x, y);
			if (data->map->map[y][x] == 'T')
				dabbing_element(data, data->element->trap, x, y);
		}
	}
	dabbing_element(data, data->element->player_front,
		data->element->pos_x, data->element->pos_y);
	nbr = ft_itoa(data->element->move_count);
	mlx_string_put(data->init->mlx, data->init->window, 10, 25, 0xFFFFFF, nbr);
	free(nbr);
	mlx_put_image_to_window(data->init->mlx, data->init->window,
		data->img->img, 0, 0);
	return (0);
}