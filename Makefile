#This is the brain of the whole operation.
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
CFLAGS		= -Wall -Wextra -Werror -I $(LIBFT) -I.
LIB_FLAGS	= -L$(LIBFT) -lft
RM			= rm -rf

# ──────────────────────────────────────────────────────────────────────────────
# DIRECTORIES
# ──────────────────────────────────────────────────────────────────────────────

# LIBFT	directory
LIBFT		= ./libft

# BUILTINS directory
BLT_DIR		= builtins

# ENVIRONMENT directory
ENV_DIR		= env

# EXECUTOR directory
EXEC_DIR	= executor

# INCLUDES directory
INC_DIR		= includes

# PARSER directory
PARSR_DIR	= parser

# SIGNALS directory
SIG_DIR		= signals

# UTILS directory
UTILS_DIR	= utils

# OBJECT FILES directory
OBJ_DIR		= obj

# ──────────────────────────────────────────────────────────────────────────────
# FILE LISTS
# ──────────────────────────────────────────────────────────────────────────────

# Executable
NAME		= minishell

# BUILTINS source files
BLT_SRCS	= placeholder.c

# ENVIRONMEN source files
ENV_SRCS	= placeholder.c

# EXECUTOR source files
EXEC_SRCS	= placeholder.c

# INCLUDES source files
INC_SRCS	= placeholder.c

# PARSER source files
PARSR_SRCS	= placeholder.c

# SIGNALS source files
SIG_SRCS	= placeholder.c

# UTILS	 source files
UTILS_SRCS	= placeholder.c

# ALL 	 source files
SRCS		= main.c \
			$(addprefix $(BLT_DIR)/, $(BLT_SRCS))\
			$(addprefix $(ENV_DIR)/, $(ENV_SRCS))\
			$(addprefix $(EXEC_DIR)/, $(EXEC_SRCS))\
			$(addprefix $(PARSR_DIR)/, $(PARSR_SRCS))\
			$(addprefix $(SIG_DIR)/, $(SIG_SRCS))\
			$(addprefix $(UTILS_DIR)/, $(UTILS_SRCS))

# Object files with path
OBJECTS		= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# ──────────────────────────────────────────────────────────────────────────────
# TARGETS
# ──────────────────────────────────────────────────────────────────────────────

# Phony targets
.PHONY: all clean fclean re

# Default: build executable
all: $(NAME)

# Link executable with libft
$(NAME): $(OBJECTS) $(LIBFT)/libft.a
	@$(CC) -o $(NAME) $(OBJECTS) $(LIB_FLAGS) -lreadline -lncurses
	@echo "$(BOLD_GREEN)Executable ready!$(RESET)"

# Compile .c to .o
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(CYAN)Compiling $<!$(RESET)"


# Build the static libft library
$(LIBFT)/libft.a:
	@$(MAKE) --no-print-directory -C $(LIBFT)

# Remove object files
clean:
	@$(MAKE) --no-print-directory fclean -C $(LIBFT)
	@echo "$(BOLD_RED)Cleaning object files…$(RESET)"
	@$(RM) $(OBJ_DIR)

# Remove objects & executable
fclean: clean
	@echo "$(BOLD_RED)Cleaning executable…$(RESET)"
	@$(RM) $(NAME)

# Rebuild everything from scratch
re: fclean all