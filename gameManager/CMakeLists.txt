add_library(gameManager STATIC ${CMAKE_CURRENT_SOURCE_DIR}/src/gameManager.cpp)
target_link_libraries(gameManager 
    PRIVATE
        inputHandler
        processGameInput
        renderer
)