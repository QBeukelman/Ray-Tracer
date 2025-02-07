# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    files.mk                                           :+:    :+:             #
#                                                      +:+                     #
#    By: hesmolde <hesmolde@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2024/12/09 17:55:12 by quentinbeuk   #+#    #+#                  #
#    Updated: 2025/02/07 01:12:55 by hein          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# ===== Sources =====
SOURCES						= main.c \

SOURCES_PARSER 				= build_scene.c \
								parser.c \
								scene_objects.c \
								split_string.c \

SOURCES_PARSER_VALIDATE		= build_ambient_light.c \
								build_camera.c \
								build_cylinder.c \
								build_light.c \
								build_plane.c \
								build_sphere.c \

SOURCES_PARSER_CLEAN		= memory_cleanup.c \

SOURCES_PARSER_COMP			= build_color.c \
								build_int.c \
								build_point_value.c \
								build_position.c \

SOURCES_UTILS				= build_object_list.c \
								error.c \
								function_protection.c \
								print_scene.c \
								vector.c \
								vector2.c \

SOURCES_RAYTRACER			= init_camera.c \
								init_window.c \
								pixel_loop.c \
								background.c \
								

# ===== Manage Directories =====
DIR_SOURCES					= sources
DIR_SOURCES_PARSER			= sources/parser
DIR_SOURCES_PARSER_VALIDATE	= sources/parser/build_objects
DIR_SOURCES_PARSER_CLEAN	= sources/parser/clean_up
DIR_SOURCES_PARSER_COMP		= sources/parser/parse_components
DIR_SOURCES_RAYTRACER		= sources/raytracer
DIR_SOURCES_UTILS			= sources/utils

# ===== Object Files =====
OBJ = $(addprefix $(DIR_OBJ)/, $(SOURCES:.c=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCES_PARSER:.c=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCES_PARSER_VALIDATE:.c=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCES_PARSER_CLEAN:.c=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCES_PARSER_COMP:.c=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCES_RAYTRACER:.c=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCES_UTILS:.c=.o)) \
