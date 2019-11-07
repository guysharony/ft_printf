# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/22 09:39:55 by gsharony          #+#    #+#              #
#    Updated: 2019/11/07 08:46:02 by gsharony         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

DIR_1		= ./src/

DIR_2		= ./display/

DIR_3		= ./error/

DIR_4		= ./libft/

SRCS		= ft_printf.c \
			  ${DIR_1}ft_strings.c ${DIR_1}ft_number.c ${DIR_1}ft_adress.c ${DIR_1}ft_len.c \
			  ${DIR_2}ft_flags.c ${DIR_2}dsp_number.c ${DIR_2}dsp_unsigned.c ${DIR_2}dsp_adress.c ${DIR_2}dsp_string.c ${DIR_2}dsp_number_utils.c ${DIR_2}dsp_pc.c \
			  ${DIR_3}err_string.c ${DIR_3}err_adress.c ${DIR_3}err_unsigned.c ${DIR_3}err_number.c\
			  ${DIR_4}ft_putchar_fd.c ${DIR_4}ft_putstr_fd.c ${DIR_4}ft_putendl_fd.c ${DIR_4}ft_putnbr_fd.c ${DIR_4}ft_itoa.c ${DIR_4}ft_atoi.c ${DIR_4}ft_bzero.c ${DIR_4}ft_calloc.c ${DIR_4}ft_isalnum.c ${DIR_4}ft_isalpha.c ${DIR_4}ft_isascii.c ${DIR_4}ft_isdigit.c ${DIR_4}ft_isprint.c ${DIR_4}ft_memccpy.c ${DIR_4}ft_memchr.c ${DIR_4}ft_memcmp.c ${DIR_4}ft_memcpy.c ${DIR_4}ft_memmove.c ${DIR_4}ft_memset.c ${DIR_4}ft_strchr.c ${DIR_4}ft_strdup.c ${DIR_4}ft_strjoin.c ${DIR_4}ft_strlcat.c ${DIR_4}ft_strlcpy.c ${DIR_4}ft_strlen.c ${DIR_4}ft_strncmp.c ${DIR_4}ft_strnstr.c ${DIR_4}ft_strrchr.c ${DIR_4}ft_strtrim.c ${DIR_4}ft_substr.c ${DIR_4}ft_tolower.c ${DIR_4}ft_toupper.c ${DIR_4}ft_itoa.c ${DIR_4}ft_strmapi.c ${DIR_4}ft_strcpy.c ${DIR_4}ft_split.c

OBJECTS		= ${SRCS:.c=.o}

INCLUDES	= ./

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -I ${INCLUDES}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: 		${NAME}

$(NAME):	${OBJECTS}
			ar rc ${NAME} ${OBJECTS}

clean:
			${RM} ${OBJECTS}

re:			fclean all

fclean:		clean
			${RM} ${NAME}

.PHONY:		all clean fclean re
