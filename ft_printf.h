/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:36:13 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/10 21:39:43 by guysharon        ###   ########.fr       */
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
	int				po;
	int				wi;
	int				pr;
}					t_format;

typedef struct		s_print
{
	char			*str;
	int				len;
	int				status;
}					t_print;

int					ft_printf(const char *format, ...);
void				ft_argument(t_format f, va_list list);
t_print				ft_flags(const char *format, va_list list);

void				ft_time(char c, int n);
int					ft_format(char c, char *format);
int					ft_format_count(const char *format, char *flags);
t_format			ft_get_params(const char *format, t_format f, va_list list);

int					dsp_number(t_format f, long long nb);
int					dsp_unsigned(t_format f, unsigned int nb, char *base);
int					dsp_str(t_format f, char *str);
int					dsp_char(t_format f, int c);
int					dsp_adress(t_format f, void *str);
int					dsp_pc(t_format f);

void				ft_print_adress(void *a, t_format f);
int					ft_size_adress(void *a, t_format f);
void				ft_print_number(long long nb, t_format f);
int					ft_size_number(long long nb, t_format f);
void				ft_print_unsigned(unsigned int nb, char *base, t_format f);
int					ft_size_unsigned(unsigned int nb, char *base, t_format f);

int					ft_pow(int nb, int power);
int					ft_putnstr(char *str, int len);
int					ft_nbrlen(long long nb, int base);
int					ft_u_nbrlen(unsigned int nb, int base);

void				ft_putnbr(int nb);
void				ft_putfloat(double nb, int p);
void				ft_putchar_base(int c, char *base);
void				ft_putnbr_base(long long nb, char *base);
void				ft_putlongnbr(unsigned int nb, char *base);
void				ft_putstr(char *str);
void				ft_putchar(int c);

int					ft_sign(t_format f, long long nb);

#endif
