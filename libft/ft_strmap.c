/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcottet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 19:18:42 by fcottet           #+#    #+#             */
/*   Updated: 2018/02/12 10:21:48 by fcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char				*ft_strmap(char const *s, char (*f)(char))
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
				str[i] = f(s[i]);
				i++;
			}
			return (str);
		}
	}
	return (NULL);
}
