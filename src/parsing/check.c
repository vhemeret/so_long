/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:30:22 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/24 17:20:08 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char	**check_error(int ac, char **av)
{
	char	**map;
	t_machine *data;

	if (ac != 2)
	{
		printf("/!\\The numbers of arguments are invalid./!\\\n");
		return (NULL);
	}
	if (!check_fd(av[1]))
		return (NULL);
	map = import_map_to_tab(av[1]);
	data->map->width = ft_strline(av[1]);
	data->map->height = count_line(av[1]);
	if (!check_map_struct(map) || !check_map_element(map))
		return (NULL);
	return (map);
}
