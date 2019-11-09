/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 13:00:20 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/09 14:23:22 by guysharon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_format(char c, char *format)
{
	int		a;

	a = 0;
	if (format == NULL)
		return (0);
	while (format[a])
	{
		if (format[a] == c)
			return (1);
		a++;
	}
	return (0);
}

int		ft_format_count(const char *format, char *flags)
{
	int		a;

	a = 0;
	while (ft_format(format[a], flags))
		a++;
	return (a);
}

int		ft_nbrlen(long long nb, int base)
{
	int		a;

	a = 1;
	if (nb < 0)
		nb *= -1;
	while (nb > (long long)base - 1)
	{
		nb /= base;
		a++;
	}
	return (a);
}

int		ft_u_nbrlen(unsigned int nb, int base)
{
	int		a;

	a = 1;
	if (nb < 0)
		nb *= -1;
	while (nb > (unsigned int)base - 1)
	{
		nb /= base;
		a++;
	}
	return (a);
}
