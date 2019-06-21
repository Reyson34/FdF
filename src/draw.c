/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcottet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 14:33:08 by fcottet           #+#    #+#             */
/*   Updated: 2018/11/04 15:52:59 by fcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		xsupy(t_co *dir, t_co *dep, t_co *ar, t_win *par)
{
	int		e;
	int		i;

	i = 0;
	par->xincr = -1;
	par->yincr = -1;
	if (dep->x < ar->x)
		par->xincr = 1;
	if (dep->y < ar->y)
		par->yincr = 1;
	e = dir->x / 2;
	while (i < dir->x)
	{
		dep->x = dep->x + par->xincr;
		if ((e = e + dir->y) > dir->x)
		{
			e = e - dir->x;
			dep->y = dep->y + par->yincr;
		}
		mlx_pixel_put(par->mlx, par->win, dep->x, dep->y, par->color);
		i++;
	}
	mlx_pixel_put(par->mlx, par->win, dep->x, dep->y, par->color);
}

void		ysupx(t_co *dir, t_co *dep, t_co *ar, t_win *par)
{
	int		e;
	int		i;

	i = 0;
	par->xincr = -1;
	par->yincr = -1;
	if (dep->x < ar->x)
		par->xincr = 1;
	if (dep->y < ar->y)
		par->yincr = 1;
	e = dir->y / 2;
	while (i < dir->y)
	{
		dep->y = dep->y + par->yincr;
		if ((e = e + dir->x) > dir->y)
		{
			e = e - dir->y;
			dep->x = dep->x + par->xincr;
		}
		mlx_pixel_put(par->mlx, par->win, dep->x, dep->y, par->color);
		i++;
	}
	mlx_pixel_put(par->mlx, par->win, dep->x, dep->y, par->color);
}

void		tracer(t_co *dep, t_co *ar, t_win *par)
{
	t_co	*dir;

	dir = malloc(sizeof(t_co));
	dir->x = abs(ar->x - dep->x);
	dir->y = abs(ar->y - dep->y);
	if (dir->x >= dir->y)
		xsupy(dir, dep, ar, par);
	else
		ysupx(dir, dep, ar, par);
	free(dir);
}

void		getxy(int i, t_map *line, t_win *par, t_co **coord)
{
	int		h;

	h = ft_atoi(line->line[i]);
	(*coord)->x = ((i - line->col) * par->w) + 1000 + par->l;
	(*coord)->y = ((i + line->col) * par->s) + 200 + par->k - (h * par->h);
}

void		draw_map(t_list *map, t_win *par)
{
	int		i;

	while (map)
	{
		i = -1;
		while (((t_map *)(map->content))->line[++i])
		{
			if (((t_map *)(map->content))->line[i + 1])
			{
				getxy(i, map->content, par, &par->dep);
				getxy(i + 1, map->content, par, &par->ar);
				tracer(par->dep, par->ar, par);
			}
			if (map->next && (((t_map *)(map->next->content))->line[i]))
			{
				getxy(i, map->content, par, &par->dep);
				getxy(i, map->next->content, par, &par->ar);
				tracer(par->dep, par->ar, par);
			}
		}
		map = map->next;
	}
	get_classy(par);
}
