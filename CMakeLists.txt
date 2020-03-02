cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_STANDARD  90)
set(CMAKE_C_STANDARD_REQUIRED True)

# set the project name
project(RTv1)

#file(GLOB SOURCES "src/*.c")

set(SOURCES
        src/camera.c
        src/color.c
        src/destroy.c
        src/double3.c
        src/events.c
        src/figures/cylinder.c
        src/figures/plane.c
        src/infinity.c
        src/loop.c
        src/main.c
        src/project.c
        src/rtv1_init.c
        src/scene.c
        src/test/test_dist.c
        src/test/test_time.c
        src/test/test_trace.c
        src/texture.c
        src/trace.c
        src/utils.c
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




