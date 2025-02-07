# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    files.mk                                           :+:    :+:             #
#                                                      +:+                     #
#    By: hesmolde <hesmolde@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2024/12/09 17:55:12 by quentinbeuk   #+#    #+#                  #
#    Updated: 2025/02/07 23:45:13 by hesmolde      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# ===== Sources =====
SOURCES						= main.c \

SOURCES_PARSER 				= parse_scene.c \
								scene_objects.c \
								split_string.c \

SOURCES_PARSER_VALIDATE		= build_ambient_light.c \
								build_camera.c \
								build_cylinder.c \
								build_light.c \
								build_plane.c \
								build_sphere.c \

SOURCES_PARSER_COMP			= build_color.c \
								build_int.c \
								build_point_value.c \
								build_position.c \

SOURCES_UTILS				= build_object_list.c \
								error.c \
								function_protection.c \
								print_scene.c \
								utils.c \
								vector.c \
								vector2.c \

SOURCES_RAYTRACER			= pixel_loop.c \
								background.c \

SOURCES_MLX_FUNCTIONS		= init_window.c \
								

# ===== Manage Directories =====
DIR_SOURCES					= sources
DIR_SOURCES_PARSER			= sources/parser
DIR_SOURCES_PARSER_VALIDATE	= sources/parser/build_objects
DIR_SOURCES_PARSER_COMP		= sources/parser/parse_components
DIR_SOURCES_RAYTRACER		= sources/raytracer
DIR_SOURCES_UTILS			= sources/utils
DIR_SOURCES_MLX_FUNCTIONS		= sources/mlx_functions

# ===== Object Files =====
OBJ = $(addprefix $(DIR_OBJ)/, $(SOURCES:.c=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCES_PARSER:.c=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCES_PARSER_VALIDATE:.c=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCES_PARSER_COMP:.c=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCES_RAYTRACER:.c=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCES_UTILS:.c=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCES_MLX_FUNCTIONS:.c=.o)) \
