#ifndef LEXER_H
#define LEXER_H

#include "./minishell.h"

typedef enum	e_token_type
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIRECT_IN,
	TOKEN_REDIRECT_OUT,
	TOKEN_REDIRECT_APPEND,
	TOKEN_HEREDOC,
	TOKEN_ENV_VAR,
	TOKEN_EXIT_STATUS,
	TOKEN_QUOTE_SINGLE,
	TOKEN_QUOTE_DOUBLE,
}		t_token_type;

typedef struct	s_token
{
	t_token_type	type;
	char*			value;
	struct s_token	*next;
}		t_token;

typedef enum	s_state
{
	IN_QUOTE,
	IN_DQUOTE,
	GENERAL,
}

#endif