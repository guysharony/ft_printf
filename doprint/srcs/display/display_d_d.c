/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_d_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 08:40:49 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/31 11:22:27 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doprint.h"

void	display_d_d(t_info *info, va_list *argp)
{
	if (info->c == 'd')
		info->print.truncate = 0;
	info->print.base = 10;
	print_signed(info, argp);
}
