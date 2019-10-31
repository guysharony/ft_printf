/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsp_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 07:04:07 by gsharony          #+#    #+#             */
/*   Updated: 2019/10/31 16:01:52 by gsharony         ###   ########.fr       */
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
	f.wi -= f.pr + ft_nbrlen(nb);
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
		while (a++ < f.pr - ft_nbrlen(nb))
			write(1, "0", 1);
	}
	ft_putnbr_base(nb, "0123456789");
	if (ft_format('-', f.fl))
		ft_time(' ', f.wi);
}
