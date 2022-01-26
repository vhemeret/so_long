/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 01:53:02 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/26 19:35:00 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	unexpected_char(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j])
		{
			if (map[i][j] == '1' || map[i][j] == 'P'
				|| map[i][j] == '0' || map[i][j] == 'C'
				|| map[i][j] == 'E')
				j++;
			else
				return (0);
		}
	}
	return (1);
}

int	map_is_rectangle(char **map, t_machine *data)
{
	int	i;
	int	len;

	len = ft_strline(map[0], data);
	i = 0;
	while (map[++i])
	{
		if (ft_strline(map[i], data) != len)
			return (0);
	}
	return (1);
}

int	check_map_border(char **map, t_machine *data)
{
	int	line;
	int	i;
	int	j;

	line = 0;
	i = -1;
	while (map[++i])
		line++;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j] != '\n' && map[i][j])
		{
			if (map[0][j] != '1')
				return (0);
			else if ((i != 0 && i != (data->map->width - 1))
				&& (map[i][0] != '1' || map[i][data->map->width - 1] != '1'))
				return (0);
			else if (map[line - 1][j] != '1')
				return (0);
		}
	}
	return (1);
}

int	check_map_struct(t_machine *data)
{
	if (!unexpected_char(data->map->map))
	{
		free_map(data->map->map, data->map->height);
		printf("/!\\ Invalid character in map. /!\\\n");
		return (0);
	}
	if (!map_is_rectangle(data->map->map, data))
	{
		free_map(data->map->map, data->map->height);
		printf("/!\\ The map is not rectangle. /!\\\n");
		return (0);
	}
	if (!check_map_border(data->map->map, data))
	{
		free_map(data->map->map, data->map->height);
		printf("/!\\ Map borders are invalid. /!\\\n");
		return (0);
	}
	return (1);
}
