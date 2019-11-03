/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsp_number_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 07:15:11 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/03 07:21:06 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int				ft_sign(t_format f, long long nb)
{
	if (ft_format('+', f.fl) && nb >= 0)
		write(1, "+", 1);
	else if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
	}
	return (nb);
}

int				ft_print_sign(t_format f, long long nb, int space)
{
	if (!ft_format('-', f.fl))
	{
		if ((f.wi > f.pr && f.pr > 0) || !ft_format('0', f.fl))
		{
			ft_time(' ', space);
			nb = ft_sign(f, nb);
		}
		else if (ft_format('0', f.fl) && f.pr < 0)
		{
			nb = ft_sign(f, nb);
			ft_time('0', space);
		}
	}
	return (nb);
}
