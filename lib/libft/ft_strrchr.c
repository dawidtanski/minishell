/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanski <dtanski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:35:49 by dtanski           #+#    #+#             */
/*   Updated: 2024/11/22 11:27:29 by dtanski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last_occurrence;

	last_occurrence = s;
	while (*s++ != '\0')
	{
		if (*s == (char)c)
			last_occurrence = s;
	}
	if (*last_occurrence != (char)c && (char)c != '\0')
		return (NULL);
	return ((char *)last_occurrence);
}
