/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:36:13 by gsharony          #+#    #+#             */
/*   Updated: 2019/10/27 15:12:09 by guysharon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *, ...);
void	ft_putstr(char *str);
void	ft_putchar(int c);
void	ft_putnbr(int nb);
void	ft_putnbr_hex(long long nb);
void	ft_print_adresse(void *a);
void	ft_putlongnbr(unsigned int nb);

#endif
