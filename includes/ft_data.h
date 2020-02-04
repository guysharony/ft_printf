/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 08:20:55 by gsharony          #+#    #+#             */
/*   Updated: 2020/02/01 20:00:40 by guysharon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DATA_H
# define FT_DATA_H

typedef struct		s_print
{
	int				length;
	int				prec;
	int				ladjust;
	char			padc;
	int				plus_sign;
	int				sign_char;
	int				altfmt;
	int				truncate;
	int				capitals;
	int				base;
	unsigned int	u;
	long			n;
}					t_print;

typedef struct		s_info
{
	int				i;
	char			c;
	const char		*fmt;
	t_print			print;
}					t_info;

#endif
