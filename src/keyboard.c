/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcottet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 15:44:09 by fcottet           #+#    #+#             */
/*   Updated: 2018/11/04 15:01:16 by fcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		instruction(t_win *par)
{
	mlx_string_put(par->mlx, par->win, 50, 850, 0xFFFFFF, "MOVES :");
	mlx_string_put(par->mlx, par->win, 50, 870, 0xFFFFFF, "W = TOP");
	mlx_string_put(par->mlx, par->win, 50, 890, 0xFFFFFF, "A = LEFT");
	mlx_string_put(par->mlx, par->win, 50, 910, 0xFFFFFF, "D = RIGHT");
	mlx_string_put(par->mlx, par->win, 50, 930, 0xFFFFFF, "S = BOTTOM");
	mlx_string_put(par->mlx, par->win, 1800, 850, 0xFFFFFF, "COMMANDS :");
	mlx_string_put(par->mlx, par->win, 1800, 870, 0xFFFFFF, "< UNZOOM");
	mlx_string_put(par->mlx, par->win, 1800, 890, 0xFFFFFF, "> ZOOM");
	mlx_string_put(par->mlx, par->win, 1800, 910, 0xFFFFFF, "^ SIZE UP");
	mlx_string_put(par->mlx, par->win, 1800, 930, 0xFFFFFF, "v SIZE DOWN");
}

void		get_classy(t_win *par)
{
	int		i;
	int		k;
	char	*str;

	str = "Bienvenue dans le Fdf de fcottet";
	i = 0;
	while (i < 80)
	{
		k = 0;
		while (k < 2000)
		{
			mlx_pixel_put(par->mlx, par->win, k, i, par->color);
			k++;
		}
		i++;
	}
	if (par->color == 0xFFFFFF)
		mlx_string_put(par->mlx, par->win, 850, 30, 0x000000, str);
	else
		mlx_string_put(par->mlx, par->win, 850, 30, 0xFFFFFF, str);
	instruction(par);
}

t_win		*high(t_win *par, int key)
{
	if (key == 126)
		par->h += 1;
	if (key == 125)
	{
		if (par->h > 1)
			par->h -= 1;
	}
	if (key == 256)
		par->ctrl *= -1;
	return (par);
}

int			deal_key(int key, void *par)
{
	if (key == 126 || key == 125 || key == 256)
		par = high(par, key);
	if (key == 123 && ((t_win *)par)->w > 2)
	{
		((t_win *)par)->w -= 2;
		((t_win *)par)->s -= 1;
	}
	if (key == 124)
	{
		((t_win *)par)->w += 2;
		((t_win *)par)->s += 1;
	}
	if (key == 13)
		((t_win *)par)->k -= 10;
	if (key == 1)
		((t_win *)par)->k += 10;
	if (key == 2)
		((t_win *)par)->l += 10;
	if (key == 0)
		((t_win *)par)->l -= 10;
	mlx_clear_window(((t_win *)par)->mlx, ((t_win *)par)->win);
	draw_map(((t_win *)par)->map, (t_win *)par);
	if (key == 53)
		exit(EXIT_SUCCESS);
	return (0);
}
