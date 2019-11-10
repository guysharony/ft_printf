#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	int		a;

	a = 42;
	printf("|%*.*p%%|\n", 20, 15, -12345);
	return (0);
}
