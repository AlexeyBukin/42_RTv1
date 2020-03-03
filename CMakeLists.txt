cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_STANDARD  90)
set(CMAKE_C_STANDARD_REQUIRED True)

# set the project name
project(RTv1)

#file(GLOB SOURCES "src/*.c")

#find src -type f -name '*.c' | sed "s/^/        /"
set(SOURCES
        src/camera.c
        src/events.c
        src/figures/cylinder.c
        src/figures/figures.c
        src/figures/plane.c
        src/figures/sphere.c
        src/loop.c
        src/main.c
        src/project.c
        src/rtv1_init.c
        src/scene.c
        src/texture.c
        src/trace.c
        src/utils/color.c
        src/utils/color_2.c
        src/utils/destroy.c
        src/utils/double3.c
        src/utils/double3_str.c
        src/utils/infinity.c
        src/utils/smart_array.c
        src/utils/utils.c
        src/utils/vector_math.c
        src/window.c
        )

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(RTv1
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        )
target_include_directories(RTv1
        PRIVATE
        ${PROJECT_SOURCE_DIR}/libft/include
        )
target_include_directories(RTv1
        PRIVATE
        ${PROJECT_SOURCE_DIR}/libsdl/include/SDL2
        )
target_link_libraries( RTv1 PRIVATE ft )

add_subdirectory(libft)
#add_subdirectory(src)
#add_subdirectory(libsdl)




