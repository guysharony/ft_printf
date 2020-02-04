/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doprint.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 10:44:36 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/31 11:34:08 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOPRINT_H
# define DOPRINT_H

# define MAXBUF 64
# include <stdarg.h>
# include <unistd.h>
# include "../../lib/includes/lib.h"
# include "../../includes/ft_data.h"
# include "../../parser/includes/parser.h"

t_info		display(t_info info, va_list *argp);

int			doprint(const char *fmt, va_list *argp);

void		display_d_d(t_info *info, va_list *argp);
void		display__x(t_info *info, va_list *argp);
void		display__z(t_info *info, va_list *argp);
void		display_c_(t_info *info, va_list *argp);
void		display_r_r(t_info *info, va_list *argp);
void		display_n_n(t_info *info, va_list *argp);
void		display_o_o(t_info *info, va_list *argp);
void		display_p_x(t_info *info, va_list *argp);
void		display_u_u(t_info *info, va_list *argp);
void		display_z_(t_info *info, va_list *argp);

void		print_signed(t_info *info, va_list *argp);

void		print_string(t_info *info, va_list *argp);

void		print_num(t_info *info, va_list *argp);

void		printnum(unsigned int u, int base);

void		print_boolean(t_info *info, va_list *argp);

void		print_unsigned(t_info *info, va_list *argp);

t_info		info_init(char c, const char *fmt, t_print print);

t_print		print_init(void);

#endif
