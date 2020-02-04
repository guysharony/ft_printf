/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:48:20 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/31 09:38:17 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/parser.h"

t_info		parse(char c, const char *fmt, va_list *argp)
{
	t_print		print;
	t_info		info;

	print = print_init();
	while (1)
	{
		c = *fmt;
		if (!parse_flags(&print, c))
			break ;
		fmt++;
	}
	parse_padding(&print, &fmt, &c);
	parse_width(&print, &fmt, argp, &c);
	parse_precision(&print, &fmt, argp, &c);
	parse_long(&print, &fmt, &c);
	print.truncate = 0;
	print.capitals = 0;
	info = info_init(c, fmt, print);
	return (info);
}
