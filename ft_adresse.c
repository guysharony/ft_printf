/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adresse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:09:56 by gsharony          #+#    #+#             */
/*   Updated: 2019/10/23 13:10:51 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_putchar_hex(int a)
{
	char	b;

	if (a >= 0 && a <= 9)
		b = a + '0';
	else if (a >= 10 && a <= 16)
		b = a + 'a' - 10;
	write(1, &b, 1);
}

void	ft_putnbr_hex(long long nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb > 15)
	{
		ft_putnbr_hex(nb / 16);
	}
	ft_putchar_hex(nb % 16);
}

void	ft_print_adresse(void *a)
{
	write(1, "0x", 2);
	ft_putnbr_hex((long long)a);
}
