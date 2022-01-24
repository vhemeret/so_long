/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:34:39 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/24 18:03:16 by vahemere         ###   ########.fr       */
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
# define TEXTURE_PLAYER_FRONT "assets/player_front.xpm"
# define TEXTURE_PLAYER_BACK "assets/player_back.xpm"
# define TEXTURE_PLAYER_LEFT "assets/player_left.xpm"
# define TEXTURE_PLAYER_RIGHT "assets/player_right.xpm"

typedef struct	s_data_img	// data image
{
	//void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_data_img;

typedef struct	s_data_element // data element map
{
	int		move_count;
	int		width;
	int		height;
	void	*player;
	void	*wall;
	void	*floor;
	void	*collectable;
	void	*door;
}				t_data_element;


typedef struct s_init // data initialisation mlx
{
	void	*mlx;
	void	*window;
	void	*img;
}				t_init;

typedef struct	s_data_map // data map
{
	char	**map;
	int		width;
	int		height;
}				t_data_map;

typedef struct s_data_machine // machine
{
	t_data_map		*map;
	t_data_img		*img;
	t_init			*init;
	t_data_element	*element;
}				t_machine;

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

/**********************MLX_INIT*************************/
int		init_mlx(t_machine *data);

/*	ASSETS	*/
int		load_assets(t_machine *data);


#endif