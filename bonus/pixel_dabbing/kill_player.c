/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:39:56 by vahemere          #+#    #+#             */
/*   Updated: 2022/02/03 14:43:14 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	up_is_player(t_machine *data, int y, int x)
{
	if (data->map->map[y - 1][x] == PLAYER)
	{
		data->map->map[y][x] = FLOOR;
		data->map->map[y - 1][x] = TRAP;
		printf("GAME OVER\n");
		mlx_loop_end(data->init->mlx);
	}
}

void	down_is_player(t_machine *data, int y, int x)
{
	if (data->map->map[y + 1][x] == PLAYER)
	{
		data->map->map[y][x] = FLOOR;
		data->map->map[y + 1][x] = TRAP;
		printf("GAME OVER\n");
		mlx_loop_end(data->init->mlx);
	}
}
