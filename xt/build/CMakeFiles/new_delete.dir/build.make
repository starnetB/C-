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
CMAKE_SOURCE_DIR = /home/ziye01/C++/xt

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ziye01/C++/xt/build

# Include any dependencies generated for this target.
include CMakeFiles/new_delete.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/new_delete.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/new_delete.dir/flags.make

CMakeFiles/new_delete.dir/new_delete.cpp.o: CMakeFiles/new_delete.dir/flags.make
CMakeFiles/new_delete.dir/new_delete.cpp.o: ../new_delete.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ziye01/C++/xt/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/new_delete.dir/new_delete.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/new_delete.dir/new_delete.cpp.o -c /home/ziye01/C++/xt/new_delete.cpp

CMakeFiles/new_delete.dir/new_delete.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/new_delete.dir/new_delete.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ziye01/C++/xt/new_delete.cpp > CMakeFiles/new_delete.dir/new_delete.cpp.i

CMakeFiles/new_delete.dir/new_delete.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/new_delete.dir/new_delete.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ziye01/C++/xt/new_delete.cpp -o CMakeFiles/new_delete.dir/new_delete.cpp.s

# Object files for target new_delete
new_delete_OBJECTS = \
"CMakeFiles/new_delete.dir/new_delete.cpp.o"

# External object files for target new_delete
new_delete_EXTERNAL_OBJECTS =

new_delete: CMakeFiles/new_delete.dir/new_delete.cpp.o
new_delete: CMakeFiles/new_delete.dir/build.make
new_delete: CMakeFiles/new_delete.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ziye01/C++/xt/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable new_delete"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/new_delete.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/new_delete.dir/build: new_delete

.PHONY : CMakeFiles/new_delete.dir/build

CMakeFiles/new_delete.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/new_delete.dir/cmake_clean.cmake
.PHONY : CMakeFiles/new_delete.dir/clean

CMakeFiles/new_delete.dir/depend:
	cd /home/ziye01/C++/xt/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ziye01/C++/xt /home/ziye01/C++/xt /home/ziye01/C++/xt/build /home/ziye01/C++/xt/build /home/ziye01/C++/xt/build/CMakeFiles/new_delete.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/new_delete.dir/depend

