/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:36:13 by gsharony          #+#    #+#             */
/*   Updated: 2019/10/28 17:04:30 by guysharon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *, ...);

//Display strings
void	ft_putstr(char *str);
void	ft_putchar(int c);

//Display adresses
void	ft_print_adresse(void *a);

//Display numbers
void	ft_putlongnbr(unsigned int nb, char *base);
void	ft_putchar_base(int c, char *base);
void	ft_putnbr_base(long long nb, char *base);

#endif
