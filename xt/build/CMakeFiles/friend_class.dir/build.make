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
include CMakeFiles/friend_class.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/friend_class.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/friend_class.dir/flags.make

CMakeFiles/friend_class.dir/friend_class.cpp.o: CMakeFiles/friend_class.dir/flags.make
CMakeFiles/friend_class.dir/friend_class.cpp.o: ../friend_class.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ziye01/C++/xt/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/friend_class.dir/friend_class.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/friend_class.dir/friend_class.cpp.o -c /home/ziye01/C++/xt/friend_class.cpp

CMakeFiles/friend_class.dir/friend_class.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/friend_class.dir/friend_class.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ziye01/C++/xt/friend_class.cpp > CMakeFiles/friend_class.dir/friend_class.cpp.i

CMakeFiles/friend_class.dir/friend_class.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/friend_class.dir/friend_class.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ziye01/C++/xt/friend_class.cpp -o CMakeFiles/friend_class.dir/friend_class.cpp.s

# Object files for target friend_class
friend_class_OBJECTS = \
"CMakeFiles/friend_class.dir/friend_class.cpp.o"

# External object files for target friend_class
friend_class_EXTERNAL_OBJECTS =

friend_class: CMakeFiles/friend_class.dir/friend_class.cpp.o
friend_class: CMakeFiles/friend_class.dir/build.make
friend_class: CMakeFiles/friend_class.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ziye01/C++/xt/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable friend_class"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/friend_class.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/friend_class.dir/build: friend_class

.PHONY : CMakeFiles/friend_class.dir/build

CMakeFiles/friend_class.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/friend_class.dir/cmake_clean.cmake
.PHONY : CMakeFiles/friend_class.dir/clean

CMakeFiles/friend_class.dir/depend:
	cd /home/ziye01/C++/xt/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ziye01/C++/xt /home/ziye01/C++/xt /home/ziye01/C++/xt/build /home/ziye01/C++/xt/build /home/ziye01/C++/xt/build/CMakeFiles/friend_class.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/friend_class.dir/depend
