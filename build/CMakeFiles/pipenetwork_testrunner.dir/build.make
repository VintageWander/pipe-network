# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.22.1/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.22.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/wander/Downloads/pipe-network

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/wander/Downloads/pipe-network/build

# Include any dependencies generated for this target.
include CMakeFiles/pipenetwork_testrunner.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/pipenetwork_testrunner.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/pipenetwork_testrunner.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pipenetwork_testrunner.dir/flags.make

CMakeFiles/pipenetwork_testrunner.dir/pipenetwork/test/main_test.cpp.o: CMakeFiles/pipenetwork_testrunner.dir/flags.make
CMakeFiles/pipenetwork_testrunner.dir/pipenetwork/test/main_test.cpp.o: ../pipenetwork/test/main_test.cpp
CMakeFiles/pipenetwork_testrunner.dir/pipenetwork/test/main_test.cpp.o: CMakeFiles/pipenetwork_testrunner.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wander/Downloads/pipe-network/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pipenetwork_testrunner.dir/pipenetwork/test/main_test.cpp.o"
	/opt/homebrew/Cellar/gcc/11.2.0_3/bin/aarch64-apple-darwin21-g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pipenetwork_testrunner.dir/pipenetwork/test/main_test.cpp.o -MF CMakeFiles/pipenetwork_testrunner.dir/pipenetwork/test/main_test.cpp.o.d -o CMakeFiles/pipenetwork_testrunner.dir/pipenetwork/test/main_test.cpp.o -c /Users/wander/Downloads/pipe-network/pipenetwork/test/main_test.cpp

CMakeFiles/pipenetwork_testrunner.dir/pipenetwork/test/main_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pipenetwork_testrunner.dir/pipenetwork/test/main_test.cpp.i"
	/opt/homebrew/Cellar/gcc/11.2.0_3/bin/aarch64-apple-darwin21-g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wander/Downloads/pipe-network/pipenetwork/test/main_test.cpp > CMakeFiles/pipenetwork_testrunner.dir/pipenetwork/test/main_test.cpp.i

CMakeFiles/pipenetwork_testrunner.dir/pipenetwork/test/main_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pipenetwork_testrunner.dir/pipenetwork/test/main_test.cpp.s"
	/opt/homebrew/Cellar/gcc/11.2.0_3/bin/aarch64-apple-darwin21-g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wander/Downloads/pipe-network/pipenetwork/test/main_test.cpp -o CMakeFiles/pipenetwork_testrunner.dir/pipenetwork/test/main_test.cpp.s

CMakeFiles/pipenetwork_testrunner.dir/pipenetwork/test/pipenetwork_test.cpp.o: CMakeFiles/pipenetwork_testrunner.dir/flags.make
CMakeFiles/pipenetwork_testrunner.dir/pipenetwork/test/pipenetwork_test.cpp.o: ../pipenetwork/test/pipenetwork_test.cpp
CMakeFiles/pipenetwork_testrunner.dir/pipenetwork/test/pipenetwork_test.cpp.o: CMakeFiles/pipenetwork_testrunner.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wander/Downloads/pipe-network/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/pipenetwork_testrunner.dir/pipenetwork/test/pipenetwork_test.cpp.o"
	/opt/homebrew/Cellar/gcc/11.2.0_3/bin/aarch64-apple-darwin21-g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/pipenetwork_testrunner.dir/pipenetwork/test/pipenetwork_test.cpp.o -MF CMakeFiles/pipenetwork_testrunner.dir/pipenetwork/test/pipenetwork_test.cpp.o.d -o CMakeFiles/pipenetwork_testrunner.dir/pipenetwork/test/pipenetwork_test.cpp.o -c /Users/wander/Downloads/pipe-network/pipenetwork/test/pipenetwork_test.cpp

CMakeFiles/pipenetwork_testrunner.dir/pipenetwork/test/pipenetwork_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pipenetwork_testrunner.dir/pipenetwork/test/pipenetwork_test.cpp.i"
	/opt/homebrew/Cellar/gcc/11.2.0_3/bin/aarch64-apple-darwin21-g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wander/Downloads/pipe-network/pipenetwork/test/pipenetwork_test.cpp > CMakeFiles/pipenetwork_testrunner.dir/pipenetwork/test/pipenetwork_test.cpp.i

CMakeFiles/pipenetwork_testrunner.dir/pipenetwork/test/pipenetwork_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pipenetwork_testrunner.dir/pipenetwork/test/pipenetwork_test.cpp.s"
	/opt/homebrew/Cellar/gcc/11.2.0_3/bin/aarch64-apple-darwin21-g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wander/Downloads/pipe-network/pipenetwork/test/pipenetwork_test.cpp -o CMakeFiles/pipenetwork_testrunner.dir/pipenetwork/test/pipenetwork_test.cpp.s

# Object files for target pipenetwork_testrunner
pipenetwork_testrunner_OBJECTS = \
"CMakeFiles/pipenetwork_testrunner.dir/pipenetwork/test/main_test.cpp.o" \
"CMakeFiles/pipenetwork_testrunner.dir/pipenetwork/test/pipenetwork_test.cpp.o"

# External object files for target pipenetwork_testrunner
pipenetwork_testrunner_EXTERNAL_OBJECTS =

pipenetwork_testrunner: CMakeFiles/pipenetwork_testrunner.dir/pipenetwork/test/main_test.cpp.o
pipenetwork_testrunner: CMakeFiles/pipenetwork_testrunner.dir/pipenetwork/test/pipenetwork_test.cpp.o
pipenetwork_testrunner: CMakeFiles/pipenetwork_testrunner.dir/build.make
pipenetwork_testrunner: libpipenetwork.dylib
pipenetwork_testrunner: CMakeFiles/pipenetwork_testrunner.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/wander/Downloads/pipe-network/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable pipenetwork_testrunner"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pipenetwork_testrunner.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pipenetwork_testrunner.dir/build: pipenetwork_testrunner
.PHONY : CMakeFiles/pipenetwork_testrunner.dir/build

CMakeFiles/pipenetwork_testrunner.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pipenetwork_testrunner.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pipenetwork_testrunner.dir/clean

CMakeFiles/pipenetwork_testrunner.dir/depend:
	cd /Users/wander/Downloads/pipe-network/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/wander/Downloads/pipe-network /Users/wander/Downloads/pipe-network /Users/wander/Downloads/pipe-network/build /Users/wander/Downloads/pipe-network/build /Users/wander/Downloads/pipe-network/build/CMakeFiles/pipenetwork_testrunner.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pipenetwork_testrunner.dir/depend
