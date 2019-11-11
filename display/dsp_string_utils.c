/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsp_string_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 06:50:47 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/11 07:10:29 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_size_string(char *str, t_format f)
{
	int		len;
	int		tmp;

	len = 0;
	tmp = 0;
	if (f.pr < 0)
		len += (int)ft_strlen(str);
	else if (f.pr > 0)
	{
		len += (int)ft_strlen(str);
		if (f.pr < (int)ft_strlen(str))
			len -= f.pr;
	}
	return (len);
}

void	ft_print_string(char *str, t_format f)
{
	if (f.pr < 0)
		ft_putstr(str);
	else if (f.pr > 0)
	{
		if (f.pr < (int)ft_strlen(str))
			ft_putnstr(str, f.pr);
		else
			ft_putstr(str);
	}
}

int		ft_size_char(char c, t_format f)
{
	int		len;

	(void)c;
	len = 0;
	if (f.pr < 0)
		len++;
	else if (f.pr == 0)
		len++;
	else if (f.pr > 0)
		len++;
	return (len);
}

void	ft_print_char(char c, t_format f)
{
	if (f.pr < 0)
		write(1, &c, 1);
	else if (f.pr == 0)
		write(1, &c, 1);
	else if (f.pr > 0)
		write(1, &c, 1);
}
