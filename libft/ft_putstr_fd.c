/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:50:08 by pjedrycz          #+#    #+#             */
/*   Updated: 2024/03/22 18:29:23 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <fcntl.h>
#include <unistd.h>
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write (fd, &s[i], 1);
		i++;
	}
}

// int	main()
// {
// 	ft_putstr_fd("test1", 1);
// 	int	fd = open("tst_ft_putstr_fd", O_WRONLY | O_CREAT, 0777);
// 	ft_putstr_fd("test2", fd);
// 	close(fd);
// 	return (0);
// }