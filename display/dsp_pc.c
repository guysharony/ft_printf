/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsp_pc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 08:41:18 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/06 08:50:47 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		dsp_pc(t_format f)
{
	int		a;

	a = f.wi - 1;
	if (!ft_format('-', f.fl) && !ft_format('0', f.fl))
		ft_time(' ', a);
	else if (!ft_format('-', f.fl) && ft_format('0', f.fl))
		ft_time('0', a);
	write(1, "%", 1);
	if (ft_format('-', f.fl))
		ft_time(' ', a);
	if (a > 0)
		return (a + 1);
	return (1);
}
