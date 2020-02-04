/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:51:36 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/31 09:44:20 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

void		parse_width(t_print *print,
		const char **fmt, va_list *argp, char *c)
{
	if (ft_isdigit(*c))
	{
		while (ft_isdigit(*c))
		{
			print->length = 10 * print->length + ft_ctod(*c);
			*c = *++(*fmt);
		}
	}
	else if (*c == '*')
	{
		print->length = va_arg(*argp, int);
		*c = *++(*fmt);
		if (print->length < 0)
		{
			print->ladjust = !print->ladjust;
			print->length = -print->length;
		}
	}
}
