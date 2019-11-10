#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	int		a;

	a = 42;
	printf("|ok %10.50--d|\n", -33);
	return (0);
}
