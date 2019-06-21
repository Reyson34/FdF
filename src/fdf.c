/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcottet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 15:59:36 by fcottet           #+#    #+#             */
/*   Updated: 2018/11/04 16:40:04 by fcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int					init_windows(int fd, int color)
{
	static t_win	*par;

	if (!color)
		color = 0xFF0000;
	par = NULL;
	par = malloc(sizeof(t_win));
	if (!(par->map = get_map(fd)))
		return (0);
	par->mlx = mlx_init();
	par->win = mlx_new_window(par->mlx, 2000, 1000, "FdF");
	par->h = 3;
	par->w = 20;
	par->s = 10;
	par->l = 0;
	par->k = 0;
	par->ctrl = 1;
	par->color = color;
	par->dep = malloc(sizeof(t_co *));
	par->ar = malloc(sizeof(t_co *));
	mlx_key_hook(par->win, deal_key, par);
	mlx_mouse_hook(par->win, deal_mouse, par);
	mlx_hook(par->win, 6, 0, hook_mousemove, par);
	draw_map(par->map, par);
	mlx_loop(par->mlx);
	return (1);
}

int					check_color(char *str)
{
	int				i;

	i = 2;
	if (ft_strlen(str) != 8)
		return (0);
	if (str[0] != '0' && str[1] != 'x')
		return (0);
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9')
			|| (str[i] >= 'A' && str[i] <= 'F'))
			i++;
		else
			return (0);
	}
	return (1);
}

int					get_color(char *str)
{
	int				color;
	int				i;

	i = 2;
	color = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			color += ft_power(16, 7 - i) * (str[i] - '0');
		if (str[i] >= 'A' && str[i] <= 'F')
			color += ft_power(16, 7 - i) * (str[i] - 'A' + 10);
		i++;
	}
	return (color);
}

int					main(int ac, char **av)
{
	int				fd;
	int				color;

	if (ac != 2 && ac != 3)
	{
		ft_putendl("usage: fdf file_name [0xRRGGBB]");
		return (0);
	}
	if (av[2])
	{
		if (check_color(av[2]) == 1)
			color = get_color(av[2]);
		else
		{
			ft_putendl("usage: fdf file_name [0xRRGGBB]");
			return (0);
		}
	}
	if ((fd = open(av[1], O_RDONLY)) < 0 || init_windows(fd, color) == 0)
	{
		ft_putendl("Echec de la lecture");
		return (0);
	}
	return (0);
}
