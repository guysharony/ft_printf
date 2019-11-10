#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	int		a;

	a = 42;
	ft_printf("|ok %*.*p|\n", -20, -10, &a);
	return (0);
}