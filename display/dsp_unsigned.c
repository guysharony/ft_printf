/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsp_unsigned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:57:46 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/10 21:39:29 by guysharon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		dsp_unsigned(t_format f, unsigned int nb, char *base)
{
	int		len;

	len = 0;
	len += ft_size_unsigned(nb, base, f);
	if (f.wi > len)
	{
		if (!ft_format('-', f.fl) && (!ft_format('0', f.fl) || f.pr >= 0))
			ft_time(' ', f.wi - len);
	}
	ft_print_unsigned(nb, base, f);
	if (f.wi > len)
	{
		if (ft_format('-', f.fl))
			ft_time(' ', f.wi - len);
		else if (ft_format('0', f.fl) && f.pr < 0)
			ft_time('0', f.wi - len);
		len += (f.wi - len);
	}
	return (len);
}
