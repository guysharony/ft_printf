/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 07:31:15 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/29 08:38:24 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doprint.h"

t_print		print_init(void)
{
	t_print		print;

	print.length = 0;
	print.prec = -1;
	print.ladjust = 0;
	print.padc = ' ';
	print.plus_sign = 0;
	print.sign_char = 0;
	print.altfmt = 0;
	print.truncate = 0;
	print.capitals = 0;
	print.base = 0;
	print.u = 0;
	print.n = 0;
	return (print);
}
