/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 07:42:01 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/01 12:38:13 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

static t_format		fl_init(void)
{
	t_format f;

	f.fl = NULL;
	f.vl = 0;
	f.le = NULL;
	f.wi = -1;
	f.pr = -1;
	return (f);
}

static void			ft_conv(t_format f, va_list list)
{
	if (f.vl == 'd' || f.vl == 'i')
		dsp_number(f, (long long)va_arg(list, int));
	else if (f.vl == 'c')
		dsp_char(f, (int)va_arg(list, int));
	else if (f.vl == 's')
		dsp_str(f, (char *)va_arg(list, char *));
	else if (f.vl == 'p')
		dsp_adress(f, (void *)va_arg(list, void *));
	else if (f.vl == 'u')
		dsp_unsigned(f, (unsigned int)va_arg(list, unsigned int), "0123456789");
	else if (f.vl == 'x')
		dsp_unsigned(f, (unsigned int)va_arg(list, unsigned int), "0123456789abcdef");
	else if (f.vl == 'X')
		dsp_unsigned(f, (unsigned int)va_arg(list, unsigned int), "0123456789ABCDEF");
}

int					ft_format(char c, char *format)
{
	int		a;

	a = 0;
	while (format[a])
	{
		if (format[a] == c)
			return (1);
		a++;
	}
	return (0);
}

char				*ft_flags(const char *format, va_list list)
{
	int				a;
	int				b;
	t_format		f;

	a = 0;
	b = 0;
	f = fl_init();
	while (ft_format(format[a], "-+ #0"))
		a++;
	f.fl = ft_substr(format, b, a);
	if (format[a] == '*')
		f.wi = (int)va_arg(list, int);
	else if (format[a] >= '0' && format[a] <= '9')
		f.wi = ft_atoi(format + a);
	while (ft_format(format[a], "0123456789*"))
		a++;
	if (format[a] == '.' && format[a + 1] == '*')
		f.pr = (int)va_arg(list, int);
	else if (format[a] == '.')
		f.pr = ft_atoi(format + a + 1);
	while (!ft_format(format[a], "diouXxfFeEgGaAcsbp"))
		a++;
	f.vl = format[a];
	ft_conv(f, list);
	return ((char *)format + a + 1);
}
