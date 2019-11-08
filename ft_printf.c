/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:32:41 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/08 17:41:52 by gsharony         ###   ########.fr       */
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
		while (p.len == -1 || p.status == -1)
			p = ft_flags(p.str, c);
		str = p.str;
		a += p.len;
	}
	va_end(c);
	return (a);
}
