#RTv1 Makefile
#@kcharla, 2020

NAME = RTv1

# (1) Platform-dependent code

UNAME := $(shell uname)
MACOS := Darwin
LINUX := Linux

ifeq ($(UNAME), $(MACOS))
$(warning "running make for MacOS")
else ifeq ($(UNAME), $(LINUX))
$(warning "running make for Linux")
LIB_SDL_COMPILER= CC\=clang
OS_FLAGS = -lm
else
$(error "Unknown system UNAME: '$(UNAME)', but available only '$(LINUX)' and '$(MACOS)'")
endif

# (2) General config
#CC = clang
#or "
CC = gcc -no-pie#" # -fPIC does not work...

export DEBUG = -g
export OPTIM = -O2

LIB_FT = libft
LIB_FT_FILE = $(LIB_FT)/libft.a

LIB_SDL = libsdl
LIB_SDL_FILE = $(LIB_SDL)/lib
LIB_SDL_FLAGS = $(shell $(LIB_SDL)/bin/sdl2-config --cflags)
LIB_SDL_LIBS = $(shell $(LIB_SDL)/bin/sdl2-config --libs)

CFLAGS = -Wall -Wextra -Werror $(DEBUG) $(OPTIM) $(OS_FLAGS) $(LIB_SDL_FLAGS)
CLIBS  = $(LIB_FT_FILE) -lm $(LIB_SDL_LIBS)

INCLUDE = -I include/ -I $(LIB_FT)/include/ -I $(LIB_SDL)/include/

BUILD_DIR = build
SRC_DIR = src

# (3) Source files

HEADER_FILES = \
include/rt_trace.h     include/rt_scene_s.h  include/rt_s.h          \
include/rt_utils_s.h   include/rt_scene.h    include/rt_num.h        \
include/rt_parser.h    include/rt_vector.h   include/rt_vector_s.h   \
include/rt_camera.h    include/rt_utils.h    include/rt_num_s.h      \
include/rt_camera_s.h  include/rt.h          include/rt_texture_s.h

SRC_FILES = \
src/loop.c                         src/events_1.c                   src/main.c                      \
src/texture.c                      src/utils/vector_2.c             src/utils/vector_8.c            \
src/utils/vector_1.c               src/utils/vector_7.c             src/utils/vector_6.c            \
src/utils/color_1.c                src/utils/vector_4.c             src/utils/color_2.c             \
src/utils/num_2.c                  src/utils/vector_3.c             src/utils/vector_5.c            \
src/utils/human_1.c                src/utils/num_1.c                src/utils/ray.c                 \
src/window.c                       src/rt.c                         src/events_2.c                  \
src/pbr/schlick.c                  src/pbr/ggx.c                    src/pbr/brdf.c                  \
src/scene/rt_material_to_str.c     src/scene/rt_scene_to_str.c      src/scene/parse/comments.c      \
src/scene/parse/add_light.c        src/scene/parse/read_comma.c     src/scene/parse/add_material.c  \
src/scene/parse/add_camera.c       src/scene/parse/read_num.c       src/scene/parse/add_figure.c    \
src/scene/parse/read_id.c          src/scene/parse/read_vec.c       src/scene/rt_scene.c            \
src/scene/rt_figure_to_str.c       src/scene/rt_add_scene.c         src/scene/rt_camera_to_str.c    \
src/scene/rt_light_to_str.c        src/trace/trace_dot_cylinder.c   src/trace/rt_trace_modes.c      \
src/trace/trace_dot_plane.c        src/trace/trace_normal_cone.c    src/trace/trace_dot_sphere.c    \
src/trace/trace_normal_cylinder.c  src/trace/trace_dot_cone.c       src/trace/trace_normal_plane.c  \
src/trace/rt_trace.c               src/trace/trace_normal_sphere.c  src/camera/project.c            \
src/camera/camera.c


O_FILES = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC_FILES))

SRC_DIRS = $(shell find $(SRC_DIR) -type d)
BUILD_DIRS_REC = $(patsubst $(SRC_DIR)/%, $(BUILD_DIR)/%, $(SRC_DIRS))

.PHONY: clean fclean all $(LIB_FT_FILE)

# (4) Rules

all: $(NAME)

$(NAME): $(LIB_FT_FILE) $(LIB_SDL_FILE) $(BUILD_DIRS_REC) $(O_FILES)
	@echo "\033[0;32m" "Building RTv1 executable..." "\033[0m"
	$(CC) $(CFLAGS) $(O_FILES) $(INCLUDE) -o $(NAME)  $(CLIBS)
	@echo "\033[0;32m" "Done" "\033[0m"

$(LIB_FT_FILE):
	@make -C $(LIB_FT)

$(LIB_SDL_FILE):
	@make -C $(LIB_SDL)

$(BUILD_DIRS_REC):
	@mkdir -vp $(BUILD_DIRS_REC)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c ${HEADER_FILES}
	@echo -n "\033[0;32m"
	@printf "%-35s | %-35s" $@ $<
	@echo "\033[0m"
	@$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

clean:
	@make -C $(LIB_FT) clean
	@make -C $(LIB_SDL) clean
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
