# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antandre <antandre@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 15:56:18 by antandre          #+#    #+#              #
#    Updated: 2024/11/13 16:27:34 by antandre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Tool and flag definitions
RM = rm -f                 # Command to remove files
MKDIR_P = mkdir -p         # Command to create directories

CC = cc                    # C compiler
CCFLAGS = -Wall -Wextra -Werror # Compiler flags

LIBFT := ./lib/Libft

# Target definitions
NAME = push_swap

SRC = $(shell find src -name "*.c")
OBJ = $(patsubst src/%.c,bin/%.o,$(SRC))
DEPS = $(patsubst src/%.c,bin/%.d,$(SRC))

LIBS := $(LIBFT)/libft.a
HEADERS	:= -Iinclude -I $(LIBFT)/include

# Number of source files
NUM_SRC = $(words $(SRC))

# Default target
all: libft $(NAME)             # all target depends on $(NAME)

#Rules to create the libraries
libft:
	@echo "Building libft..."
	@$(MAKE) -C $(LIBFT) > /dev/null
	@echo "libft built succesfully"

# Rule to create the program
$(NAME): $(OBJ)
	@echo "Creating $(NAME)"
	@$(CC) $(OBJ) $(LIBS) $(HEADERS) -o $(NAME)
	@echo "$(NAME) created successfully"

# Rule to compile .c files to .o files in bin/
bin/%.o: src/%.c
	@$(MKDIR_P) $(dir $@)     # Create the directory for the object file if it doesn't exist
	@$(CC) $(CCFLAGS) -MMD -c $< -o $@ $(HEADERS)
	@$(eval COUNT=$(shell expr $(COUNT) + 1))
	@echo "[$(COUNT)/$(NUM_SRC)] Compiling $<\r"

# Clean up object and dependency files
clean:
	@$(RM) -r bin/            # Remove the bin/ directory
	@$(MAKE) --no-print-directory -C $(LIBFT) clean
	@echo "Cleaned up object and dependency files"

# Clean up everything including the static library
fclean: clean
	@$(RM) $(NAME)            # Remove the program
	@$(MAKE) --no-print-directory -C $(LIBFT) fclean
	@echo "Cleaned up $(NAME)"

# Rebuild everything
re: fclean all                # Run fclean and then all

# Include dependency files
-include $(DEPS)

# Declare phony targets
.PHONY: all, clean, fclean, re, libmlx, libft

# Initialize progress counter
COUNT = 0
