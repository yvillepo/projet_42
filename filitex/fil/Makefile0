# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjuffard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/07 21:24:41 by mjuffard          #+#    #+#              #
#    Updated: 2016/02/08 19:15:01 by mjuffard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./src/
INC_PATH = ./inc/
LIB_PATH = ./lib/
OBJ_PATH = ./obj/

SRC_NAME = ft_check_tetri.c \
		   ft_count_tetri.c
LIB_NAME = -lft
OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
LIB = $(addprefix -L,$(LIB_PATH))

NAME = fillit
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: lib
	@make fillit

$(NAME): $(OBJ)
	$(CC) $(LIB) $(LIB_NAME) $^ -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

lib:
	@make -C ./lib/Libft/
	@cp ./lib/Libft/libft.h ./inc/
	@cp ./lib/Libft/libft.a ./lib/

clean:
	rm -rf $(OBJ) $(OBJ_PATH)
	@make clean -C ./lib/Libft/

fclean: clean
	rm -rf $(NAME)
	@make fclean -C ./lib/Libft/

re: fclean all

.PHONY: re fclean clean lib
