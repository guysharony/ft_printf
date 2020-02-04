/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 08:37:59 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/31 11:38:04 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/doprint.h"

void		display_address(t_info *info, va_list *argp)
{
	display_p_x(info, argp);
}

void		display_number(t_info *info, va_list *argp)
{
	if (info->c == 'd' || info->c == 'D')
		display_d_d(info, argp);
	else if (info->c == 'z')
		display_z_(info, argp);
	else if (info->c == 'Z')
		display__z(info, argp);
	else if (info->c == 'r' || info->c == 'R')
		display_r_r(info, argp);
	else if (info->c == 'o' || info->c == 'O')
		display_o_o(info, argp);
	else if (info->c == 'u' || info->c == 'U')
		display_u_u(info, argp);
	else if (info->c == 'x')
		display_p_x(info, argp);
	else if (info->c == 'X')
		display__x(info, argp);
	else if (info->c == 'n' || info->c == 'N')
		display_n_n(info, argp);
}

void		display_string(t_info *info, va_list *argp)
{
	if (info->c == 'c')
		display_c_(info, argp);
	else if (info->c == 's')
		print_string(info, argp);
}

void		display_boolean(t_info *info, va_list *argp)
{
	print_boolean(info, argp);
}

t_info		display(t_info info, va_list *argp)
{
	if (ft_includes(info.c, "p"))
		display_address(&info, argp);
	else if (ft_includes(info.c, "dzrouxnDZROUXN"))
		display_number(&info, argp);
	else if (ft_includes(info.c, "cs"))
		display_string(&info, argp);
	else if (ft_includes(info.c, "bB"))
		display_boolean(&info, argp);
	else if (info.c == '\0')
		info.fmt--;
	else
		ft_putchar(info.c);
	info.fmt++;
	return (info);
}
