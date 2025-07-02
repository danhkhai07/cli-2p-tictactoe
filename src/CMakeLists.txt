add_library(gameManager STATIC gameManager.cpp)

# Add include path
target_include_directories(gameManager PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Install package
install(TARGETS gameManager
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)