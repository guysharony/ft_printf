/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:50:28 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/29 07:45:58 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

void		parse_padding(t_print *print, const char **fmt, char *c)
{
	if (*c == '0')
	{
		print->padc = '0';
		*c = *++(*fmt);
	}
}
