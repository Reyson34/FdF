/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcottet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 19:22:42 by fcottet           #+#    #+#             */
/*   Updated: 2018/10/12 13:10:12 by fcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*trim;

	i = 0;
	k = 0;
	if (s == NULL)
		return (NULL);
	j = (ft_strlen(s) - 1);
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
		i++;
	while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && j > 0)
		j--;
	if (j == 0)
		i = 1;
	if ((trim = (char *)malloc(sizeof(char) * (j - i + 2))))
	{
		while (i <= j && s[i])
			trim[k++] = s[i++];
		trim[k] = '\0';
		return (trim);
	}
	return (NULL);
}
