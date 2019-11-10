/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsp_adress.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 11:57:19 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/10 04:06:36 by guysharon        ###   ########.fr       */
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
		f.wi -= f.pr;
	if (str != NULL || f.wi > 0)
		f.wi -= 2;
	return (f);
}

void			ft_print_after(void *str, t_format f)
{
	if (ft_format('-', f.fl) || (ft_format('0', f.fl) && str == NULL && f.pr < 0))
	{
		if (str == NULL)
			write(1, "0x", 2);
		if (ft_format('0', f.fl) && f.pr < 0 && str == NULL)
			ft_time('0', f.wi);
		else
		{
			ft_time('0', f.pr);
			ft_time(' ', f.wi);
		}
	}
}

int				dsp_adress(t_format f, void *str)
{
	int		a;

	if (f.pr >= 0 || f.wi >= 0)
		f = ft_var(f, str);
	if (!ft_format('-', f.fl) && f.pr >= 0)
	{
		ft_time(' ', f.wi);
		if (str == NULL)
			write(1, "0x", 2);
		ft_time('0', f.pr);
	}
	if (str != NULL || (str == NULL && f.pr == -1 && f.wi == -1))
		a = ft_print_adress(str);
	ft_print_after(str, f);
	if (f.wi > 0)
		return (f.wi + a);
	return (a);
}
