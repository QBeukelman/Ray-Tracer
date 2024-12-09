# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: quentinbeukelman <quentinbeukelman@stud      +#+                      #
#                                                    +#+                       #
#    Created: 2024/12/09 17:42:12 by quentinbeuk   #+#    #+#                  #
#    Updated: 2024/12/09 18:32:43 by quentinbeuk   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

include includes/make/colors.mk
include includes/make/files.mk

# ===== Names =====
CC 				= gcc
CFlags 			= # -Wall -Werror -Wextra

NAME_EXECUTABLE = miniRT
LIBFT			= includes/libft

INC 			= inc
DIR_OBJ			= obj


# ===== OS Specific =====
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
# Linux
endif
ifeq ($(UNAME_S),Darwin)
# Mac
endif


# ===== Rules =====
all: $(NAME_EXECUTABLE)

$(NAME_EXECUTABLE): $(OBJ)
	@echo "$(BLUE)\nMaking LIBFT ...\n$(RESET)"
	@$(MAKE) -C $(LIBFT)
	@echo "$(BLUE)Making miniRT ...\n$(RESET)"
	@$(CC) $(CFLAGS) $^ $(LIBFT)/libft.a -o $(NAME_EXECUTABLE)
	@echo "$(GREEN)Compile successful\n$(RESET)"

$(DIR_OBJ)/%.o: $(DIR_SOURCES)/%.c | $(DIR_OBJ)
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(DIR_OBJ)/%.o: $(DIR_SOURCES_PARSER)/%.c | $(DIR_OBJ)
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(DIR_OBJ):
	@mkdir -p $@


# ===== Clean =====
clean:
	@echo "$(BLUE)\nCleaning ...$(RESET)"
	@$(MAKE) clean -C ./includes/libft/
	@$(RM) -rf $(DIR_OBJ)
	@$(RM) -rf $(EXTRA_O)
	@$(RM) -rf $(OBJS)
	@echo "$(GREEN)$(BOLD)\nAll clean!\n$(RESET)"

fclean: clean
	@$(MAKE) fclean -C ./includes/libft/
	@$(RM) $(NAME_EXECUTABLE)

re: fclean all

.PHONY: all clean
