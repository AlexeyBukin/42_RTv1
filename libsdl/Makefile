# Makefile for Rtv1 project in school 21 (ecole 42)
# written by kcharla, 2020
#
# Usage:
#
# 1) `make all' OR `make libftprintf.a' to compile libftprintf.a
#
# 2.1) `make clean' to delete objects locally and in libft
# 2.2) `make lclean' to delete objects locally only (don't touch libft)
#
# 3.1) `make fclean' to delete libftprintf.a, libft.a and objects locally and
#			in libft
# 3.2) `make lfclean' to delete libftprintf.a and objects locally
#			(don't touch libft)
#
# 4.1) `make re' to run `make fclean' and `make all'
# 4.2) `make lre' to run `make lfclean' and `make all'
#
# TO USE DEBUG add `DEBUG=-g' before rule like this: `make DEBUG=-g re'

NAME = libsdl.a

SDL_DIR_NAME=SDL2-2.0.10-source

BUILD_DIR = build_sdl/

CC = $(SDL_DIR_NAME)/build-scripts/gcc-fat.sh

CLEAN_DIRS=$(BUILD_DIR) bin lib share
FCLEAN_DIRS=include

INSTALL_PATH=$(CURDIR)/
LIB_SDL_DIR=lib/

.PHONY: clean fclean all

all: $(NAME)

#mkdir -vp $(BUILD_DIR) && cd $(BUILD_DIR) && ../$(SDL_DIR_NAME)/configure --disable-shared  --static-libs --prefix=$(INSTALL_PATH)

$(NAME):
	@echo "make: Running build of SDL library..."
	mkdir -vp $(BUILD_DIR) && cd $(BUILD_DIR) && ../$(SDL_DIR_NAME)/configure --prefix=$(INSTALL_PATH)
	@echo "make: Running libSDL \`make'..."
	make -C $(BUILD_DIR)
	@echo "make: Running libSDL \`make install'..."
	make -C $(BUILD_DIR) install
	#@echo "make: Preparing files..."
	#cp $(LIB_SDL_DIR)libSDL2.a $(NAME)

clean:
	@rm -rf $(CLEAN_DIRS)
	@echo "make: Done clean of \`$(NAME)'."

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(FCLEAN_DIRS)
	@echo "make: Done full clean of \`$(NAME)'."

re: fclean all
	@echo "make: Done recompile of \`$(NAME)'."
