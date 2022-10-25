# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: md-aless <md-aless@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/31 15:15:46 by md-aless          #+#    #+#              #
#    Updated: 2022/01/31 16:16:38 by md-aless         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HDRS = ft_printf.h

SRC = 	ft_printf.c \
		ft_printf_utils.c \
		ft_printf_utils2.c \
		ft_printf_utils3.c 

OBJS = ${SRC:.c=.o}

CC = gcc -Wall -Wextra -Werror

.c.o = ${CC} -I ${HDRS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
		ar rc ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re