# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 17:42:12 by quentinbeuk       #+#    #+#              #
#    Updated: 2025/05/07 11:47:32 by qbeukelm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include includes/make/colors.mk
include includes/make/files.mk


# ===== Names =====
CC 				= cc
CFLAGS 			= -Wall -Werror -Wextra # -fsanitize=address
VALGRIND_CMD	= valgrind --leak-check=full --show-leak-kinds=all ./miniRT


NAME_EXECUTABLE = miniRT

INC 			= inc
DIR_OBJ			= obj

# ===== Submodules =====
LIBFT			= ./includes/libft/libft.a

MLX42_DIR		= ./includes/MLX42
MLX42_URL		= https://github.com/codam-coding-college/MLX42.git

FRAMEWORKS 		= -framework Cocoa
FRAMEWORKS 		+= -framework OpenGL
FRAMEWORKS 		+= -framework IOKit

LDFLAGS 		+= $(FRAMEWORKS)


# ===== OS Specific =====
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	MLX42 = ./includes/MLX42/build/libmlx42.a -I include -ldl -lglfw -pthread -lm
endif
ifeq ($(OS),Windows_NT)
    # Windows code here
endif
ifeq ($(UNAME_S),Darwin)
    BREW_PREFIX = /Users/$(USER)/.brew
    MLX42 = ./includes/MLX42/build/libmlx42.a -L$(BREW_PREFIX)/lib -lglfw
    LDFLAGS += $(FRAMEWORKS)
    CFLAGS += -I$(BREW_PREFIX)/include
endif


# ===== Rules =====
all: $(NAME_EXECUTABLE)

$(NAME_EXECUTABLE): submodules-checked $(OBJ)
	@echo "$(BLUE)\nMaking miniRT ...\n$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME_EXECUTABLE) $(MLX42)
	@echo "$(GREEN)Compile successful\n$(RESET)"

$(DIR_OBJ)/%.o: $(DIR_SOURCES)/%.c | $(DIR_OBJ)
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@
	
$(DIR_OBJ)/%.o: $(DIR_SOURCES_CONTROLS)/%.c | $(DIR_OBJ)
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(DIR_OBJ)/%.o: $(DIR_SOURCES_MLX)/%.c | $(DIR_OBJ)
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(DIR_OBJ)/%.o: $(DIR_SOURCES_MLX_HOOKS)/%.c | $(DIR_OBJ)
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(DIR_OBJ)/%.o: $(DIR_SOURCES_PARSER)/%.c | $(DIR_OBJ)
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(DIR_OBJ)/%.o: $(DIR_SOURCES_PARSER_BUILD)/%.c | $(DIR_OBJ)
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(DIR_OBJ)/%.o: $(DIR_SOURCES_PARSER_COMP)/%.c | $(DIR_OBJ)
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(DIR_OBJ)/%.o: $(DIR_SOURCES_PARSER_VALIDATE)/%.c | $(DIR_OBJ)
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(DIR_OBJ)/%.o: $(DIR_SOURCES_RAYTRACER)/%.c | $(DIR_OBJ)
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(DIR_OBJ)/%.o: $(DIR_SOURCES_RAYTRACER_COLLISION)/%.c | $(DIR_OBJ)
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(DIR_OBJ)/%.o: $(DIR_SOURCES_RAYTRACER_RENDERING)/%.c | $(DIR_OBJ)
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(DIR_OBJ)/%.o: $(DIR_SOURCES_RAYTRACER_SHADING)/%.c | $(DIR_OBJ)
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(DIR_OBJ)/%.o: $(DIR_SOURCES_RAYTRACER_VEC)/%.c | $(DIR_OBJ)
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(DIR_OBJ)/%.o: $(DIR_SOURCES_UTILS)/%.c | $(DIR_OBJ)
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(DIR_OBJ)/%.o: $(DIR_SOURCERS_UTILS_PRINT)/%.c | $(DIR_OBJ)
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(DIR_OBJ):
	@mkdir -p $@


# ===== Clean =====
clean:
	@echo "$(BLUE)\nCleaning ...$(RESET)"
	@$(MAKE) clean --no-print-directory -C ./includes/libft/
	@$(RM) -rf submodules-checked
	@$(RM) -rf $(DIR_OBJ)
	@$(RM) -rf $(EXTRA_O)
	@$(RM) -rf $(OBJS)
	@echo "$(GREEN)$(BOLD)\nAll clean!\n$(RESET)"

fclean: clean
	@$(MAKE) fclean --no-print-directory -C ./includes/libft/
	@$(RM) $(NAME_EXECUTABLE)

re: fclean all


# ===== Valgrind =====
valgrind-run:
	$(VALGRIND_CMD) ./miniRT $(SCENE)

.PHONY: all clean submodules

include includes/make/submodules.mk
