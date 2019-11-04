/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsp_number_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 07:15:11 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/04 09:27:47 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int				ft_sign(t_format f, long long nb)
{
	if (!ft_format('+', f.fl) && ft_format(' ', f.fl) && nb >= 0)
		write(1, " ", 1);
	if (ft_format('+', f.fl) && nb >= 0)
		write(1, "+", 1);
	else if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
	}
	return (nb);
}

int				ft_print_before(t_format f, long long nb, int space, int zero)
{
	int		len;

	len = 0;
	if (!ft_format('-', f.fl) && ((f.wi > f.pr && f.pr > 0) || !ft_format('0', f.fl)))
		ft_time(' ', space);
	ft_sign(f, nb);
	if (!ft_format('-', f.fl) && ft_format('0', f.fl) && f.pr < 0)
		ft_time('0', space);
	if (space > 0)
		len += space;
	if (zero > 0)
		len += zero;
	if (nb < 0 || (ft_format('+', f.fl) && nb >= 0))
		len++;
	if (ft_format(' ', f.fl))
		len++;
	return (len);
}
