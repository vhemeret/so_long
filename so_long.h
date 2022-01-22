/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:34:39 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/22 05:11:02 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SO_LONG_H
# define SO_LONG_H

# include "minilibx_linux/mlx.h"
# include "src/get_next_line/get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64
# define TEXTURE_WALL "assets/wall.xpm"
# define TEXTURE_COLLECTIBLE "assets/colletible.xpm"
# define TEXTURE_FLOOR "assets/floor.xpm"
# define TEXTURE_DOOR "assets/door.xpm"
# define TEXTURE_PLAYER "assets/player.xpm"

typedef struct	s_data_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
}				t_data_img;

typedef struct s_init
{
	void	*mlx;
	void	*window;
	void	*img;
}				t_init;

typedef struct	s_data_map
{
	char	**map;
	int		width;
	int		height;
}				t_data_map;


/**********************PARSING*************************/
char	**check_error(int ac, char **av);

/*	PARSING UTILS	*/
int		count_line(char *path_to_file);
char	**import_map_to_tab(char *path_to_file);
int		ft_strline(char *str);

/*	PARSING FILE	*/
int		check_fd(char *path_to_file);
int		check_is_symbolic_link(char *path_to_file);
int		check_is_directory(char *path_to_file);
int		check_existing_file(char *path_to_file);
int		check_name_file(char *path_to_file);

/*	PARSING MAP		*/
int		check_map_struct(char **map);
int		check_map_element(char **map);

/**********************CLEANING*************************/
char	**free_map(char **tab, int nb_elem);

#endif