#include ".../inc/minishell.h"

typedef struct {
    char *input;
    int pos;
    char cur_token;
} Tokenizer;

typedef struct {
    int prec;
    char assoc;
} OpInfo;

OpInfo OPINFO_MAP[256];

void init_opinfo_map() {
    OPINFO_MAP['+'] = (OpInfo){1, 'L'};
    OPINFO_MAP['-'] = (OpInfo){1, 'L'};
    OPINFO_MAP['*'] = (OpInfo){2, 'L'};
    OPINFO_MAP['/'] = (OpInfo){2, 'L'};
    OPINFO_MAP['^'] = (OpInfo){3, 'R'};
}

void next_token(Tokenizer *tokenizer) {
    while (isspace(tokenizer->input[tokenizer->pos])) tokenizer->pos++;
    tokenizer->cur_token = tokenizer->input[tokenizer->pos++];
}

int parse_atom(Tokenizer *tokenizer);

int parse_expr(Tokenizer *tokenizer, int min_prec) {
    int lhs = parse_atom(tokenizer);

    while (1) {
        char op = tokenizer->cur_token;
        OpInfo op_info = OPINFO_MAP[(unsigned char)op];
        if (op_info.prec < min_prec) break;

        int next_min_prec = (op_info.assoc == 'L') ? op_info.prec + 1 : op_info.prec;
        next_token(tokenizer);
        int rhs = parse_expr(tokenizer, next_min_prec);

        switch (op) {
            case '+': lhs += rhs; break;
            case '-': lhs -= rhs; break;
            case '*': lhs *= rhs; break;
            case '/': lhs /= rhs; break;
            case '^': lhs = (int)pow(lhs, rhs); break;
            default: printf("Unknown operator: %c\n", op); exit(1);
        }
    }

    return lhs;
}

int parse_atom(Tokenizer *tokenizer) {
    if (tokenizer->cur_token == '(') {
        next_token(tokenizer);
        int val = parse_expr(tokenizer, 1);
        if (tokenizer->cur_token != ')') {
            printf("Unmatched '('\n");
            exit(1);
        }
        next_token(tokenizer);
        return val;
    } else if (isdigit(tokenizer->cur_token)) {
        int val = 0;
        while (isdigit(tokenizer->cur_token)) {
            val = val * 10 + (tokenizer->cur_token - '0');
            next_token(tokenizer);
        }
        return val;
    } else {
        printf("Unexpected token: %c\n", tokenizer->cur_token);
        exit(1);
    }
}

int main() {
    char input[] = "2 + 3 ^ 2 * 3 + 4";
    Tokenizer tokenizer = {input, 0, 0};
    init_opinfo_map();
    next_token(&tokenizer);
    int result = parse_expr(&tokenizer, 1);
    printf("Result: %d\n", result);
    return 0;
}