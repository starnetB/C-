# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ziye01/C++/iiw

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ziye01/C++/iiw/build

# Include any dependencies generated for this target.
include CMakeFiles/zeban.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/zeban.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/zeban.dir/flags.make

CMakeFiles/zeban.dir/递归/zeban.cpp.o: CMakeFiles/zeban.dir/flags.make
CMakeFiles/zeban.dir/递归/zeban.cpp.o: ../递归/zeban.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ziye01/C++/iiw/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/zeban.dir/递归/zeban.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zeban.dir/递归/zeban.cpp.o -c /home/ziye01/C++/iiw/递归/zeban.cpp

CMakeFiles/zeban.dir/递归/zeban.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zeban.dir/递归/zeban.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ziye01/C++/iiw/递归/zeban.cpp > CMakeFiles/zeban.dir/递归/zeban.cpp.i

CMakeFiles/zeban.dir/递归/zeban.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zeban.dir/递归/zeban.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ziye01/C++/iiw/递归/zeban.cpp -o CMakeFiles/zeban.dir/递归/zeban.cpp.s

# Object files for target zeban
zeban_OBJECTS = \
"CMakeFiles/zeban.dir/递归/zeban.cpp.o"

# External object files for target zeban
zeban_EXTERNAL_OBJECTS =

zeban: CMakeFiles/zeban.dir/递归/zeban.cpp.o
zeban: CMakeFiles/zeban.dir/build.make
zeban: CMakeFiles/zeban.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ziye01/C++/iiw/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable zeban"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/zeban.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/zeban.dir/build: zeban

.PHONY : CMakeFiles/zeban.dir/build

CMakeFiles/zeban.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/zeban.dir/cmake_clean.cmake
.PHONY : CMakeFiles/zeban.dir/clean

CMakeFiles/zeban.dir/depend:
	cd /home/ziye01/C++/iiw/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ziye01/C++/iiw /home/ziye01/C++/iiw /home/ziye01/C++/iiw/build /home/ziye01/C++/iiw/build /home/ziye01/C++/iiw/build/CMakeFiles/zeban.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/zeban.dir/depend

