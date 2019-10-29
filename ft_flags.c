/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 07:42:01 by gsharony          #+#    #+#             */
/*   Updated: 2019/10/29 09:43:39 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	fl_init(void)
{
	t_format f;

	f.left = 0;
	f.zero = 0;
	f.val = 'a';
	f.pr[0] = 0;
	f.pr[1] = 0;
	return (f);
}

int			ft_flags(const char *format, va_list list)
{
	t_format	f;
	int			a;

	a = 0;
	f = fl_init();
	while (format[a] != '\0' && !ft_isalpha(format[a]))
	{
		if (format[a] == '-')
			f.left = 1;
		if (format[a] == '0')
			f.zero = 1;
		if (format[a] == '.')
		{
			f.pr[0] = 1;
			a++;
			if (format[a++] == '*')
			{
				f.pr[1] = (int)va_arg(list, int);
				a--;
			}
		}
		a++;
	}
	f.val = format[a];
	ft_argument(f, list);
	return (a);
}
