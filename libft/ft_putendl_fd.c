/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:31:01 by pjedrycz          #+#    #+#             */
/*   Updated: 2024/03/22 18:38:11 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <fcntl.h>
#include <unistd.h>
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

// int	main()
// {
// 	ft_putendl_fd("test1", 1);
// 	int	fd = open("tst_putendl_fd", O_WRONLY | O_CREAT, 0777);
// 	ft_putendl_fd("test2", fd);
//	close(fd);
// 	return (0);
// }