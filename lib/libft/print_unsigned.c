/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanski <dtanski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:31:15 by dtanski           #+#    #+#             */
/*   Updated: 2024/11/22 11:38:18 by dtanski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_number_len(unsigned int number)
{
	int	len;

	len = 0;
	if (number == 0)
		return (1);
	while (number != 0)
	{
		number /= 10;
		len++;
	}
	return (len);
}

static void	write_function(char c)
{
	write(1, &c, 1);
}

static void	ft_putunsigned(unsigned int n)
{
	if (n >= 10)
	{
		ft_putunsigned(n / 10);
		ft_putunsigned(n % 10);
	}
	else
		write_function(n + '0');
}

int	print_unsigned(unsigned int number)
{
	ft_putunsigned(number);
	return (ft_number_len(number));
}
