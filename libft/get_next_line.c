/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcottet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 09:45:07 by fcottet           #+#    #+#             */
/*   Updated: 2018/10/31 13:45:47 by fcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char			*check_end(char *str, int i)
{
	if (ft_strchr(str, '\n'))
	{
		ft_strcpy(str, ft_strchr(str, '\n') + 1);
		return (str);
	}
	if (i > 0)
	{
		ft_strcpy(str, ft_strchr(str, '\0'));
		return (str);
	}
	return (NULL);
}

int					get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	static char		*file[OPEN_MAX];
	int				ret;
	int				i;
	char			*tmp;

	i = 0;
	if (fd < 0 || BUFF_SIZE < 1 || !line || read(fd, buff, 0) < 0)
		return (-1);
	if (!(file[fd]) && (file[fd] = ft_strnew(0)) == NULL)
		return (-1);
	while (!(ft_strchr(file[fd], '\n'))
		&& (ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = file[fd];
		file[fd] = ft_strjoinfree(tmp, buff);
	}
	while (file[fd][i] != '\n' && file[fd][i] != '\0')
		i++;
	(*line) = ft_strsub(file[fd], 0, i);
	if (check_end(file[fd], i) == NULL)
		return (0);
	return (1);
}
