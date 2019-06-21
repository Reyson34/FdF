/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcottet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 21:02:51 by fcottet           #+#    #+#             */
/*   Updated: 2018/11/03 21:11:41 by fcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	**ft_tab_creation(char const *s, char c)
{
	int		i;
	int		j;
	int		cmp;

	i = 0;
	cmp = 0;
	while (*(s + i) != '\0')
	{
		while (*(s + i) == c)
			i++;
		j = i;
		while (*(s + i) != c && *(s + i) != '\0')
			i++;
		if ((i - j) > 0)
			cmp++;
	}
	return ((char**)malloc(sizeof(char*) * (cmp + 1)));
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		cmp;
	char	**ret;

	if (s == NULL || (ret = ft_tab_creation(s, c)) == NULL)
		return (NULL);
	i = 0;
	cmp = 0;
	while (*(s + i) != '\0')
	{
		while (*(s + i) == c)
			i++;
		j = i;
		while (*(s + i) != c && *(s + i) != '\0')
			i++;
		if ((i - j) > 0)
		{
			*(ret + cmp) = ft_strsub(s, j, (i - j));
			cmp++;
		}
	}
	ret[cmp] = 0;
	return (ret);
}
