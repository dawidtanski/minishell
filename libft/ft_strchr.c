/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:59:36 by pjedrycz          #+#    #+#             */
/*   Updated: 2024/03/22 19:31:02 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <string.h>
// #include <stdio.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	cc;

	if (!s)
		return (NULL);
	i = 0;
	cc = (char) c;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == cc)
	{
		return ((char *) &s[i]);
	}
	return (NULL);
}

// int	main()
// {
// 	char *str = "strinrg";
// 	printf("%p : %p\n", strchr(str, ' '), ft_strchr(str, ' '));
// 	printf("%p : %p\n", strchr(str, '\0'), ft_strchr(str, '\0'));
// 	printf("%p : %p\n", strchr(str, 's'), ft_strchr(str, 's'));
// 	printf("%p : %p\n", strchr(str, 'g'), ft_strchr(str, 'g'));
// 	return (0);
// }