/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:33:38 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/24 17:50:49 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	load_assets(t_machine *data)
{
	if (!load_player(data) || !load_floor(data)
		|| !load_wall(data) || !load_collectable(data))
	{
		printf("/!\\ Error when trying to import xpm to img /!\\\n");
		return (0);
	}
	return (1);
}