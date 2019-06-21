/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcottet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 19:10:49 by fcottet           #+#    #+#             */
/*   Updated: 2018/10/12 14:24:24 by fcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*cpy;
	char const	*origin;

	if (n == 0 || src == dest)
		return (dest);
	i = 0;
	cpy = (char *)dest;
	origin = (char const*)src;
	while (i < n)
	{
		cpy[i] = origin[i];
		i++;
	}
	return (dest);
}
