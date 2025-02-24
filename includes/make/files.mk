# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    files.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qbeukelm <qbeukelm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 17:55:12 by quentinbeuk       #+#    #+#              #
#    Updated: 2025/02/22 12:57:00 by qbeukelm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ===== Sources =====
SOURCES						= main.c \

SOURCES_MLX					= init_window.c \

SOURCES_PARSER 				= build_object_list.c \
								parse_scene.c \
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

SOURCES_RAYTRACER			= pixel_loop.c \
								background.c \
								viewport.c \

SOURCES_RAYTRACER_COLLISION = sphere.c \

SOURCES_RAYTRACER_VECTOR	= vector_maths.c \
								vector_operations.c \

SOURCES_UTILS				= error.c \
								function_protection.c \
								print_scene.c \
								utils.c \


# ===== Manage Directories =====
DIR_SOURCES					= sources
DIR_SOURCES_MLX				= sources/mlx
DIR_SOURCES_PARSER			= sources/parser
DIR_SOURCES_PARSER_VALIDATE	= sources/parser/build_objects
DIR_SOURCES_PARSER_COMP		= sources/parser/parse_components
DIR_SOURCES_RAYTRACER		= sources/raytracer
DIR_SOURCES_RAYTRACER_COLLISION = sources/raytracer/collision
DIR_SOURCES_RAYTRACER_VEC	= sources/raytracer/vector
DIR_SOURCES_UTILS			= sources/utils

# ===== Object Files =====
OBJ = $(addprefix $(DIR_OBJ)/, $(SOURCES:.c=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCES_MLX:.c=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCES_PARSER:.c=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCES_PARSER_VALIDATE:.c=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCES_PARSER_COMP:.c=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCES_RAYTRACER:.c=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCES_RAYTRACER_VECTOR:.c=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCES_RAYTRACER_COLLISION:.c=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCES_UTILS:.c=.o)) \
