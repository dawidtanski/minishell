/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:07:35 by pjedrycz          #+#    #+#             */
/*   Updated: 2024/03/21 18:07:37 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"

int	ft_tolower(int c)
{
	if ((c >= 65) && (c <= 90))
		c = c + 32;
	return (c);
}

// int	main()
// {
// 	printf("after: %d", ft_tolower('U'));
// 	return (0);
// }