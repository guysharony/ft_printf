/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display__x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 08:56:28 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/31 11:21:14 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doprint.h"

void	display__x(t_info *info, va_list *argp)
{
	info->print.base = 16;
	info->print.capitals = 16;
	print_unsigned(info, argp);
}
