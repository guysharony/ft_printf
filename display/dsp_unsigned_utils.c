#include "../ft_printf.h"

int		ft_size_unsigned(unsigned int nb, char *base, t_format f)
{
	int		len;
	int		tmp;

	len = 0;
	tmp = 0;
	if (f.pr < 0)
		len += ft_nbrlen(nb, ft_strlen(base));
	else if (f.pr == 0 && nb != 0)
		len += ft_nbrlen(nb, ft_strlen(base));
	else if (f.pr > 0)
	{
		tmp = f.pr - ft_nbrlen(nb, ft_strlen(base));
		len += ft_nbrlen(nb, ft_strlen(base));
	}
	if (tmp > 0)
		len += tmp;
	return (len);
}

void	ft_print_unsigned(unsigned int nb, char *base, t_format f)
{
	if (f.pr < 0)
		ft_putnbr_base(nb, base);
	else if (f.pr == 0 && nb != 0)
		ft_putnbr_base(nb, base);
	else if (f.pr > 0)
	{
		ft_time('0', f.pr - ft_nbrlen(nb, ft_strlen(base)));
		ft_putnbr_base(nb, base);
	}
}
