/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:34:01 by pjedrycz          #+#    #+#             */
/*   Updated: 2024/03/26 18:59:05 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sum;
	int		i;
	int		j;

	i = 0;
	j = 0;
	sum = (char *) malloc ((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!sum)
		return (NULL);
	while (s1[i])
		sum[j++] = s1[i++];
	i = 0;
	while (s2[i])
		sum[j++] = s2[i++];
	sum[j] = '\0';
	return (sum);
}

// int	main()
// {
// 	char	*s1 = "Dupa";
// 	char	*s2 = "blada";
// 	char	*join;

// 	join = ft_strjoin(s1, s2);
// 	printf("%s", join);
// 	// free???
// 	return (0);
// }
