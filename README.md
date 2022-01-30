precompil bonus :

gcc -Wall -Wextra -Werror -g3 -fsanitize=address bonus/*.c bonus/parsing/*.c bonus/get_next_line/*.c bonus/cleaning/*.c bonus/manage_assets/*.c bonus/pixel_dabbing/*.c bonus/malloc_struct/*.c bonus/hook/*.c minilibx_linux/libmlx_Linux.a -lXext -lX11 -I ./minilibx_linux/