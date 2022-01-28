/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:30:22 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/28 15:57:20 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	check_error(int ac, char **av, t_machine *data)
{
	if (ac != 2)
	{
		printf("Error\n/!\\ The numbers of arguments are invalid. /!\\\n");
		return (0);
	}
	if (!check_fd(av[1]))
		return (0);
	data->map->map = import_map_to_tab(av[1]);
	data->map->height = count_line(av[1]);
	if (!check_map_struct(data) || !check_map_element(data))
		return (0);
	return (1);
}
