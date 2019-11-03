/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 10:20:28 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/03 11:30:09 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int		a;
	int		b;
	int		c;
	int		d;

	a = -42;
	printf("\n___ Testing [simple output] ___\n");
	c = ft_printf(">---|%%|\n");
	d = printf("<---|%%|\n");
	printf("[%d] - [%d]\n\n", c, d);
	c = ft_printf(">---|%%%%|\n");
	d = printf("<---|%%%%|\n");
	printf("[%d] - [%d]\n\n", c, d);

	printf("\n___ Testing [%%c] ___ \n");
	c = ft_printf(">---|%c|\n", 'a');
	d = printf("<---|%c|\n", 'a');
	c = ft_printf(">---|%c|\n", '\0');
	d = printf("<---|%c|\n", '\0');
	c = ft_printf(">---|%c|\n", (char)0xff11ff11);
	d = printf("<---|%c|\n", (char)0xff11ff11);
	c = ft_printf(">---|%c|\n", -21);
	d = printf("<---|%c|\n", -21);
	c = ft_printf(">---|%4c|\n", 'U');
	d = printf("<---|%4c|\n", 'U');
	c = ft_printf(">---|%-1c|\n", 12);
	d = printf("<---|%-1c|\n", 12);
	c = ft_printf(">---|%-12c|\n", '\n');
	d = printf("<---|%-12c|\n", '\n');
	c = ft_printf(">---|hello ca%----4c %1c va %10c%-c ??|\n", '\0', '\n', (char)564, 0);
	d = printf("<---|hello ca%----4c %1c va %10c%-c ??|\n", '\0', '\n', (char)564, 0);

	printf("\n___ Testing [%%s] ___\n");
	c = ft_printf(">---|%s|\n", NULL);
	d = printf("<---|%s|\n", NULL);
	c = ft_printf(">---|%s|\n", "coco");
	d = printf("<---|%s|\n", "coco");
	c = ft_printf(">---|%s|\n", "");
	d = printf("<---|%s|\n", "");
	c = ft_printf(">---|%.15s|\n", "coco");
	d = printf("<---|%.15s|\n", "coco");
	c = ft_printf(">---|%.5s|\n", "coco et titi");
	d = printf("<---|%.5s|\n", "coco et titi");
	c = ft_printf(">---|%.0s|\n", "coco et ti");
	d = printf("<---|%.0s|\n", "coco et ti");
	c = ft_printf(">---|%.s|\n", "coco");
	d = printf("<---|%.s|\n", "coco");
	c = ft_printf(">---|%.2s|\n", NULL);
	d = printf("<---|%.2s|\n", NULL);
	c = ft_printf(">---|%10s|\n", NULL);
	d = printf("<---|%10s|\n", NULL);
	c = ft_printf(">---|%-8s|\n", "coco");
	d = printf("<---|%-8s|\n", "coco");
	c = ft_printf(">---|%1s|\n", "hi");
	d = printf("<---|%1s|\n", "hi");
	c = ft_printf(">---|%-2s|\n", "");
	d = printf("<---|%-2s|\n", "");
	c = ft_printf(">---|Coucou %.0s\n%s%---12s|\n", "hi", "coco", NULL);
	d = printf("<---|Coucou %.0s\n%s%---12s|\n", "hi", "coco", NULL);
	c = ft_printf(">---|u%4.2ss %-1.s\n %---5.3s|\n", "coco", NULL, "yooo");
	d = printf("<---|u%4.2ss %-1.s\n %---5.3s|\n", "coco", NULL, "yooo");
	c = ft_printf(">---|%1.4s et %-6.8s et %4.2s|\n", "tuuu", "12345", "hu");
	d = printf("<---|%1.4s et %-6.8s et %4.2s|\n", "tuuu", "12345", "hu");

	printf("\n___ Testing [%%p] ___\n");
	c = ft_printf(">---|%p|\n", NULL);
	d = printf("<---|%p|\n", NULL);
	c = ft_printf(">---|%p|\n", &a);
	d = printf("<---|%p|\n", &a);
	c = ft_printf(">---|%20p|\n", &a);
	d = printf("<---|%20p|\n", &a);
	c = ft_printf(">---|%-25p|\n", &a);
	d = printf("<---|%-25p|\n", &a);
	c = ft_printf(">---|%2p|\n", &a);
	d = printf("<---|%2p|\n", &a);
	c = ft_printf(">---|%----24p et hello %2p %12p|\n", &b, &a, NULL);
	d = printf("<---|%----24p et hello %2p %12p|\n", &b, &a, NULL);

	printf("\n___ Testing [%%d] ___\n");
	c = ft_printf(">---|%d|\n", 42);
	d = printf("<---|%d|\n", 42);
	c = ft_printf(">---|%d|\n", -42);
	d = printf("<---|%d|\n", -42);
	c = ft_printf(">---|%d|\n", 0);
	d = printf("<---|%d|\n", 0);
	c = ft_printf(">---|%d|\n", 3);
	d = printf("<---|%d|\n", 3);
	ft_printf(">---|%d|\n", -2147483647);
	printf("<---|%d|\n", -2147483647);
	ft_printf(">---|%d|\n", 0);
	printf("<---|%d|\n", 0);
	ft_printf(">---|%+d|\n", 0);
	printf("<---|%+d|\n", 0);
	ft_printf(">---|%+++d|\n", 534);
	printf("<---|%+++d|\n", 534);
	ft_printf(">---|% d|\n", 0xff11ff);
	printf("<---|% d|\n", 0xff11ff);
	ft_printf(">---|%.2d|\n", 1144);
	printf("<---|%.2d|\n", 1144);
	ft_printf(">---|%.d|\n", 0);
	printf("<---|%.d|\n", 0);
	ft_printf(">---|%-7d|\n", 7789);
	printf("<---|%-7d|\n", 7789);
	ft_printf(">---|%0d|\n", -579);
	printf("<---|%0d|\n", -579);
	ft_printf(">---|%04d|\n", 0);
	printf("<---|%04d|\n", 0);
	ft_printf(">---|%+12.5d|\n", 140);
	printf("<---|%+12.5d|\n", 140);
	ft_printf(">---|%00+10.4d|\n", 0);
	printf("<---|%00+10.4d|\n", 0);
	ft_printf(">---|%.0d|\n", -21);
	printf("<---|%.0d|\n", -21);
	ft_printf(">---|%.5d|\n", -421);
	printf("<---|%.5d|\n", -421);
	ft_printf(">---|%5d|\n", -741);
	printf("<---|%5d|\n", -741);
	ft_printf(">---|hello % .d this is a test|\n", 0);
	printf("<---|hello % .d this is a test|\n", 0);

	printf("\n___ Testing [%%i] ___\n");
	ft_printf(">---|%i|\n", (signed int)0xff11);
	printf("<---|%i|\n", (signed int)0xff11);
	ft_printf(">---|%.2i|\n", -10);
	printf("<---|%.2i|\n", -10);
	ft_printf(">---|%.i|\n", 44);
	printf("<---|%.i|\n", 44);
	ft_printf(">---|%08i|\n", -71);
	printf("<---|%08i|\n", -71);
	ft_printf(">---|%-2i|\n", -7);
	printf("<---|%-2i|\n", -7);
	ft_printf(">---|%.0i|\n", 0);
	printf("<---|%.0i|\n", 0);

	printf("\n___ Testing [%%u] ___\n");
	ft_printf(">---|%u|\n", 0);
	printf("<---|%u|\n", 0);
	ft_printf(">---|%u|\n", 1234);
	printf("<---|%u|\n", 1234);
	ft_printf(">---|%u|\n", -1001234);
	printf("<---|%u|\n", -1001234);
	ft_printf(">---|%.1u|\n", 121);
	printf("<---|%.1u|\n", 121);
	ft_printf(">---|%.0u|\n", 76543);
	printf("<---|%.0u|\n", 76543);
	ft_printf(">---|%.u|\n", -7);
	printf("<---|%.u|\n", -7);
	ft_printf(">---|%4u|\n", 1);
	printf("<---|%4u|\n", 1);
	ft_printf(">---|%-12u|\n", 17894);
	printf("<---|%-12u|\n", 17894);
	ft_printf(">---|%2u|\n", 17894);
	printf("<---|%2u|\n", 17894);
	ft_printf(">---|%08u|\n", 171894);
	printf("<---|%08u|\n", 171894);
	ft_printf(">---|%0u|\n", 194);
	printf("<---|%0u|\n", 194);
	ft_printf(">---|%-3u|\n", 194);
	printf("<---|%-3u|\n", 194);
	ft_printf(">---|toto et %02u coco %-5u mimi|\n", 19, -20);
	printf("<---|toto et %02u coco %-5u mimi|\n", 19, -20);
	ft_printf(">---|\ntoto et %00009u%-2u mimi et titi%--14u|\n", 0, 14, 200);
	printf("<---|\ntoto et %00009u%-2u mimi et titi%--14u|\n", 0, 14, 200);
	ft_printf(">---|ko%-4.2u et %05.2u!|\n", -456, 0);
	printf("<---|ko%-4.2u et %05.2u!|\n", -456, 0);
	ft_printf(">---|%05.1u %3.4u %-4.7u|\n", 45, -1789, 147);
	printf("<---|%05.1u %3.4u %-4.7u|\n", 45, -1789, 147);
	ft_printf(">---|%.u|\n", 0);
	printf("<---|%.u|\n", 0);

	printf("\n___ Testing [%%x & %%X] ___\n");
	ft_printf(">---|%x|\n", 0);
	printf("<---|%x|\n", 0);
	ft_printf(">---|%X|\n", 0xa0);
	printf("<---|%X|\n", 0xa0);
	ft_printf(">---|%x|\n", 0xa0ffff);
	printf("<---|%x|\n", 0xa0ffff);
	ft_printf(">---|%x|\n", -12345678);
	printf("<---|%x|\n", -12345678);
	ft_printf(">---|%X|\n", 0);
	printf("<---|%X|\n", 0);
	ft_printf(">---|%x|\n", 0x78aa);
	printf("<---|%x|\n", 0x78aa);
	ft_printf(">---|%X|\n", 0xff7744);
	printf("<---|%X|\n", 0xff7744);
	ft_printf(">---|%.x|\n", 12);
	printf("<---|%.x|\n", 12);
	ft_printf(">---|%.0X|\n", 0xaabbcc);
	printf("<---|%.0X|\n", 0xaabbcc);
	ft_printf(">---|%.2X|\n", 0x11aabbcc);
	printf("<---|%.2X|\n", 0x11aabbcc);
	ft_printf(">---|%.10x|\n", 0x1234abcd);
	printf("<---|%.10x|\n", 0x1234abcd);
	ft_printf(">---|%.4x|\n", 0x78);
	printf("<---|%.4x|\n", 0x78);
	ft_printf(">---|%3x|\n", 0xa43);
	printf("<---|%3x|\n", 0xa43);
	ft_printf(">---|%1X|\n", 0xa3);
	printf("<---|%1X|\n", 0xa3);
	ft_printf(">---|%4x|\n", 0xdd);
	printf("<---|%4x|\n", 0xdd);
	ft_printf(">---|%011X|\n", 0xdd66);
	printf("<---|%011X|\n", 0xdd66);
	ft_printf(">---|%-6x|\n", 0xdd66);
	printf("<---|%-6x|\n", 0xdd66);
	ft_printf(">---|%-2x|\n", 0xadd66);
	printf("<---|%-2x|\n", 0xadd66);
	ft_printf(">---|%20x|\n", 0x123456bc);
	printf("<---|%20x|\n", 0x123456bc);
	ft_printf(">---|test%---10.6x et %01X !!\n|\n", 0xaabb, 0);
	printf("<---|test%---10.6x et %01X !!\n|\n", 0xaabb, 0);
	ft_printf(">---|t %7.5X%0006.2x!|\n", 0xab, 0x876);
	printf("<---|t %7.5X%0006.2x!|\n", 0xab, 0x876);
	ft_printf(">---|toto %00.4X%4.2xet c'est fini \n|\n", 0x037a, 0x9e);
	printf("<---|toto %00.4X%4.2xet c'est fini \n|\n", 0x037a, 0x9e);
	ft_printf(">---|cc%.4X et %0012x %04X !!|\n", 0xaef, 0xe, 0);
	printf("<---|cc%.4X et %0012x %04X !!|\n", 0xaef, 0xe, 0);
	return (0);
}
