# This is the brain of the whole operation.
# Let's get this ship going!

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

CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
RM = rm -rf

SRC_DIR = src
OBJ_DIR = obj

NAME = libft.a

FILES =	ft_isalpha.c	ft_toupper.c	ft_isdigit.c	ft_tolower.c	ft_isalnum.c	ft_strchr.c		\
		ft_isascii.c	ft_strrchr.c	ft_isprint.c	ft_strncmp.c	ft_strcmp.c		ft_strlen.c		\
		ft_memset.c		ft_memcmp.c		ft_bzero.c		ft_memcpy.c		ft_memchr.c		ft_memmove.c	\
		ft_strnstr.c	ft_atoi.c		ft_strlcpy.c	ft_strlcat.c	ft_calloc.c		ft_strdup.c		\
		ft_strjoin.c	ft_strtrim.c	ft_split.c		ft_itoa.c		ft_strmapi.c	ft_striteri.c	\
		ft_substr.c		ft_printf.c		get_next_line.c					get_next_line_utils.c			\
		ft_putendl_fd.c					ft_putnbr_fd.c					ft_putchar_fd.c	ft_putstr_fd.c	\
		ft_lstadd_front_bonus.c			ft_lstsize_bonus.c				ft_lstlast_bonus.c				\
		ft_lstadd_back_bonus.c			ft_lstdelone_bonus.c			ft_lstclear_bonus.c				\
		ft_lstiter_bonus.c				ft_lstmap_bonus.c				ft_lstnew_bonus.c				\

OBJECTS = $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $^
	@echo "$(BOLD_GREEN)Library is ready!!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(MAGENTA)Compiling $<!$(RESET)"

clean:
	@echo "$(BOLD_RED)Cleaning libft files!!$(RESET)"
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
