/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel_first.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:39:38 by dtanski           #+#    #+#             */
/*   Updated: 2025/02/20 21:12:30 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstdel_first(t_dlist **list, void (*del)(void*))
{
	t_dlist	*tmp;

	if (!list || !(*list))
		return ;
	tmp = *list;
	*list = (*list)->next;
	if (*list)
		(*list)->previous = NULL;
	tmp->next = NULL;
	del(tmp->content);
	free(tmp);
}
