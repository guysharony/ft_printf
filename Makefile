# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/22 09:39:55 by gsharony          #+#    #+#              #
#    Updated: 2019/10/28 16:19:38 by guysharon        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

DIR			= ./

SRCS		= ${DIR}ft_printf.c ${DIR}ft_display.c ${DIR}ft_number.c ${DIR}ft_adresse.c

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
