/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsp_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 07:04:07 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/11 12:29:54 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static long long	sign_number(long long nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		return (-nb);
	}
	return (nb);
}

static long long	before_number(long long nb, int len, t_format f)
{
	if (f.wi > len)
	{
		if (!ft_format('-', f.fl))
		{
			if (!ft_format('0', f.fl) || f.pr > 0)
				ft_time(' ', f.wi - len);
			else if (ft_format('0', f.fl) && f.pr < 0)
			{
				nb = sign_number(nb);
				ft_time('0', f.wi - len);
			}
		}
		else if (ft_format('-', f.fl))
		{
			if (ft_format('0', f.fl) && f.pr <= 0)
			{
				nb = sign_number(nb);
				ft_time('0', f.wi - len);
			}
		}
	}
	return (nb);
}

int					dsp_number(t_format f, long long nb)
{
	int		len;

	len = 0;
	len += ft_size_number(nb, f);
	nb = before_number(nb, len, f);
	ft_print_number(nb, f);
	if (f.wi > len)
	{
		if (ft_format('-', f.fl))
		{
			if (!(ft_format('0', f.fl) && f.pr <= 0))
				ft_time(' ', f.wi - len);
		}
		len += (f.wi - len);
	}
	return (len);
}
