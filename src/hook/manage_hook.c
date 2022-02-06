/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:59:56 by vahemere          #+#    #+#             */
/*   Updated: 2022/02/06 17:41:13 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	pos_player(t_machine *data)
{
	int	y;
	int	x;

	y = -1;
	while (++y < data->map->height)
	{
		x = -1;
		while (++x < data->map->width)
		{
			if (data->map->map[y][x] == PLAYER)
			{
				data->element->pos_x = x;
				data->element->pos_y = y;
				return ;
			}
		}
	}
}

int	check_moove(int pos_y, int pos_x, t_machine *data)
{
	if (data->map->map[pos_y][pos_x] == WALL)
		return (0);
	if (data->map->map[pos_y][pos_x] == DOOR
		&& data->element->nb_collectable != 0)
		return (0);
	else if (data->map->map[pos_y][pos_x] == DOOR
		&& data->element->nb_collectable == 0)
	{
		mlx_loop_end(data->init->mlx);
		printf("YOU WIN WITH %i MOVES\n", data->element->move_count + 1);
		return (1);
	}
	if (data->map->map[pos_y][pos_x] == COLLECTIBLE)
	{
		data->map->map[pos_y][pos_x] = FLOOR;
		data->element->nb_collectable--;
	}
	data->element->move_count++;
	printf("%i\n", data->element->move_count);
	return (1);
}

int	set_texture_player(int keynum)
{
	if (keynum == UP)
		return (POS_BACK);
	if (keynum == DOWN)
		return (POS_FRONT);
	if (keynum == LEFT)
		return (POS_LEFT);
	if (keynum == RIGHT)
		return (POS_RIGHT);
	return (1);
}

int	manage_hook(int keynum, t_machine *data)
{
	if (keynum == ESC)
		mlx_loop_end(data->init->mlx);
	if (keynum == UP)
		if (check_moove(data->element->pos_y - 1, data->element->pos_x, data))
			update_player_less_y(data);
	if (keynum == DOWN)
		if (check_moove(data->element->pos_y + 1, data->element->pos_x, data))
			update_player_more_y(data);
	if (keynum == LEFT)
		if (check_moove(data->element->pos_y, data->element->pos_x - 1, data))
			update_player_less_x(data);
	if (keynum == RIGHT)
		if (check_moove(data->element->pos_y, data->element->pos_x + 1, data))
			update_player_more_x(data);
	pixel_dabbing(data, set_texture_player(keynum));
	return (0);
}
