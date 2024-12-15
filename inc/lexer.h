#ifndef LEXER_H
#define LEXER_H

#include "./minishell.h"

typedef enum e_token_type
{
    word = -1,
	token_null = 0,
    token_newline = '\n',
    token_pipe = '|',
    token_redirect_in = '<',
    token_redirect_out = '>',
    token_redirect_append = 5,
    token_heredoc = 2,
    token_env_var = 3,
    token_exit_status = 4,
    token_quote_single = '\'', 
    token_quote_double = '\"',
} t_token_type;

typedef struct	s_token
{
	char			*data;
	int				type;
	struct s_token	*next;
}		t_token;

typedef enum	s_state
{
	in_quote,
	in_dquote,
	general,
}		t_state;

typedef struct s_lexer
{
	t_token	*toks_list;
	int		num_toks;
}		t_lexer;

int	lexer_build(char *input, int size, t_lexer *lexer_buf);
void	lexer_destroy(t_lexer *lexerbuf);

#endif