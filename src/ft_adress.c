/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adress.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:09:56 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/10 18:17:34 by guysharon        ###   ########.fr       */
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
