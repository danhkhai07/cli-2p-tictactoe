cmake_minimum_required(VERSION 3.5)
project(CLI-2P-TicTacToe)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Change install path
if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    message(STATUS "Setting default CMAKE_INSTALL_PREFIX path to ${CMAKE_BINARY_DIR}/install")
    set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install" CACHE STRING "Install path" FORCE)
endif()

# Add executable
add_executable(TicTacToe ${CMAKE_SOURCE_DIR}/main.cpp)

# Add subdirectories
add_subdirectory(gameManager)
add_subdirectory(inputHandler)
add_subdirectory(processGameInput)
add_subdirectory(renderer)

# Establish main -> gameManager
target_link_libraries(TicTacToe PRIVATE gameManager)

# Install package
install(TARGETS TicTacToe
    RUNTIME DESTINATION bin)

install(DIRECTORY gameManager/include/.
    inputHandler/include/.
    processGameInput/include/.
    renderer/include/.
    DESTINATION include   
)

install(FILES logs.txt README.md DESTINATION .)