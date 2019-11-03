/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsp_unsigned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:57:46 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/03 09:35:17 by gsharony         ###   ########.fr       */
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

static int		ft_space(t_format f, unsigned int nb, int base)
{
	int		a;

	a = f.wi;
	if ((f.pr > 0 || f.pr < f.wi) && f.pr > (int)ft_u_nbrlen(nb, base))
		a -= f.pr;
	else
		a -= ft_u_nbrlen(nb, base);
	if (ft_format('+', f.fl) || nb < 0)
		return (a - 1);
	return (a);
}

static int		ft_number(t_format f, unsigned int nb, int base)
{
	int		a;

	a = ft_u_nbrlen(nb, base);
	if (f.pr < 0 || f.pr >= a || f.pr < a)
		a -= ft_u_nbrlen(nb, base);
	else
		a = f.pr;
	ft_time('0', f.pr - (ft_u_nbrlen(nb, base) - a));
	return (nb / ft_recursive_power(10, a));
}

void	dsp_unsigned(t_format f, unsigned int nb, char *base)
{
	int		a;

	a = ft_space(f, nb, ft_strlen(base));
	nb = ft_print_sign(f, nb, a);
	if (ft_format(' ', f.fl))
		write(1, " ", 1);
	if (!(f.pr == 0 && nb == 0))
		ft_putlongnbr(ft_number(f, nb, ft_strlen(base)), base);
	if (ft_format('-', f.fl))
		ft_time(' ', a);
}
