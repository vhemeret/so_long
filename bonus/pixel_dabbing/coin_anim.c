/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin_anim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 20:12:46 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/31 19:55:15 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	manage_coin(t_machine *data, int x, int y)
{
	if (data->element->frame == 50)
		dabbing_element(data, data->element->floor, x, y);
	if (data->element->frame == 50)
		dabbing_element(data, data->element->coin1, x, y);
	if (data->element->frame == 100)
		dabbing_element(data, data->element->coin2, x, y);
	if (data->element->frame == 150)
		dabbing_element(data, data->element->coin3, x, y);
	if (data->element->frame == 200)
	{
		dabbing_element(data, data->element->coin4, x, y);
		data->element->frame = 0;
	}
}

void	get_coin(t_machine *data)
{
	int	y;
	int	x;

	data->element->frame++;
	y = -1;
	while (++y < data->map->height)
	{
		x = -1;
		while (++x < data->map->width)
		{
			if (data->map->map[y][x] == 'C')
				manage_coin(data, x, y);
		}
	}
}

int	animate_dabbing(t_machine *data)
{
	char	*nbr;

	get_coin(data);
	nbr = ft_itoa(data->element->move_count);
	mlx_string_put(data->init->mlx, data->init->window, 10, 10, 0xFFFFFF, nbr);
	mlx_put_image_to_window(data->init->mlx, data->init->window,
		data->img->img, 0, 0);
	mlx_string_put(data->init->mlx, data->init->window, 10, 10, 0xFFFFFF, nbr);
	free(nbr);
	return (0);
}
