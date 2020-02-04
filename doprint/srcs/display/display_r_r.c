/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_r_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 08:50:33 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/31 11:23:36 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doprint.h"

void	display_r_r(t_info *info, va_list *argp)
{
	if (info->c == 'r')
		info->print.truncate = 0;
	info->print.base = 16;
	print_signed(info, argp);
}
