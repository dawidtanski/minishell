/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_args_default.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:28:45 by dtanski           #+#    #+#             */
/*   Updated: 2025/02/19 23:16:17 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	count_arguments(t_token *tmp)
{
	int	i;

	i = 0;
	while (tmp && (tmp->type == WORD || tmp->type == VAR))
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	create_args_default_mode(t_token **token_node, t_command *last_cmd)
{
	int		i;
	int		args_num;
	t_token	*tmp;

	i = 0;
	tmp = *token_node;
	args_num = count_arguments(tmp);
	last_cmd->args = malloc(sizeof(char *) * (args_num + 2));
	if (!last_cmd->args)
		return (FAILURE);
	tmp = *token_node;
	i = 0;
	last_cmd->args[i] = ft_strdup(last_cmd->cmd);
	i++;
	while (tmp->type == WORD || tmp->type == VAR)
	{
		last_cmd->args[i] = ft_strdup(tmp->str);
		i++;
		tmp = tmp->next;
	}
	last_cmd->args[i] = NULL;
	*token_node = tmp;
	return (SUCCESS);
}

static char	**copy_default_in_new_tab(int len, char **new_tab,
	t_command *last_cmd, t_token **tk_node)
{
	int		i;
	t_token	*tmp;

	i = 0;
	tmp = *tk_node;
	while (i < len)
	{
		new_tab[i] = last_cmd->args[i];
		i++;
	}
	while (tmp->type == WORD || tmp->type == VAR)
	{
		new_tab[i] = ft_strdup(tmp->str);
		i++;
		tmp = tmp->next;
	}
	new_tab[i] = NULL;
	return (new_tab);
}

int	add_args_default_mode(t_token **token_node, t_command *last_cmd)
{
	int		i;
	int		len;
	char	**new_tab;
	t_token	*tmp;

	i = 0;
	tmp = *token_node;
	while (tmp->type == WORD || tmp->type == VAR)
	{
		i++;
		tmp = tmp->next;
	}
	len = 0;
	while (last_cmd->args[len])
		len++;
	new_tab = malloc(sizeof(char *) * (i + len + 1));
	if (!new_tab)
		return (FAILURE);
	new_tab = copy_default_in_new_tab(len, new_tab, last_cmd, token_node);
	free(last_cmd->args);
	last_cmd->args = new_tab;
	*token_node = tmp;
	return (SUCCESS);
}

int	fill_args(t_token **token_node, t_command *last_cmd)
{
	if (!ft_strcmp(last_cmd->cmd, "echo"))
	{
		if (!(last_cmd->args))
			return (create_args_echo_mode(token_node, last_cmd));
		else
			return (add_args_echo_mode(token_node, last_cmd));
	}
	else
	{
		if (last_cmd && !(last_cmd->args))
			return (create_args_default_mode(token_node, last_cmd));
		else
			return (add_args_default_mode(token_node, last_cmd));
	}
	return (SUCCESS);
}
