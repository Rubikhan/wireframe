#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smaddux <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/17 23:18:19 by smaddux           #+#    #+#              #
#    Updated: 2017/12/18 00:10:57 by smaddux          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME   	= fdf
OBJ    	= $(SRC:.c=.o)
WOPS   	= -Wall -Wextra -Werror
MLXOPS  = -framework OpenGL -framework AppKit

SRCDIR 	= $(addprefix sources/, $(SRC))
SRC    	= main.c listen.c drawline.c readmap.c
MLXDIR = $(addprefix minilibx/, $(MLXOBJS))
MLXOBJS = mlx_init_loop.o mlx_int_str_to_wordtab.o mlx_new_image.o mlx_new_window.o \
			mlx_shaders.o mlx_xpm.o


all: 	$(NAME) 

$(NAME): $(OBJ)
				$(MAKE) -C ./libft/ 
				$(MAKE) -C ./minilibx 
				gcc $(OBJ) -L libft -lft -L minilibx -lmlx $(MLXOPS) -o $(NAME)

$(OBJ): $(SRCDIR)
				gcc $(WOPS) -c $(SRCDIR) -I fdf.h 

clean:
				make -C ./libft/ clean
				/bin/rm -f $(OBJ)
				/bin/rm -f $(MLXDIR)

fclean: clean 
				make -C ./libft/ fclean
				/bin/rm -f $(NAME)
				make -C ./minilibx/ clean

re: 			fclean all

.PHONY: all clean fclean re

