/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsp_unsigned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:57:46 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/11 12:12:32 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static unsigned int		sign_unsigned(unsigned int nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		return (-nb);
	}
	return (nb);
}

static unsigned int		before_unsigned(unsigned int nb, int len, t_format f)
{
	if (f.wi > len)
	{
		if (!ft_format('-', f.fl))
		{
			if (!ft_format('0', f.fl) || f.pr > 0)
				ft_time(' ', f.wi - len);
			else if (ft_format('0', f.fl) && f.pr < 0)
			{
				nb = sign_unsigned(nb);
				ft_time('0', f.wi - len);
			}
		}
		else if (ft_format('-', f.fl))
		{
			if (ft_format('0', f.fl) && f.pr <= 0)
			{
				nb = sign_unsigned(nb);
				ft_time('0', f.wi - len);
			}
		}
	}
	return (nb);
}

int						dsp_unsigned(t_format f, unsigned int nb, char *base)
{
	int		len;

	len = 0;
	len += ft_size_unsigned(nb, base, f);
	nb = before_unsigned(nb, len, f);
	ft_print_unsigned(nb, base, f);
	if (f.wi > len)
	{
		if (ft_format('-', f.fl))
			ft_time(' ', f.wi - len);
		len += (f.wi - len);
	}
	return (len);
}
