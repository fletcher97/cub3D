#   NOTE: FOR THIS TO RUN, CHANGE THE PROJECT'S RUNNING CONFIGURATIONS.
#   On the running configurations window of both CMake targets:
#   1) set the "Environment Variables" to DYLD_LIBRARY_PATH=<path_to_dylib_folder>
#   (the same path of PATHS in line 24)
#   2) set the "Working Directory" to the absolute path of your project root folder
#   Note that relative paths don't work! You can just get the absolute
#   path with the pwd command.
#   Also, the .c files of the MiniLibX can't be inside the add_executable
#   rule, otherwise it will raise a lot of warnings.

cmake_minimum_required(VERSION 3.17)
project(cub3d C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall -Werror -Wextra")
set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_C_FLAGS}" -framework OpenGL -framework AppKit")

include_directories(inc
                    lib/libft/inc
                    lib/minilibx_mms_20200219)

find_library(LIBMLX
        NAMES libmlx.dylib
        PATHS ./lib/minilibx_mms_20200219)

file(GLOB SRC src/*.c src/*/*.c lib/libft/srcs/*/*.c)
file(GLOB INC inc/*.h lib/libft/include/libft.h lib/minilibx_mms_20200219/mlx.h)

add_executable(cub3d_mandatory ${SRC} ${INC})
target_link_libraries(cub3d_mandatory ${LIBMLX})
set_target_properties(cub3d_mandatory PROPERTIES COMPILE_FLAGS "-D BONUS=0")

add_executable(cub3d_bonus ${SRC} ${INC})
target_link_libraries(cub3d_mandatory ${LIBMLX})
set_target_properties(cub3d_mandatory PROPERTIES COMPILE_FLAGS "-D BONUS=1")


###LINUX VERSION

#   NOTE: FOR THIS TO RUN, CHANGE THE PROJECT'S RUNNING CONFIGURATIONS.
#   On the running configurations window of both CMake targets:
#   1) set the "Environment Variables" to DYLD_LIBRARY_PATH=<path_to_dylib_folder>
#   (the same path of PATHS in line 24)
#   2) set the "Working Directory" to the absolute path of your project root folder
#   Note that relative paths don't work! You can just get the absolute
#   path with the pwd command.
#   Also, the .c files of the MiniLibX can't be inside the add_executable
#   rule, otherwise it will raise a lot of warnings.

#cmake_minimum_required(VERSION 3.17)
#project(cub3d C)
#
#set(CMAKE_C_STANDARD 11)
#set(CMAKE_C_FLAGS "-Wall -Werror -Wextra")
#set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_C_FLAGS})
#set(CMAKE_VERBOSE_MAKEFILE ON)
## -L/usr/lib -lXext -lX11 -lm -lz
#
#include_directories(inc
#lib/libft/inc
#lib/minilibx-linux
#/usr/include/X11
#/usr/lib
#/lib)
#
#link_directories(lib/minilibx-linux /usr/local/lib /lib /usr/lib)
#
#file(GLOB SRC src/*.c src/*/*.c lib/libft/src/*/*.c)
##file(GLOB INC inc/*.h lib/libft/include/libft.h lib/minilibx_mms_20200219/mlx.h)
#
#add_executable(cub3d_mandatory ${SRC})
#target_link_libraries(cub3d_mandatory mlx X11 Xext m z)
#set_target_properties(cub3d_mandatory PROPERTIES COMPILE_FLAGS "-D BONUS=0")
#
##add_executable(cub3d_bonus ${SRC})
##target_link_libraries(cub3d_bonus ${LIBMLX})
##set_target_properties(cub3d_bonus PROPERTIES COMPILE_FLAGS "-D BONUS=1")
#