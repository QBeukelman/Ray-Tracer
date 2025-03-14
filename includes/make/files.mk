# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    files.mk                                           :+:    :+:             #
#                                                      +:+                     #
#    By: hesmolde <hesmolde@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2024/12/09 17:55:12 by quentinbeuk   #+#    #+#                  #
#    Updated: 2025/03/09 20:17:31 by hesmolde      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# ===== Sources =====
SOURCES						= main.c \

SOURCES_MLX					= window_handler.c \

SOURCES_MLX_HOOKS			= key_enter.c \
								key_hooks.c \

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

SOURCES_PARSER_COMP			= build_colour.c \
								build_int.c \
								build_point_value.c \
								build_position.c \

SOURCES_RAYTRACER_RENDERING	= render_image.c \
								background.c \
								rays.c \
								world_matrix.c \

SOURCES_RAYTRACER_COLLISION = plane.c \
								sphere.c \

SOURCES_RAYTRACER_SHADING	= shading.c \
								shadow_ray.c \


SOURCES_RAYTRACER_VECTOR	= vector_maths.c \
								vector_operations.c \

SOURCES_UTILS				= colour_utils.c \
								error.c \
								function_protection.c \
								print_scene.c \
								utils.c \


# ===== Manage Directories =====
DIR_SOURCES					= sources
DIR_SOURCES_MLX				= sources/mlx
DIR_SOURCES_MLX_HOOKS		= sources/mlx/input_hooks
DIR_SOURCES_PARSER			= sources/parser
DIR_SOURCES_PARSER_VALIDATE	= sources/parser/build_objects
DIR_SOURCES_PARSER_COMP		= sources/parser/parse_components
DIR_SOURCES_RAYTRACER		= sources/raytracer
DIR_SOURCES_RAYTRACER_COLLISION = sources/raytracer/collision
DIR_SOURCES_RAYTRACER_SHADING = sources/raytracer/shading
DIR_SOURCES_RAYTRACER_RENDERING = sources/raytracer/rendering
DIR_SOURCES_RAYTRACER_VEC	= sources/raytracer/vector
DIR_SOURCES_UTILS			= sources/utils

# ===== Object Files =====
OBJ = $(addprefix $(DIR_OBJ)/, $(SOURCES:.c=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCES_MLX:.c=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCES_MLX_HOOKS:.c=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCES_PARSER:.c=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCES_PARSER_VALIDATE:.c=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCES_PARSER_COMP:.c=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCES_RAYTRACER:.c=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCES_RAYTRACER_VECTOR:.c=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCES_RAYTRACER_COLLISION:.c=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCES_RAYTRACER_SHADING:.c=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCES_RAYTRACER_RENDERING:.c=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCES_UTILS:.c=.o)) \
