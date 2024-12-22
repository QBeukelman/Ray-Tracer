# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    files.mk                                           :+:    :+:             #
#                                                      +:+                     #
#    By: quentinbeukelman <quentinbeukelman@stud      +#+                      #
#                                                    +#+                       #
#    Created: 2024/12/09 17:55:12 by quentinbeuk   #+#    #+#                  #
#    Updated: 2024/12/20 18:04:29 by hein          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# ===== Sources =====
SOURCES						= main.c \

SOURCES_PARSER 				= parser.c \
								build_scene.c \
								scene_objects.c \
								split_string.c \

SOURCES_PARSER_VALIDATE		= add_object.c \
								build_ambient_light.c \

SOURCES_PARSER_COMP			= build_color.c \

SOURCES_UTILS				= error.c \
								function_protection.c \

# ===== Manage Directories =====
DIR_SOURCES					= sources
DIR_SOURCES_PARSER			= sources/parser
DIR_SOURCES_PARSER_VALIDATE	= sources/parser/build_objects
DIR_SOURCES_PARSER_COMP		= sources/parser/parse_components
DIR_SOURCES_UTILS			= sources/utils

# ===== Object Files =====
OBJ = $(addprefix $(DIR_OBJ)/, $(SOURCES:.c=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCES_PARSER:.c=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCES_PARSER_VALIDATE:.c=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCES_PARSER_COMP:.c=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCES_UTILS:.c=.o)) \
