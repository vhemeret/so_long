/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:59:56 by vahemere          #+#    #+#             */
/*   Updated: 2022/02/03 15:57:14 by vahemere         ###   ########.fr       */
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
		while (++x < data->map->height)
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

void	pos_door(t_machine *data)
{
	int	y;
	int	x;

	y = -1;
	while (++y < data->map->height)
	{
		x = -1;
		while (++x < data->map->height)
		{
			if (data->map->map[y][x] == DOOR)
			{
				data->element->d_x = x;
				data->element->d_y = y;
				return ;
			}
		}
	}
}

int	check_moove(int pos_y, int pos_x, t_machine *data)
{
	if (data->map->map[pos_y][pos_x] == TRAP)
	{
		mlx_loop_end(data->init->mlx);
		printf("GAME OVER\n");
		return (0);
	}
	if (!manage_move(pos_y, pos_x, data))
		return (0);
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
	pos_door(data);
	if (keynum == ESC)
		mlx_loop_end(data->init->mlx);
	if (keynum == UP)
		if (check_moove(data->element->pos_y - 1, data->element->pos_x, data))
			update_player_less_y(data);
	if (keynum == DOWN)
		if (check_moove(data->element->pos_y + 1, data->element->pos_x, data))
			update_player_more_y(data);
	if (keynum == LEFT)
	{
		if (check_moove(data->element->pos_y, data->element->pos_x - 1, data))
			update_player_less_x(data);
	}
	if (keynum == RIGHT)
		if (check_moove(data->element->pos_y, data->element->pos_x + 1, data))
			update_player_more_x(data);
	pixel_dabbing(data, set_texture_player(keynum));
	return (0);
}
