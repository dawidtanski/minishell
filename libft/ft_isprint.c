/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:06:11 by pjedrycz          #+#    #+#             */
/*   Updated: 2024/03/21 18:06:15 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
		return (c);
	return (0);
}

// int	main()
// {
// 	printf ("Wynik zadania %d", ft_isprint(-1));
// 	return (0);
// }