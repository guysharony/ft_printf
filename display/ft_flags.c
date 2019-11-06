/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 07:42:01 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/06 14:44:03 by gsharony         ###   ########.fr       */
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
	else if (f.vl == '%')
		return (dsp_pc(f));
	return (-1);
}

t_print				ft_width(const char *format, int a, va_list list)
{
	t_print		p;

	p.status = 0;
	p.len = -1;
	if (format[a] == '*')
	{
		p.len = (int)va_arg(list, int);
		p.status++;
	}
	else if (format[a] >= '0' && format[a] <= '9')
	{
		p.len = ft_atoi(format + a);
		p.status += ft_format_count(format + a, "0123456789");
	}
	else
		p.status = 0;
	return (p);
}

t_print				ft_precision(const char *format, int a, va_list list)
{
	t_print		p;

	p.status = 0;
	p.len = -1;
	if (format[a] == '.' && format[a + 1] == '*')
	{
		p.len = (int)va_arg(list, int);
		p.status++;
	}
	else if (format[a] == '.')
	{
		p.len = ft_atoi(format + a + 1);
		p.status += ft_format_count(format + a + 1, "0123456789") + 1;
	}
	else
		p.status = 0;
	return (p);
}

t_print				ft_flags(const char *format, va_list list)
{
	int				a;
	t_format		f;
	t_print			p;

	f = fl_init();
	p.len = 0;
	a = ft_format_count(format, "-+ #0");
	f.fl = ft_substr(format, 0, a);
	p = ft_width(format, a, list);
	if (p.status == -1)
		return (p);
	f.wi = p.len;
	a += p.status;
	p = ft_precision(format, a, list);
	if (p.status == -1)
		return (p);
	f.pr = p.len;
	a += p.status;
	f.vl = format[a];
	p.len = ft_conv(f, list);
	p.str = (char *)format + a + 1;
	free(f.fl);
	return (p);
}
