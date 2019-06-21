/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcottet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 19:21:00 by fcottet           #+#    #+#             */
/*   Updated: 2018/10/12 14:26:13 by fcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;
	int		j;

	if (*little == '\0')
		return ((char*)big);
	i = 0;
	while (*(big + i) != '\0' && len > 0)
	{
		if (*little == *(big + i))
		{
			j = 0;
			while (*(little + j) && *(big + i + j)
				&& *(little + j) == *(big + i + j) && (len - j) > 0)
				j++;
			if (*(little + j) == '\0')
				return ((char*)big + i);
		}
		i++;
		len--;
	}
	return (NULL);
}
