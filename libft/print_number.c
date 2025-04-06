/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanski <dtanski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:34:48 by dtanski           #+#    #+#             */
/*   Updated: 2024/11/22 11:29:02 by dtanski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_number_len(int number)
{
	int	len;

	len = 0;
	if (number == 0)
		return (1);
	if (number < 0)
		len++;
	while (number != 0)
	{
		number /= 10;
		len++;
	}
	return (len);
}

int	print_number(int number)
{
	ft_putnbr_fd(number, 1);
	return (ft_number_len(number));
}
