#include "ft_printf.h"

void			ft_putchar_base(int c, char *base)
{
	write(1, &base[c], 1);
}

void			ft_putnbr_base(long long nb, char *base)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb >= (long long)ft_strlen(base))
	{
		ft_putnbr_base(nb / ft_strlen(base), base);
		ft_putnbr_base(nb % ft_strlen(base), base);
	}
	else
		ft_putchar_base(nb, base);
}

void			ft_putlongnbr(unsigned int nb, char *base)
{
	if (nb >= ft_strlen(base))
	{
		ft_putlongnbr(nb / ft_strlen(base), base);
		ft_putlongnbr(nb % ft_strlen(base), base);
	}
	else
		ft_putchar_base(nb, base);
}