# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/30 15:34:26 by lduflot           #+#    #+#              #
#    Updated: 2025/02/19 16:45:57 by lduflot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############################
##ARGUMENTS/MACRO

CC = cc
CFLAGS = -g -Wall -Wextra -Werror
NAME = push_swap

###############################
##SOURCES

FILES =	check_arguments/ft_check_max_min_int.c \
				check_arguments/ft_check_only_num.c \
				check_arguments/ft_check_doublon.c \
				check_arguments/ft_check_one_string.c \
				check_arguments/ft_check_tri.c \
				check_arguments/ft_check_arguments_utils.c \
				check_arguments/error.c \
				ft_instructions/ft_instructions_utils.c \
				ft_instructions/ft_push.c \
				ft_instructions/ft_reverse_rotate.c \
				ft_instructions/ft_rotate.c \
				ft_instructions/ft_swap.c \
				ft_initialisation_node/ft_initialisation_node_utils.c \
				ft_initialisation_node/ft_add_node.c \
				push_swap.c \
				main.c

OBJS = $(FILES:.c=.o)

###############################
##RULES

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

