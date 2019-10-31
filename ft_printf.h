/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:36:13 by gsharony          #+#    #+#             */
/*   Updated: 2019/10/30 10:56:35 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct		s_format
{
	int				left;
	int				zero;
	char			val;
	int				pr[2];
}					t_format;

int					ft_printf(const char *format, ...);
void				ft_argument(t_format f, va_list list);
char				*ft_flags(const char *format, va_list list);

void				dsp_number(t_format f, long long nb);
void				dsp_unsigned(t_format f, unsigned int nb);

void				ft_putstr(char *str);
void				ft_putchar(int c);

void				ft_print_adresse(void *a);

void				ft_putlongnbr(unsigned int nb, char *base);
void				ft_putchar_base(int c, char *base);
void				ft_putnbr_base(long long nb, char *base);

#endif
