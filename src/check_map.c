/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcottet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 16:20:28 by fcottet           #+#    #+#             */
/*   Updated: 2018/11/04 16:22:54 by fcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_map			*split_line(char *line)
{
	static int	c = 0;
	t_map		*ret;

	ret = malloc(sizeof(t_map *));
	ret->line = ft_strsplit(line, ' ');
	ret->col = c;
	c++;
	return (ret);
}

int				check_line(char *line)
{
	int			i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '-' && line[i] != '+'
				&& (line[i] < 48 || line[i] > 57))
			return (0);
		i++;
	}
	return (1);
}

t_list			*get_new_map(char *line)
{
	t_list		*map;

	map = malloc(sizeof(t_list));
	map->content = split_line(line);
	return (map);
}

t_list			*get_map(int fd)
{
	char		*line;
	t_list		*map;
	t_list		*tmp;

	line = NULL;
	map = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		if (check_line(line) == 0)
			return (NULL);
		if (map == NULL)
		{
			map = get_new_map(line);
			tmp = map;
		}
		else
		{
			map->next = get_new_map(line);
			map = map->next;
			map->next = NULL;
		}
		free(line);
	}
	free(line);
	return (tmp);
}
