/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adress.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:09:56 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/10 03:56:09 by guysharon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_print_adress(void *a)
{
	int		len;

	len = 2;
	write(1, "0x", 2);
	ft_putnbr_base((long long)a, "0123456789abcdef");
	len += ft_nbrlen((long long)a, 16);
	return (len);
}
