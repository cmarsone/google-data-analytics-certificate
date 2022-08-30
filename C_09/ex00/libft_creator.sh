# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmarsone <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 09:15:40 by cmarsone          #+#    #+#              #
#    Updated: 2022/08/29 08:50:26 by cmarsone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh
gcc -Wall -Wextra -Werror -c ft_swap.c ft_putchar.c ft_strcmp.c ft_strlen.c ft_putstr.c ft_strcmp.c
ar rc libft.a ft_swap.o ft_putchar.o ft_strlen.o ft_strcmp.o ft_putstr.o
ranlib libft.a
rm -f ft_putchar.o ft_strcmp.o ft_swap.o ft_putstr.o ft_strlen.o
