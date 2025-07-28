cmake_minimum_required(VERSION 3.10)
project(BLINK_API VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Директории
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(BIN_DIR "${CMAKE_SOURCE_DIR}/bin")

# Имя для бинарника
set(LIB_NAME "blink_api")

# Файлы с исходниками
file(GLOB_RECURSE BLINK_API_SRC
	${SRC_DIR}/*.cpp
)

# Где .h-файлы
include_directories(${INCLUDE_DIR})

# Сборка бинарника для API
add_library(${LIB_NAME} SHARED
	${BLINK_API_SRC}
)

# Куда собрать бинарник
set_target_properties(${BINARY_NAME} ${LIB_NAME} PROPERTIES
	LIBRARY_OUTPUT_DIRECTORY ${BIN_DIR}
)

# Сообщение после успешной сборки
message(STATUS "BLINK_API ${BINARY_NAME} was build")
