/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsp_number_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 07:15:11 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/10 22:06:35 by guysharon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_size_number(long long nb, t_format f)
{
	int		len;
	int		tmp;

	len = 0;
	tmp = 0;
	if (f.pr < 0)
		len += ft_nbrlen(nb, 10);
	else if (f.pr == 0 && nb != 0)
		len += ft_nbrlen(nb, 10);
	else if (f.pr > 0)
	{
		tmp = f.pr - ft_nbrlen(nb, 10);
		len += ft_nbrlen(nb, 10);
	}
	if (tmp > 0)
		len += tmp;
	if (nb < 0)
		return (len + 1);
	return (len);
}

void	ft_print_number(long long nb, t_format f)
{
	if (f.pr < 0)
		ft_putnbr_base(nb, "0123456789");
	else if (f.pr == 0 && nb != 0)
		ft_putnbr_base(nb, "0123456789");
	else if (f.pr > 0)
	{
		if (nb < 0)
		{
			nb *= -1;
			write(1, "-", 1);
		}
		ft_time('0', f.pr - ft_nbrlen(nb, 10));
		ft_putnbr_base(nb, "0123456789");
	}
}
