NAME        = so_long
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g3
INCLUDES    = -I./include -I./libft -I./minilibx-linux

LIBFT_DIR   = ./libft
LIBFT       = $(LIBFT_DIR)/libft.a

SRC_DIR     = src

SRCS        = $(SRC_DIR)/main.c \
              $(SRC_DIR)/parsing_all.c \
              $(SRC_DIR)/parsing.c \
              $(SRC_DIR)/utils.c	\
			  $(SRC_DIR)/parsing_player.c \
			  $(SRC_DIR)/game_one.c	\
			  $(SRC_DIR)/map_utils.c \

OBJS        = $(SRCS:.c=.o)

MLX_DIR     = minilibx-linux
MLX_LIB     = $(MLX_DIR)/libmlx.a

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(MLX_LIB):
	@make -C $(MLX_DIR)
	@echo "MiniLibX GOOD 🤓👍🔥"

$(NAME): $(MLX_LIB) $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) \
		-L$(LIBFT_DIR) -lft \
		-L$(MLX_DIR) -lmlx -lXext -lX11 -lm \
		-o $(NAME)
	@echo "TOUT EST GOOD 🤓👍🔥"

clean:
	@rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	@echo "TOUT LES FICHIERS .o 💀"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "so_long 💀"

re: fclean all

.PHONY: all clean fclean re
