add_library(phones_operetions_on_price
        phones_operetions_on_price.h
        phones_operetions_on_price.c
)
target_include_directories(phones_operetions_on_price PUBLIC "${PROJECT_SOURCE_DIR}/finding_and_names")
target_link_libraries(phones_operetions_on_price PUBLIC finding_and_names)