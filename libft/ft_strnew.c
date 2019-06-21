/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcottet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 19:20:48 by fcottet           #+#    #+#             */
/*   Updated: 2018/09/30 14:29:38 by fcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;

	new = NULL;
	if ((new = malloc(sizeof(char) * (size + 1))))
	{
		ft_memset(new, '\0', size + 1);
		return (new);
	}
	return (new);
}
