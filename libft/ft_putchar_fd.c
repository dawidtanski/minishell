/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:48:23 by pjedrycz          #+#    #+#             */
/*   Updated: 2024/03/22 18:38:33 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <fcntl.h>
#include <unistd.h>
#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

// int	main()
// {
// 	ft_putchar_fd('a', 1);
// 	int fd = open("testputchar", O_WRONLY | O_CREAT, 0777);
// 	ft_putchar_fd('b', fd);
// 	close(fd);
// 	return (0);
// }