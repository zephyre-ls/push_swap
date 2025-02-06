# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/30 15:34:26 by lduflot           #+#    #+#              #
#    Updated: 2025/02/06 12:32:50 by lduflot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############################
##ARGUMENTS/MACRO

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = pushswap.a

###############################
##SOURCES

FILES =	ft_check_max_min_int.c \
				ft_check_only_num.c \
				ft_check_doublon.c \
				ft_check_max_min_int.c \
				ft_check_only_num.c \
				ft_push.c \
				ft_reverse_rotate.c \
				ft_rotate.c \
				ft_swap.c \
				main.c \
				ft_list_manip.c \
				push_swap.c 

OBJS = $(FILES:.c=.o)

###############################
##RULES

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

