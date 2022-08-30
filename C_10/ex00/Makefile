# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmarsone <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 15:49:20 by cmarsone          #+#    #+#              #
#    Updated: 2022/08/29 09:35:51 by cmarsone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		= gcc

CFLAGS	= -Wall -Wextra -Werror -g

EXEC	= ft_display_file

FILE	= ${wildcard b}

SRC		= ${wildcard *.c}

OBJ		= ${SRC:.c=.o}

RM		= rm -rf

all: 			${EXEC}

compilation.o:	${OBJ}
				${CC} ${CFLAGS} -o ${EXEC} ${OBJ}


compilation.c:	${SRC}
				${CC} ${CFLAGS} -c ${SRC}

clean:
				${RM} ${OBJ}

fclean:			clean
				${RM} ${EXEC}

re:				fclean all

.PHONY:			clean
