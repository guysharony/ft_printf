/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsp_adress.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 11:57:19 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/09 14:09:02 by guysharon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		dsp_adress(t_format f, void *str)
{
	int		a;

	f.wi -= ft_nbrlen((long long)str, 16) + 2;
	if (!ft_format('-', f.fl))
		ft_time(' ', f.wi);
	a = ft_print_adress(str);
	if (ft_format('-', f.fl))
		ft_time(' ', f.wi);
	if (f.wi > 0)
		return (f.wi + a);
	return (a);
}
