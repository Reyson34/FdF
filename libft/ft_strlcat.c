/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcottet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 19:17:58 by fcottet           #+#    #+#             */
/*   Updated: 2018/02/11 20:17:50 by fcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = ft_strlen(dest);
	k = ft_strlen(src);
	if (n < j)
		return (n + k);
	while (src[i] != '\0' && (j + i + 1) < n)
	{
		dest[j + i] = src[i];
		i++;
	}
	dest[j + i] = '\0';
	return (j + k);
}
