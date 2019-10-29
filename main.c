/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 10:20:28 by gsharony          #+#    #+#             */
/*   Updated: 2019/10/29 09:41:56 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	int				a;
	unsigned int	b;

	a = -42;
	b = a;
	ft_printf("String--------|%s|\n", "Misdle");
	ft_printf("Character-----|%c|\n", 'a');
	ft_printf("Number--------|%d|\n", 42);
	ft_printf("Octet---------|%i|\n", 042);
	ft_printf("Hexa----------|%i|\n", 0x125);
	ft_printf("Adresse-------|%p|\n", &a);
	ft_printf("Unsigned int--|%u|\n", -456);
	return (0);
}
