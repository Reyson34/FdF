/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcottet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 18:59:54 by fcottet           #+#    #+#             */
/*   Updated: 2018/10/12 14:21:43 by fcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int			num;
	int			i;
	int			neg;

	i = 0;
	neg = 1;
	num = 0;
	while (nptr[i] == '\n' || nptr[i] == '\t' || nptr[i] == '\v'
		|| nptr[i] == ' ' || nptr[i] == '\r' || nptr[i] == '\f')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg = -neg;
		i++;
	}
	while (nptr[i] && nptr[i] > 47 && nptr[i] < 58)
	{
		num = num * 10;
		num = num + (nptr[i] - 48);
		i++;
	}
	return ((num) * neg);
}
