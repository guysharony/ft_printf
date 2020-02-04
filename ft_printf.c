/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 10:22:52 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/31 11:05:07 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_printf(const char *fmt, ...)
{
	va_list		listp;
	int			size;

	va_start(listp, fmt);
	size = doprint(fmt, &listp);
	va_end(listp);
	return (size);
}
