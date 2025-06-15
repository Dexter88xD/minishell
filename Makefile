#This is the Captin speaking!
#Let's get this ship going!

# ──────────────────────────────────────────────────────────────────────────────
# COLOURS
# ──────────────────────────────────────────────────────────────────────────────

BLACK        = \\033[0;30m
RED          = \\033[0;31m
GREEN        = \\033[0;32m
YELLOW       = \\033[0;33m
BLUE         = \\033[0;34m
MAGENTA      = \\033[0;35m
CYAN         = \\033[0;36m
WHITE        = \\033[0;37m

BOLD_BLACK   = \\033[1;30m
BOLD_RED     = \\033[1;31m
BOLD_GREEN   = \\033[1;32m
BOLD_YELLOW  = \\033[1;33m
BOLD_BLUE    = \\033[1;34m
BOLD_MAGENTA = \\033[1;35m
BOLD_CYAN    = \\033[1;36m
BOLD_WHITE   = \\033[1;37m

RESET        = \\033[0m

# ──────────────────────────────────────────────────────────────────────────────
# COMPILER SETTINGS
# ──────────────────────────────────────────────────────────────────────────────

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g -I $(LIBFT) -I $(INC_DIR)
LIB_FLAGS	= -L$(LIBFT) -lft
RM			= rm -rf

# ──────────────────────────────────────────────────────────────────────────────
# DIRECTORIES
# ──────────────────────────────────────────────────────────────────────────────

LIBFT		= ./libft

BLT_DIR		= builtins

ENV_DIR		= env

EXEC_DIR	= executor

INC_DIR		= includes

PARSR_DIR	= parser

SIG_DIR		= signals

UTILS_DIR	= utils

OBJ_DIR		= obj

# ──────────────────────────────────────────────────────────────────────────────
# FILE LISTS
# ──────────────────────────────────────────────────────────────────────────────

NAME		= minishell


BLT_SRCS	= cd.c echo.c env.c exit.c export.c pwd.c unset.c

ENV_SRCS	=

EXEC_SRCS	= excution.c

INC_SRCS	=

PARSR_SRCS	= parser.c tokeniser.c filtering.c expander.c

SIG_SRCS	=

UTILS_SRCS	= linked_list_utils.c linked_list_del_utils.c expander_utils.c utils.c

SRCS		= main.c \
			$(addprefix $(BLT_DIR)/, $(BLT_SRCS))\
			$(addprefix $(ENV_DIR)/, $(ENV_SRCS))\
			$(addprefix $(EXEC_DIR)/, $(EXEC_SRCS))\
			$(addprefix $(PARSR_DIR)/, $(PARSR_SRCS))\
			$(addprefix $(SIG_DIR)/, $(SIG_SRCS))\
			$(addprefix $(UTILS_DIR)/, $(UTILS_SRCS))

OBJECTS		= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# ──────────────────────────────────────────────────────────────────────────────
# TARGETS
# ──────────────────────────────────────────────────────────────────────────────

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)/libft.a
	@$(CC) -o $(NAME) $(OBJECTS) $(LIB_FLAGS) -lreadline -lncurses
	@echo "$(BOLD_GREEN)Executable ready!$(RESET)"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(CYAN)Compiling $<!$(RESET)"


$(LIBFT)/libft.a:
	@$(MAKE) --no-print-directory -C $(LIBFT)

clean:
	@$(MAKE) --no-print-directory fclean -C $(LIBFT)
	@echo "$(BOLD_RED)Cleaning object files…$(RESET)"
	@$(RM) $(OBJ_DIR)

fclean: clean
	@echo "$(BOLD_RED)Cleaning executable…$(RESET)"
	@$(RM) $(NAME)

re: fclean all