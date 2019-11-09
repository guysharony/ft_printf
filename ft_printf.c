/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:32:41 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/09 16:58:48 by guysharon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	int			a;
	char		b;
	va_list		c;
	t_print		p;

	a = 0;
	va_start(c, str);
	while ((b = *str++) != '\0')
	{
		if (b != '%')
		{
			ft_putchar(b);
			a++;
			continue ;
		}
		p = ft_flags(str, c);
		if (p.len == -1)
			continue ;
		str = p.str;
		a += p.len;
	}
	va_end(c);
	return (a);
}
