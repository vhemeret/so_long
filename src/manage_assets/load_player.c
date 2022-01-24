/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:47:11 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/24 17:49:20 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	load_player(t_machine *data)
{
	if (!load_player_front(data) || !load_player_back(data)
		|| !load_player_left(data) || !load_player_right(data))
		return (0);
	return (1);
}