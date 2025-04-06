/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 22:54:00 by pjedrycz          #+#    #+#             */
/*   Updated: 2025/03/07 08:32:41 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Reallocates memory for global variable (g_env_vars)
// and returns pointer to new variables. 
// NULL if operation fails.
static char	**realloc_env_vars(t_data *data, int size)
{
	char	**new_env;
	int		i;

	new_env = ft_calloc(size + 1, sizeof * new_env);
	if (!new_env)
		return (NULL);
	i = 0;
	while (data->env[i] && i < size)
	{
		new_env[i] = ft_strdup(data->env[i]);
		free_ptr(data->env[i]);
		i++;
	}
	free(data->env);
	return (new_env);
}

// Adds an environment variable with the given key
// corresponding to the given value. If the key already
// exists in the environment variables, the value will
// be overwritten. If not, it creates a new entry.
// Returns 1 if the operation was successful, or 0 if failes.
bool	set_env_var(t_data *data, char *key, char *value)
{
	int		indx;
	char	*tmp;

	indx = get_env_var_index(data->env, key);
	if (value == NULL)
		value = "";
	tmp = ft_strjoin("=", value);
	if (!tmp)
		return (false);
	if (indx != -1 && data->env[indx])
	{
		free_ptr(data->env[indx]);
		data->env[indx] = ft_strjoin(key, tmp);
	}
	else
	{
		indx = env_var_count(data->env);
		data->env = realloc_env_vars(data, indx + 1);
		if (!data->env)
			return (false);
		data->env[indx] = ft_strjoin(key, tmp);
	}
	free_ptr(tmp);
	return (true);
}

// Removes the variable at the given index from the
// environment variables.
// Returns 1 if the removal was successful, 0 if case
// of an invalid index or a memory allocation error.
bool	remove_env_var(t_data *data, int indx)
{
	int	i;
	int	count;

	if (indx > env_var_count(data->env))
		return (false);
	free_ptr(data->env[indx]);
	i = indx;
	count = indx;
	while (data->env[i + 1])
	{
		data->env[i] = ft_strdup(data->env[i + 1]);
		free_ptr(data->env[i + 1]);
		count++;
		i++;
	}
	data->env = realloc_env_vars(data, count);
	if (!data->env)
		return (false);
	return (true);
}
