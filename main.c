/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 10:20:28 by gsharony          #+#    #+#             */
/*   Updated: 2019/10/23 13:15:56 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int		a;
	a = 3;
	ft_printf("String: |%s|\nCharacter: |%c|\nNumber: |%d|\nOctet: |%i|\nHexa :|%i|\nAdresse: |%p|\n", "Middle", 'a', 10, 0125, 0x125, &a);
	return (0);
}
