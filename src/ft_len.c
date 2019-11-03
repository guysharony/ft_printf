/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 13:00:20 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/03 08:50:54 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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
