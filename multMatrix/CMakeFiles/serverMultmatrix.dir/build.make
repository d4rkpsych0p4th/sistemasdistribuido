# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/ubuntu/multMatrix

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/multMatrix

# Include any dependencies generated for this target.
include CMakeFiles/serverMultmatrix.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/serverMultmatrix.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/serverMultmatrix.dir/flags.make

CMakeFiles/serverMultmatrix.dir/utils.cpp.o: CMakeFiles/serverMultmatrix.dir/flags.make
CMakeFiles/serverMultmatrix.dir/utils.cpp.o: utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/multMatrix/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/serverMultmatrix.dir/utils.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/serverMultmatrix.dir/utils.cpp.o -c /home/ubuntu/multMatrix/utils.cpp

CMakeFiles/serverMultmatrix.dir/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serverMultmatrix.dir/utils.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/multMatrix/utils.cpp > CMakeFiles/serverMultmatrix.dir/utils.cpp.i

CMakeFiles/serverMultmatrix.dir/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serverMultmatrix.dir/utils.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/multMatrix/utils.cpp -o CMakeFiles/serverMultmatrix.dir/utils.cpp.s

CMakeFiles/serverMultmatrix.dir/utils.cpp.o.requires:

.PHONY : CMakeFiles/serverMultmatrix.dir/utils.cpp.o.requires

CMakeFiles/serverMultmatrix.dir/utils.cpp.o.provides: CMakeFiles/serverMultmatrix.dir/utils.cpp.o.requires
	$(MAKE) -f CMakeFiles/serverMultmatrix.dir/build.make CMakeFiles/serverMultmatrix.dir/utils.cpp.o.provides.build
.PHONY : CMakeFiles/serverMultmatrix.dir/utils.cpp.o.provides

CMakeFiles/serverMultmatrix.dir/utils.cpp.o.provides.build: CMakeFiles/serverMultmatrix.dir/utils.cpp.o


CMakeFiles/serverMultmatrix.dir/serverObjetos.cpp.o: CMakeFiles/serverMultmatrix.dir/flags.make
CMakeFiles/serverMultmatrix.dir/serverObjetos.cpp.o: serverObjetos.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/multMatrix/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/serverMultmatrix.dir/serverObjetos.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/serverMultmatrix.dir/serverObjetos.cpp.o -c /home/ubuntu/multMatrix/serverObjetos.cpp

CMakeFiles/serverMultmatrix.dir/serverObjetos.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serverMultmatrix.dir/serverObjetos.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/multMatrix/serverObjetos.cpp > CMakeFiles/serverMultmatrix.dir/serverObjetos.cpp.i

CMakeFiles/serverMultmatrix.dir/serverObjetos.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serverMultmatrix.dir/serverObjetos.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/multMatrix/serverObjetos.cpp -o CMakeFiles/serverMultmatrix.dir/serverObjetos.cpp.s

CMakeFiles/serverMultmatrix.dir/serverObjetos.cpp.o.requires:

.PHONY : CMakeFiles/serverMultmatrix.dir/serverObjetos.cpp.o.requires

CMakeFiles/serverMultmatrix.dir/serverObjetos.cpp.o.provides: CMakeFiles/serverMultmatrix.dir/serverObjetos.cpp.o.requires
	$(MAKE) -f CMakeFiles/serverMultmatrix.dir/build.make CMakeFiles/serverMultmatrix.dir/serverObjetos.cpp.o.provides.build
.PHONY : CMakeFiles/serverMultmatrix.dir/serverObjetos.cpp.o.provides

CMakeFiles/serverMultmatrix.dir/serverObjetos.cpp.o.provides.build: CMakeFiles/serverMultmatrix.dir/serverObjetos.cpp.o


CMakeFiles/serverMultmatrix.dir/multmatrix.cpp.o: CMakeFiles/serverMultmatrix.dir/flags.make
CMakeFiles/serverMultmatrix.dir/multmatrix.cpp.o: multmatrix.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/multMatrix/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/serverMultmatrix.dir/multmatrix.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/serverMultmatrix.dir/multmatrix.cpp.o -c /home/ubuntu/multMatrix/multmatrix.cpp

CMakeFiles/serverMultmatrix.dir/multmatrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serverMultmatrix.dir/multmatrix.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/multMatrix/multmatrix.cpp > CMakeFiles/serverMultmatrix.dir/multmatrix.cpp.i

CMakeFiles/serverMultmatrix.dir/multmatrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serverMultmatrix.dir/multmatrix.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/multMatrix/multmatrix.cpp -o CMakeFiles/serverMultmatrix.dir/multmatrix.cpp.s

CMakeFiles/serverMultmatrix.dir/multmatrix.cpp.o.requires:

.PHONY : CMakeFiles/serverMultmatrix.dir/multmatrix.cpp.o.requires

CMakeFiles/serverMultmatrix.dir/multmatrix.cpp.o.provides: CMakeFiles/serverMultmatrix.dir/multmatrix.cpp.o.requires
	$(MAKE) -f CMakeFiles/serverMultmatrix.dir/build.make CMakeFiles/serverMultmatrix.dir/multmatrix.cpp.o.provides.build
.PHONY : CMakeFiles/serverMultmatrix.dir/multmatrix.cpp.o.provides

CMakeFiles/serverMultmatrix.dir/multmatrix.cpp.o.provides.build: CMakeFiles/serverMultmatrix.dir/multmatrix.cpp.o


# Object files for target serverMultmatrix
serverMultmatrix_OBJECTS = \
"CMakeFiles/serverMultmatrix.dir/utils.cpp.o" \
"CMakeFiles/serverMultmatrix.dir/serverObjetos.cpp.o" \
"CMakeFiles/serverMultmatrix.dir/multmatrix.cpp.o"

# External object files for target serverMultmatrix
serverMultmatrix_EXTERNAL_OBJECTS =

serverMultmatrix: CMakeFiles/serverMultmatrix.dir/utils.cpp.o
serverMultmatrix: CMakeFiles/serverMultmatrix.dir/serverObjetos.cpp.o
serverMultmatrix: CMakeFiles/serverMultmatrix.dir/multmatrix.cpp.o
serverMultmatrix: CMakeFiles/serverMultmatrix.dir/build.make
serverMultmatrix: CMakeFiles/serverMultmatrix.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/multMatrix/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable serverMultmatrix"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/serverMultmatrix.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/serverMultmatrix.dir/build: serverMultmatrix

.PHONY : CMakeFiles/serverMultmatrix.dir/build

CMakeFiles/serverMultmatrix.dir/requires: CMakeFiles/serverMultmatrix.dir/utils.cpp.o.requires
CMakeFiles/serverMultmatrix.dir/requires: CMakeFiles/serverMultmatrix.dir/serverObjetos.cpp.o.requires
CMakeFiles/serverMultmatrix.dir/requires: CMakeFiles/serverMultmatrix.dir/multmatrix.cpp.o.requires

.PHONY : CMakeFiles/serverMultmatrix.dir/requires

CMakeFiles/serverMultmatrix.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/serverMultmatrix.dir/cmake_clean.cmake
.PHONY : CMakeFiles/serverMultmatrix.dir/clean

CMakeFiles/serverMultmatrix.dir/depend:
	cd /home/ubuntu/multMatrix && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/multMatrix /home/ubuntu/multMatrix /home/ubuntu/multMatrix /home/ubuntu/multMatrix /home/ubuntu/multMatrix/CMakeFiles/serverMultmatrix.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/serverMultmatrix.dir/depend

