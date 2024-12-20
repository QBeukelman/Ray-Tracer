# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    submodules.mk                                      :+:    :+:             #
#                                                      +:+                     #
#    By: hein <hein@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2024/12/16 20:54:55 by hein          #+#    #+#                  #
#    Updated: 2024/12/21 00:36:05 by hein          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# ===== Check_files =====

CHECK_LIBFT := includes/libft/libft.a
CHECK_MLX42 := includes/MLX42/build/libmlx42.a

#======Rules======

$(LIBFT):
	@echo "$(BLUE)\nMaking LIBFT ...\n$(RESET)"
	@$(MAKE) --no-print-directory -C includes/libft

$(MLX42): add-mlx42 update-submodules
	@echo "$(BLUE)\nMaking MLX42 ...\n$(RESET)"
	@cmake includes/MLX42 -B includes/MLX42/build
	@make --no-print-directory -C includes/MLX42/build -j4

submodules-checked:
	@if [ ! -f "$(CHECK_LIBFT)" ] || [ ! -f "$(CHECK_MLX42)" ]; then \
		echo "$(BLUE)\nRequired files missing. Re-installing submodules ...\n$(RESET)"; \
		$(MAKE) --no-print-directory submodules; \
		touch submodules-checked; \
	fi

submodules: $(MLX42) $(LIBFT)
	@echo "$(GREEN)Submodules MLX42 and LIBFT succesfully initialized.\n$(RESET)"
	
add-mlx42:
	@if [ ! -d "$(MLX42_DIR)" ]; then \
		echo "$(BLUE)\nInstalling MLX42 ...\n$(RESET)"; \
		git submodule add --recurse $(MLX42_URL) $(MLX42_DIR); \
		echo "$(GREEN)\nInstallation succesful.\n$(RESET)"; \
	else \
		echo "$(GREEN)\nMLX42 library found.\n$(RESET)"; \
	fi

update-submodules:
	@echo "$(BLUE)\nInitializing and updating submodules ...\n$(RESET)"
	@git submodule update --init --recursive
	
