# **************************************************************************** #
#                           GARBAGE COLLECTOR FOR C                            #
# **************************************************************************** #

NAME = garbage_collector

SRCS =	bin_malloc.c	bin_bzero.c		bin_calloc.c \
		bin_itoa.c		bin_split.c		bin_strdup.c \
		bin_strjoin.c	bin_strlcat.c	bin_strlcpy.c \
		bin_strlen.c	bin_strmapi.c	bin_strrchr.c \
		bin_strtrim.c	bin_substr.c	bin_strchr.c

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