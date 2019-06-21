/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcottet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 19:03:56 by fcottet           #+#    #+#             */
/*   Updated: 2018/10/12 14:22:40 by fcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	void	fill_nbr(char **nbr, int n, int i)
{
	if (n < 0)
	{
		(*nbr)[0] = '-';
		i++;
		n = -n;
	}
	i--;
	if (n >= 10)
	{
		fill_nbr(nbr, (n / 10), i);
	}
	(*nbr)[i] = (n % 10) + '0';
}

char			*ft_itoa(int n)
{
	char		*nbr;
	int			i;
	int			j;
	int			neg;

	nbr = NULL;
	neg = 0;
	i = 0;
	j = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (j < 0)
	{
		j = -j;
		neg = 1;
	}
	while ((j / 10) > 0)
	{
		j /= 10;
		i++;
	}
	if ((nbr = ft_strnew(i + neg + 1)))
		fill_nbr(&nbr, n, i + 1);
	return (nbr);
}
