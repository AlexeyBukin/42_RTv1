cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_STANDARD  90)
set(CMAKE_C_STANDARD_REQUIRED True)

# MAC version cmake start
#SET(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.13.sdk -mmacosx-version-min=10.7")
# MAC end


# set the project name
project(RTv1)

set(SDL2_INCLUDE_DIR libsdl/include)

# Linux version cmake start
set(SDL2_LIBRARY libsdl/lib/libSDL2.so)

## includes cmake/FindSDL2.cmake
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# Linux end


find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})


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

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        )

target_include_directories(${PROJECT_NAME}
        PRIVATE
        ${PROJECT_SOURCE_DIR}/libft/include
        )

target_include_directories(${PROJECT_NAME}
        PRIVATE
        ${PROJECT_SOURCE_DIR}/libsdl/include/
        )

add_subdirectory(libft)
target_link_libraries(${PROJECT_NAME} ft)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})

