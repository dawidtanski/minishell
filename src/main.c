/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:15:50 by pjedrycz          #+#    #+#             */
/*   Updated: 2024/12/02 22:53:42 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int main(int argc, char **argv, char **env)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	if (!start_check(&data, argc, argv) || !init_data(&data, env))
		exit_shell(NULL, Ex)///////


	return (0);
}