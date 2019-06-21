/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcottet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 19:11:48 by fcottet           #+#    #+#             */
/*   Updated: 2018/10/12 14:24:40 by fcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*tmp;

	tmp = NULL;
	if ((tmp = ft_strnew(n + 1)))
	{
		ft_memcpy(tmp, src, n);
		ft_memcpy(dest, tmp, n);
		free(tmp);
	}
	return (dest);
}
