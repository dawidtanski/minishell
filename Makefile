NAME = minishell

SRC_DIR	=./src
INC_DIR	=./inc

LIBFT_DIR = ./lib/libft
LIBFT = ./lib/libft/libft.a

CC = gcc
DEPFLAGS = -MP -MD
CFLAGS = -Wall -Wextra -Werror -g $(DEPFLAGS)

INC			=	-I ./inc -I $(LIBFT_DIR)
LIB			=	-L $(LIBFT_DIR) -lft
## Sprawdzić, czy można używać wildcard ! Ktoś twierdził, że nie. Alternatywa - foreach
SRC			= 	$(wildcard $(SRC_DIR)/*.c)
OBJ_FILES	= 	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))
# OBJ			=	$(SRC:.c=.o)

#TEXT COLORSS
GREEN		=	\033[0;32m
RED 		=	\033[0;31m
YELLOW		=	\033[0;33m
RESET		=	\033[0m

all: $(NAME)

$(NAME):$(LIBFT) $(OBJ)
		@echo "$(RED)[ .. ] Compiling Mandatory..$(RESET)"
		@$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIB) -o $@
		@echo "$(GREEN)[ OK ]$(RESET) $(YELLOW)Mandatory Ready!$(RESET)"

$(OBJ): $(SRC_DIR)/%.o: $(SRC_DIR)/%.c
		@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

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
