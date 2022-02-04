/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_coin_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 20:39:18 by vahemere          #+#    #+#             */
/*   Updated: 2022/02/04 21:52:06 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	load_coin1(t_machine *data)
{
	data->element->coin1 = mlx_xpm_file_to_image(data->init->mlx,
			TEXTURE_COIN1, &data->element->width, &data->element->height);
	if (!data->element->coin1)
	{
		mlx_destroy_image(data->init->mlx, data->img->img);
		mlx_destroy_image(data->init->mlx, data->element->player_front);
		mlx_destroy_image(data->init->mlx, data->element->player_back);
		mlx_destroy_image(data->init->mlx, data->element->player_left);
		mlx_destroy_image(data->init->mlx, data->element->player_right);
		return (0);
	}
	return (1);
}

int	load_coin2(t_machine *data)
{
	data->element->coin2 = mlx_xpm_file_to_image(data->init->mlx,
			TEXTURE_COIN2, &data->element->width, &data->element->height);
	if (!data->element->coin2)
	{
		mlx_destroy_image(data->init->mlx, data->img->img);
		mlx_destroy_image(data->init->mlx, data->element->player_front);
		mlx_destroy_image(data->init->mlx, data->element->player_back);
		mlx_destroy_image(data->init->mlx, data->element->player_left);
		mlx_destroy_image(data->init->mlx, data->element->player_right);
		mlx_destroy_image(data->init->mlx, data->element->coin1);
		return (0);
	}
	return (1);
}

int	load_coin3(t_machine *data)
{
	data->element->coin3 = mlx_xpm_file_to_image(data->init->mlx,
			TEXTURE_COIN3, &data->element->width, &data->element->height);
	if (!data->element->coin3)
	{
		mlx_destroy_image(data->init->mlx, data->img->img);
		mlx_destroy_image(data->init->mlx, data->element->player_front);
		mlx_destroy_image(data->init->mlx, data->element->player_back);
		mlx_destroy_image(data->init->mlx, data->element->player_left);
		mlx_destroy_image(data->init->mlx, data->element->player_right);
		mlx_destroy_image(data->init->mlx, data->element->coin1);
		mlx_destroy_image(data->init->mlx, data->element->coin2);
		return (0);
	}
	return (1);
}

int	load_coin4(t_machine *data)
{
	data->element->coin4 = mlx_xpm_file_to_image(data->init->mlx,
			TEXTURE_COIN4, &data->element->width, &data->element->height);
	if (!data->element->coin4)
	{
		mlx_destroy_image(data->init->mlx, data->img->img);
		mlx_destroy_image(data->init->mlx, data->element->player_front);
		mlx_destroy_image(data->init->mlx, data->element->player_back);
		mlx_destroy_image(data->init->mlx, data->element->player_left);
		mlx_destroy_image(data->init->mlx, data->element->player_right);
		mlx_destroy_image(data->init->mlx, data->element->coin1);
		mlx_destroy_image(data->init->mlx, data->element->coin2);
		mlx_destroy_image(data->init->mlx, data->element->coin3);
		return (0);
	}
	return (1);
}

int	load_coin(t_machine *data)
{
	if (!load_coin1(data) || !load_coin2(data) || !load_coin3(data)
		|| !load_coin4(data))
		return (0);
	return (1);
}
