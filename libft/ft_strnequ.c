/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcottet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 19:20:21 by fcottet           #+#    #+#             */
/*   Updated: 2018/02/11 20:15:08 by fcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = 0;
	if (s1 && s2)
	{
		while (i < n && s1[i] && s2[i])
		{
			if (s1[i] == s2[i])
				res++;
			i++;
		}
		if (res == n || (res == ft_strlen(s1) && res == ft_strlen(s2)))
			return (1);
	}
	return (0);
}
