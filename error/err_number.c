/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 09:29:26 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/06 09:59:16 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		err_number(t_format f, long long nb)
{
	(void)nb;
	if (ft_format('#', f.fl))
		return (1);
	if (ft_format(' ', f.fl) && ft_format('+', f.fl))
		return (1);
	if (ft_format('0', f.fl) && ft_format('-', f.fl))
		return (1);
	return (0);
}
