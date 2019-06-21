/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcottet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 15:40:37 by fcottet           #+#    #+#             */
/*   Updated: 2018/10/12 15:46:20 by fcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strjoinfree(char *s1, char *s2)
{
	char	*new;

	new = NULL;
	if (s1 && s2)
	{
		if ((new = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
		{
			ft_strcpy(new, s1);
			ft_strcat(new, s2);
			free(s1);
			return (new);
		}
	}
	return (NULL);
}
