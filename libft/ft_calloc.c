/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:44:54 by gsharony          #+#    #+#             */
/*   Updated: 2019/10/17 08:59:30 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*a;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (!(a = malloc(count * size)))
		return (NULL);
	if (a)
		ft_bzero(a, count * size);
	return (a);
}
