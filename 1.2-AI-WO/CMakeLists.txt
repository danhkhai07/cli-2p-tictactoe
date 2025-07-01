cmake_minimum_required(VERSION 3.5)
project(CLI-2P-TicTacToe)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Change install path
if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    message(STATUS "Setting default CMAKE_INSTALL_PREFIX path to ${CMAKE_SOURCE_DIR}/PACKAGE")
    set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/PACKAGE" CACHE STRING "Install path" FORCE)
endif()

# Add executable
add_executable(TicTacToe ${CMAKE_SOURCE_DIR}/src/main.cpp)

# Add include path
target_include_directories(TicTacToe PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Establish dependency
target_link_libraries(TicTacToe PRIVATE gameManager)

# Add subdirectories
add_subdirectory(src)

# Install package
install(TARGETS TicTacToe
    RUNTIME DESTINATION bin)

install(DIRECTORY include/.
    DESTINATION include   
)

install(FILES logs.txt README.md DESTINATION .)