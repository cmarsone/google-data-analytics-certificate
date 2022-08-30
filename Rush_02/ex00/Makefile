# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmarsone <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 09:54:47 by cmarsone          #+#    #+#              #
#    Updated: 2022/08/28 17:35:43 by cmarsone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -g

EXEC		= rush-02

INCLUDES	= numbers.dict

LDFLAGS		= 

OBJECTS		= ${SRCS:.c=.o}

RM			= rm -rf

SRCS		= ${wildcard rush-02.c}

all: 			compilation.o
				./${EXEC}

compilation.o: 	${OBJECTS}
				${CC} ${CFLAGS} -o ${EXEC} ${OBJECTS}

compilation.c:	${SRCS}
				${CC} ${CFLAGS} -c ${SRCS}

clean:
				${RM} ${OBJECTS}

fclean:			clean
				${RM} ${EXEC}

re:				fclean all 

.PHONY:			fclean clean
