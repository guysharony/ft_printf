/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 07:42:01 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/10 21:41:06 by guysharon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

static t_format		fl_init(void)
{
	t_format f;

	f.fl = NULL;
	f.vl = 0;
	f.po = 0;
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
	else if (ft_isalpha(f.vl) || f.vl == '%')
		return (dsp_pc(f));
	return (-1);
}

t_print				ft_flags(const char *format, va_list list)
{
	t_format		f;
	t_print			p;

	f = fl_init();
	while (ft_format(format[f.po], "-.0123456789*"))
		f = ft_get_params(format, f, list);
	f.vl = format[f.po];
	p.len = ft_conv(f, list);
	p.str = (char *)format + f.po + 1;
	return (p);
}
