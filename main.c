/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 10:20:28 by gsharony          #+#    #+#             */
/*   Updated: 2019/10/31 16:05:47 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int a;

	a = -42;
	printf("\n___ Testing [simple output] ___\n");
	ft_printf("Display 1p----|%%|\n");
	ft_printf("Display 2p----|%%%%|\n");
	ft_printf("Display 3p----|%%%%%%|\n");
	printf("\n___ Testing [only formats] ___\n");
	ft_printf("String--------|%s|\n", "Middle");
	ft_printf("Character-----|%c|\n", 'a');
	ft_printf("Number--------|%d|\n", 42);
	ft_printf("Octet---------|%i|\n", 042);
	ft_printf("Hexa----------|%i|\n", 0x125);
	ft_printf("Adresse-------|%p|\n", &a);
	ft_printf("Unsigned int--|%u|\n", -456);
	ft_printf("Unsigned hex--|%x|\n", 450);
	ft_printf("Unsigned HEX--|%X|\n", 450);
	ft_printf("\n___ Testing [formats with flags] ___\n");
	ft_printf("Number flag---|%-+508.10d|\n", -42);
	ft_printf("|%%+508.10d|--|%+508.10d|\n", -42);
	return (0);
}
