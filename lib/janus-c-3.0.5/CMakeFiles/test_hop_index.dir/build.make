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
CMAKE_COMMAND = /snap/cmake/1009/bin/cmake

# The command to remove a file.
RM = /snap/cmake/1009/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/janus/NTNU_ROV_COM/lib/janus-c-3.0.5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/janus/NTNU_ROV_COM/lib/janus-c-3.0.5

# Include any dependencies generated for this target.
include CMakeFiles/test_hop_index.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test_hop_index.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test_hop_index.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_hop_index.dir/flags.make

CMakeFiles/test_hop_index.dir/tests/c/hop_index.c.o: CMakeFiles/test_hop_index.dir/flags.make
CMakeFiles/test_hop_index.dir/tests/c/hop_index.c.o: tests/c/hop_index.c
CMakeFiles/test_hop_index.dir/tests/c/hop_index.c.o: CMakeFiles/test_hop_index.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/janus/NTNU_ROV_COM/lib/janus-c-3.0.5/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/test_hop_index.dir/tests/c/hop_index.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/test_hop_index.dir/tests/c/hop_index.c.o -MF CMakeFiles/test_hop_index.dir/tests/c/hop_index.c.o.d -o CMakeFiles/test_hop_index.dir/tests/c/hop_index.c.o -c /home/janus/NTNU_ROV_COM/lib/janus-c-3.0.5/tests/c/hop_index.c

CMakeFiles/test_hop_index.dir/tests/c/hop_index.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_hop_index.dir/tests/c/hop_index.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/janus/NTNU_ROV_COM/lib/janus-c-3.0.5/tests/c/hop_index.c > CMakeFiles/test_hop_index.dir/tests/c/hop_index.c.i

CMakeFiles/test_hop_index.dir/tests/c/hop_index.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_hop_index.dir/tests/c/hop_index.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/janus/NTNU_ROV_COM/lib/janus-c-3.0.5/tests/c/hop_index.c -o CMakeFiles/test_hop_index.dir/tests/c/hop_index.c.s

# Object files for target test_hop_index
test_hop_index_OBJECTS = \
"CMakeFiles/test_hop_index.dir/tests/c/hop_index.c.o"

# External object files for target test_hop_index
test_hop_index_EXTERNAL_OBJECTS =

test_hop_index: CMakeFiles/test_hop_index.dir/tests/c/hop_index.c.o
test_hop_index: CMakeFiles/test_hop_index.dir/build.make
test_hop_index: libjanus.a
test_hop_index: /usr/local/lib/libfftw3.a
test_hop_index: CMakeFiles/test_hop_index.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/janus/NTNU_ROV_COM/lib/janus-c-3.0.5/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable test_hop_index"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_hop_index.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_hop_index.dir/build: test_hop_index
.PHONY : CMakeFiles/test_hop_index.dir/build

CMakeFiles/test_hop_index.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_hop_index.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_hop_index.dir/clean

CMakeFiles/test_hop_index.dir/depend:
	cd /home/janus/NTNU_ROV_COM/lib/janus-c-3.0.5 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/janus/NTNU_ROV_COM/lib/janus-c-3.0.5 /home/janus/NTNU_ROV_COM/lib/janus-c-3.0.5 /home/janus/NTNU_ROV_COM/lib/janus-c-3.0.5 /home/janus/NTNU_ROV_COM/lib/janus-c-3.0.5 /home/janus/NTNU_ROV_COM/lib/janus-c-3.0.5/CMakeFiles/test_hop_index.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_hop_index.dir/depend

