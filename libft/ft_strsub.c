/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcottet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 19:22:22 by fcottet           #+#    #+#             */
/*   Updated: 2018/09/30 14:28:07 by fcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char				*ft_strsub(char	const *s, unsigned int start, size_t len)
{
	char			*new;
	unsigned int	i;

	new = NULL;
	i = 0;
	if (s)
	{
		if ((new = ft_strnew(len)))
		{
			while (i < len)
			{
				new[i] = s[start];
				i++;
				start++;
			}
			return (new);
		}
	}
	return (NULL);
}
