/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 13:21:27 by pjedrycz          #+#    #+#             */
/*   Updated: 2024/03/21 22:15:39 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static int	ft_isinset(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_trimmed(const char *s1, size_t start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (len <= 0 || start >= ft_strlen(s1))
		return (ft_strdup(""));
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s1[start + i];
		i++;
	}
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(s1) - 1;
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	while (ft_isinset(set, s1[i]))
		i++;
	while (ft_isinset(set, s1[j]))
		j--;
	return (ft_trimmed(s1, i, j - (i - 1)));
}

// int	main()
// {
// 	char	*str;
// 	char	*set;

// 	str = "asdtestasd";
// 	set = "asd";
// 	printf("Trimmed string: %s\n", ft_strtrim(str, set));
// 	return (0);
// }