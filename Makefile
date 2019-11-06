# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/22 09:39:55 by gsharony          #+#    #+#              #
#    Updated: 2019/11/06 09:37:59 by gsharony         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

DIR_1		= ./src/

DIR_2		= ./display/

DIR_3		= ./error/

SRCS		= ft_printf.c ${DIR_1}ft_string.c ${DIR_1}ft_number.c ${DIR_1}ft_adress.c ${DIR_1}ft_len.c ${DIR_2}ft_flags.c ${DIR_2}dsp_number.c ${DIR_2}dsp_string.c ${DIR_2}dsp_number_utils.c ${DIR_2}dsp_pc.c ${DIR_3}err_string.c ${DIR_3}err_adress.c ${DIR_3}err_unsigned.c ${DIR_3}err_number.c

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
