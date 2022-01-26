/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:30:22 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/26 01:46:16 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	check_error(int ac, char **av, t_machine *data)
{
	char	**map;

	if (ac != 2)
	{
		printf("/!\\The numbers of arguments are invalid./!\\\n");
		return ;
	}
	if (!check_fd(av[1]))
		return ;
	map = import_map_to_tab(av[1]);
	data->map->height = count_line(av[1]);
	if (!check_map_struct(map, data) || !check_map_element(map, data))
		return ;
	data->map->map = map;
}
