/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanski <dtanski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:32:55 by dtanski           #+#    #+#             */
/*   Updated: 2024/11/22 11:23:05 by dtanski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*ft_set_str(int len)
{
	char	*temp;

	temp = malloc((len + 1) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	temp[len] = '\0';
	return (temp);
}

static int	ft_intlen(long len)
{
	int	count;

	count = 0;
	if (len < 0)
	{
		count++;
		len = -len;
	}
	if (len == 0)
		count++;
	if (len > 0)
	{
		while (len)
		{
			len /= 10;
			count++;
		}
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	temp;
	int		i;
	char	*itoa;
	long	long_n;

	long_n = n;
	i = ft_intlen(long_n);
	itoa = ft_set_str(i);
	if (itoa == NULL)
		return (NULL);
	if (long_n == 0)
		itoa[0] = '0';
	if (n < 0)
	{
		itoa[0] = '-';
		long_n = -long_n;
	}
	while (long_n > 0)
	{
		temp = long_n % 10;
		long_n /= 10;
		itoa[i - 1] = temp + 48;
		i--;
	}
	return (itoa);
}
