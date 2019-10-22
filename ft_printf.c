/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 09:08:04 by gsharony          #+#    #+#             */
/*   Updated: 2019/10/22 11:20:21 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include <stdarg.h>
#include <stdio.h>

size_t		dispInt(int value)
{
	if (value < 10)
	{
		putchar(0x30 + value);
		return (1);
	}
	size_t size = dispInt(value / 10);
	putchar(0x30 + value % 10);
	return (1 + size);
}

int			ft_printf(const char *str, ...)
{
	va_list		paramInfo;

	va_start(paramInfo, str);
	size_t		written = 0;
	char		current;

	while ((current = *str) != '\0')
	{
		str++;
		if (current != '%')
		{
			putchar(current);
			written++;
			continue;
		}
		switch (*str++)
		{
			case 'd':
				{
					int integer = (int)va_arg(paramInfo, int);
					written += dispInt(integer);
				}
				break;
			case 's':
				{
					const char * string = (const char *)va_arg(paramInfo, const char *);
					while (*string != '\0')
					{
						putchar(*string++);
						written++;
					}
				}
				break;
			default:
				fprintf(stderr, "Specified format is not supported!");
				abort();
		}
	}
	va_end(paramInfo);
	return (written);
}
