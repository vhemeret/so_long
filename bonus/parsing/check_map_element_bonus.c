/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_element.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 22:56:01 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/28 16:10:09 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	count_collectible(char **map, t_machine *data)
{
	int	i;
	int	j;

	data->element->nb_collectable = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C')
			{
				data->element->nb_collectable++;
			}
		}
	}
}

int	check_collectible(char **map, t_machine *data)
{
	int	i;
	int	j;

	i = -1;
	data->element->nb_collectable = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C')
			{
				count_collectible(map, data);
				return (1);
			}
		}
	}
	return (0);
}

int	check_door(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'E')
				return (1);
		}
	}
	return (0);
}

int	check_player(char **map)
{
	int	i;
	int	j;
	int	player;

	player = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
				player += 1;
		}
	}
	if (player > 1 || player == 0)
		return (0);
	return (1);
}

int	check_map_element(t_machine *data)
{
	if (!check_collectible(data->map->map, data))
	{
		free_map(data->map->map, data->map->height);
		printf("Error\n/!\\ The number of collectible is invalid. /!\\\n");
		return (0);
	}
	if (!check_door(data->map->map))
	{
		free_map(data->map->map, data->map->height);
		printf("Error\n/!\\ The number of exit is invalid. /!\\\n");
		return (0);
	}
	if (!check_player(data->map->map))
	{
		free_map(data->map->map, data->map->height);
		printf("Error\n/!\\ The number of player is invalid. /!\\\n");
		return (0);
	}
	return (1);
}
