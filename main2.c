#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	printf("|%-0*..-.5p|\n", -30, NULL);
	ft_printf("|%-0*..-.5p|\n", -30, NULL);
	return (0);
}