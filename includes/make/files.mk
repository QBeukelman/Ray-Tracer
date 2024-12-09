# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    files.mk                                           :+:    :+:             #
#                                                      +:+                     #
#    By: quentinbeukelman <quentinbeukelman@stud      +#+                      #
#                                                    +#+                       #
#    Created: 2024/12/09 17:55:12 by quentinbeuk   #+#    #+#                  #
#    Updated: 2024/12/09 18:29:03 by quentinbeuk   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# ===== Sources =====
SOURCES						= main.c \

SOURCES_PARSER 				= parser.c \

# ===== Manage Directories =====
DIR_SOURCES					= sources
DIR_SOURCES_PARSER			= sources/parser

# ===== Object Files =====
OBJ = $(addprefix $(DIR_OBJ)/, $(SOURCES:.c=.o)) \
	$(addprefix $(DIR_OBJ)/, $(SOURCES_PARSER:.c=.o))
