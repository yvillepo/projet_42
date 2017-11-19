
#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: cpirlot <cpirlot@student.42.fr>            +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2017/07/06 09:32:29 by cpirlot           #+#    #+#             *#
#*   Updated: 2017/10/06 13:42:16 by cpirlot          ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

CC = gcc
FLAGS = -g -Wall -Wextra 
NAME = fillit
LIBFT_DIR = libft
SRC = main.c read_input.c validate.c error.c get_tetri_pos.c utils.c \
	  allo.c insert_tetri.c solve.c
OBJ = $(SRC:.c=.o)
LIBFT = $(LIBFT_DIR)/libft.a

# PROGRESS BAR
T = $(words $(OBJ))
N = 0
C = $(words $N)$(eval N := x $N)
ECHO = "[`expr $C  '*' 100 / $T`%]"

#Colors
_GREY=\x1b[30m
_RED=\x1b[31m
_GREEN=\x1b[32m
_YELLOW=\x1b[33m
_BLUE=\x1b[34m
_PURPLE=\x1b[35m
_CYAN=\x1b[36m
_WHITE=\x1b[37m
_END=\x1b[0m

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@echo "\n$(NAME) compilation : $(_CYAN)done$(_END)"
	@$(CC) -o $(NAME) $(OBJ) -L$(LIBFT_DIR) -lft

%.o: %.c
	@printf "%-60b\r" "$(ECHO) $(_CYAN) Compiling $@ $(_END)"
	@$(CC) $(FLAGS) -c $<

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@$(RM) -f $(OBJ)
	@echo "clean: $(_CYAN)done$(_END)"
	@make fclean -C $(LIBFT_DIR)

fclean: clean
	@$(RM) -f $(NAME)
	@echo "fclean: $(_CYAN)done$(_END)"

re: fclean all

.PHONY: all clean fclean re
