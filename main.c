/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 10:20:28 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/01 11:25:39 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int		a;
	int		b;

	a = -42;
	printf("\n___ Testing [simple output] ___\n");
	ft_printf(">---|%%|\n");
	printf("<---|%%|\n");
	ft_printf(">---|%%%%|\n");
	printf("<---|%%%%|\n");

	printf("\n___ Testing [%%c] ___ \n");
	ft_printf(">---|%c|\n", 'a');
	printf("<---|%c|\n", 'a');
	ft_printf(">---|%c|\n", '\0');
	printf("<---|%c|\n", '\0');
	ft_printf(">---|%c|\n", (char)0xff11ff11);
	printf("<---|%c|\n", (char)0xff11ff11);
	ft_printf(">---|%c|\n", -21);
	printf("<---|%c|\n", -21);
	ft_printf(">---|%4c|\n", 'U');
	printf("<---|%4c|\n", 'U');
	ft_printf(">---|%-1c|\n", 12);
	printf("<---|%-1c|\n", 12);
	ft_printf(">---|%-12c|\n", '\n');
	printf("<---|%-12c|\n", '\n');
	ft_printf(">---|hello ca%----4c %1c va %10c%-c ??|\n", '\0', '\n', (char)564, 0);
	printf("<---|hello ca%----4c %1c va %10c%-c ??|\n", '\0', '\n', (char)564, 0);

	printf("\n___ Testing [%%s] ___\n");
	ft_printf(">---|%s|\n", NULL);
	printf("<---|%s|\n", NULL);
	ft_printf(">---|%s|\n", "coco");
	printf("<---|%s|\n", "coco");
	ft_printf(">---|%s|\n", "");
	printf("<---|%s|\n", "");
	ft_printf(">---|%.15s|\n", "coco");
	printf("<---|%.15s|\n", "coco");
	ft_printf(">---|%.5s|\n", "coco et titi");
	printf("<---|%.5s|\n", "coco et titi");
	ft_printf(">---|%.0s|\n", "coco et ti");
	printf("<---|%.0s|\n", "coco et ti");
	ft_printf(">---|%.s|\n", "coco");
	printf("<---|%.s|\n", "coco");
	ft_printf(">---|%.2s|\n", NULL);
	printf("<---|%.2s|\n", NULL);
	ft_printf(">---|%10s|\n", NULL);
	printf("<---|%10s|\n", NULL);
	ft_printf(">---|%-8s|\n", "coco");
	printf("<---|%-8s|\n", "coco");
	ft_printf(">---|%1s|\n", "hi");
	printf("<---|%1s|\n", "hi");
	ft_printf(">---|%-2s|\n", "");
	printf("<---|%-2s|\n", "");
	ft_printf(">---|Coucou %.0s\n%s%---12s|\n", "hi", "coco", NULL);
	printf("<---|Coucou %.0s\n%s%---12s|\n", "hi", "coco", NULL);
	ft_printf(">---|u%4.2ss %-1.s\n %---5.3s|\n", "coco", NULL, "yooo");
	printf("<---|u%4.2ss %-1.s\n %---5.3s|\n", "coco", NULL, "yooo");
	ft_printf(">---|%1.4s et %-6.8s et %4.2s|\n", "tuuu", "12345", "hu");
	printf("<---|%1.4s et %-6.8s et %4.2s|\n", "tuuu", "12345", "hu");

	printf("\n___ Testing [%%p] ___\n");
	ft_printf(">---|%p|\n", NULL);
	printf("<---|%p|\n", NULL);
	ft_printf(">---|%p|\n", &a);
	printf("<---|%p|\n", &a);
	ft_printf(">---|%20p|\n", &a);
	printf("<---|%20p|\n", &a);
	ft_printf(">---|%-25p|\n", &a);
	printf("<---|%-25p|\n", &a);
	ft_printf(">---|%2p|\n", &a);
	printf("<---|%2p|\n", &a);
	ft_printf(">---|%----24p et hello %2p %12p|\n", &b, &a, NULL);
	printf("<---|%----24p et hello %2p %12p|\n", &b, &a, NULL);

	printf("\n___ Testing [%%d] ___\n");
	ft_printf(">---|%d|\n", 42);
	ft_printf(">---|%d|\n", -42);
	ft_printf(">---|%d|\n", 0);
	ft_printf(">---|%d|\n", 3);
	ft_printf(">---|%d|\n", -2147483647);
	ft_printf(">---|% d|\n", 0);
	ft_printf(">---|%+d|\n", 0);
	ft_printf(">---|%+++d|\n", 534);
	ft_printf(">---|% d|\n", 0xff11ff);
	ft_printf(">---|%.12d|\n", 1144);
	ft_printf(">---|%.d|\n", 0);
	ft_printf(">---|%-7d|\n", 7789);
	ft_printf(">---|%0d|\n", -579);
	ft_printf(">---|%04d|\n", 0);
	ft_printf(">---|%+12.5d|\n", 140);
	ft_printf(">---|%00+10.4d|\n", 0);
	ft_printf(">---|%.0d|\n", -21);
	ft_printf(">---|%.5d|\n", -421);
	ft_printf(">---|%5d|\n", -741);
	ft_printf(">---|hello % .d this is a test|\n", 0);

	printf("\n___ Testing [%%i] ___\n");
	ft_printf(">---|%i|\n", (signed int)0xff11);
	ft_printf(">---|%.2i|\n", -10);
	ft_printf(">---|%.i|\n", 44);
	ft_printf(">---|%08i|\n", -71);
	ft_printf(">---|%-2i|\n", -7);
	ft_printf(">---|%.0i|\n", 0);
	return (0);
}
