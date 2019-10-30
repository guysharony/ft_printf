/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:32:41 by gsharony          #+#    #+#             */
/*   Updated: 2019/10/30 08:23:16 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*void	ft_argument(t_format f, va_list list)
{
	if (f.val == 's')
	{
		char *s = va_arg(list, char *);
		ft_putstr(s);
	}
	else if (f.val == 'c')
	{
		int c = va_arg(list, int);
		ft_putchar(c);
	}
	else if (f.val == 'd' || f.val == 'i')
	{
		int d = va_arg(list, int);
		ft_putnbr_base((long long)d, "0123456789");
	}
	else if (f.val == 'p')
	{
		void *p = va_arg(list, void *);
		ft_print_adresse(&p);
	}
	else if (f.val == 'u')
	{
		unsigned int u = va_arg(list, unsigned int);
		ft_putlongnbr(u, "0123456789");
	}
}*/

int		ft_printf(const char *str, ...)
{
	int			a;
	char		b;
	va_list		c;

	a = 0;
	va_start(c, str);
	while ((b = *str) != '\0')
	{
		str++;
		if (b != '%')
		{
			ft_putchar(b);
			a++;
			continue ;
		}
		str = ft_flags(str, c);
	}
	va_end(c);
	return (a);
}
