/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsp_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 11:36:30 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/01 12:47:49 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

static void		print_flags(t_format f, char *str)
{
	int		a;

	if (f.pr > 0 && (f.pr < (int)ft_strlen(str) || f.pr < f.wi))
		a = f.wi - f.pr;
	else if (f.pr <= 0 || f.pr > f.wi)
		a = f.wi - ft_strlen(str);
	if (!ft_format('-', f.fl))
		ft_time(' ', a);
	if (f.pr < 0)
		ft_putnstr(str, ft_strlen(str));
	else
		ft_putnstr(str, f.pr);
	if (ft_format('-', f.fl))
		ft_time(' ', a);
}

void	dsp_char(t_format f, int c)
{
	if (f.pr >= 0)
		f.pr = -1;
	f.wi--;
	if (!ft_format('-', f.fl))
		ft_time(' ', f.wi);
	write(1, &c, 1);
	if (ft_format('-', f.fl))
		ft_time(' ', f.wi);
}

void	dsp_str(t_format f, char *str)
{
	print_flags(f, str);
}
