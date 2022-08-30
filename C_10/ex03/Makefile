# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmarsone <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/24 16:53:13 by cmarsone          #+#    #+#              #
#    Updated: 2022/08/30 08:31:39 by cmarsone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror -g

EXEC	= ft_hexdump

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
