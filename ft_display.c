/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:23:09 by gsharony          #+#    #+#             */
/*   Updated: 2019/10/28 15:55:52 by guysharon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str)
{
	int		a;

	a = 0;
	if (!str)
		return ;
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
