/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 07:33:10 by gsharony          #+#    #+#             */
/*   Updated: 2020/02/02 11:19:49 by guysharon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include "../../includes/ft_printf.h"

int		ft_strlen(char *str);
int		ft_includes(char c, char *str);
int		ft_isdigit(char c);
int		ft_ctod(char c);
int		ft_pos(int nbr);

char	*ft_strcpy(char *dest, const char *src);
char	*ft_strdup(const char *str);

void	ft_putchar(char c);

#endif
