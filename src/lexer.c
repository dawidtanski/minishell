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

// int	match_pattern(const char *pattern, const char *filename)
// {
// 	if (*pattern == '\0' && *filename == '\0') 
// 		return (1); // Koniec wzorca i nazwy pliku, pasują
// 		// Dopasowanie `*`: może pasować do dowolnej liczby znaków
// 	if (*pattern == '*')
// 	{
// 		return (match_pattern(pattern + 1, filename) || (*filename && match_pattern(pattern, filename + 1)));
// 		// Dwie opcje - pierwsza - ignorujemy '*' we wzorcu
// 		// druga - kontynuujemy dopasowanie po '*'
// 	}
// 		// Dopasowanie `?`: pasuje do dokładnie jednego znaku
// 	if (*pattern == '?')
// 		return *filename && match_pattern(pattern + 1, filename + 1);
// 		// Dopasowanie pojedynczego znaku
// 	if (*pattern == *filename)
// 		return match_pattern(pattern + 1, filename + 1);
// 	return 0; // Brak dopasowania
// }

int	lexer_build(char *input, int size, t_lexer *lexer_buf)
{
	t_token	*token;
	char	c;
	int		state;
	int		token_type;
	// int		n_temp_tok;
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
	// n_temp_tok = 0;
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
			else if (token_type == token_whitespace)
			{
				if (j > 0)
				{
					token->data = '\0';
					token->next = malloc(sizeof(t_token));
					token = token->next;
					token_init(token, size - i);
					j = 0;
				}
			}
			else if (token_type == token_newline || token_type == token_pipe || token_type == token_redirect_in || token_type == token_redirect_out || token_type == token_redirect_append || token_type == token_heredoc || token_type == token_env_var || token_type == token_exit_status )
			{
				if (j > 0)
				{
					token->data = '\0';
					token->next = malloc(sizeof(t_token));
					token = token->next;
					token_init(token, size - i);
					j = 0;
				}
				token->data[0] = token_type;
				token->data[1] = '\0';
				token->type = token_type;
				token->next = malloc(sizeof(t_token));
				token = token->next;
				token_init(token, size - i);
			}
		}
		else if (state = in_dquote)
		{
			token->data[j++] = c;
			if (token_type = token_quote_double)
				state = general;
		}
		else if (state = in_quote)
		{
			token->data[j++] = c;
			if (token_type = token_quote_single)
				state = general;
		}
		if (token_type == token_null)
		{
			if (j > 0)
			{
				token->data[j] = '\0';
				// n_temp_tok++;
				j = 0;
			}
		}
			i++;
		}
	}