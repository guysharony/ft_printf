#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	printf("|%*.***d|\n", -50, -60, -80, -90, -123);
	ft_printf("|%*.***d|\n", -50, -60, -80, -90, -123);
	return (0);
}