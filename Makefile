# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: qbeukelm <qbeukelm@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2024/12/09 17:42:12 by quentinbeuk   #+#    #+#                  #
#    Updated: 2025/02/23 11:05:47 by quentinbeuk   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

include includes/make/colours.mk
include includes/make/files.mk


# ===== Names =====
CC 				= cc
# CFLAGS 			= -Wall -Werror -Wextra
CFLAGS 			= -fsanitize=address

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
	
$(DIR_OBJ)/%.o: $(DIR_SOURCES_MLX)/%.c | $(DIR_OBJ)
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(DIR_OBJ)/%.o: $(DIR_SOURCES_PARSER)/%.c | $(DIR_OBJ)
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(DIR_OBJ)/%.o: $(DIR_SOURCES_PARSER_VALIDATE)/%.c | $(DIR_OBJ)
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(DIR_OBJ)/%.o: $(DIR_SOURCES_PARSER_COMP)/%.c | $(DIR_OBJ)
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(DIR_OBJ)/%.o: $(DIR_SOURCES_RAYTRACER)/%.c | $(DIR_OBJ)
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(DIR_OBJ)/%.o: $(DIR_SOURCES_RAYTRACER_COLLISION)/%.c | $(DIR_OBJ)
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(DIR_OBJ)/%.o: $(DIR_SOURCES_RAYTRACER_VEC)/%.c | $(DIR_OBJ)
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(DIR_OBJ)/%.o: $(DIR_SOURCES_UTILS)/%.c | $(DIR_OBJ)
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
valgrind: all
	@echo "$(BLUE)\nTo create a Valgrind executable, run the following command:\n$(RESET)"
	@echo "export EXEC_VALGRIND="valgrind --suppressions=MLX42.supp --leak-check=full --show-leak-kinds=all ./miniRT""
	@echo "$(GREEN)\nRun $$EXEC_VALGRIND <file_name.rt> to execute with Valgrind.\n$(RESET)"

.PHONY: all clean submodules

include includes/make/submodules.mk