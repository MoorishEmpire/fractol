# Variables
CC = cc
CFLAGS = -Wall -Werror -Wextra
CFLAGS += -DGL_SILENCE_DEPRECATION
RM = rm -f
NAME = fractol
HEADER = mandatory/fractol.h

# Sources
SRC = \
      mandatory/arguments.c \
      mandatory/events.c \
      mandatory/initialize.c \
      mandatory/main.c \
      mandatory/render.c \
      mandatory/utils.c
OBJ = $(SRC:.c=.o)

# MLX
MINILIBX_DIR = minilibx_opengl
MINILIBX_LIB = $(MINILIBX_DIR)/libmlx.a
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

# LIBFT
LIBFT_DIR = libft_mandatory
LIBFT_LIB = $(LIBFT_DIR)/libft.a

# Targets
all: $(NAME)

$(NAME): $(OBJ) $(MINILIBX_LIB) $(LIBFT_LIB)
	$(emo)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT_LIB) $(MINILIBX_LIB) $(MLX_FLAGS) -o $(NAME)

$(MINILIBX_LIB):
	@make -s -C $(MINILIBX_DIR)

$(LIBFT_LIB):
	@make -s -C $(LIBFT_DIR)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -s -C $(MINILIBX_DIR) clean
	@make -s -C $(LIBFT_DIR) clean
	@$(RM) $(OBJ)

fclean: clean
	@make -s -C $(MINILIBX_DIR) clean
	@make -s -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

define emo
@echo "\033[0;91m" #https://manytools.org/hacker-tools/ascii-banner/ -ANSI Shadow
@echo "\t███████╗██████╗  █████╗  ██████╗████████╗ ██████╗ ██╗"
@echo "\t██╔════╝██╔══██╗██╔══██╗██╔════╝╚══██╔══╝██╔═══██╗██║"
@echo "\t█████╗  ██████╔╝███████║██║        ██║   ██║   ██║██║"
@echo "\t██╔══╝  ██╔══██╗██╔══██║██║        ██║   ██║   ██║██║"
@echo "\t██║     ██║  ██║██║  ██║╚██████╗   ██║   ╚██████╔╝███████╗"
@echo "\t╚═╝     ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝   ╚═╝    ╚═════╝ ╚══════╝"
@echo "\033[0m"
@echo "\033[0;32m"
@echo "\t   ____                     _                           _    "
@echo "\t  | __ ) _   _    __ _ ___ | |      _ __ ___   ___  ___| |_  "
@echo "\t  |  _ \| | | |  / _\`|/ _ \  |_____| '\''_  \\ / _ \/ __| __| "
@echo "\t  | |_) | |_| | | (_| |  __/ |_____| | | | | | (_) \__ \ |_  "
@echo "\t  |____/ \__, |  \__,_|\___|_|     |_| |_| |_|\___/|___/\__| "
@echo "\t         |___/                                               "
@echo "\033[0m"
@echo "\033[0;33m"
@echo "\t  _ ____________    __  __ ___ ___  "
@echo "\t / |__ /__ /__  |  |  \/  | __|   \ "
@echo "\t | ||_ \|_ \ / /   | |\/| | _|| |) |"
@echo "\t |_|___/___//_/    |_|  |_|___|___/ "
@echo "\033[0m"
endef
                                                          
