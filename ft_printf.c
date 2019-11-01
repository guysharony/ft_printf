/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:32:41 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/01 11:15:19 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		else
			if (*str == '%')
			{
				write(1, "%", 1);
				str++;
				continue ;
			}
		str = ft_flags(str, c);
	}
	va_end(c);
	return (a);
}
