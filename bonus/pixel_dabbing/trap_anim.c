/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trap_anim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:57:34 by vahemere          #+#    #+#             */
/*   Updated: 2022/02/03 16:00:56 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	move_up(t_machine *data, int y, int x)
{
	data->map->map[y][x] = FLOOR;
	dabbing_element(data, data->element->floor, x, y);
	data->map->map[y - 1][x] = TRAP;
	dabbing_element(data, data->element->trap, x, y - 1);
}

void	move_down(t_machine *data, int y, int x)
{
	data->map->map[y][x] = FLOOR;
	dabbing_element(data, data->element->floor, x, y);
	data->map->map[y + 1][x] = TRAP;
	dabbing_element(data, data->element->trap, x, y + 1);
}

void	manage_trap(t_machine *data, int y, int x)
{
	if (data->element->frame_trap == 100)
	{
		if ((data->map->map[y + 1][x] == FLOOR
			|| data->map->map[y + 1][x] == PLAYER)
			&& data->element->state_wall == 0)
		{
			down_is_player(data, y, x);
			move_down(data, y, x);
			if (data->map->map[y + 2][x] == WALL)
				data->element->state_wall = 1;
		}
		else if ((data->map->map[y - 1][x] == FLOOR
			|| data->map->map[y - 1][x] == PLAYER)
			&& data->element->state_wall == 1)
		{
			up_is_player(data, y, x);
			move_up(data, y, x);
			if (data->map->map[y - 2][x] == WALL)
				data->element->state_wall = 0;
		}
		else
			data->element->state_wall = 1;
		data->element->frame_trap = 0;
	}
	data->element->frame_trap++;
}

void	move_trap(t_machine *data)
{
	int	y;
	int	x;

	y = -1;
	while (++y < data->map->height)
	{
		x = -1;
		while (++x < data->map->width)
		{
			if (data->map->map[y][x] == 'T')
				manage_trap(data, y, x);
		}
	}
}
