/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:43:52 by dtanski           #+#    #+#             */
/*   Updated: 2025/02/20 21:13:05 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	dlstclear(t_dlist **list, void (*del)(void*))
{
	t_dlist	*tmp;

	if (list)
		return ;
	while (*list)
	{
		tmp = *list;
		*list = (*list)->next;
		ft_lstdelone(tmp, del);
	}
	*list = NULL;
}
