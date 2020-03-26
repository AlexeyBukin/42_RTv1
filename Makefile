#RTv1 Makefile
#@kcharla, 2010

NAME = RTv1

CC = clang

LIBM =
DEBUG =
OPTIM = -O2

CFLAGS = -Wall -Wextra -Werror $(DEBUG) $(OPTIM)

LIB_FT = libft/
LIB_FT_FILE = $(LIB_FT)/libft.a

LIB_SDL_EXTENSION = .dylib
LIB_SDL = libsdl/
LIB_SDL_FILE = $(LIB_SDL)/lib/libSDL2$(LIB_SDL_EXTENSION)

INCLUDE = -I include/ -I $(LIB_FT)include/ -I $(LIB_SDL)include/

# find include -type f -name '*.h' | sed "s/\$/ \\\\/"
HEADERS = \
include/scene.h \
include/rtv1.h \
include/color.h \
include/vector.h

BUILD_DIR = build/
SRC_DIR = src/

#SRC_FILES = $(shell find $(SRC_DIR) -not \( -path $(MAIN_DIR) -prune \) -type f -name "*.c")
# find src -type f -name '*.c' | sed "s/\$/ \\\\/"

SRC_FILES = \
src/loop.c \
src/project.c \
src/main.c \
src/rtv1_init.c \
src/texture.c \
src/utils/vector_math.c \
src/utils/color.c \
src/utils/double3.c \
src/utils/infinity.c \
src/utils/destroy.c \
src/utils/color_2.c \
src/utils/double3_str.c \
src/utils/utils.c \
src/utils/smart_array.c \
src/trace.c \
src/window.c \
src/events.c \
src/camera.c \
src/scene/scene.c \
src/scene/sphere.c \
src/scene/figures.c \
src/scene/cylinder.c \
src/scene/lights.c \
src/scene/plane.c \
src/utils/ray.c

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

$(BUILD_DIR)%.o: $(SRC_DIR)%.c ${HEADERS}
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
