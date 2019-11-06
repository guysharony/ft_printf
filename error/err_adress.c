/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_adress.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 09:15:26 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/06 09:59:03 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		err_adress(t_format f, void *p)
{
	(void)p;
	if (ft_format('+', f.fl) || ft_format('0', f.fl) || ft_format(' ', f.fl))
		return (1);
	if (ft_format('#', f.fl) || f.pr >= 0)
		return (1);
	if (ft_format(' ', f.fl) && ft_format('+', f.fl))
		return (1);
	if (ft_format('0', f.fl) && ft_format('-', f.fl))
		return (1);
	return (0);
}
