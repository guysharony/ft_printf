/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 08:42:34 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/31 09:30:39 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doprint.h"

void	printnum(unsigned int u, int base)
{
	char	buf[MAXBUF];
	char	*p;
	char	*digits;

	p = &buf[MAXBUF - 1];
	digits = ft_strdup("0123456789abcdef");
	while (u != 0)
	{
		*p-- = digits[u % base];
		u /= base;
	}
	while (++p != &buf[MAXBUF])
		ft_putchar(*p);
}
