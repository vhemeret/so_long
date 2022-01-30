/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin_anim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 20:12:46 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/30 20:24:14 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	manage_coin(t_machine *data, int x, int y)
{
	static int time = 0;

	if (time == 6)
		time = 1;
	if (time % 6 == 1)
		time = 1;
	dabbing_element(data, data->element->floor, x, y);
	if (time % 6 == 1)
		dabbing_element(data, data->element->coin1, x, y);
	if (time % 6 == 2)
		dabbing_element(data, data->element->coin2, x, y);
	if (time % 6 == 3)
		dabbing_element(data, data->element->coin3, x, y);
	if (time % 6 == 5)
		dabbing_element(data, data->element->coin4, x, y);
	time++;
}

int		animate_dabbing(t_machine *data)
{
	int		x;
	int		y;
	char	*nbr;

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
	nbr = ft_itoa(data->element->move_count);
	mlx_string_put(data->init->mlx, data->init->window, 10, 10, 0xFFFFFF, nbr);
	mlx_put_image_to_window(data->init->mlx, data->init->window,
		data->img->img, 0, 0);
	mlx_string_put(data->init->mlx, data->init->window, 10, 10, 0xFFFFFF, nbr);
	free(nbr);
	return (0);
}
