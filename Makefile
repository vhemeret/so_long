# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/29 12:09:39 by vahemere          #+#    #+#              #
#    Updated: 2022/01/29 17:02:44 by vahemere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ_DIR = obj
SRC_DIR = $(shell find src -type d)

vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)
SRC = so_long.c \
pixel_dabbing.c \
check_fd.c check_map_element.c check_map_struct.c check.c utils.c \
load_assets.c load_player.c \
malloc_struct.c \
manage_hook.c \
cleaning.c \
get_next_line.c \
get_next_line_utils.c \

OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

#OBJ_BONUS_DIR = obj_bonus
#SRC_BONUS_DIR = $(shell find bonus -type d)

#vpath %.c $(foreach dir, $(SRC_BONUS_DIR), $(dir):)
#
#
#
#
#

#OBJS_BONUS = $(addprefix $(OBJ_BONUS_DIR)/, $(SRC_BONUS_DIR:%.c=%.o))

NAME	= so_long
NORM = cd src && norminette

LIB_DIR = minilibx_linux
LIB_NAME = $(LIB_DIR)/libmlx_Linux.a

########################### COMPILATION AND FLAGS ###########################

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB_FLAGS = -lXext -lX11 -lm

##################################### COLOR ##################################

COLOUR_PURPLE = \033[0;35m
COLOUR_END = \033[0m

##################################### MAIN ###################################

all: $(NAME)

$(NAME): $(OBJS)
		cd $(LIB_DIR) && ./configure
		$(CC) $(CFLAGS) $(OBJS) $(LIB_NAME) $(LIB_FLAGS) -I $(LIB_DIR) -o $(NAME)
		@echo "\n\t$(COLOUR_PURPLE)***EXECUTABLE CREATED SUCCESSFULL***\n\n$(COLOUR_END)"

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
		$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_DIR):
	mkdir -p $@
	@echo "\n\t$(COLOUR_PURPLE)OBJECT DIRECTORY CREATED\n\n$(COLOUR_END)"

clean:
	rm -rf $(OBJS) $(OBJ_DIR)
	@echo "\n\t$(COLOUR_PURPLE)OBJECT DIRECTORY CREATED\n\n$(COLOUR_END)"

fclean: clean
	rm -rf $(NAME)
	cd $(LIB_DIR) && make clean
	@echo "\n\t$(COLOUR_PURPLE)DELETE EXECUTABLE SUCCESSFULL\n\n$(COLOUR_END)"

norm:
	@echo "$(COLOUR_PURPLE)***CHECK NORM FILES***$(COLOUR_END)"
	@$(NORM)
	

re: fclean all

.PHONY: all clean fclean norm re