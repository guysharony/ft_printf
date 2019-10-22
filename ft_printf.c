/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:32:41 by gsharony          #+#    #+#             */
/*   Updated: 2019/10/22 15:06:18 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str)
{
	int		a;

	a = 0;
	if (!str)
		return ;
	while (str[a] != '\0')
	{
		write(1, &str[a], 1);
		a++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_argument(char op, va_list list)
{
	if (op == 's')
	{
		char *d = va_arg(list, char *);
		ft_putstr(d);
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
	return (a);
}
