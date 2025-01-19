cmake_minimum_required(VERSION 3.21)

project(phone_company VERSION 1.3.1 DESCRIPTION "Projekt wykonany metoda prob i bledow" 
HOMEPAGE_URL "https://github.com/white-sweatshirt/Studying/tree/main/Phone_company"
 LANGUAGES C)
 

add_subdirectory(finding_and_names)
add_subdirectory(phones_operetions_on_price)
add_subdirectory(phones_showing)
add_executable(phone_company 
                    main.c)

target_include_directories(phone_company 
                        PUBLIC "${PROJECT_SOURCE_DIR}/finding_and_names" 
                        PUBLIC "${PROJECT_SOURCE_DIR}/phones_operetions_on_price"
                        PUBLIC "${PROJECT_SOURCE_DIR}/phones_showing")
target_link_libraries(phone_company 
                        PUBLIC phones_operetions_on_price
                        PUBLIC finding_and_names 
                        PUBLIC phones_showing )
include(CTest)
enable_testing()