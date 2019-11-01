/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsp_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 07:04:07 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/01 13:49:52 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int		ft_space(t_format f, int nb)
{
	int		a;

	a = f.wi;
	if (f.pr > 0 && (f.pr < (int)ft_nbrlen(nb, 10) || f.pr < f.wi))
		a -= f.pr;
	else
		a -= ft_nbrlen(nb, 10);
	if (ft_format('+', f.fl))
		return (a - 1);
	return (a);
}

static int		ft_zero(t_format f, int nb)
{
	int		a;

	a = 0;
	if (f.pr >= 0)
	{
		if (nb < 0)
		{
			nb *= -1;
			write(1, "-", 1);
		}
		a = f.pr - ft_nbrlen(nb, 10);
		ft_time('0', a);
	}
	return (a);
}

void			ft_time(char c, int n)
{
	while (n-- > 0)
		write(1, &c, 1);
}

void			dsp_number(t_format f, long long nb)
{
	int		a;

	a = ft_space(f, nb);
	if (!ft_format('-', f.fl))
		ft_time(' ', a);
	if (ft_format('+', f.fl))
		write(1, "+", 1);
	ft_zero(f, nb);
	if (f.pr < 0)
		ft_putnbr_base(nb, "0123456789");
	else
		ft_putnbr_base(nb / (10 * f.pr), "0123456789");
	if (ft_format('-', f.fl))
		ft_time(' ', a);
}
