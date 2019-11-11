/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsp_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 11:36:30 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/11 07:06:21 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int				dsp_char(t_format f, int c)
{
	int		a;

	a = f.wi - 1;
	if (f.pr > 0 && f.wi > 0 && f.pr < f.wi && !ft_format('0', f.fl))
		a = f.pr - 1;
	if (!ft_format('-', f.fl))
	{
		if (ft_format('0', f.fl))
			ft_time('0', a);
		else
			ft_time(' ', a);
	}
	write(1, &c, 1);
	if (ft_format('-', f.fl))
		ft_time(' ', a);
	if (a > 0)
		return (a + 1);
	return (1);
}

int				dsp_str(t_format f, char *str)
{
	int		len;

	len = 0;
	len += ft_size_string(str, f);
	if (f.wi > len)
	{
		if (!ft_format('-', f.fl) && (!ft_format('0', f.fl) || f.pr > 0))
			ft_time(' ', f.wi - len);
		else if (!ft_format('-', f.fl) && ft_format('0', f.fl) && f.pr < 0)
			ft_time('0', f.wi - len);
	}
	ft_print_string(str, f);
	if (f.wi > len)
	{
		if (ft_format('-', f.fl))
			ft_time(' ', f.wi - len);
		len += (f.wi - len);
	}
	return (len);
}
