/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcottet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 19:17:42 by fcottet           #+#    #+#             */
/*   Updated: 2018/10/12 14:25:56 by fcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;

	new = NULL;
	if (s1 && s2)
	{
		if ((new = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
		{
			ft_strcpy(new, s1);
			ft_strcat(new, s2);
			return (new);
		}
	}
	return (NULL);
}
