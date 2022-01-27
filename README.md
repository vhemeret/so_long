compilation temporaire :

gcc -Wall -Wextra -Werror src/so_long.c src/cleaning/*.c src/get_next_line/*.c src/hook/src*.c src/malloc_struct/*.c src/manage_assets/*.c src/parsing/*.c  minilibx_linux/libmlx_Linux.a -lXext -lX11 -I ./minilibx_linux/


