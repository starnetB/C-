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
include CMakeFiles/abstractfatory.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/abstractfatory.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/abstractfatory.dir/flags.make

CMakeFiles/abstractfatory.dir/DesignerMode/AbstractFactoryPattern/abstract.cpp.o: CMakeFiles/abstractfatory.dir/flags.make
CMakeFiles/abstractfatory.dir/DesignerMode/AbstractFactoryPattern/abstract.cpp.o: ../DesignerMode/AbstractFactoryPattern/abstract.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ziye01/C++/iiw/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/abstractfatory.dir/DesignerMode/AbstractFactoryPattern/abstract.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/abstractfatory.dir/DesignerMode/AbstractFactoryPattern/abstract.cpp.o -c /home/ziye01/C++/iiw/DesignerMode/AbstractFactoryPattern/abstract.cpp

CMakeFiles/abstractfatory.dir/DesignerMode/AbstractFactoryPattern/abstract.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/abstractfatory.dir/DesignerMode/AbstractFactoryPattern/abstract.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ziye01/C++/iiw/DesignerMode/AbstractFactoryPattern/abstract.cpp > CMakeFiles/abstractfatory.dir/DesignerMode/AbstractFactoryPattern/abstract.cpp.i

CMakeFiles/abstractfatory.dir/DesignerMode/AbstractFactoryPattern/abstract.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/abstractfatory.dir/DesignerMode/AbstractFactoryPattern/abstract.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ziye01/C++/iiw/DesignerMode/AbstractFactoryPattern/abstract.cpp -o CMakeFiles/abstractfatory.dir/DesignerMode/AbstractFactoryPattern/abstract.cpp.s

CMakeFiles/abstractfatory.dir/DesignerMode/AbstractFactoryPattern/Factory.cpp.o: CMakeFiles/abstractfatory.dir/flags.make
CMakeFiles/abstractfatory.dir/DesignerMode/AbstractFactoryPattern/Factory.cpp.o: ../DesignerMode/AbstractFactoryPattern/Factory.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ziye01/C++/iiw/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/abstractfatory.dir/DesignerMode/AbstractFactoryPattern/Factory.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/abstractfatory.dir/DesignerMode/AbstractFactoryPattern/Factory.cpp.o -c /home/ziye01/C++/iiw/DesignerMode/AbstractFactoryPattern/Factory.cpp

CMakeFiles/abstractfatory.dir/DesignerMode/AbstractFactoryPattern/Factory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/abstractfatory.dir/DesignerMode/AbstractFactoryPattern/Factory.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ziye01/C++/iiw/DesignerMode/AbstractFactoryPattern/Factory.cpp > CMakeFiles/abstractfatory.dir/DesignerMode/AbstractFactoryPattern/Factory.cpp.i

CMakeFiles/abstractfatory.dir/DesignerMode/AbstractFactoryPattern/Factory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/abstractfatory.dir/DesignerMode/AbstractFactoryPattern/Factory.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ziye01/C++/iiw/DesignerMode/AbstractFactoryPattern/Factory.cpp -o CMakeFiles/abstractfatory.dir/DesignerMode/AbstractFactoryPattern/Factory.cpp.s

# Object files for target abstractfatory
abstractfatory_OBJECTS = \
"CMakeFiles/abstractfatory.dir/DesignerMode/AbstractFactoryPattern/abstract.cpp.o" \
"CMakeFiles/abstractfatory.dir/DesignerMode/AbstractFactoryPattern/Factory.cpp.o"

# External object files for target abstractfatory
abstractfatory_EXTERNAL_OBJECTS =

abstractfatory: CMakeFiles/abstractfatory.dir/DesignerMode/AbstractFactoryPattern/abstract.cpp.o
abstractfatory: CMakeFiles/abstractfatory.dir/DesignerMode/AbstractFactoryPattern/Factory.cpp.o
abstractfatory: CMakeFiles/abstractfatory.dir/build.make
abstractfatory: CMakeFiles/abstractfatory.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ziye01/C++/iiw/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable abstractfatory"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/abstractfatory.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/abstractfatory.dir/build: abstractfatory

.PHONY : CMakeFiles/abstractfatory.dir/build

CMakeFiles/abstractfatory.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/abstractfatory.dir/cmake_clean.cmake
.PHONY : CMakeFiles/abstractfatory.dir/clean

CMakeFiles/abstractfatory.dir/depend:
	cd /home/ziye01/C++/iiw/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ziye01/C++/iiw /home/ziye01/C++/iiw /home/ziye01/C++/iiw/build /home/ziye01/C++/iiw/build /home/ziye01/C++/iiw/build/CMakeFiles/abstractfatory.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/abstractfatory.dir/depend

