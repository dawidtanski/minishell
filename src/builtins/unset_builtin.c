/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 21:29:57 by pjedrycz          #+#    #+#             */
/*   Updated: 2025/02/19 22:33:41 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Removes env variables given by user.
// First, checks if given variable has a valid key.
// 0 if all arguments are unset or 1 if one or more not.
int	unset_builtin(t_data *data, char **args)
{
	int	i;
	int	indx;
	int	ret;

	ret = EXIT_SUCCESS;
	i = 1;
	while (args[i])
	{
		if (!is_valid_env_var_key(args[i]) || ft_strchr(args[i], '=') != NULL)
		{
			errmsg_cmd("unset", args[i], "not a valid key", false);
			ret = EXIT_FAILURE;
		}
		else
		{
			indx = get_env_var_index(data->env, args[i]);
			if (indx != -1)
				remove_env_var(data, indx);
		}
		i++;
	}
	return (ret);
}
