# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hush <hush@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/27 22:20:09 by hush              #+#    #+#              #
#    Updated: 2020/05/28 01:01:34 by hush             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# Makefile for Rtv1 project in school 21 (ecole 42)
# written by kcharla, 2020

NAME = libsdl.a

#SDL_DIR_NAME=SDL2-2.0.10-source
SDL_DIR_NAME=SDL2_source

BUILD_DIR = build_sdl/

CC = $(SDL_DIR_NAME)/build-scripts/gcc-fat.sh
#CC = clang

CLEAN_DIRS=$(BUILD_DIR) bin share
FCLEAN_DIRS=lib include

INSTALL_PATH=$(CURDIR)/
LIB_SDL_DIR=installed/

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

clean:
	@rm -rf $(CLEAN_DIRS)
	@echo "make: Done clean of \`$(NAME)'."

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(FCLEAN_DIRS)
	@echo "make: Done full clean of \`$(NAME)'."

re: fclean all
	@echo "make: Done recompile of \`$(NAME)'."
