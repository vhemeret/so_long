/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:48:59 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/17 11:58:52 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include </mnt/nfs/homes/vahemere/Desktop/project/so_long/mlx/mlx.h>

int main(void)
{
	void	*mlx;

	mlx = mlx_init();
	mlx_new_window(mlx, 1000, 500, "test window mlx");
	mlx_loop(mlx);
}