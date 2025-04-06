/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanski <dtanski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:22:08 by dtanski           #+#    #+#             */
/*   Updated: 2025/01/08 19:22:27 by dtanski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim_all(const char *s1, const char *set)
{
	char	*new_str;
	char	**split;
	size_t	size_new_str;

	if (!s1)
		return (0);
	split = ft_split((char *)s1, (char *)set);
	if (!split)
		return (0);
	size_new_str = get_length(split);
	if (size_new_str == 0)
		return (ft_strdup(""));
	new_str = ft_calloc(size_new_str + 1, sizeof(char));
	if (!new_str)
		return (0);
	concat_all(new_str, split);
	free_arr((void **)split);
	return (new_str);
}

static size_t	get_length(char **strs)
{
	size_t	len;

	len = 0;
	while (*strs)
	{
		len += ft_strlen(*strs);
		strs++;
	}
	return (len);
}

static void	concat_all(char *dest, char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		ft_strcat(dest, strs[i]);
		i++;
	}
}
