# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/22 09:39:55 by gsharony          #+#    #+#              #
#    Updated: 2019/10/22 09:44:03 by gsharony         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

DIR			= ./

SRCS		= ft_printf.c

OBJECTS		= ${SRCS:.c=.o}

INCLUDES	= ./

LIBFT		= libft/libft.a

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -I ${INCLUDES}

.c.o:
			${CC} ${CFLAGS} -I ${INCLUDES} -c $< -o ${<:.c=.o}

all: 		${NAME}

$(NAME):	${OBJECTS}
			ar rc ${NAME} ${OBJECTS} ${LIBFT}

clean:
			${RM} ${OBJECTS}

re:			fclean all

fclean:		clean
			${RM} ${NAME}

.PHONY:		all clean fclean re
