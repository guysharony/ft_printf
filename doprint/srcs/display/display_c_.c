/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_c_.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 08:51:50 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/31 11:22:07 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doprint.h"

void	display_c_(t_info *info, va_list *argp)
{
	info->c = va_arg(*argp, int);
	ft_putchar(info->c);
}
