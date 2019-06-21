/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcottet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 19:19:06 by fcottet           #+#    #+#             */
/*   Updated: 2018/02/12 10:21:58 by fcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	str = NULL;
	i = 0;
	if (s && f)
	{
		if ((str = ft_strnew(ft_strlen(s))))
		{
			while (s[i])
			{
				str[i] = f(i, s[i]);
				i++;
			}
			return (str);
		}
	}
	return (NULL);
}
