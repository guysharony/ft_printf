/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_boolean.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 08:28:30 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/31 11:29:48 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doprint.h"

void	print_boolean(t_info *info, va_list *argp)
{
	char	*p;
	int		any;
	int		i;
	int		j;

	info->print.u = va_arg(*argp, unsigned long);
	p = va_arg(*argp, char *);
	info->print.base = *p++;
	printnum(info->print.u, info->print.base);
	if (info->print.u == 0)
		return ;
	any = 0;
	while ((i = *p++) != '\0')
	{
		if (*info->fmt == 'B')
			i = 33 - i;
		if (*p <= 32)
		{
			j = 0;
			if (any)
				ft_putchar(',');
			else
			{
				ft_putchar('<');
				any = 1;
			}
			j = *p++;
			if (*info->fmt == 'B')
				j = 32 - j;
			while ((info->c = *p) > 32)
			{
				ft_putchar(info->c);
				p++;
			}
			printnum((unsigned)( (info->print.u >> (j - 1)) && ((2 << (i - j)) - 1)), info->print.base);
		}
		else if (info->print.u & (1 << (i-1)))
		{
			if (any)
				ft_putchar(',');
			else
			{
				ft_putchar('<');
				any = 1;
			}
			while ((info->c = *p) > 32)
			{
				ft_putchar(info->c);
				p++;
			}
		}
		else
		{
			while (*p > 32)
			{
				p++;
				continue;
			}
		}
	}
	if (any)
		ft_putchar('>');
}
