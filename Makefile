# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 08:33:35 by qnguyen           #+#    #+#              #
#    Updated: 2022/02/24 08:26:08 by qnguyen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wordle
SRC = get_next_line.c main.c utilities.c check_functions.c

all: libft.a
	@gcc -g $(SRC) -Llibft/ -lft -Ilibft/ #-o wordle

libft.a:
	make -C ./libft/

clean:
	@make clean -C libft/
	@/bin/rm -f $(wildcard *.o)

fclean: clean
	@make fclean -C libft/
	@/bin/rm -f $(NAME)

re: fclean all
