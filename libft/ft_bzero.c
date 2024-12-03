/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:03:21 by pjedrycz          #+#    #+#             */
/*   Updated: 2024/03/26 19:35:43 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*temp;

	temp = (char *) s;
	while (n > 0)
	{
		*(temp++) = 0;
		n--;
	}
}

// int	main()
// {
// 	char s[100] = "aaaaa";
// 	char sbis[100] = "aaaaa";
// 	strcpy(sbis, s);
// 	bzero(s, 3);
// 	ft_bzero(sbis, 3);
// 	int		i;
// 	i = 0;
// 	while (i < 5 && s[i] == sbis[i])
// 		i++;
// 	if (i == 5)
// 		printf("OK\n");
// 	else
// 		printf("Failed : expected [%c][%c][%c][%c][%c], 
//		got [%c][%c][%c][%c][%c].\n", 
//		s[0], s[1], s[2], s[3], s[4], sbis[0], sbis[1], 
//		sbis[2], sbis[3], sbis[4]);
// 	return (0);
// }