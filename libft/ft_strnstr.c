/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanski <dtanski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:35:55 by dtanski           #+#    #+#             */
/*   Updated: 2024/11/22 11:27:22 by dtanski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if ((big == NULL) && (len == 0))
		return (NULL);
	if (*little == '\0')
		return ((char *)big);
	while (*big && len)
	{
		while (*(little + i) == *(big + i) && (i < len) && *(little + i))
		{
			if (*(little + i + 1) == '\0')
				return ((char *)big);
			i++;
		}
		big++;
		len--;
	}
	return (NULL);
}
