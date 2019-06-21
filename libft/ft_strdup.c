/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcottet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 19:16:05 by fcottet           #+#    #+#             */
/*   Updated: 2018/02/12 10:20:43 by fcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strdup(const char *s)
{
	char	*str;

	if ((str = ft_strnew(ft_strlen(s))))
	{
		ft_memcpy(str, s, ft_strlen(s));
		if (!str)
			return (NULL);
		return (str);
	}
	return (NULL);
}
