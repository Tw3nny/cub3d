NAME		= cub3d

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
CPPFLAGS	= -I include -I $(LIBFT_DIR) -D BUFFER_SIZE=4096
RM			= rm -rf

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRC_DIR		= src
OBJ_DIR		= obj

SRC			= main.c \
			  parsing/parse_scene.c \
			  parsing/read_file.c \
			  parsing/parse_header.c \
			  parsing/parse_color.c \
			  parsing/parse_map.c \
			  parsing/check_map.c \
			  parsing/scene_utils.c

OBJ			= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

LDLIBS		= -lm

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) $(LDLIBS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus
