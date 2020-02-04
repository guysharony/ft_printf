/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_p_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 08:55:32 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/31 11:24:55 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doprint.h"

void	display_p_x(t_info *info, va_list *argp)
{
	if (info->c == 'p')
		info->print.altfmt = 1;
	info->print.truncate = 0;
	info->print.base = 16;
	print_unsigned(info, argp);
}
