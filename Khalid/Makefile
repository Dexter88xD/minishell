#This is the brain of the whole operation.
#Let's get this ship going!

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(LIBFT) -I.
LIB_FLAGS = -L$(LIBFT) -lft
RM = rm -rf

LIBFT = ./libft/
SRC_DIR = src
BONUS_DIR = bonus
OBJ_DIR = obj
BONUS_OBJ_DIR = bonus_obj

NAME = minishell
B_NAME = minishell_bonus

SRCS = test.c
BSRCS = test_bonus.c

OBJECTS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
B_OBJECTS = $(addprefix $(BONUS_OBJ_DIR)/, $(BSRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)/libft.a
	@$(CC) -o $(NAME) $(OBJECTS) $(LIB_FLAGS)
	@echo "Executable ready!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: $(B_NAME)

$(B_NAME): $(B_OBJECTS) $(LIBFT)/libft.a
	@$(CC) -o $(B_NAME) $(B_OBJECTS) $(LIB_FLAGS)
	@echo "Bonus executable ready!!"

$(BONUS_OBJ_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(BONUS_OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT)/libft.a:
	@$(MAKE) --no-print-directory -C $(LIBFT)

clean:
	@$(MAKE) --no-print-directory fclean -C $(LIBFT)
	@echo "Cleaning object files!!"
	@$(RM) $(OBJ_DIR) $(BONUS_OBJ_DIR)

fclean : clean
	@echo "Cleaning executable!!"
	@$(RM) $(NAME) $(B_NAME)

re : fclean all

.PHONY : all clean fclean re bonus