#include "../inc/minishell.h"
#include <ctype.h>

// Program służący do parsowania licz oraz operatorów matematycznych

typedef	struct s_tokenizer
{
    char	*input; // Ciąg znaków wpisywany do terminala, który poddany będzie parsowaniu
    int		pos; // pozycja znaku w ciągu znaków
    char	cur_token; // wskaźnik na aktualny token
}		t_tokenizer;

typedef struct s_opinfo
{
    int		prec; // precedense - priorytet operatora określony przez wartość liczbową
    char	assoc; // asocjatywność - prawostronna lub lewostronna (P,L) - określa kolejność wykonywania działań w przypadku tokenów o tym samym priorytecie
}		t_opinfo;

t_opinfo	op_map[256]; // Inicjujemy tablicę z wszystkimi znakami ascii

void init_opinfo_map()
{
	// Przypisanie asocjatywności i wartości priorytetu dla każdego operatora
    op_map['+'] = (t_opinfo){1, 'L'};
    op_map['-'] = (t_opinfo){1, 'L'};
    op_map['*'] = (t_opinfo){2, 'L'};
    op_map['/'] = (t_opinfo){2, 'L'};
    op_map['^'] = (t_opinfo){3, 'R'};
}

int	op_switch (char op, int lhs, int rhs)
{
	if (op == '+')
		return (lhs + rhs);
	else if (op == '-')
		return (lhs - rhs);
	else if (op == '*')
		return (lhs * rhs);
	else if (op == '/')
		return (lhs / rhs);
	else if (op == '^')
		return (int)ft_pow(lhs, rhs);
	printf("Unknown operator: %c\n", op);
	exit(1);
	return (0);
}



// Funkcja pomija białe znaki następnie przypisuje token z wartości wpisanej w terminal przez użytkownika do tokenizer->input
void next_token(t_tokenizer *tokenizer)
{
    while (ft_isspace(tokenizer->input[tokenizer->pos]))
		tokenizer->pos++;
    tokenizer->cur_token = tokenizer->input[tokenizer->pos++];
}

int parse_atom(t_tokenizer *tokenizer);

int parse_expr(t_tokenizer *tokenizer, int min_prec)
{
    int			lhs;
	int			rhs;
	char		op;
	t_opinfo	op_info;
	int			next_min_prec;
	 
	lhs = parse_atom(tokenizer);
    while (1)
	{
        op = tokenizer->cur_token;
        op_info = op_map[(unsigned char)op];
        if (op_info.prec < min_prec) break;
		if (op_info.assoc == 'L')
			next_min_prec = op_info.prec + 1;
		else
			next_min_prec = op_info.prec;
        next_token(tokenizer);
        rhs = parse_expr(tokenizer, next_min_prec);
		lhs = op_switch(op, lhs, rhs);
    }

    return (lhs);
}

// Atom to specyficzny rodzaj tokenów - jest nim liczba lub wyrażenie w nawiasach 

int parse_atom(t_tokenizer *tokenizer)
{
	int	val;

    if (tokenizer->cur_token == '(')
	{
        next_token(tokenizer);
        val = parse_expr(tokenizer, 1);
        if (tokenizer->cur_token != ')')
		{
            printf("Unmatched '('\n");
            exit(1);
        }
        next_token(tokenizer);
        return (val);
    }
	else if (isdigit(tokenizer->cur_token))
	{
        val = 0;
        while (isdigit(tokenizer->cur_token))
		{
            val = val * 10 + (tokenizer->cur_token - '0');
            next_token(tokenizer);
        }
        return (val);
    }
	else
	{
        printf("Unexpected token: %c\n", tokenizer->cur_token);
        exit(1);
    }
}

int main() {
    char input[] = "1 + 3 ^ 2 * 3 + 9 * 2";
    t_tokenizer tokenizer = {input, 0, 0};
    init_opinfo_map();
    next_token(&tokenizer);
    int result = parse_expr(&tokenizer, 1);
    printf("Result: %d\n", result);
    return 0;
}