/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 13:20:12 by pjedrycz          #+#    #+#             */
/*   Updated: 2024/03/22 19:34:28 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <string.h>
// #include <stdio.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*r;
	char	cc;

	cc = (char) c;
	i = 0;
	r = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == cc)
			r = (char *) &s[i];
		i++;
	}
	if (s[i] == cc)
		r = (char *) &s[i];
	return (r);
}

// int	main()
// {
// 	char *str = "strinrg";
// 	printf("\nTest de ft_strrchr :\n");
// 	printf("%p : %p\n", strrchr(str, '\0'), ft_strrchr(str, '\0'));
// 	printf("%p : %p\n", strrchr(str, 'r'), ft_strrchr(str, 'r'));
// 	return (0);
// }