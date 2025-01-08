cmake_minimum_required(VERSION 3.10)  # Set the minimum required CMake version

# Define the project and its settings
project(TicTacToe CXX)  # Specify the project name and the programming language (C++)

set(CMAKE_CXX_STANDARD 17)  # Set the C++ standard version
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add the executable or library targets
add_executable(tictactoe src/main.cpp)
