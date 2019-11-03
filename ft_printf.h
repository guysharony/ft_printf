/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:36:13 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/03 08:49:16 by gsharony         ###   ########.fr       */
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
	char			*fl;
	char			vl;
	char			*le;
	int				wi;
	int				pr;
}					t_format;

int					ft_printf(const char *format, ...);
void				ft_argument(t_format f, va_list list);
char				*ft_flags(const char *format, va_list list);

void				dsp_number(t_format f, long long nb);
void				dsp_unsigned(t_format f, unsigned int nb, char *base);
void				dsp_str(t_format f, char *str);
void				dsp_char(t_format f, int c);
void				dsp_adress(t_format f, void *str);

void				ft_putstr(char *str);
void				ft_putnstr(char *str, int len);
void				ft_putchar(int c);
void				ft_time(char c, int n);
void				ft_print_adress(void *a);
void				ft_putlongnbr(unsigned int nb, char *base);
void				ft_putchar_base(int c, char *base);
void				ft_putnbr_base(long long nb, char *base);
int					ft_format(char c, char *format);

int					ft_nbrlen(long long nb, int base);
int					ft_u_nbrlen(unsigned int nb, int base);
int					ft_sign(t_format f, long long nb);
int					ft_print_sign(t_format f, long long nb, int space);

#endif
