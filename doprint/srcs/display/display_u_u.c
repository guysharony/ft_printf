/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_u_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 08:54:40 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/31 11:23:53 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doprint.h"

void	display_u_u(t_info *info, va_list *argp)
{
	if (info->c == 'u')
		info->print.truncate = 0;
	info->print.base = 10;
	print_unsigned(info, argp);
}
