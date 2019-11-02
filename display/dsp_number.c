/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsp_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 07:04:07 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/02 15:34:46 by guysharon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int		ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}

static int		ft_space(t_format f, int nb)
{
	int		a;

	a = f.wi;
	if (f.pr > 0 && (f.pr < (int)ft_nbrlen(nb, 10) || f.pr < f.wi))
		a -= f.pr;
	else
		a -= ft_nbrlen(nb, 10);
	if (ft_format('+', f.fl) || nb < 0)
		return (a - 1);
	return (a);
}

static int		ft_number(t_format f, long long nb)
{
	int		a;

	a = ft_nbrlen(nb, 10);
	if (f.pr < 0 || f.pr > a)
		a -= ft_nbrlen(nb, 10);
	else
		a = f.pr;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	ft_time('0', f.pr - (ft_nbrlen(nb, 10) - a));
	return (nb / ft_recursive_power(10, a));
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
	if (!ft_format('-', f.fl) && !ft_format('0', f.fl))
		ft_time(' ', a);
	else if (!ft_format(' ', f.fl) && ft_format('0', f.fl))
		ft_time('0', a);
	if (ft_format('+', f.fl) && nb >= 0)
		write(1, "+", 1);
	if (ft_format(' ', f.fl))
		write(1, " ", 1);
	if (!(f.pr == 0 && nb == 0))
		ft_putnbr_base(ft_number(f, nb), "0123456789");
	if (ft_format('-', f.fl))
		ft_time(' ', a);
}
