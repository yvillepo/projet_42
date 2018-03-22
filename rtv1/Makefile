# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/20 17:00:03 by yvillepo          #+#    #+#              #
#    Updated: 2018/03/20 19:30:11 by yvillepo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1
CC = clang
CFLAGS = -Wall -Wextra
FRAMEWORK = -framework OpenGL -framework AppKit

SRC_PATH = ./src/
SRC_NAME = main.c \
		   init.c \
		   affiche.c \
		   hook.c \
		   raytracer.c \
		   read.c \
		   util.c \
		   plane.c \
		   math.c \
		   line.c \
		   sphere.c \
		   intersection.c \
		   cyl.c \
		   cone.c \
		   vect.c \
		   supr.c \
		   camera.c \
		   light.c \
		   rotate_obj.c \
		   rotate.c

OBJ_PATH = ./obj/
CPPFLAGS = -Iincludes
OBJ_NAME = $(SRC_NAME:.c=.o)

FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft
FT_LNK	= -L ./libft -l ft

MLX = ./minilibx_macos/
MLX_LIB	= $(addprefix $(MLX),libft.a)
MLX_INC = -I ./minilibx_macos
MLX_LNK = -L ./minilibx_macos -l mlx

LNK = $(FT_LNK) $(MLX_LNK)
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ) $(FT_LIB) $(MLX_LIB)
	$(CC) $(FRAMEWORK) $(LNK) $(OBJ) -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(FT_LIB):
	@make -C $(FT)

$(MLX_LIB):
	@make -C $(MLX)

clean:
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@make -C $(FT) clean
	@make -C $(MLX) clean

fclean: clean
	rm -fv $(NAME)
	@make -C $(FT) fclean
	@make -C $(MLX) clean

re: fclean all
