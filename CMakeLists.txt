cmake_minimum_required(VERSION 3.12)
project(yirenFS)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_C_FLAGS_DEBUG "$ENV{CFLAGS} -O0 -Wall -g -ggdb -std=c99")
set(CMAKE_C_FLAGS_RELEASE "$ENV{CFLAGS} -O3 -Wall -ggdb -std=c99")


SET(LIB_LIST memory/alloc.c utils/sys.c utils/log.c utils/path.c datastruct/string.c
  shell.c shell_command.c
  fs.c
  device_io.c)

aux_source_directory("yiren/" YIREN_SRCS)

# 相关的源文件是SRC_LIST中定义的源文件列表
ADD_EXECUTABLE(main main.c ${LIB_LIST} ${YIREN_SRCS})