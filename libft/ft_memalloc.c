/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcottet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 19:09:05 by fcottet           #+#    #+#             */
/*   Updated: 2018/10/12 14:23:44 by fcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;

	mem = 0;
	if ((mem = malloc(sizeof(char) * size)))
	{
		ft_memset(mem, 0, size);
		return (mem);
	}
	return (NULL);
}
