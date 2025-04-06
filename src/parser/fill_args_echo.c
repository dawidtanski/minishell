/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_args_echo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:48:50 by dtanski           #+#    #+#             */
/*   Updated: 2025/02/19 23:16:52 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	create_args_echo_mode(t_token **token_node, t_command *last_cmd)
{
	int		nb_args;
	t_token	*tmp;
	int		i;

	remove_empty_var_args(token_node);
	tmp = *token_node;
	nb_args = count_args(tmp);
	last_cmd->args = malloc(sizeof(char *) * (nb_args + 2));
	if (!last_cmd->args)
		return (FAILURE);
	i = 0;
	last_cmd->args[i] = ft_strdup(last_cmd->cmd);
	i++;
	while (tmp->type == WORD || tmp->type == VAR)
	{
		if (tmp->join == true)
			last_cmd->args[i] = join_vars(&tmp);
		else
			last_cmd->args[i] = ft_strdup(tmp->str);
		i++;
		tmp = tmp->next;
	}
	last_cmd->args[i] = NULL;
	*token_node = tmp;
	return (SUCCESS);
}

int	add_args_echo_mode(t_token **token_node, t_command *last_cmd)
{
	int		len;
	int		nb_args;
	char	**new_tab;
	t_token	*tmp;

	remove_empty_var_args(token_node);
	tmp = *token_node;
	nb_args = count_args(tmp);
	len = 0;
	while (last_cmd->args[len])
		len++;
	new_tab = malloc(sizeof(char *) * (nb_args + len + 1));
	if (!new_tab)
		return (FAILURE);
	new_tab = copy_in_new_tab(len, new_tab, last_cmd, tmp);
	free(last_cmd->args);
	last_cmd->args = new_tab;
	while (tmp->type == WORD || tmp->type == VAR)
		tmp = tmp->next;
	*token_node = tmp;
	return (SUCCESS);
}
