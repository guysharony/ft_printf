/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_z_.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 08:45:39 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/31 11:24:07 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doprint.h"

void	display_z_(t_info *info, va_list *argp)
{
	info->print.truncate = 0;
	info->print.base = 16;
	print_signed(info, argp);
}
