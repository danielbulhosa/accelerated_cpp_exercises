# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/danielbulhosa/CLionProjects/Accelerated C++ Exercises/exercise10-2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/danielbulhosa/CLionProjects/Accelerated C++ Exercises/exercise10-2/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/exercise10_2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/exercise10_2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/exercise10_2.dir/flags.make

CMakeFiles/exercise10_2.dir/main.cpp.o: CMakeFiles/exercise10_2.dir/flags.make
CMakeFiles/exercise10_2.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/danielbulhosa/CLionProjects/Accelerated C++ Exercises/exercise10-2/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/exercise10_2.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/exercise10_2.dir/main.cpp.o -c "/Users/danielbulhosa/CLionProjects/Accelerated C++ Exercises/exercise10-2/main.cpp"

CMakeFiles/exercise10_2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exercise10_2.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/danielbulhosa/CLionProjects/Accelerated C++ Exercises/exercise10-2/main.cpp" > CMakeFiles/exercise10_2.dir/main.cpp.i

CMakeFiles/exercise10_2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exercise10_2.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/danielbulhosa/CLionProjects/Accelerated C++ Exercises/exercise10-2/main.cpp" -o CMakeFiles/exercise10_2.dir/main.cpp.s

CMakeFiles/exercise10_2.dir/median.cpp.o: CMakeFiles/exercise10_2.dir/flags.make
CMakeFiles/exercise10_2.dir/median.cpp.o: ../median.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/danielbulhosa/CLionProjects/Accelerated C++ Exercises/exercise10-2/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/exercise10_2.dir/median.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/exercise10_2.dir/median.cpp.o -c "/Users/danielbulhosa/CLionProjects/Accelerated C++ Exercises/exercise10-2/median.cpp"

CMakeFiles/exercise10_2.dir/median.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exercise10_2.dir/median.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/danielbulhosa/CLionProjects/Accelerated C++ Exercises/exercise10-2/median.cpp" > CMakeFiles/exercise10_2.dir/median.cpp.i

CMakeFiles/exercise10_2.dir/median.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exercise10_2.dir/median.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/danielbulhosa/CLionProjects/Accelerated C++ Exercises/exercise10-2/median.cpp" -o CMakeFiles/exercise10_2.dir/median.cpp.s

# Object files for target exercise10_2
exercise10_2_OBJECTS = \
"CMakeFiles/exercise10_2.dir/main.cpp.o" \
"CMakeFiles/exercise10_2.dir/median.cpp.o"

# External object files for target exercise10_2
exercise10_2_EXTERNAL_OBJECTS =

exercise10_2: CMakeFiles/exercise10_2.dir/main.cpp.o
exercise10_2: CMakeFiles/exercise10_2.dir/median.cpp.o
exercise10_2: CMakeFiles/exercise10_2.dir/build.make
exercise10_2: CMakeFiles/exercise10_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/danielbulhosa/CLionProjects/Accelerated C++ Exercises/exercise10-2/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable exercise10_2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/exercise10_2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/exercise10_2.dir/build: exercise10_2

.PHONY : CMakeFiles/exercise10_2.dir/build

CMakeFiles/exercise10_2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/exercise10_2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/exercise10_2.dir/clean

CMakeFiles/exercise10_2.dir/depend:
	cd "/Users/danielbulhosa/CLionProjects/Accelerated C++ Exercises/exercise10-2/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/danielbulhosa/CLionProjects/Accelerated C++ Exercises/exercise10-2" "/Users/danielbulhosa/CLionProjects/Accelerated C++ Exercises/exercise10-2" "/Users/danielbulhosa/CLionProjects/Accelerated C++ Exercises/exercise10-2/cmake-build-debug" "/Users/danielbulhosa/CLionProjects/Accelerated C++ Exercises/exercise10-2/cmake-build-debug" "/Users/danielbulhosa/CLionProjects/Accelerated C++ Exercises/exercise10-2/cmake-build-debug/CMakeFiles/exercise10_2.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/exercise10_2.dir/depend

