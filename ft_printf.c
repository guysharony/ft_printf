/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:32:41 by gsharony          #+#    #+#             */
/*   Updated: 2019/10/27 15:10:38 by guysharon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_argument(char op, va_list list)
{
	if (op == 's')
	{
		char *s = va_arg(list, char *);
		ft_putstr(s);
	}
	else if (op == 'c')
	{
		int c = va_arg(list, int);
		ft_putchar(c);
	}
	else if (op == 'd' || op == 'i')
	{
		int d = va_arg(list, int);
		ft_putnbr(d);
	}
	else if (op == 'p')
	{
		void *p = va_arg(list, void *);
		ft_print_adresse(&p);
	}
	else if (op == 'u')
	{
		unsigned int u = va_arg(list, unsigned int);
		ft_putlongnbr(u);
	}
}

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
		ft_argument(*str, c);
		str++;
	}
	va_end(c);
	return (a);
}
