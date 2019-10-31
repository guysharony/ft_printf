/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 07:42:01 by gsharony          #+#    #+#             */
/*   Updated: 2019/10/31 12:46:23 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static t_format		fl_init(void)
{
	t_format f;

	f.left = 0;
	f.zero = 0;
	f.val = 'a';
	f.pr[0] = 0;
	f.pr[1] = 0;
	return (f);
}

static void			ft_conv(t_format f, va_list list)
{
	if (f.val == 'd' || f.val == 'i')
		dsp_number(f, (long long)va_arg(list, int));
	else if (f.val == 'c')
		dsp_char(f, (int)va_arg(list, int));
	else if (f.val == 's')
		dsp_str(f, (char *)va_arg(list, char *));
	else if (f.val == 'p')
		dsp_adress(f, (void *)va_arg(list, void *));
	else if (f.val == 'u')
		dsp_unsigned(f, (unsigned int)va_arg(list, unsigned int));
}

char				*ft_flags(const char *format, va_list list)
{
	t_format		f;
	const char		*tmp;

	f = fl_init();
	tmp = format;
	while (*format != '\0' && !ft_isalpha(*format))
	{
		if (*format == '-')
			f.left = 1;
		if (*format == '0')
			f.zero = 1;
		if (*format == '.')
		{
			f.pr[0] = 1;
			format++;
			if (*format == '*')
				f.pr[1] = (int)va_arg(list, int);
			else if (*format >= '0' && *format <= '9')
				f.pr[1] = ft_atoi(format);
		}
		format++;
	}
	f.val = *format++; 
	ft_conv(f, list);
	return ((char *)format);
}
