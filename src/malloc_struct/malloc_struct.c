/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:00:36 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/26 18:31:01 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	malloc_map_and_element(t_machine *data)
{
	data->map = malloc(sizeof(t_data_map));
	if (!data->map)
	{
		free(data->init);
		free(data);
		return (0);
	}
	data->element = malloc(sizeof(t_data_element));
	if (!data->element)
	{
		free(data->map);
		free(data->init);
		free(data);
		return (0);
	}
	return (1);
}

int	malloc_img_and_tmp(t_machine *data)
{
	data->img = malloc(sizeof(t_data_img));
	if (!data->img)
	{
		free(data->element);
		free(data->map);
		free(data->init);
		free(data);
		return (0);
	}
	data->tmp = malloc(sizeof(t_data_img));
	if (!data->tmp)
	{
		free(data->img);
		free(data->element);
		free(data->map);
		free(data->init);
		free(data);
		return (0);
	}
	return (1);
}

t_machine	*manage_malloc_struct(void)
{
	t_machine	*data;
	
	data = malloc(sizeof(t_machine));
	if (!data)
		return (NULL);
	data->init = malloc(sizeof(t_init));
	if (!data->init)
	{
		free(data);
		return (NULL);
	}
	if (!malloc_map_and_element(data))
		return (NULL);
	if (!malloc_img_and_tmp(data))
		return (NULL);
	return (data);
}
