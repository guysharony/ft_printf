/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display__z.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 08:48:46 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/31 11:21:39 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doprint.h"

void	display__z(t_info *info, va_list *argp)
{
	info->print.base = 16;
	info->print.capitals = 16;
	print_signed(info, argp);
}
