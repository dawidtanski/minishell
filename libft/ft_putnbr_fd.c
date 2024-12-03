/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:35:49 by pjedrycz          #+#    #+#             */
/*   Updated: 2024/03/28 17:59:20 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <fcntl.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = n;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num *= -1;
	}
	if (num <= 9)
	{
		ft_putchar_fd(num + 48, fd);
	}
	else
	{
		ft_putnbr_fd(num / 10, fd);
		ft_putnbr_fd(num % 10, fd);
	}
}

// int	main()
// {
// 	printf("\n0 : \n");
// 	ft_putnbr_fd(0, 1);
// 	printf("\n1 : \n");
// 	ft_putnbr_fd(1, 1);
// 	printf("\n100 : \n");
// 	ft_putnbr_fd(100, 1);
// 	printf("\n659 : \n");
// 	ft_putnbr_fd(659, 1);
// 	printf("\n-5 : \n");
// 	ft_putnbr_fd(-5, 1);
// 	printf("\n-2147483648 : \n");
// 	ft_putnbr_fd(-2147483648, 1);
// 	int	fd = open("tst_ft_putnbr_fd", O_WRONLY | O_CREAT, 0777);
// 	ft_putnbr_fd(-593, fd);
// 	close(fd);
// 	return (0);
// }