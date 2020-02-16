#RTv1 Makefile
#@kcharla, 2010

NAME = RTv1

CC = clang

DEBUG =

CFLAGS = -Wall -Wextra -Werror $(DEBUG)

LIB_FT = libft/
LIB_FT_FILE = $(LIB_FT)/libft.a

LIB_SDL = libsdl/
LIB_SDL_FILE = $(LIB_SDL)/lib/libSDL2.dylib

INCLUDE = -I include/ -I $(LIB_FT)include/ -I $(LIB_SDL)include/SDL2/

BUILD_DIR = build/
SRC_DIR = src/

SRC_FILES_OLD = $(shell find $(SRC_DIR) -not \( -path $(MAIN_DIR) -prune \) -type f -name "*.c")

#SRC_FILES = $(shell find $(SRC_DIR) -not \( -path $(MAIN_DIR) -prune \) -type f -name "*.c")
#find src -type f -name '*.c' | sed "s/\$/ \\\\/"

SRC_FILES=\
src/color.c \
src/destroy.c \
src/events.c \
src/loop.c \
src/main.c \
src/texture.c \
src/window.c

O_FILES = $(patsubst $(SRC_DIR)%.c, $(BUILD_DIR)%.o, $(SRC_FILES))

SRC_DIRS = $(shell find $(SRC_DIR) -type d)
BUILD_DIRS_REC = $(patsubst $(SRC_DIR)%, $(BUILD_DIR)%, $(SRC_DIRS))

.PHONY: clean fclean all

all: $(NAME)

$(NAME): $(LIB_FT_FILE) $(LIB_SDL_FILE) $(BUILD_DIRS_REC) $(O_FILES)
	$(CC) $(CFLAGS) $(O_FILES) $(INCLUDE) -o $(NAME) $(LIB_FT_FILE) $(LIB_SDL_FILE)

$(LIB_FT_FILE):
	@make DEBUG=$(DEBUG) -C $(LIB_FT)

$(LIB_SDL_FILE):
	@make -C $(LIB_SDL)

$(BUILD_DIRS_REC):
	@mkdir -vp $(BUILD_DIRS_REC)

$(BUILD_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<
	@ar rc $(NAME) $@

clean:
	@make clean -C $(LIB_FT)
	@make clean -C $(LIB_SDL)
	@rm -rf $(BUILD_DIR)
	@echo "make: Done clean of \`$(NAME)'."

fclean: lclean
	@make fclean -C $(LIB_FT)
	@make fclean -C $(LIB_SDL)
	@rm -f $(NAME)
	@echo "make: Done full clean of \`$(NAME)'."

re: fclean all
	@echo "make: Done recompile of \`$(NAME)'."

lclean:
	@rm -rf $(BUILD_DIR)
	@echo "make: Done local clean of \`$(NAME)'."

lfclean: lclean
	@rm -f $(NAME)
	@echo "make: Done local full clean of \`$(NAME)'."

lre: lfclean all
	@echo "make: Done local recompile of \`$(NAME)'."
