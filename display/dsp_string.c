/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsp_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 11:36:30 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/06 09:13:27 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int		ft_space(t_format f, char *str)
{
	int		len;

	len = f.wi;
	if (f.pr >= 0 && (f.pr < (int)ft_strlen(str) || f.pr < f.wi))
		len -= f.pr;
	else
		len -= ft_strlen(str);
	return (len);
}

static int		ft_string(t_format f, char *str)
{
	if (f.pr < 0)
		return (ft_strlen(str));
	return (f.pr);
}

int				dsp_char(t_format f, int c)
{
	int		a;

	if (err_char(f, c))
		return (-1);
	a = f.wi - 1;
	if (!ft_format('-', f.fl))
		ft_time(' ', a);
	write(1, &c, 1);
	if (ft_format('-', f.fl))
		ft_time(' ', a);
	if (a > 0)
		return (a + 1);
	return (1);
}

int				dsp_str(t_format f, char *str)
{
	int		a;
	int		b;
	int		len;

	if (err_str(f, str))
		return (-1);
	a = ft_space(f, str);
	b = ft_string(f, str);
	if (!ft_format('-', f.fl))
		ft_time(' ', a);
	len = ft_putnstr(str, b);
	if (ft_format('-', f.fl))
		ft_time(' ', a);
	if (a > 0)
		return (a + len);
	return (len);
}
