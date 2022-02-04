/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:45:09 by vahemere          #+#    #+#             */
/*   Updated: 2022/02/03 15:55:23 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	update_player_less_x(t_machine *data)
{
	data->map->map[data->element->pos_y][data->element->pos_x] = FLOOR;
	data->element->pos_x--;
	data->map->map[data->element->pos_y][data->element->pos_x] = PLAYER;
}

void	update_player_more_x(t_machine *data)
{
	data->map->map[data->element->pos_y][data->element->pos_x] = FLOOR;
	data->element->pos_x++;
	data->map->map[data->element->pos_y][data->element->pos_x] = PLAYER;
}

void	update_player_less_y(t_machine *data)
{
	data->map->map[data->element->pos_y][data->element->pos_x] = FLOOR;
	data->element->pos_y--;
	data->map->map[data->element->pos_y][data->element->pos_x] = PLAYER;
}

void	update_player_more_y(t_machine *data)
{
	data->map->map[data->element->pos_y][data->element->pos_x] = FLOOR;
	data->element->pos_y++;
	data->map->map[data->element->pos_y][data->element->pos_x] = PLAYER;
}