# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmarsone <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/24 16:23:48 by cmarsone          #+#    #+#              #
#    Updated: 2022/08/29 11:51:06 by cmarsone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror -g

EXEC	= ft_tail

OBJ		= ${SRC:.c=.o}

SRC		= ${wildcard *.c}

RM		= rm -rf

all:			${EXEC}

compilation.o:	${OBJ}
				${CC} ${CFLAGS} -o ${EXEC} ${OBJ}

compilation.c:	${SRC}
				${CC} ${CFLAGS} -c ${SRC}

clean:
				${RM} ${OBJ}

fclean:			clean
				${RM} ${EXEC}

re:				fclean all

.PHONY:			clean fclean

