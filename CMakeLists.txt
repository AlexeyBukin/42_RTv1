cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_STANDARD  90)
set(CMAKE_C_STANDARD_REQUIRED True)

#Tweak for MacOS
#set(MAC_OS  TRUE)
set(MAC_OS  FALSE)

if (MAC_OS)
    SET(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.13.sdk -mmacosx-version-min=10.7")
endif()



# set the project name
project(RTv1)

set(SDL2_INCLUDE_DIR libsdl/include)

#Linux
if (NOT MAC_OS)
    set(SDL2_LIBRARY libsdl/lib/libSDL2.so)
    set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
endif()

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})


#file(GLOB SOURCES "src/*.c")

# find src -type f -name '*.c' | sed "s/^/        /"
set(SOURCES
        src/loop.c
        src/camera/project.c
        src/main.c
        src/texture.c
        src/utils/vector_2.c
        src/utils/vector_1.c
        src/utils/clamp.c
        src/utils/color_1.c
        src/utils/vector_4.c
        src/utils/color_2.c
        src/utils/vector_3.c
        src/utils/num_1.c
        src/window.c
        src/rt.c
        src/events.c
        src/camera/camera.c
        src/scene/rt_material_to_str.c
        src/scene/parse/comments.c
        src/scene/parse/add_light.c
        src/scene/parse/read_comma.c
        src/scene/parse/add_material.c
        src/scene/parse/scene_from_file.c
        src/scene/parse/read_num.c
        src/scene/parse/add_figure.c
        src/scene/parse/read_id.c
        src/scene/parse/read_vec.c
        src/scene/rt_scene.c
        src/scene/rt_figure_to_str.c
        src/scene/rt_light_to_str.c
        src/trace/trace_dot_cylinder.c
        src/trace/trace_dot_plane.c
        src/trace/trace_normal_cone.c
        src/trace/trace_dot_sphere.c
        src/trace/trace_normal_cylinder.c
        src/trace/trace_dot_cone.c
        src/trace/trace_normal_plane.c
        src/trace/trace_normal_sphere.c
        src/trace/rt_trace.c
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

