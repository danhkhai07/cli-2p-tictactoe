add_library(gameManager STATIC gameManager.cpp)

# Add include path
target_include_directories(gameManager PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Establish dependency
target_link_libraries(TicTacToe PRIVATE gameManager)