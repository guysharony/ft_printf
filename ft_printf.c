/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:32:41 by gsharony          #+#    #+#             */
/*   Updated: 2019/10/22 15:16:29 by gsharony         ###   ########.fr       */
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

void	ft_putchar(int c)
{
	char	a;

	a = (char)c;
	write(1, &a, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		return (ft_putstr("-2147483648"));
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

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
	else if (op == 'd')
	{
		int d = va_arg(list, int);
		ft_putnbr(d);
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
