cmake_minimum_required(VERSION 3.10)
project(BLINK_API VERSION 0.1.0 LANGUAGES CXX)

# --- Настройки видимости символов ---
if (UNIX)
	set(CMAKE_CXX_VISIBILITY_PRESET hidden)	# скрыть все символы по умолчанию
	set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)	# скрыть inline-функции
	add_compile_options(-fvisibility=hidden) # дополнительная защита для скрытия
elseif (WIN32)
	# Для Windows CMake должен автоматически обработать __declspec(dllexport)
endif()

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
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
set_target_properties(${LIB_NAME} PROPERTIES
	LIBRARY_OUTPUT_DIRECTORY ${BIN_DIR}
)

# Сообщение после успешной сборки
message(STATUS "BLINK_API ${LIB_NAME} was built to ${BIN_DIR}")
