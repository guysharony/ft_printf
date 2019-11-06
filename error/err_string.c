/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 08:18:23 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/06 09:12:15 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		err_char(t_format f, int c)
{
	(void)c;
	if (f.pr >= 0 || ft_format('+', f.fl) || ft_format('0', f.fl))
		return (1);
	if (ft_format(' ', f.fl))
		return (1);
	return (0);
}

int		err_str(t_format f, char *str)
{
	(void)str;
	if (ft_format('+', f.fl) || ft_format('0', f.fl) || ft_format(' ', f.fl))
		return (1);
	if (ft_format('#', f.fl))
		return (1);
	if (ft_format(' ', f.fl) && ft_format('+', f.fl))
		return (1);
	if (ft_format('0', f.fl) && ft_format('-', f.fl))
		return (1);
	return (0);
}
