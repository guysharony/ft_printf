# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/22 09:39:55 by gsharony          #+#    #+#              #
#    Updated: 2019/10/31 13:02:58 by gsharony         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

DIR_1		= ./src/

DIR_2		= ./display/

SRCS		= ft_printf.c ${DIR_1}ft_string.c ${DIR_1}ft_number.c ${DIR_1}ft_adress.c ${DIR_1}ft_len.c ${DIR_2}ft_flags.c ${DIR_2}dsp_number.c ${DIR_2}dsp_string.c

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
