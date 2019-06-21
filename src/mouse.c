/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcottet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 17:05:52 by fcottet           #+#    #+#             */
/*   Updated: 2018/11/04 15:01:29 by fcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int					hook_mousemove(int x, int y, void *par)
{
	static t_co		*xy;
	t_co			*prev;

	if (((t_win *)par)->ctrl > 0)
	{
		if (!xy)
			xy = malloc(sizeof(t_co *));
		prev = malloc(sizeof(t_co *));
		if (xy->x)
			prev->x = xy->x;
		xy->x = x;
		if (prev->x)
		{
			if (prev->x < x)
				((t_win *)par)->color = (((t_win *)par)->color + 1000)
					% 16777215;
			if (prev->x > x)
				((t_win *)par)->color = (((t_win *)par)->color - 1000)
					% 16777215;
		}
		mlx_clear_window(((t_win *)par)->mlx, ((t_win *)par)->win);
		draw_map(((t_win *)par)->map, (t_win *)par);
		free(prev);
	}
	return (y);
}

int					deal_mouse(int button, int x, int y, void *par)
{
	static t_co		*xy;
	t_co			*last;

	if (!xy)
		xy = malloc(sizeof(t_co *));
	last = malloc(sizeof(t_co *));
	if (button == 1)
	{
		if (xy->x && xy->y)
		{
			last->x = xy->x;
			last->y = xy->y;
		}
		xy->x = x;
		xy->y = y;
		if (last->x && last->y)
		{
			tracer(last, xy, par);
			xy = NULL;
		}
	}
	free(last);
	return (0);
}
