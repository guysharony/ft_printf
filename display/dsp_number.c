/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsp_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 07:04:07 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/06 09:38:52 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int		ft_space(t_format f, int nb)
{
	int		a;

	a = f.wi;
	if ((a > 0 && ft_format('+', f.fl)) || nb < 0)
		a--;
	if (f.pr > 0 && (f.pr < (int)ft_nbrlen(nb, 10) || f.pr < f.wi))
		a -= f.pr;
	else
		a -= ft_nbrlen(nb, 10);
	if (a < 0)
		return (0);
	return (a);
}

static int		ft_number(t_format f, long long nb)
{
	int		a;

	a = ft_nbrlen(nb, 10);
	if (f.pr < 0 || f.pr >= a || f.pr < a)
		a -= ft_nbrlen(nb, 10);
	else
		a = f.pr;
	return (a);
}

void			ft_time(char c, int n)
{
	while (n-- > 0)
		write(1, &c, 1);
}

int				dsp_number(t_format f, long long nb)
{
	int				nb_space;
	int				nb_zero;
	long long		nb_value;
	int				len;

	if (err_number(f, nb))
		return (-1);
	nb_space = ft_space(f, nb);
	nb_zero = f.pr - (ft_nbrlen(nb, 10) - ft_number(f, nb));
	nb_value = nb / ft_pow(10, ft_number(f, nb));
	len = ft_print_before(f, nb_value, nb_space, nb_zero);
	if (nb_value < 0)
		nb_value *= -1;
	ft_time('0', nb_zero);
	if (!(f.pr == 0 && nb == 0))
	{
		len += ft_nbrlen(nb_value, 10);
		ft_putnbr_base(nb_value, "0123456789");
	}
	if (ft_format('-', f.fl))
		ft_time(' ', nb_space);
	return (len);
}
