/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:51:41 by dtanski           #+#    #+#             */
/*   Updated: 2025/02/20 21:15:13 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_dlist **list, t_dlist *new)
{
	t_dlist	*last;

	if (!*list)
	{
		ft_dlstadd_front(list, new);
		return ;
	}
	last = ft_dlstlast(*list);
	last->next = new;
	new->previous = last;
	new->next = NULL;
}
