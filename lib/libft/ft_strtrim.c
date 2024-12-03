/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanski <dtanski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:35:44 by dtanski           #+#    #+#             */
/*   Updated: 2024/11/22 11:27:36 by dtanski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_set_in_s(const char *set, char c)
{
	if (ft_strchr(set, (int)c))
		return (1);
	else
		return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimedstr;
	size_t	begin;
	size_t	fin;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	fin = 0;
	begin = 0;
	while (*(s1 + begin) && ft_set_in_s(set, *(s1 + begin)))
	{
		begin++;
	}
	fin = ft_strlen(s1);
	while ((fin > begin) && ft_set_in_s(set, *(s1 + (fin - 1))))
		fin--;
	trimedstr = (char *)malloc(sizeof(*s1) * (fin - begin + 1));
	if (trimedstr == NULL)
		return (NULL);
	i = 0;
	while (fin > begin)
		*(trimedstr + i++) = *(s1 + begin++);
	*(trimedstr + i) = '\0';
	return (trimedstr);
}
