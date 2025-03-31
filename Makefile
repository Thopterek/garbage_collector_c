# **************************************************************************** #
#                           GARBAGE COLLECTOR FOR C                            #
# **************************************************************************** #

NAME = garbage_collector

SRCS =	bin_malloc.c	src/bin_bzero.c		src/bin_calloc.c \
		src/bin_itoa.c		src/bin_split.c		src/bin_strdup.c \
		src/bin_strjoin.c	src/bin_strlcat.c	src/bin_strlcpy.c \
		src/bin_strlen.c	src/bin_strmapi.c	src/bin_strrchr.c \
		src/bin_strtrim.c	src/bin_substr.c	src/bin_strchr.c

OBJ = $(SRCS:.c=.o)

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# The rule to build the project
all: $(NAME)

# Compiling bin_malloc
$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

# Compile object files
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Cleaning object files in both projects
clean:
	@rm -f $(OBJ)

# Full clean
fclean: clean
	@rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re