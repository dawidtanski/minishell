/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:07:17 by pjedrycz          #+#    #+#             */
/*   Updated: 2024/03/21 18:07:18 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"

int	ft_toupper(int c)
{
	if ((c >= 97) && (c <= 122))
		c = c - 32;
	return (c);
}

// int	main()
// {
// 	printf("after: %d", ft_toupper('u'));
// 	return (0);
// }