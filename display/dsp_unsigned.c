/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsp_unsigned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:57:46 by gsharony          #+#    #+#             */
/*   Updated: 2019/10/31 15:06:44 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	dsp_unsigned(t_format f, unsigned int nb, char *base)
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
		while (a++ < f.pr - ft_u_nbrlen(nb))
			write(1, "0", 1);
	}
	ft_putlongnbr(nb, base);
}
