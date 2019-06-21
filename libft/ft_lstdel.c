/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcottet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 19:06:59 by fcottet           #+#    #+#             */
/*   Updated: 2018/11/03 18:40:21 by fcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;
	t_list	*lstnext;

	lst = *alst;
	while (lst)
	{
		lstnext = lst->next;
		del(lst->content, lst->content_size);
		free(lst);
		lst = lstnext;
	}
	*alst = NULL;
}
