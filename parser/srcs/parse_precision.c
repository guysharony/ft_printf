/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:50:55 by gsharony          #+#    #+#             */
/*   Updated: 2020/02/02 10:14:33 by guysharon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

void		parse_precision(t_print *print,
		const char **fmt, va_list *argp, char *c)
{
	if (*c == '.')
	{
		*c = *++(*fmt);
		print->prec = 0;
		if (ft_isdigit(*c))
		{
			while (ft_isdigit(*c))
			{
				print->prec = 10 * print->prec + ft_ctod(*c);
				*c = *++(*fmt);
			}
		}
		else if (*c == '*')
		{
			print->prec = va_arg(*argp, int);
			*c = *++(*fmt);
		}
	}
}
