add_library(operetion_on_list_of_phones STATIC 
            operetion_on_list_of_phones.c
            operetion_on_list_of_phones.h
            
)
target_include_directories(operetion_on_list_of_phones 
                            PUBLIC "${PROJECT_SOURCE_DIR}/finding_and_names")

target_link_libraries(operetion_on_list_of_phones PUBLIC finding_and_names)