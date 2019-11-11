#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	int		a;

	a = 42;
	printf("|%10s|\n", "Test1");
	printf("|%-10s|\n", "Test1");
	printf("|%10s|\n", "Test1");
	printf("|%-10s|\n", "Test1");
	return (0);
}
