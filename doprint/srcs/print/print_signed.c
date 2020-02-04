/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 07:11:47 by gsharony          #+#    #+#             */
/*   Updated: 2020/02/01 19:39:57 by guysharon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doprint.h"

void	print_signed(t_info *info, va_list *argp)
{
	info->print.n = va_arg(*argp, int);
	if (info->print.n >= 0)
	{
		info->print.u = info->print.n;
		info->print.sign_char = info->print.plus_sign;
	}
	else
	{
		info->print.u = -info->print.n;
		info->print.sign_char = '-';
	}
	print_num(info, argp);
}
