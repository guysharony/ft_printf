/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsp_adress_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 08:29:52 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/11 08:29:57 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_size_adress(void *a, t_format f)
{
	int		len;
	int		tmp;

	len = 2;
	tmp = 0;
	if (f.pr < 0)
		len += ft_nbrlen((long long)a, 16);
	else if (f.pr == 0)
	{
		if (a != NULL)
			len += ft_nbrlen((long long)a, 16);
	}
	else if (f.pr > 0)
	{
		tmp = f.pr - ft_nbrlen((long long)a, 16);
		len += ft_nbrlen((long long)a, 16);
	}
	if (tmp > 0)
		len += tmp;
	return (len);
}

void	ft_print_adress(void *a, t_format f)
{
	write(1, "0x", 2);
	if (f.pr < 0)
		ft_putnbr_base((long long)a, "0123456789abcdef");
	else if (f.pr == 0)
	{
		if (a != NULL)
			ft_putnbr_base((long long)a, "0123456789abcdef");
	}
	else if (f.pr > 0)
	{
		ft_time('0', f.pr - ft_nbrlen((long long)a, 16));
		ft_putnbr_base((long long)a, "0123456789abcdef");
	}
}
