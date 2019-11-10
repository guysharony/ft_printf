/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adress.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:09:56 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/10 13:24:33 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

int		ft_print_adress(void *a, t_format f)
{
	int		len;

	len = ft_nbrlen((long long)a, 16);
	if (f.pr > len)
		ft_time('0', f.pr - len);
	else if (f.wi > 0)
	{
		if (ft_format('0', f.fl))
		{
			if (f.pr > f.wi)
				ft_time('0', f.wi - len);
			else if (f.pr < 0 && !ft_format('-', f.fl))
				ft_time('0', f.wi - len);
		}
	}
	if (f.pr > f.wi && f.wi > 0)
		ft_time('0', f.pr);
	if (!(f.pr == 0 && a == NULL))
		ft_putnbr_base((long long)a, "0123456789abcdef");
	return (len);
}
