/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsp_adress.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 11:57:19 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/09 21:05:54 by guysharon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_format		ft_var(t_format f, void *str)
{
	f.wi -= ft_nbrlen((long long)str, 16);
	f.pr -= ft_nbrlen((long long)str, 16);
	if (str == NULL)
	{
		f.wi++;
		f.pr++;
	}
	if (f.pr > 0)
		f.wi -= f.pr + 2;
	return (f);
}

int				dsp_adress(t_format f, void *str)
{
	int		a;

	f = ft_var(f, str);
	if (!ft_format('-', f.fl))
	{
		ft_time(' ', f.wi);
		if (str == NULL)
			write(1, "0x", 2);
		ft_time('0', f.pr);
	}
	a = ft_print_adress(str);
	if (ft_format('-', f.fl))
	{
		if (str == NULL)
			write(1, "0x", 2);
		ft_time('0', f.pr);
		ft_time(' ', f.wi);
	}
	if (f.wi > 0)
		return (f.wi + a);
	return (a);
}
