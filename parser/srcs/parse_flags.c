/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:52:01 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/29 07:45:35 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

int			parse_flags(t_print *print, char c)
{
	if (ft_includes(c, "#-+ "))
	{
		if (c == '#')
			print->altfmt = 1;
		else if (c == '-')
			print->ladjust = 1;
		else if (c == '+')
			print->plus_sign = '+';
		else if (c == ' ')
		{
			if (print->plus_sign == 0)
				print->plus_sign = ' ';
		}
		return (1);
	}
	return (0);
}
