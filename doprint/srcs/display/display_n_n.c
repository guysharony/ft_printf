/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_n_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 08:57:15 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/31 11:22:44 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doprint.h"

void	display_n_n(t_info *info, va_list *argp)
{
	if (info->c == 'n')
		info->print.truncate = 0;
	info->print.base = 16;
	print_unsigned(info, argp);
}
