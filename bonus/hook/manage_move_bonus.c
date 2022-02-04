/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 20:50:15 by vahemere          #+#    #+#             */
/*   Updated: 2022/02/01 11:58:33 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	manage_move(int pos_y, int pos_x, t_machine *data)
{
	if (data->map->map[pos_y][pos_x] == WALL)
		return (0);
	if (data->map->map[pos_y][pos_x] == DOOR
		&& data->element->nb_collectable != 0)
		return (0);
	if (data->element->nb_collectable == 0)
		data->map->map[data->element->d_y][data->element->d_x] = DOOR_OPEN;
	if (data->map->map[pos_y][pos_x] == COLLECTIBLE)
	{
		data->map->map[pos_y][pos_x] = FLOOR;
		data->element->nb_collectable--;
	}
	if ((data->map->map[pos_y][pos_x] == DOOR_OPEN
		|| data->map->map[pos_y][pos_x] == DOOR)
		&& data->element->nb_collectable == 0)
	{
		mlx_loop_end(data->init->mlx);
		printf("YOU WIN WITH %i MOVES\n", data->element->move_count + 1);
		return (1);
	}
	data->element->move_count++;
	return (1);
}
