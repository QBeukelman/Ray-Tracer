# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    files.mk                                           :+:    :+:             #
#                                                      +:+                     #
#    By: hesmolde <hesmolde@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2024/12/09 17:55:12 by quentinbeuk   #+#    #+#                  #
#    Updated: 2025/05/01 18:01:29 by quentinbeuk   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# ===== Sources =====
SOURCES						= main.c \

SOURCES_CONTROLS			= adjust_value.c \
								select_object.c \
								select_property.c \
								select_vec.c \

SOURCES_MLX					= mlx_run.c \
								mlx_window_handler.c \

SOURCES_MLX_HOOKS			= key_enter.c \
								key_hooks.c \

SOURCES_PARSER 				= build_object_list.c \
								parse_scene.c \
								scene_objects.c \
								split_string.c \

SOURCES_PARSER_BUILD		= build_ambient_light.c \
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
SOURCES_PARSER_VALIDATE		= index_objects.c \
								parser_post_validation.c \
								parser_pre_validation.c \

SOURCES_RAYTRACER_RENDERING	= render_image.c \
								background.c \
								viewport.c \

SOURCES_RAYTRACER_COLLISION = sphere.c \

SOURCES_RAYTRACER_COLLISION = plane.c \
								sphere.c \

SOURCES_RAYTRACER_SHADING	= shading.c \
								shadow_ray.c \

SOURCES_RAYTRACER_VECTOR	= vector_maths.c \
								vector_operations.c \

SOURCES_UTILS				= error.c \
								function_protection.c \
								print_scene.c \
SOURCES_UTILS				= colour_utils.c \
								error.c \
								utils.c \
								radians_math.c \

SOURCERS_UTILS_PRINT		= print_cylinder.c \
								print_lights_camera.c \
								print_sphere.c \
								print_plane.c \
								print_scene.c \
								print_utils.c \


# ===== Manage Directories =====
DIR_SOURCES					= sources
DIR_SOURCES_CONTROLS		= sources/controls
DIR_SOURCES_MLX				= sources/mlx
DIR_SOURCES_PARSER			= sources/parser
DIR_SOURCES_PARSER_BUILD	= sources/parser/build_objects
DIR_SOURCES_PARSER_COMP		= sources/parser/parse_components
DIR_SOURCES_PARSER_VALIDATE = sources/parser/parse_validation
DIR_SOURCES_RAYTRACER		= sources/raytracer
DIR_SOURCES_RAYTRACER_COLLISION = sources/raytracer/collision
DIR_SOURCES_RAYTRACER_VEC	= sources/raytracer/vector
DIR_SOURCES_UTILS			= sources/utils
DIR_SOURCERS_UTILS_PRINT	= sources/utils/print_utils

# ===== Object Files =====
OBJ = $(addprefix $(DIR_OBJ)/, $(SOURCES:.c=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCES_CONTROLS:.c=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCES_MLX:.c=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCES_PARSER:.c=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCES_PARSER_BUILD:.c=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCES_PARSER_COMP:.c=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCES_PARSER_VALIDATE:.c=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCES_RAYTRACER:.c=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCES_RAYTRACER_VECTOR:.c=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCES_RAYTRACER_COLLISION:.c=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCES_UTILS:.c=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCERS_UTILS_PRINT:.c=.o)) \
