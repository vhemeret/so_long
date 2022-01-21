/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:30:22 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/21 22:55:44 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char	**check_error(int ac, char **av)
{
	char	**map;

	if (ac != 2 || !check_fd(av[1]))
		return (NULL);
	map = import_map_to_tab(av[1]);
	if (!check_map_struct(map) || !check_map_element(map))
		return (NULL);
	return (map);
}
