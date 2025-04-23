#This is the brain of the whole operation.
#Let's get this ship going!

# ──────────────────────────────────────────────────────────────────────────────
# COMPILER SETTINGS
# ──────────────────────────────────────────────────────────────────────────────

# C compiler
CC			= cc

# Compiler warnings & includes
CFLAGS		= -Wall -Wextra -Werror -I $(LIBFT) -I.

# Link flags for libft
LIB_FLAGS	= -L$(LIBFT) -lft

# Remove files/dirs
RM			= rm -rf

# ──────────────────────────────────────────────────────────────────────────────
# DIRECTORIES
# ──────────────────────────────────────────────────────────────────────────────

# LIBFT			directory
LIBFT		= ./libft

# BUILTINS		directory
BLT_DIR		= builtins

# ENVIRONMENT	directory
ENV_DIR		= env

# EXECUTOR		directory
EXEC_DIR	= executor

# INCLUDES		directory
INC_DIR		= includes

# PARSER		directory
PARSR_DIR	= parser

# SIGNALS		directory
SIG_DIR		= signals

# UTILS			directory
UTILS_DIR	= utils

# OBJECT FILES	directory
OBJ_DIR		= obj

# ──────────────────────────────────────────────────────────────────────────────
# FILE LISTS
# ──────────────────────────────────────────────────────────────────────────────

# Executable
NAME		= minishell

# BUILTINS		source files
BLT_SRCS	= placeholder.c

# ENVIRONMENT	source files
ENV_SRCS	= placeholder.c

# EXECUTOR		source files
EXEC_SRCS	= placeholder.c

# INCLUDES		source files
INC_SRCS	= placeholder.c

# PARSER		source files
PARSR_SRCS	= placeholder.c

# SIGNALS		source files
SIG_SRCS	= placeholder.c

# UTILS			source files
UTILS_SRCS	= placeholder.c

# ALL 			source files
SRCS      = main.c \
			$(addprefix $(BLT_DIR)/, $(BLT_SRCS))\
			$(addprefix $(ENV_DIR)/, $(ENV_SRCS))\
			$(addprefix $(EXEC_DIR)/, $(EXEC_SRCS))\
			$(addprefix $(PARSR_DIR)/, $(PARSR_SRCS))\
			$(addprefix $(SIG_DIR)/, $(SIG_SRCS))\
			$(addprefix $(UTILS_DIR)/, $(UTILS_SRCS))

# Object files with path
OBJECTS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# ──────────────────────────────────────────────────────────────────────────────
# TARGETS
# ──────────────────────────────────────────────────────────────────────────────

# Phony targets
.PHONY: all clean fclean re

# Default: build executable
all: $(NAME)

# Link executable with libft
$(NAME): $(OBJECTS) $(LIBFT)/libft.a
	@$(CC) -o $(NAME) $(OBJECTS) $(LIB_FLAGS)
	@echo "Executable ready!"

# Compile .c to .o
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@


# Build the static libft library
$(LIBFT)/libft.a:
	@$(MAKE) --no-print-directory -C $(LIBFT)

# Remove object files
clean:
	@$(MAKE) --no-print-directory fclean -C $(LIBFT)
	@echo "Cleaning object files…"
	@$(RM) $(OBJ_DIR)

# Remove objects & executable
fclean: clean
	@echo "Cleaning executable…"
	@$(RM) $(NAME)

# Rebuild everything from scratch
re: fclean all