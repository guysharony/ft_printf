/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doprint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 10:27:39 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/31 11:40:21 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/doprint.h"

int		doprint(const char *fmt, va_list *listp)
{
	t_info		info;
	char		c;
	int			i;

	i = 0;
	while ((c = *fmt) != '\0')
	{
		if (c != '%')
		{
			ft_putchar(c);
			fmt++;
			i++;
			continue;
		}
		fmt++;
		info = display(parse(c, fmt, listp), listp);
		i += info.i;
		c = info.c;
		fmt = info.fmt;
	}
	return (i);
}
