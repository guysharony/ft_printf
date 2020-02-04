/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_o_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 08:53:44 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/31 11:23:01 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doprint.h"

void	display_o_o(t_info *info, va_list *argp)
{
	if (info->c == 'o')
		info->print.truncate = 0;
	info->print.base = 8;
	print_unsigned(info, argp);
}
