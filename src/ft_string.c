/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:23:09 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/01 09:09:52 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putnstr(char *str, int len)
{
	int		a;

	a = 0;
	if (!str)
	{
		if (len <= 6 && len >= 0)
			write(1, "(null)", len);
		else if (len < 0)
			write(1, "(null)", 0);
		else
			write(1, "(null)", 6);
		return ;
	}
	while (str[a])
	{
		write(1, &str[a], 1);
		a++;
	}
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
