/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 07:42:01 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/04 12:05:51 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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

static int			ft_conv(t_format f, va_list list)
{
	unsigned int	nbr;

	if (f.vl == 'd' || f.vl == 'i')
		return (dsp_number(f, (long long)va_arg(list, int)));
	else if (f.vl == 'c')
		return (dsp_char(f, va_arg(list, int)));
	else if (f.vl == 's')
		return (dsp_str(f, va_arg(list, char *)));
	else if (f.vl == 'p')
		return (dsp_adress(f, va_arg(list, void *)));
	else if (f.vl == 'u' || f.vl == 'x' || f.vl == 'X')
	{
		nbr = va_arg(list, unsigned int);
		if (f.vl == 'u')
			return (dsp_unsigned(f, nbr, "0123456789"));
		else if (f.vl == 'x')
			return (dsp_unsigned(f, nbr, "0123456789abcdef"));
		else if (f.vl == 'X')
			return (dsp_unsigned(f, nbr, "0123456789ABCDEF"));
	}
	return (-1);
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

int					ft_format_count(const char *format, char *flags)
{
	int		a;

	a = 0;
	while (ft_format(format[a], flags))
		a++;
	return (a);
}

t_print				ft_flags(const char *format, va_list list)
{
	int				a;
	t_format		f;
	t_print			p;

	a = 0;
	f = fl_init();
	a += ft_format_count(format, "-+ #0");
	f.fl = ft_substr(format, 0, a);
	if (format[a] == '*')
		f.wi = (int)va_arg(list, int);
	else if (format[a] >= '0' && format[a] <= '9')
		f.wi = ft_atoi(format + a);
	a += ft_format_count(format + a, "0123456789*");
	if (format[a] == '.' && format[a + 1] == '*')
		f.pr = (int)va_arg(list, int);
	else if (format[a] == '.')
		f.pr = ft_atoi(format + a + 1);
	while (!ft_format(format[a], "diouXxfFeEgGaAcsbp"))
		a++;
	f.vl = format[a];
	p.len = ft_conv(f, list);
	p.str = (char *)format + a + 1;
	free(f.fl);
	return (p);
}
