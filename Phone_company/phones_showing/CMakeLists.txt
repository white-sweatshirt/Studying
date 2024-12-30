add_library( phones_showing STATIC
            phones_showing.c
            phones_showing.h
)
target_include_directories(phones_showing PUBLIC "${PROJECT_SOURCE_DIR}/finding_and_names")
target_link_libraries(phones_showing PUBLIC finding_and_names)