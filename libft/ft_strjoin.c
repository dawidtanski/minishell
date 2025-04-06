/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanski <dtanski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:36:35 by dtanski           #+#    #+#             */
/*   Updated: 2024/11/22 11:26:24 by dtanski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*costr;

	if (!s1 || !s2)
		return (NULL);
	costr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (costr == NULL)
		return (NULL);
	ft_strlcpy(costr, (char *)s1, (ft_strlen(s1) + 1));
	ft_strlcat(costr, (char *)s2, (ft_strlen(s1) + ft_strlen(s2) + 1));
	return (costr);
}
