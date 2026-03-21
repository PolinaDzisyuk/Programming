cmake_minimum_required(VERSION 3.10)

project(book)

set(BOOK_DIR ${CMAKE_CURRENT_SOURCE_DIR}/BOOK)

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(SOURCE
    ${SOURCE_DIR}/book_func.c
)

# option(CHOICE_LIB "Собрать с динамической библиотекой?" OFF)
# if(${CHOICE_LIB})
#     message(STATUS "Выбрана динамическая библиотека") 
# else()
#     message(STATUS "Выбрана статическая библиотека по умолчанию")
# endif()

if(${LIB} STREQUAL "D")
    add_definitions("-DLIB=${LIB}")
    message(STATUS "Выбрана динамическая библиотека") 
    add_library(BOOK_LIB SHARED 
    ${SOURCE}
)
else()
    message(STATUS "Выбрана статическая библиотека по умолчанию")
    add_library(BOOK_LIB STATIC 
    ${SOURCE}
)
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_executable(book ${SOURCE_DIR}/main.c)
target_link_libraries(book BOOK_LIB)
