/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 13:03:16 by pjedrycz          #+#    #+#             */
/*   Updated: 2024/03/21 23:07:07 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

// //Prints char with it's index from the given string
// void print_char_with_index(unsigned int i, char* c)
// {
// 	printf("Index: %u, Char: %c\n", i, *c);
// }

// int main()
// {
// 	char str[] = "Hello, World!";
// 	ft_striteri(str, print_char_with_index);
// 	return (0);
// }