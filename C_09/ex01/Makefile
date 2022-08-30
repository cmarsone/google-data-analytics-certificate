# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmarsone <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 09:54:47 by cmarsone          #+#    #+#              #
#    Updated: 2022/08/29 17:41:48 by cmarsone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRCS	=	./srcs/ft_putchar.c ./srcs/ft_swap.c ./srcs/ft_putstr.c ./srcs/ft_strlen.c ./srcs/ft_strcmp.c

OBJS	=	${SRCS:.c=.o}

INCLUDES	= ./includes/

CC		= gcc

CFLAGS	=  -Wall -Wextra -Werror

RM		= rm -f

HEADERS	= includes/ft.h

${NAME}	:	${OBJS}
			ar rcs ${NAME} ${OBJS}

all		:	${NAME}

.c.o:
			${CC} ${CFLAGS} -I ${INCLUDES} -c $< -o ${<:.c=.o}

clean	:
			${RM} ${OBJS}

fclean	:	clean
			${RM} ${NAME}

re		:	fclean all

.PHONY	:	clean fclean all re
