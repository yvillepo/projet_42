# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile libft                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmartzol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/30 23:15:42 by hmartzol          #+#    #+#              #
#    Updated: 2016/02/10 04:36:27 by hmartzol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libft.a

SRCDIR =	src
OBJDIR =	OBJ
INCDIR =	includes

ITEMS =		ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove ft_memchr \
			ft_memcmp ft_strlen ft_strdup ft_strcpy ft_strncpy ft_strcat \
			ft_strncat ft_strlcat ft_strchr ft_strrchr ft_strstr ft_strnstr \
			ft_strcmp ft_strncmp ft_atoi ft_isalpha ft_isdigit ft_isalnum \
			ft_isascii ft_isprint ft_toupper ft_tolower ft_memalloc ft_memdel \
			ft_strnew ft_strdel ft_strclr ft_striter ft_striteri ft_strmap \
			ft_strmapi ft_strequ ft_strnequ ft_strsub ft_strjoin ft_strtrim \
			ft_strsplit ft_itoa ft_putchar ft_putstr ft_putendl ft_putnbr \
			ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_lstnew \
			ft_lstdelone ft_lstdel ft_lstadd ft_lstiter ft_lstmap ft_puttab \
			ft_puttab_fd ft_putlist ft_putlist_fd ft_lstappend ft_isspace \
			ft_strcntc ft_readfile ft_ptinit ft_ptnew

OBJ =		$(patsubst %, $(OBJDIR)/%.o, $(ITEMS))

CC =		gcc
FLAGS =		-Wall -Wextra -Werror

INCLUDE =	-I$(INCDIR)/
LIBS =		

.PHONY: all
all: $(NAME)

$(NAME): auteur $(OBJDIR) $(OBJ)
	ar rc $@ $(OBJ)
	ranlib $@

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(FLAGS) $(INCLUDE) $(LIBS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(OBJDIR)

.PHONY: fclean
fclean: clean
	rm -rf $(NAME)

.PHONY: re
re: fclean all

.PHONY: norm
norm:
	clear
	norminette $(patsubst %, $(SRCDIR)/%.c, $(ITEMS)) $(INCDIR)/libft.h

auteur:
	echo "hmartzol\n" > auteur
