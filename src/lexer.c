#include "../inc/minishell.h"
#include "../inc/lexer.h"

int get_token_type(char c, char next_c)
{
    if (c == '|')
        return (token_pipe);
	else if (c == ' ')
		return (token_whitespace);
    else if (c == '<')
        return (token_redirect_in);
    else if (c == '>')
        return (token_redirect_out);
    else if (c == '\'')
        return (token_quote_single);
    else if (c == '\"')
        return (token_quote_double);
    else if (c == '\n')
        return (token_newline);
    else if (c == '\0')
        return (token_null);
    else if (c == '$')
    {
        if (next_c == '?')
            return (token_exit_status);
        return (token_env_var);
    }
    return (token_word);
}

void	strip_quotes(char *src, char *dest)
{
	int		i;
	int		j;
	int		len;
	char	c;
	char	last_quote;

	len = ft_strlen(src);
	if (len <= 1)
	{
		strcpy(dest, src);
		return ;
	}
	i = 0;
	j = 0;
	last_quote = 0;
	while (i < len)
	{
		c = src[i];
		if ((c == '\'' || c == '\"') && last_quote == 0)
			last_quote = c;
		else if (c == last_quote)
			last_quote = 0;
		else
			dest[j++] = c;
		i++;
	}
	dest[j] = '\0';
}

void	token_init(t_token *token, int	data_size)
{
	token->data = malloc(data_size + 1);
	token->data[0] = 0;
	token->type = token_null;
}

void	token_destroy(t_token *token)
{
	if (token != NULL)
	{
		free(token->data);
		token_destroy(token->next);
		free(token);
	}
}

int	lexer_build(char *input, int size, t_lexer *lexer_buf)
{
	t_token	*token;
	char	c;
	int		state;
	int		token_type;
	int		n_temp_tok;
	int		i;
	int		j;
	
	if (lexer_buf == NULL || input == NULL)
		return (-1);
	if (size == 0 || input[0] == '\0')
	{
		lexer_buf->num_toks = 0;
		return (0);
	}
	lexer_buf->toks_list = malloc(sizeof(t_token));
	token = lexer_buf->toks_list;
	token_init(token, size);
	i = 0;
	j = 0;
	n_temp_tok = 0;
	state = general;
	c = input[i];

	while (i < size && (c != '\0'))
	{
		token_type = get_token_type(c);
		if (state = general)
		{
			if (token_type == token_quote_single)
			{
				state = in_quote;
				token->data[j++] = token_quote_single;
				token->type = token;
			}
			else if (token_type == token_quote_double)
			{
				state = in_dquote;
				token->data[j++] = token_quote_double;
				token->type = token;
			}
			else if (token_type == token_word)
			{
				token->data[j++] = c;
				token->type = token;
			}
		}
	}
}