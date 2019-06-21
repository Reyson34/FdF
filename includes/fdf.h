/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcottet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 19:45:24 by fcottet           #+#    #+#             */
/*   Updated: 2018/11/04 14:50:06 by fcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <stdlib.h>
# include <mlx.h>

typedef struct	s_co
{
	int			x;
	int			y;
}				t_co;

typedef struct	s_map
{
	char		**line;
	int			col;
}				t_map;

typedef struct	s_win
{
	void		*mlx;
	void		*win;
	int			h;
	int			w;
	int			s;
	int			l;
	int			k;
	t_list		*map;
	int			color;
	int			ctrl;
	int			xincr;
	int			yincr;
	t_co		*ar;
	t_co		*dep;
}				t_win;

t_list			*get_map(int fd);
int				*str_to_int(char **tabstr);
int				deal_key(int key, void *par);
void			draw_map(t_list *map, t_win *par);
void			tracer(t_co *dep, t_co *ar, t_win *par);
void			get_classy(t_win *par);
int				deal_mouse(int button, int x, int y, void *par);
int				hook_mousemove(int x, int y, void *par);

#endif
