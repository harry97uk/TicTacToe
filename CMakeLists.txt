cmake_minimum_required(VERSION 3.12)
project(TicTacToeProject)

set(CMAKE_CXX_STANDARD 17)

# Add your source files here
set(SOURCES
    main.cpp
    src/display.cpp
    src/button.cpp
    src/tictactoe/application.cpp
    src/tictactoe/menu_display.cpp
    src/tictactoe/menu.cpp
    src/tictactoe/game_display.cpp
    src/tictactoe/game.cpp
)

# Add the include directory to the include path
include_directories(include)

# Find the Raylib library
find_package(raylib 3.0 REQUIRED)

# Create the executable
add_executable(TicTacToe ${SOURCES})

# Link your project with the Raylib library
target_link_libraries(TicTacToe raylib)