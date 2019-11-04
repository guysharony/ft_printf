/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsp_unsigned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:57:46 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/04 11:35:54 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int		ft_space(t_format f, unsigned int nb, int base)
{
	int		a;

	a = f.wi;
	if ((a > 0 && ft_format('+', f.fl)) || nb < 0)
		a--;
	if ((f.pr > 0 || f.pr < f.wi) && f.pr > (int)ft_u_nbrlen(nb, base))
		a -= f.pr;
	else
		a -= ft_u_nbrlen(nb, base);
	if (a < 0)
		return (0);
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
	return (a);
}

int				dsp_unsigned(t_format f, unsigned int nb, char *base)
{
	int					nb_space;
	int					nb_zero;
	unsigned int		nb_value;
	int					len;

	nb_space = ft_space(f, nb, ft_strlen(base));
	nb_value = ft_number(f, nb, ft_strlen(base));
	nb_zero = f.pr - (ft_u_nbrlen(nb, ft_strlen(base)) - nb_value);
	nb_value = nb / ft_pow(ft_strlen(base), nb_value);
	len = ft_print_before(f, nb_value, nb_space, nb_zero);
	nb_value = ft_sign(f, nb_value);
	ft_time('0', nb_zero);
	if (!(f.pr == 0 && nb == 0))
	{
		len += ft_u_nbrlen(nb_value, ft_strlen(base));
		ft_putlongnbr(nb_value, base);
	}
	if (ft_format('-', f.fl))
		ft_time(' ', nb_space);
	return (len);
}
