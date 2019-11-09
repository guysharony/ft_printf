#include "../ft_printf.h"
#include <stdio.h>

static t_print		ft_width(const char *format, int a, va_list list)
{
	t_print		p;

	p.status = 0;
	if (format[a] == '*')
	{
		p.len = (int)va_arg(list, int);
		p.status++;
	}
	else if (format[a] >= '0' && format[a] <= '9')
	{
		p.len = ft_atoi(format + a);
		p.status += ft_format_count(format + a, "0123456789");
	}
	else
		p.status = 0;
	return (p);
}

static t_print		ft_precision(const char *format, int a, va_list list)
{
	t_print		p;

	p.status = 0;
	p.len = 0;
	if (format[a] == '*')
	{
		while (format[p.status + a] == '*')
		{
			p.len = (int)va_arg(list, int);
			p.status++;
		}
		p.status++;
	}
	else if (format[a] >= '0' && format[a] <= '9')
	{
		p.len = ft_atoi(format + a);
		p.status += ft_format_count(format + a, "0123456789") + 1;
	}
	else
		p.status++;
	return (p);
}

t_format			ft_checker(t_format f, t_print p)
{
	char	*tmp;

	tmp = NULL;
	if (p.len < 0)
	{
		tmp = f.fl;
		f.fl = ft_strjoin(tmp, "-");
		free(tmp);
		f.wi = p.len * -1;
	}
	else
		f.pr = p.len;
	f.po += p.status;
	return (f);
}

t_format			ft_get_params(const char *format, t_format f, va_list list)
{
	t_print		p;
	char		*tmp;

	if (ft_format(format[f.po], "-+0"))
	{
		tmp = f.fl;
		f.fl = ft_strjoin(tmp, &format[f.po]);
		free(tmp);
		f.po++;
	}
	else if (ft_format(format[f.po], "0123456789*"))
	{
		p = ft_width(format, f.po, list);
		f.wi = p.len;
		f.po += p.status;
	}
	else if (format[f.po] == '.')
	{
		p = ft_precision(format, f.po + 1, list);
		f = ft_checker(f, p);
	}
	return (f);
}