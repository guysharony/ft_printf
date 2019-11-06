/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_unsigned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 09:35:55 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/06 09:59:48 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		err_unsigned(t_format f, unsigned int nb)
{
	(void)nb;
	if (ft_format('#', f.fl) || ft_format('+', f.fl) || ft_format(' ', f.fl))
		return (1);
	if (ft_format(' ', f.fl) && ft_format('+', f.fl))
		return (1);
	if (ft_format('0', f.fl) && ft_format('-', f.fl))
		return (1);
	return (0);
}
