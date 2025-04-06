/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel_last.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:33:46 by dtanski           #+#    #+#             */
/*   Updated: 2025/02/20 21:14:39 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstdel_last(t_dlist *lst, void (*del)(void*))
{
	t_dlist	*tmp;
	t_dlist	*last_node;

	if (!lst || !lst->next)
		return ;
	last_node = ft_dlstlast(lst);
	tmp = lst->previous;
	tmp->next = 0;
	del(last_node->content);
	free(last_node);
}
