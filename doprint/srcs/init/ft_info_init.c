/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 07:31:49 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/31 11:37:45 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doprint.h"

t_info		info_init(char c, const char *fmt, t_print print)
{
	t_info	info;

	info.i = 0;
	info.c = c;
	info.fmt = fmt;
	info.print = print;
	return (info);
}
