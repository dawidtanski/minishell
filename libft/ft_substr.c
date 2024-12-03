/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 13:24:47 by pjedrycz          #+#    #+#             */
/*   Updated: 2024/03/21 21:29:29 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	subs = ft_calloc(len + 1, sizeof(char));
	if (!subs)
		return (NULL);
	while (i < len)
	{
		subs[i] = s[i + start];
		i++;
	}
	return (subs);
}

// int	main()
// {
// 	char const		*str;
// 	unsigned int	start;
// 	size_t			len;

// 	str = "testujemy";
// 	start = 0;
// 	len = 11;
// 	printf("Substring: %s\n", ft_substr(str, start, len));
// 	return (0);
// }