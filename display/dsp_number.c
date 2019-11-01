/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsp_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 07:04:07 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/01 10:47:51 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_time(char c, int n)
{
	while (n-- > 0)
		write(1, &c, 1);
}

void	dsp_number(t_format f, long long nb)
{
	int		a;

	a = 0;
	f.wi -= f.pr + ft_nbrlen(nb, 10);
	if (nb < 0)
		f.wi++;
	if (!ft_format('-', f.fl))
		ft_time(' ', f.wi);
	if (f.pr >= 0)
	{
		if (nb < 0)
		{
			nb *= -1;
			write(1, "-", 1);
		}
		while (a++ < f.pr - ft_nbrlen(nb, 10))
			write(1, "0", 1);
	}
	if (f.pr < 0)
		ft_putnbr_base(nb, "0123456789");
	else
		ft_putnbr_base(nb / (10 * f.pr), "0123456789");
	if (ft_format('-', f.fl))
		ft_time(' ', f.wi);
}
