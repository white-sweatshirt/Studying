cmake_minimum_required(VERSION 3.21.0)
project(dziennik VERSION 1.1.0 
DESCRIPTION "Przykladowy opis i strona" HOMEPAGE_URL "https://github.com/white-sweatshirt/Studying"
 LANGUAGES C )

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

include_directories(library)
set(Code_to_execute 
    library/function_for_edziennik.h
    sources/e-dziennik.c
    sources/function_for_edziennik.c
)
add_executable(e-dziennik ${Code_to_execute})

