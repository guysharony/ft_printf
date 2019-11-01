/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsp_adress.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 11:57:19 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/01 10:59:27 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	dsp_adress(t_format f, void *str)
{
	if (f.pr >= 0)
		return ;
	f.wi -= ft_nbrlen((long long)str, 16) + 2;
	if (!str)
		f.wi -= 1;
	if (!ft_format('-', f.fl))
		ft_time(' ', f.wi);
	ft_print_adress(str);
	if (ft_format('-', f.fl))
		ft_time(' ', f.wi);
}
