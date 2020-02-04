/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:55:14 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/31 09:37:53 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../../lib/includes/lib.h"
# include "../../includes/ft_data.h"

int		parse_flags(t_print *print, char c);
void	parse_long(t_print *print,
		const char **fmt, char *c);
void	parse_padding(t_print *print,
		const char **fmt, char *c);
void	parse_precision(t_print *print,
		const char **fmt, va_list *argp, char *c);
void	parse_width(t_print *print,
		const char **fmt, va_list *argp, char *c);

t_info	parse(char c, const char *fmt, va_list *argp);

#endif
