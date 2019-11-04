/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:31:41 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/04 11:33:00 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar_base(nb, "0123456789");
}

void	ft_putfloat(double nb, int p)
{
	signed long int		decipart;
	signed long int		intpart;

	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	intpart = (signed long int)nb;
	ft_putnbr(intpart);
	write(1, ".", 1);
	nb -= intpart;
	nb *= 10;
	while (p-- > 0 && (signed long int)nb == 0)
	{
		write(1, "0", 1);
		nb *= 10;
	}
	nb *= ft_pow(10, p);
	decipart = (signed long int)(nb + 0.5);
	ft_putnbr(decipart);
}
