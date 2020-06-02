cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_STANDARD  90)
set(CMAKE_C_STANDARD_REQUIRED True)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

# set the project name
project(RTv1)

#School21 Macs seems not to work without this line
if (APPLE)
    set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.13.sdk -mmacosx-version-min=10.7")
endif(APPLE)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# find src     -type f -name '*.c' | sed 'N;N;s/\n/ /g' |  sed '$s/\\\\\\//' | column -t
set(SOURCES
        )

set(SDL2_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/libsdl/include)
#execute_process(COMMAND ${PROJECT_SOURCE_DIR}/libsdl/bin/sdl2-config --cflags OUTPUT_VARIABLE SDL_CFLAGS)
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${SDL_CFLAGS}")

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC
        ${SDL2_INCLUDE_DIR}                      )

target_include_directories(${PROJECT_NAME} PUBLIC
        ${PROJECT_SOURCE_DIR}/include            )

target_include_directories(${PROJECT_NAME} PUBLIC
        ${PROJECT_SOURCE_DIR}/libft/include      )

add_subdirectory(libft)
target_link_libraries(${PROJECT_NAME} ft)
target_link_libraries(${PROJECT_NAME} m)

execute_process(COMMAND
        ${PROJECT_SOURCE_DIR}/libsdl/bin/sdl2-config --libs | tr -d '\n\t\r' | tr -d [:space:]
        OUTPUT_VARIABLE SDL_LIBS)
string(REGEX REPLACE "\n$" "" SDL_LIBS "${SDL_LIBS}")

#message(WARNING "'${SDL_LIBS}'")
#message(WARNING "flags ${SDL_FLAGS}")
#message(WARNING "libs ${SDL_LIBS}")
target_link_libraries(${PROJECT_NAME} ${SDL_LIBS})

#target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/libsdl/lib/libSDL2.so)
#target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/libsdl/lib/libSDL2main.a)
