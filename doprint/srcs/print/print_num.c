/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 07:23:57 by gsharony          #+#    #+#             */
/*   Updated: 2020/02/04 13:12:25 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doprint.h"

static void		print_u(t_info *info, char **prefix, char **p, char *digits)
{
	int		i;

	if (info->print.truncate)
		info->print.u = (long)((int)(info->print.u));
	if (info->print.u != 0 && info->print.altfmt)
	{
		if (info->print.base == 8)
			*(prefix) = "0";
		else if (info->print.base == 16)
			*(prefix) = "0x";
	}
	if (info->print.prec == -1 || info->print.prec > 0)
	{
		i = (info->print.u % info->print.base) + info->print.capitals;
		*(*p)-- = digits[i];
		info->print.u /= info->print.base;
		info->i++;
	}
	while (info->print.u != 0)
	{
		i = (info->print.u % info->print.base) + info->print.capitals;
		*(*p)-- = digits[i];
		info->print.u /= info->print.base;
		info->i++;
	}
}

static void		print_p(t_info *info, char **prefix, char **p, char *c)
{
	if (info->print.length > 0 && info->print.prec > 0)
		info->print.length = ft_pos(info->print.length - info->print.prec);
	if (info->print.padc == ' ' && !info->print.ladjust)
		while (--info->print.length >= 0)
		{
			info->i++;
			ft_putchar(' ');
		}
	if (info->print.sign_char)
		ft_putchar(info->print.sign_char);
	if (*prefix)
		while (*(*prefix))
			ft_putchar(*(*prefix)++);
	if (info->print.padc == '0')
		while (--info->print.length >= 0 && info->i++)
			ft_putchar('0');
	if (info->print.prec > 0)
		while (--info->print.prec >= 0 && info->i++)
			ft_putchar('0');
	while (++(*p) != c)
		ft_putchar(*(*p));
	if (info->print.ladjust)
		while (--info->print.length >= 0 && info->i++)
			ft_putchar(' ');
}

static void		get_length(t_info *info, char **prefix)
{
	if (info->print.sign_char)
	{
		info->print.length--;
		info->i++;
	}
	if (*prefix)
		info->print.length -= ft_strlen(*prefix);
}

void			print_num(t_info *info, va_list *argp)
{
	char			buf[MAXBUF];
	char			*p;
	char			*prefix;
	static char		*digits;

	p = &buf[MAXBUF - 1];
	prefix = 0;
	digits = ft_strdup("0123456789abcdef0123456789ABCDEF");
	print_u(info, &prefix, &p, digits);
	info->print.prec = info->print.prec - info->i;
	info->print.length -= (&buf[MAXBUF - 1] - p);
	get_length(info, &prefix);
	print_p(info, &prefix, &p, &buf[MAXBUF]);
	free(digits);
}
