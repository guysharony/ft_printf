/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsp_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 11:36:30 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/11 08:23:45 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

int				dsp_char(t_format f, int c)
{
	int		len;

	len = 0;
	len += ft_size_char(c, f);
	if (f.wi > len)
	{
		if (!ft_format('-', f.fl) && !ft_format('0', f.fl))
			ft_time(' ', f.wi - len);
		else if (!ft_format('-', f.fl) && ft_format('0', f.fl))
			ft_time('0', f.wi - len);
	}
	printf("[%d] - [%d] - [%d] - [%s]\n", f.wi, f.pr, len, f.fl);
	ft_print_char(c, f);
	if (f.wi > len)
	{
		if (ft_format('-', f.fl))
			ft_time(' ', f.wi - len);
		len += (f.wi - len);
	}
	return (len);
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
