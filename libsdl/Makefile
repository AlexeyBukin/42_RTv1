# Makefile for Rtv1 project in school 21 (ecole 42)
# written by kcharla, 2020


NAME = libSDLmake

SDL_DIR_NAME=SDL2_source

BUILD_DIR = build_sdl/

CC = $(SDL_DIR_NAME)/build-scripts/gcc-fat.sh

CLEAN_DIRS=$(BUILD_DIR) bin share
FCLEAN_DIRS=lib include

INSTALL_PATH=$(CURDIR)/

.PHONY: clean fclean all

all: $(NAME)

$(NAME):
	@echo "make: Running build of SDL library..."
	mkdir -vp $(BUILD_DIR) && cd $(BUILD_DIR) && ../$(SDL_DIR_NAME)/configure --prefix=$(INSTALL_PATH)
	@echo "make: Running libSDL \`make'..."
	make -C $(BUILD_DIR)
	@echo "make: Running libSDL \`make install'..."
	make -C $(BUILD_DIR) install

clean:
	@rm -rf $(CLEAN_DIRS)
	@echo "make: Done clean of \`$(NAME)'."

fclean: clean
	@rm -rf $(FCLEAN_DIRS)
	@echo "make: Done full clean of \`$(NAME)'."

re: fclean all
	@echo "make: Done recompile of \`$(NAME)'."
