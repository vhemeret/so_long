/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:48:59 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/17 18:58:16 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_linux/mlx.h"

typedef	struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

#include <stdio.h>
int main(void)
{
	void	*mlx;
	void	*window;
	void	*img;
	t_data	*data_img;
	int		a;
	int		b;
	
	(void)data_img;
	a = 0;
	b = 0;
	mlx = mlx_init();
	window = mlx_new_window(mlx, 1000, 500, "So_long");
	img = mlx_xpm_file_to_image(mlx, "/mnt/nfs/homes/vahemere/Desktop/project/so_long/assets/test.xpm", &a, &b);
	if (!img)
		return (0);
	mlx_put_image_to_window(mlx, window, img, 1, 1);
	mlx_loop(mlx);

	//img->img = mlx_new_image(mlx, img_width, img_heigth);
	//img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	//mlx_new_window(mlx, 1000, 500, "test window mlx");

}