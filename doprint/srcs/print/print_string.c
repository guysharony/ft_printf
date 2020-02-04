/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 07:59:42 by gsharony          #+#    #+#             */
/*   Updated: 2020/02/04 13:13:51 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doprint.h"

static void		print_pb(t_info *info, int f, char **p, char **p2)
{
	if (info->print.length > 0 && !info->print.ladjust)
	{
		info->print.n = 0;
		if (f == 1)
			free(*p);
		*p2 = *p;
		while (*(*p) != '\0' && info->print.n < info->print.prec)
		{
			info->print.n++;
			(*p)++;
		}
		*p = *p2;
		while (info->print.n < info->print.length)
		{
			ft_putchar(' ');
			info->print.n++;
			info->i++;
		}
	}
	if (f == 1 && info->print.length)
		free(*p);
}

static void		print_st(t_info *info, char **p)
{
	info->print.n = 0;
	while (*(*p) != '\0')
	{
		if (++info->print.n > info->print.prec)
			break ;
		ft_putchar(*(*p)++);
		info->i++;
	}
}

static void		print_pa(t_info *info)
{
	if (info->print.n < info->print.length && info->print.ladjust)
	{
		while (info->print.n < info->print.length)
		{
			ft_putchar(' ');
			info->print.n++;
			info->i++;
		}
	}
}

void			print_string(t_info *info, va_list *argp)
{
	char	*p;
	char	*p2;
	int		f;

	f = 0;
	if (info->print.prec == -1)
		info->print.prec = 0x7fffffff;
	p = va_arg(*argp, char *);
	if (p == (char *)0)
	{
		p = ft_strdup("(null)");
		f = 1;
	}
	print_pb(info, f, &p, &p2);
	print_st(info, &p);
	print_pa(info);
}
