/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsp_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 11:36:30 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/01 13:06:40 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int		ft_space(t_format f, char *str)
{
	if (f.pr > 0 && (f.pr < (int)ft_strlen(str) || f.pr < f.wi))
		return (f.wi - f.pr);
	return (f.wi - ft_strlen(str));
}

static int		ft_string(t_format f, char *str)
{
	if (f.pr < 0)
		return (ft_strlen(str));
	return (f.pr);
}

void			dsp_char(t_format f, int c)
{
	int		a;

	a = f.wi - 1;
	if (!ft_format('-', f.fl))
		ft_time(' ', a);
	write(1, &c, 1);
	if (ft_format('-', f.fl))
		ft_time(' ', a);
}

void			dsp_str(t_format f, char *str)
{
	int		a;
	int		b;

	a = ft_space(f, str);
	b = ft_string(f, str);
	if (!ft_format('-', f.fl))
		ft_time(' ', a);
	ft_putnstr(str, b);
	if (ft_format('-', f.fl))
		ft_time(' ', a);
}
