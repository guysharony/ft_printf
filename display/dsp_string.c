/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsp_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 11:36:30 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/01 09:11:52 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	dsp_char(t_format f, int c)
{
	if (f.pr >= 0)
		f.pr = -1;
	write(1, &c, 1);
}

void	dsp_str(t_format f, char *str)
{

	if (f.pr < 0)
	{
		ft_putstr(str);
		return ;
	}
	else if (f.pr == 0)
		return ;
	else
	{
		ft_putnstr(str, f.pr);
		return ;
	}
	ft_putstr(str);
}
