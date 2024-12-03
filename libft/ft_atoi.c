/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:00:45 by pjedrycz          #+#    #+#             */
/*   Updated: 2024/03/21 20:43:00 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == 9 || c == 10 || c == 11 || c == 12 || c == 13 || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	nb;
	int	neg;
	int	i;

	nb = 0;
	neg = 1;
	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '+' && nptr[i + 1] != '-')
		i++;
	if (nptr[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (nptr[i] && nptr[i] >= 48 && nptr[i] <= 57)
	{
		nb = (nb * 10) + (nptr[i] - 48);
		i++;
	}
	return (nb * neg);
}

// int	main()
// {
// 	char	*str;

// 	str = " -345d";
// 	printf("Changed to int: %d", ft_atoi(str));
// 	return (0);
// }