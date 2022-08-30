# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmarsone <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/24 14:17:07 by cmarsone          #+#    #+#              #
#    Updated: 2022/08/30 07:17:37 by cmarsone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		= gcc

CFLAGS	= -Wall -Wextra -Werror -g

EXEC	= do-op

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
