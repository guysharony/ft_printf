/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsp_adress.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 11:57:19 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/10 21:27:46 by guysharon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		dsp_adress(t_format f, void *str)
{
	int		len;

	len = 0;
	len += ft_size_adress(str, f);
	if (f.wi > len)
	{
		if (!ft_format('-', f.fl) && (!ft_format('0', f.fl) || f.pr >= 0))
			ft_time(' ', f.wi - len);
	}
	ft_print_adress(str, f);
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
