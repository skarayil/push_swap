NAME        = push_swap
BONUS_NAME  = checker

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
INCLUDES    = -I./include -I./library/libft -I./library/printf -I./bonus/include

SRC_DIR     = sources
BONUS_DIR   = bonus/sources
OBJ_DIR     = objects
BONUS_OBJ_DIR = object_bonus

LIBFT_DIR   = library/libft
LIBFT       = $(LIBFT_DIR)/libft.a
PRINTF_DIR  = library/printf
PRINTF      = $(PRINTF_DIR)/libftprintf.a
GNL_DIR     = bonus/library/get_next_line
GNL_SRC     = $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
GNL_OBJ     = $(GNL_SRC:$(GNL_DIR)/%.c=$(BONUS_OBJ_DIR)/%.o)

SRCS        = $(SRC_DIR)/main.c \
              $(SRC_DIR)/array.c \
              $(SRC_DIR)/butterfly.c \
              $(SRC_DIR)/caterpillar.c \
              $(SRC_DIR)/parsing.c \
              $(SRC_DIR)/push.c \
              $(SRC_DIR)/rev_rotate.c \
              $(SRC_DIR)/rotate.c \
              $(SRC_DIR)/stack.c \
              $(SRC_DIR)/utils.c \
              $(SRC_DIR)/swap.c

BONUS_SRCS  = $(BONUS_DIR)/checker.c \
			  $(BONUS_DIR)/utils_bonus.c \
              $(BONUS_DIR)/swap_bonus.c \
              $(BONUS_DIR)/push_bonus.c \
              $(BONUS_DIR)/rotate_bonus.c \
              $(BONUS_DIR)/rev_rotate_bonus.c \
              $(BONUS_DIR)/array_bonus.c \
              $(BONUS_DIR)/parsing_bonus.c \
              $(BONUS_DIR)/stack_bonus.c 

OBJS        = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
BONUS_OBJS  = $(BONUS_SRCS:$(SRC_DIR)/%.c=$(BONUS_OBJ_DIR)/%.o)
BONUS_OBJS  := $(BONUS_OBJS:$(BONUS_DIR)/%.c=$(BONUS_OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT) $(PRINTF) $(BONUS_OBJS) $(GNL_OBJ)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(GNL_OBJ) $(LIBFT) $(PRINTF) -o $(BONUS_NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BONUS_OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BONUS_OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -I$(GNL_DIR) -c $< -o $@

$(BONUS_OBJ_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(BONUS_OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -I$(GNL_DIR) -c $< -o $@

$(BONUS_OBJ_DIR)/%.o: $(GNL_DIR)/%.c
	@mkdir -p $(BONUS_OBJ_DIR)
	@$(CC) $(CFLAGS) -I$(GNL_DIR) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(PRINTF):
	@$(MAKE) -C $(PRINTF_DIR) --no-print-directory

clean:
	@rm -rf $(OBJ_DIR) $(BONUS_OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@$(MAKE) -C $(PRINTF_DIR) clean --no-print-directory

fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)
	@rm -rf $(OBJ_DIR) $(BONUS_OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	@$(MAKE) -C $(PRINTF_DIR) fclean --no-print-directory

re: fclean all

.PHONY: all clean fclean re bonus