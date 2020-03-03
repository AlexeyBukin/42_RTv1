cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_STANDARD  90)
set(CMAKE_C_STANDARD_REQUIRED True)

# set the project name
project(RTv1)

#file(GLOB SOURCES "src/*.c")

# find src -type f -name '*.c' | sed "s/^/        /"
set(SOURCES
        src/loop.c
        src/project.c
        src/main.c
        src/rtv1_init.c
        src/texture.c
        src/utils/vector_math.c
        src/utils/color.c
        src/utils/double3.c
        src/utils/infinity.c
        src/utils/destroy.c
        src/utils/color_2.c
        src/utils/double3_str.c
        src/utils/utils.c
        src/utils/smart_array.c
        src/trace.c
        src/window.c
        src/events.c
        src/camera.c
        src/scene/scene.c
        src/scene/sphere.c
        src/scene/figures.c
        src/scene/cylinder.c
        src/scene/lights.c
        src/scene/plane.c

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




