/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsp_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 11:36:30 by gsharony          #+#    #+#             */
/*   Updated: 2019/10/31 11:56:04 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dsp_char(t_format f, int c)
{
	if (f.pr[0] == 1)
	{
		f.pr[0] = 0;
		f.pr[1] = 0;
	}
	write(1, &c, 1);
}

void	dsp_str(t_format f, char *str)
{
	size_t	a;

	if (f.pr[0] == 1)
	{
		if (f.pr[1] < 0)
		{
			ft_putstr(str);
			return ;
		}
		else if (f.pr[1] == 0)
			return ;
		else
		{
			a = 0;
			while (str[a] && a < ft_strlen(str))
				write(1, &str[a++], 1);
			return ;
		}
	}
	ft_putstr(str);
}
