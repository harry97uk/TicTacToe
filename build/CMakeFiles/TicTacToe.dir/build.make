# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.27.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.27.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/harrygardiner/TicTacToe

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/harrygardiner/TicTacToe/build

# Include any dependencies generated for this target.
include CMakeFiles/TicTacToe.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TicTacToe.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TicTacToe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TicTacToe.dir/flags.make

CMakeFiles/TicTacToe.dir/main.cpp.o: CMakeFiles/TicTacToe.dir/flags.make
CMakeFiles/TicTacToe.dir/main.cpp.o: /Users/harrygardiner/TicTacToe/main.cpp
CMakeFiles/TicTacToe.dir/main.cpp.o: CMakeFiles/TicTacToe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/harrygardiner/TicTacToe/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TicTacToe.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TicTacToe.dir/main.cpp.o -MF CMakeFiles/TicTacToe.dir/main.cpp.o.d -o CMakeFiles/TicTacToe.dir/main.cpp.o -c /Users/harrygardiner/TicTacToe/main.cpp

CMakeFiles/TicTacToe.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/TicTacToe.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/harrygardiner/TicTacToe/main.cpp > CMakeFiles/TicTacToe.dir/main.cpp.i

CMakeFiles/TicTacToe.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/TicTacToe.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/harrygardiner/TicTacToe/main.cpp -o CMakeFiles/TicTacToe.dir/main.cpp.s

CMakeFiles/TicTacToe.dir/src/tictactoe/display.cpp.o: CMakeFiles/TicTacToe.dir/flags.make
CMakeFiles/TicTacToe.dir/src/tictactoe/display.cpp.o: /Users/harrygardiner/TicTacToe/src/tictactoe/display.cpp
CMakeFiles/TicTacToe.dir/src/tictactoe/display.cpp.o: CMakeFiles/TicTacToe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/harrygardiner/TicTacToe/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TicTacToe.dir/src/tictactoe/display.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TicTacToe.dir/src/tictactoe/display.cpp.o -MF CMakeFiles/TicTacToe.dir/src/tictactoe/display.cpp.o.d -o CMakeFiles/TicTacToe.dir/src/tictactoe/display.cpp.o -c /Users/harrygardiner/TicTacToe/src/tictactoe/display.cpp

CMakeFiles/TicTacToe.dir/src/tictactoe/display.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/TicTacToe.dir/src/tictactoe/display.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/harrygardiner/TicTacToe/src/tictactoe/display.cpp > CMakeFiles/TicTacToe.dir/src/tictactoe/display.cpp.i

CMakeFiles/TicTacToe.dir/src/tictactoe/display.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/TicTacToe.dir/src/tictactoe/display.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/harrygardiner/TicTacToe/src/tictactoe/display.cpp -o CMakeFiles/TicTacToe.dir/src/tictactoe/display.cpp.s

CMakeFiles/TicTacToe.dir/src/tictactoe/game.cpp.o: CMakeFiles/TicTacToe.dir/flags.make
CMakeFiles/TicTacToe.dir/src/tictactoe/game.cpp.o: /Users/harrygardiner/TicTacToe/src/tictactoe/game.cpp
CMakeFiles/TicTacToe.dir/src/tictactoe/game.cpp.o: CMakeFiles/TicTacToe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/harrygardiner/TicTacToe/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/TicTacToe.dir/src/tictactoe/game.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TicTacToe.dir/src/tictactoe/game.cpp.o -MF CMakeFiles/TicTacToe.dir/src/tictactoe/game.cpp.o.d -o CMakeFiles/TicTacToe.dir/src/tictactoe/game.cpp.o -c /Users/harrygardiner/TicTacToe/src/tictactoe/game.cpp

CMakeFiles/TicTacToe.dir/src/tictactoe/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/TicTacToe.dir/src/tictactoe/game.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/harrygardiner/TicTacToe/src/tictactoe/game.cpp > CMakeFiles/TicTacToe.dir/src/tictactoe/game.cpp.i

CMakeFiles/TicTacToe.dir/src/tictactoe/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/TicTacToe.dir/src/tictactoe/game.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/harrygardiner/TicTacToe/src/tictactoe/game.cpp -o CMakeFiles/TicTacToe.dir/src/tictactoe/game.cpp.s

# Object files for target TicTacToe
TicTacToe_OBJECTS = \
"CMakeFiles/TicTacToe.dir/main.cpp.o" \
"CMakeFiles/TicTacToe.dir/src/tictactoe/display.cpp.o" \
"CMakeFiles/TicTacToe.dir/src/tictactoe/game.cpp.o"

# External object files for target TicTacToe
TicTacToe_EXTERNAL_OBJECTS =

TicTacToe: CMakeFiles/TicTacToe.dir/main.cpp.o
TicTacToe: CMakeFiles/TicTacToe.dir/src/tictactoe/display.cpp.o
TicTacToe: CMakeFiles/TicTacToe.dir/src/tictactoe/game.cpp.o
TicTacToe: CMakeFiles/TicTacToe.dir/build.make
TicTacToe: /usr/local/Cellar/raylib/4.5.0/lib/libraylib.dylib
TicTacToe: CMakeFiles/TicTacToe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/harrygardiner/TicTacToe/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable TicTacToe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TicTacToe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TicTacToe.dir/build: TicTacToe
.PHONY : CMakeFiles/TicTacToe.dir/build

CMakeFiles/TicTacToe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TicTacToe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TicTacToe.dir/clean

CMakeFiles/TicTacToe.dir/depend:
	cd /Users/harrygardiner/TicTacToe/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/harrygardiner/TicTacToe /Users/harrygardiner/TicTacToe /Users/harrygardiner/TicTacToe/build /Users/harrygardiner/TicTacToe/build /Users/harrygardiner/TicTacToe/build/CMakeFiles/TicTacToe.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/TicTacToe.dir/depend

