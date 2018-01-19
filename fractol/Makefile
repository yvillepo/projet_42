# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/22 23:12:10 by pbondoer          #+#    #+#              #
#    Updated: 2018/01/19 06:08:19 by yvillepo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

# src / obj files

SRC = main.c \
	  affiche.c \
	  init.c \
	  mandelbrot.c \
	  hook.c \
	  zomm.c \
	  util.c \
	  color.c \
	  translation.c

OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

# compiler
CC		= gcc
CFLAGS	= -Wall -Wextra #-Werror 

# mlx library
FRAMEWORK	=  -framework OpenGL -framework AppKit

# ft library
FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft
FT_LNK	= -L ./libft -l ft

MLX = ./minilibx_macos/
MLX_LIB	= $(addprefix $(MLX),libft.a)
MLX_INC = -I ./minilibx_macos
MLX_LNK = -L ./minilibx_macos -l mlx
# directories
SRCDIR	= ./src/
INCDIR	= ./includes/
OBJDIR	= ./obj/

all: obj $(FT_LIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	@make -C $(FT)

$(MLX_LIB):
	@make -C $(MLX)

$(NAME): $(OBJ) $(FT_LIB) $(MLX_LIB)
	$(CC) $(OBJ) $(FRAMEWORK) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME)

clean:
	@rm -rf $(OBJDIR)
	@make -C $(FT) clean
	@make -C $(MLX) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(FT) fclean
	@make -C $(MLX) clean

re: fclean all
