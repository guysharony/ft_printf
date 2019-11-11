/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:23:09 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/11 07:23:34 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_size_nstr(char *str, int len)
{
	int		a;

	a = 0;
	if (!str)
	{
		if (len <= 6 && len >= 0)
			return (len);
		return (6);
	}
	while (str[a] && len-- > 0)
		a++;
	return (a);
}

int		ft_putnstr(char *str, int len)
{
	int		a;

	a = 0;
	if (!str)
	{
		if (len <= 6 && len >= 0)
		{
			write(1, "(null)", len);
			return (len);
		}
		else
			write(1, "(null)", 6);
		return (6);
	}
	while (str[a] && len-- > 0)
	{
		write(1, &str[a], 1);
		a++;
	}
	return (a);
}

void	ft_putstr(char *str)
{
	int		a;

	a = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return ;
	}
	while (str[a] != '\0')
	{
		write(1, &str[a], 1);
		a++;
	}
}

void	ft_putchar(int c)
{
	char	a;

	a = (char)c;
	write(1, &a, 1);
}
