/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsp_adress.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 11:57:19 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/10 12:59:58 by gsharony         ###   ########.fr       */
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

void			ft_after(void *str, t_format f)
{
	(void)str;
	if (ft_format('-', f.fl))
		ft_time(' ', f.wi);
}

void			ft_before(void *str, t_format f)
{
	(void)str;
	if (!ft_format('-', f.fl))
	{
		if (!ft_format('0', f.fl))
			ft_time(' ', f.wi);
		else if (ft_format('0', f.fl) && f.wi > f.pr && f.pr >= 0)
			ft_time(' ', f.wi);
	}
}

int				dsp_adress(t_format f, void *str)
{
	f = ft_var(f, str);
	ft_before(str, f);
	write(1, "0x", 2);
	ft_print_adress(str, f);
	ft_after(str, f);
	return (f.wi);
}
