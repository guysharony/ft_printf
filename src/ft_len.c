/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 13:00:20 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/01 18:23:08 by guysharon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_nbrlen(long long nb, int base)
{
	int		a;

	a = 1;
	if (nb < 0)
		nb *= -1;
	while (nb > 9)
	{
		nb /= base;
		a++;
	}
	return (a);
}

int		ft_u_nbrlen(unsigned int nb)
{
	int		a;

	a = 0;
	if (nb < 0)
		nb *= -1;
	while (nb > 0)
	{
		nb /= 10;
		a++;
	}
	return (a);
}
