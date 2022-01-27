/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:34:39 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/27 18:55:00 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SO_LONG_H
# define SO_LONG_H

# include "minilibx_linux/mlx.h"
# include "src/get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>

# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64

# define TEXTURE_WALL "assets/wall.xpm"
# define TEXTURE_COLLECTIBLE "assets/collectible.xpm"
# define TEXTURE_FLOOR "assets/floor.xpm"
# define TEXTURE_DOOR "assets/door.xpm"
# define TEXTURE_PLAYER_FRONT "assets/player_front.xpm"
# define TEXTURE_PLAYER_BACK "assets/player_back.xpm"
# define TEXTURE_PLAYER_LEFT "assets/player_left.xpm"
# define TEXTURE_PLAYER_RIGHT "assets/player_right.xpm"

# define WALL '1'
# define FLOOR '0'
# define DOOR 'E'
# define COLLECTIBLE 'C'
# define PLAYER 'P'

# define POS_FRONT 1
# define POS_BACK 2
# define POS_LEFT 3
# define POS_RIGHT 4

typedef enum	e_keynum
{
	ESC = 65307,
	UP = 119,
	DOWN = 115,
	LEFT = 97,
	RIGHT = 100,
}				t_keynum;

typedef struct	s_data_img	// data image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_data_img;

typedef struct	s_data_element // data element map
{
	int		move_count;
	int		nb_collectable;
	int		width;
	int		height;
	int		color;
	int		pos_x;
	int		pos_y;
	void	*player_front;
	void	*player_back;
	void	*player_left;
	void	*player_right;
	void	*wall;
	void	*floor;
	void	*collectable;
	void	*door;
}				t_data_element;


typedef struct s_init // data initialisation mlx
{
	void	*mlx;
	void	*window;
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
	t_data_img		*tmp;
	t_init			*init;
	t_data_element	*element;
}				t_machine;

/**********************PARSING*************************/
int	check_error(int ac, char **av, t_machine *data);

/*	PARSING UTILS	*/
int		count_line(char *path_to_file);
char	**import_map_to_tab(char *path_to_file);
int		ft_strline(char *str, t_machine *data);

/*	PARSING FILE	*/
int		check_fd(char *path_to_file);
int		check_is_symbolic_link(char *path_to_file);
int		check_is_directory(char *path_to_file);
int		check_existing_file(char *path_to_file);
int		check_name_file(char *path_to_file);

/*	PARSING MAP		*/
int		check_map_struct(t_machine *data);
int		check_map_element(t_machine *data);

/**********************STRUCT***************************/
t_machine	*manage_malloc_struct(void);

/**********************CLEANING*************************/
char	**free_map(char **tab, int nb_elem);
void	free_struct(t_machine *data);
int		free_all(char *str, t_machine *data);

/**********************MLX_INIT*************************/
int		init_mlx(t_machine *data);

/*	ASSETS	*/
int		load_assets(t_machine *data);
int		load_player(t_machine *data);

/**********************PIXEL_DABBING*********************/
void	pixel_dabbing(t_machine *data, int poition);

/**********************MANAGE_HOOK***********************/
int		manage_hook(int keynum, t_machine *data);
void	pos_player(t_machine *data);
int		data_hook(t_machine *data);


#endif