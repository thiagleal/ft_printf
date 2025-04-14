# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsiqueir <tsiqueir@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/10 12:49:29 by tsiqueir          #+#    #+#              #
#    Updated: 2025/04/13 00:17:33 by tsiqueir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nome da biblioteca estatica
NAME = libftprintf.a

# Diretorios
SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj
LIBFT_DIR = libft

# Source e Objects
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
LIBFT_FILES = $(wildcard $(LIBFT_DIR)/src/**/*.o)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Include
INCLUDE = -I$(INC_DIR)

# Copilador, flags, compressor e remover
CC = cc
RM = rm -rf
COMPRESS = ar rcs
#CFLAGS = -Wall -Wextra -Werror

# Regras
all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS)
	@make libft -C $(LIBFT_DIR) > /dev/null
	@$(COMPRESS) $(NAME) $(OBJS) $(LIBFT_DIR)/**/**/*.o
	@echo "Library $(NAME) successfully created!"

clean:
	@$(RM) $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR) > /dev/null
	@echo "Object files and directories removed!"

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR) > /dev/null
	@echo "Library $(NAME) removed!"
	
re: fclean all

test: all $(NAME) src/main_ft_printf.c
	@$(CC) $(INCLUDE) -o test_ft_printf src/main_ft_printf.c $(NAME)
	@echo "Test created"

fcleantest: fclean
	@$(RM) test_ft_printf
	@echo "Test removed"

.PHONY: all clean fclean re test fcleantest
