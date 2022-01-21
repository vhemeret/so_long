/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_element.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 22:56:01 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/21 23:09:02 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	check_collectible(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C')
				return (1);
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

int	check_map_element(char **map)
{
	if (!check_collectible(map))
	{
		printf("/!\\ Nombre de collectible invalide.\n");
		return (0);
	}
	if (!check_door(map))
	{
		printf("/!\\ Nombre de sortie invalide.\n");
		return (0);
	}
	if (!check_player(map))
	{
		printf("/!\\ Nombre de joueur invalide.\n");
		return (0);
	}
	return (1);
}