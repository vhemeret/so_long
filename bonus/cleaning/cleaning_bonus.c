/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 20:47:21 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/31 19:57:58 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	free_bonus_img(t_machine *data)
{
	if (data->element->coin1)
		mlx_destroy_image(data->init->mlx, data->element->coin1);
	if (data->element->coin2)
		mlx_destroy_image(data->init->mlx, data->element->coin2);
	if (data->element->coin3)
		mlx_destroy_image(data->init->mlx, data->element->coin3);
	if (data->element->coin4)
		mlx_destroy_image(data->init->mlx, data->element->coin4);
	if (data->element->door_open)
		mlx_destroy_image(data->init->mlx, data->element->door_open);
	if (data->element->trap)
		mlx_destroy_image(data->init->mlx, data->element->trap);
}
