NAME = minishell

SRC_DIR	=./src
INC_DIR	=./inc
OBJ_DIR	=./obj

LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

INC			=	-I $(INC_DIR) -I $(LIBFT_DIR) -I /usr/include/readline
LIB			=	-L $(LIBFT_DIR) -lft -lreadline

## Sprawdzić, czy można używać wildcard ! Ktoś twierdził, że nie. Alternatywa - foreach
SRC			=	main.c \
			utils/init_data.c \
			env/env.c \
			env/env_set.c \
			lexer/parse_user_input.c \
			lexer/tokenizer.c \
			lexer/tokenizer_utils.c\
			lexer/tokenizer_utils_2.c\
			lexer/token_lst_utils.c \
			expansion/var_expander.c \
			expansion/var_expander_utils.c \
			expansion/identify_var.c \
			expansion/quotes_handler.c \
			expansion/quotes_remove.c \
			expansion/recover_value.c \
			expansion/replace_var.c \
			parser/create_commands.c \
			parser/parse_word.c \
			parser/fill_args_echo.c \
			parser/fill_args_echo_utils.c \
			parser/fill_args_default.c \
			parser/parse_input.c \
			parser/parse_trunc.c \
			parser/parse_append.c \
			parser/parse_heredoc.c \
			parser/parse_heredoc_utils.c \
			parser/parse_pipe.c \
			parser/cmd_lst_utils.c \
			parser/cmd_lst_utils_cleanup.c \
			builtins/export_builtin.c \
			builtins/unset_builtin.c \
			builtins/cd_builtin.c \
			builtins/env_builtin.c \
			builtins/pwd_builtin.c \
			builtins/echo_builtin.c \
			builtins/exit_builtin.c \
			execution/execute.c \
			execution/execute_cmd.c \
			execution/execute_utils.c \
			execution/parse_path.c \
			redirections/pipe.c \
			redirections/file_io.c \
			utils/exit.c \
			utils/error.c \
			utils/cleanup.c \
			signals/signal.c \

# OBJ
OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))

#TEXT COLORSS
GREEN		=	\033[0;32m
RED 		=	\033[0;31m
YELLOW		=	\033[0;33m
RESET		=	\033[0m

all:	$(NAME)

$(NAME):$(LIBFT) $(OBJ)
		@echo "$(RED)[ .. ] Compiling Mandatory..$(RESET)"
		@$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIB) -o $@
		@echo "$(GREEN)[ OK ]$(RESET) $(YELLOW)Mandatory Ready!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -o	$@ -c $<

$(LIBFT):
		@echo "$(RED)[ .. ] Compiling Libft..$(RESET)"
		@make -C $(LIBFT_DIR)
		@echo "$(GREEN)[ OK ]$(RESET) $(YELLOW)Libft ready!$(RESET)"

clean: 
		@make clean -C $(LIBFT_DIR)
		@rm -rf $(OBJ)
		@rm -rf $(SRC_DIR)/*.d
		@echo "Object files removed"

fclean: clean
		@make -s $@ -C $(LIBFT_DIR)
		@rm -rf $(NAME)
		@echo "Binary files removed"

re:		fclean all

.PHONY:	all clean fclean re
