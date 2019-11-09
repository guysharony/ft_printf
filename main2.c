#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	ft_printf("%-24..-.12..9.7d\n", 42);
	return (0);
}