/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanski <dtanski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:34:54 by dtanski           #+#    #+#             */
/*   Updated: 2024/11/22 11:28:51 by dtanski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_print_hex(unsigned long int ap, char *template, int len)
{
	if (ap <= 15)
		len += print_char(template[ap % 16]);
	else
	{
		len = ft_print_hex(ap / 16, template, len);
		len += print_char(template[ap % 16]);
	}
	return (len);
}

int	print_hex(unsigned long int ap, int imput)
{
	char	*template;

	if (imput == 'x')
		template = "0123456789abcdef";
	else
		template = "0123456789ABCDEF";
	return (ft_print_hex(ap, template, 0));
}
