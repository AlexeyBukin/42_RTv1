#RTv1 Makefile
#@kcharla, 2010

NAME = RTv1

CC = clang

LIBM =
DEBUG =

CFLAGS = -Wall -Wextra -Werror $(DEBUG)

LIB_FT = libft/
LIB_FT_FILE = $(LIB_FT)/libft.a

LIB_SDL_EXTENSION = .dylib
LIB_SDL = libsdl/
LIB_SDL_FILE = $(LIB_SDL)/lib/libSDL2$(LIB_SDL_EXTENSION)

INCLUDE = -I include/ -I $(LIB_FT)include/ -I $(LIB_SDL)include/SDL2/

HEADER=include/rtv1.h

BUILD_DIR = build/
SRC_DIR = src/

#SRC_FILES = $(shell find $(SRC_DIR) -not \( -path $(MAIN_DIR) -prune \) -type f -name "*.c")
#find src -type f -name '*.c' | sed "s/\$/ \\\\/"

SRC_FILES=\
src/camera.c \
src/color.c \
src/color_2.c \
src/destroy.c \
src/double3.c \
src/double3_str.c \
src/events.c \
src/figures/cylinder.c \
src/figures/plane.c \
src/infinity.c \
src/loop.c \
src/main.c \
src/project.c \
src/rtv1_init.c \
src/scene.c \
src/test/test_dist.c \
src/test/test_time.c \
src/test/test_trace.c \
src/texture.c \
src/trace.c \
src/utils.c \
src/vector_math.c \
src/window.c \


O_FILES = $(patsubst $(SRC_DIR)%.c, $(BUILD_DIR)%.o, $(SRC_FILES))

SRC_DIRS = $(shell find $(SRC_DIR) -type d)
BUILD_DIRS_REC = $(patsubst $(SRC_DIR)%, $(BUILD_DIR)%, $(SRC_DIRS))

.PHONY: clean fclean all

all: $(NAME)

$(NAME): $(LIB_FT_FILE) $(LIB_SDL_FILE) $(BUILD_DIRS_REC) $(O_FILES)
	@echo "\033[0;32m" "Building RTv1 executable..." "\033[0m"
	$(CC) $(CFLAGS) $(O_FILES) $(INCLUDE) -o $(NAME) $(LIB_FT_FILE) $(LIB_SDL_FILE) $(LIBM)
	@echo "\033[0;32m" "Done" "\033[0m"

$(LIB_FT_FILE):
	@make DEBUG=$(DEBUG) -C $(LIB_FT)

$(LIB_SDL_FILE):
	@make -C $(LIB_SDL)

$(BUILD_DIRS_REC):
	@mkdir -vp $(BUILD_DIRS_REC)

$(BUILD_DIR)%.o: $(SRC_DIR)%.c ${HEADER}
	@echo -n "\033[0;32m"
	@printf "%-30s | %-25s" $@ $<
	@echo "\033[0m"
	@$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<


clean:
	@make -C $(LIB_FT) clean
	@make $(LIB_SDL_COMPILER) -C $(LIB_SDL) clean
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
