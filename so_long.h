/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:34:39 by vahemere          #+#    #+#             */
/*   Updated: 2022/02/04 22:07:22 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SO_LONG_H
# define SO_LONG_H

# include "minilibx_linux/mlx.h"
# include "src/get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <time.h>

# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64

/*	PATH TEXTURE MANDATORY PART */
# define TEXTURE_WALL "assets/wall.xpm"
# define TEXTURE_COLLECTIBLE "assets/collectible.xpm"
# define TEXTURE_FLOOR "assets/floor.xpm"
# define TEXTURE_DOOR "assets/door.xpm"
# define TEXTURE_PLAYER_FRONT "assets/player_front.xpm"
# define TEXTURE_PLAYER_BACK "assets/player_back.xpm"
# define TEXTURE_PLAYER_LEFT "assets/player_left.xpm"
# define TEXTURE_PLAYER_RIGHT "assets/player_right.xpm"

/*	PATH TEXTURE BONUS PART */
# define TEXTURE_COIN1	"assets/bonus/coin1.xpm"
# define TEXTURE_COIN2	"assets/bonus/coin2.xpm"
# define TEXTURE_COIN3	"assets/bonus/coin3.xpm"
# define TEXTURE_COIN4	"assets/bonus/coin4.xpm"
# define TEXTURE_TRAP	"assets/bonus/trap.xpm"
# define TEXTURE_TRAP_ACTIVE "assets/bonus/trap_active.xpm"
# define TEXTURE_DOOR_OPEN "assets/bonus/door_open.xpm"
# define TEXTURE_UFO "assets/bonus/ufo.xpm"

# define WALL '1'
# define FLOOR '0'
# define DOOR 'E'
# define COLLECTIBLE 'C'
# define PLAYER 'P'
/*	BONUS */
# define TRAP 'T'
# define UFO 'U'
# define DOOR_OPEN 'O'

# define POS_FRONT 1
# define POS_BACK 2
# define POS_LEFT 3
# define POS_RIGHT 4

# define SPEED 150

typedef enum	e_keynum
{
	ESC = 65307,
	UP = 119,
	DOWN = 115,
	LEFT = 97,
	RIGHT = 100,
}				t_keynum;


/**********************STRUCT*************************/

/*	DATA IMG */
typedef struct	s_data_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_data_img;

/*	DATA ELEMENT MAP */
typedef struct	s_data_element
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
	/* BONUS */
	void	*coin1; 
	void	*coin2;
	void	*coin3;
	void	*coin4;
	void	*door_open;
	void	*trap;
	int		frame;
	int		frame_trap;
	int		state_wall;
	int		d_x;
	int		d_y;

}				t_data_element;

/*	DATA SETTING MLX*/
typedef struct s_init
{
	void	*mlx;
	void	*window;
	int		texture_succes;
}				t_init;

/*	DATA MAP */
typedef struct	s_data_map
{
	char	**map;
	int		width;
	int		height;
}				t_data_map;


/*	MACHINE	*/
typedef struct s_data_machine
{
	t_data_map		*map;
	t_data_img		*img;
	t_data_img		*tmp;
	t_init			*init;
	t_data_element	*element;
}				t_machine;

/******************************************************/

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
int		destroy_notify(t_machine *data);

/**********************MLX_INIT*************************/
int		init_mlx(t_machine *data);

/*	ASSETS	*/
int		load_assets(t_machine *data);
int		load_player(t_machine *data);

/**********************PIXEL_DABBING*********************/
int		pixel_dabbing(t_machine *data, int poition);
void	dabbing_element(t_machine *data, void *img, int x, int y);

/**********************MANAGE_HOOK***********************/
int		manage_hook(int keynum, t_machine *data);
void	pos_player(t_machine *data);
int		data_hook(t_machine *data);


/**********************BONUS_PART************************/
int		first_dabbing(t_machine *data);
void	manage_coin(t_machine *data, int x, int y);
int		animate_dabbing(t_machine *data);
char	*ft_itoa(int n);
int		load_coin(t_machine *data);
int		manage_move(int pos_y, int pos_x, t_machine *data);
void	move_trap(t_machine *data);
void	up_is_player(t_machine *data, int y, int x);
void	down_is_player(t_machine *data, int y, int x);
void	update_player_less_x(t_machine *data);
void	update_player_more_x(t_machine *data);
void	update_player_more_y(t_machine *data);
void	update_player_less_y(t_machine *data);
int		load_door_open(t_machine *data);

#endif