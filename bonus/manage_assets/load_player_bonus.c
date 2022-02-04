/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:47:11 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/28 16:06:29 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	load_player_front(t_machine *data)
{
	data->element->player_front = mlx_xpm_file_to_image(data->init->mlx,
			TEXTURE_PLAYER_FRONT, &data->element->width,
			&data->element->height);
	if (!data->element->player_front)
		return (0);
	return (1);
}

int	load_player_back(t_machine *data)
{
	data->element->player_back = mlx_xpm_file_to_image(data->init->mlx,
			TEXTURE_PLAYER_BACK, &data->element->width,
			&data->element->height);
	if (!data->element->player_back)
		return (0);
	return (1);
}

int	load_player_left(t_machine *data)
{
	data->element->player_left = mlx_xpm_file_to_image(data->init->mlx,
			TEXTURE_PLAYER_LEFT, &data->element->width,
			&data->element->height);
	if (!data->element->player_left)
		return (0);
	return (1);
}

int	load_player_right(t_machine *data)
{
	data->element->player_right = mlx_xpm_file_to_image(data->init->mlx,
			TEXTURE_PLAYER_RIGHT, &data->element->width,
			&data->element->height);
	if (!data->element->player_right)
		return (0);
	return (1);
}

int	load_player(t_machine *data)
{
	if (!load_player_front(data) || !load_player_back(data)
		|| !load_player_left(data) || !load_player_right(data))
		return (0);
	return (1);
}
