#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	printf("|%-*..-.10*.d|\n",20, 30, -123);
	ft_printf("|%-*..-.10*.d|\n",20, 30, -123);
	return (0);
}