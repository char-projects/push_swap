# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/11 22:50:44 by cschnath          #+#    #+#              #
#    Updated: 2025/02/09 17:05:38 by cschnath         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIB_DIR = ../lib


SRC_NAMES = ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_printf.c \
	ft_printf_utils.c \
	ft_atof.c \
	get_next_line.c \
	get_next_line_utils.c \
	ft_charppfree.c \
	ft_printcharpp.c \


OBJS = $(SRC_NAMES:.c=.o)

SRCBON	= ft_lstnew_bonus.c \
	  ft_lstadd_front_bonus.c \
	  ft_lstsize_bonus.c \
	  ft_lstlast_bonus.c \
	  ft_lstadd_back_bonus.c \
	  ft_lstdelone_bonus.c \
	  ft_lstclear_bonus.c \
	  ft_lstiter_bonus.c \
	  ft_lstmap_bonus.c \

OBJSBON	= ${SRCBON:.c=.o}

# All target: Compile the library only if any object files are missing or outdated.
all: $(LIB_DIR)/$(NAME)

# Creating the library in the specified lib directory
$(LIB_DIR)/$(NAME): $(OBJS)
	@mkdir -p $(LIB_DIR)
	ar -rcs $(LIB_DIR)/$(NAME) $(OBJS)

# Rule to compile .c files into .o files
%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

# Bonus target: Add bonus object files to the library (if any are missing or outdated)
bonus: $(OBJSBON)
	ar -rcs $(LIB_DIR)/$(NAME) $(OBJSBON)

# Clean up object files (both main and bonus)
clean:
	@rm -f $(OBJS) $(OBJSBON)

# Fully clean: remove both object files and the static library
fclean: clean
	@rm -f $(LIB_DIR)/$(NAME)

# Rebuild everything from scratch
re: fclean all

.PHONY: all clean fclean re bonus
