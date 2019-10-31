/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsp_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 07:04:07 by gsharony          #+#    #+#             */
/*   Updated: 2019/10/31 13:11:27 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	dsp_number(t_format f, long long nb)
{
	int		a;

	a = 0;
	if (f.left == '-')
		f.zero = 0;
	if (f.pr[0] == 1)
	{
		if (nb < 0)
		{
			nb *= -1;
			write(1, "-", 1);
		}
		while (a++ < f.pr[1] - ft_nbrlen(nb))
			write(1, "0", 1);
	}
	ft_putnbr_base(nb, "0123456789");
}