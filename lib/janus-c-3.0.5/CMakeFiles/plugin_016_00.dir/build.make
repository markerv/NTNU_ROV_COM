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
CMAKE_SOURCE_DIR = /home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5

# Include any dependencies generated for this target.
include CMakeFiles/plugin_016_00.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/plugin_016_00.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/plugin_016_00.dir/flags.make

CMakeFiles/plugin_016_00.dir/src/c/plugins/plugin_016_00.c.o: CMakeFiles/plugin_016_00.dir/flags.make
CMakeFiles/plugin_016_00.dir/src/c/plugins/plugin_016_00.c.o: src/c/plugins/plugin_016_00.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/plugin_016_00.dir/src/c/plugins/plugin_016_00.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/plugin_016_00.dir/src/c/plugins/plugin_016_00.c.o   -c /home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/plugins/plugin_016_00.c

CMakeFiles/plugin_016_00.dir/src/c/plugins/plugin_016_00.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/plugin_016_00.dir/src/c/plugins/plugin_016_00.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/plugins/plugin_016_00.c > CMakeFiles/plugin_016_00.dir/src/c/plugins/plugin_016_00.c.i

CMakeFiles/plugin_016_00.dir/src/c/plugins/plugin_016_00.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/plugin_016_00.dir/src/c/plugins/plugin_016_00.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/src/c/plugins/plugin_016_00.c -o CMakeFiles/plugin_016_00.dir/src/c/plugins/plugin_016_00.c.s

# Object files for target plugin_016_00
plugin_016_00_OBJECTS = \
"CMakeFiles/plugin_016_00.dir/src/c/plugins/plugin_016_00.c.o"

# External object files for target plugin_016_00
plugin_016_00_EXTERNAL_OBJECTS =

libplugin_016_00.so: CMakeFiles/plugin_016_00.dir/src/c/plugins/plugin_016_00.c.o
libplugin_016_00.so: CMakeFiles/plugin_016_00.dir/build.make
libplugin_016_00.so: libjanus.a
libplugin_016_00.so: CMakeFiles/plugin_016_00.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared module libplugin_016_00.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/plugin_016_00.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/plugin_016_00.dir/build: libplugin_016_00.so

.PHONY : CMakeFiles/plugin_016_00.dir/build

CMakeFiles/plugin_016_00.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/plugin_016_00.dir/cmake_clean.cmake
.PHONY : CMakeFiles/plugin_016_00.dir/clean

CMakeFiles/plugin_016_00.dir/depend:
	cd /home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5 /home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5 /home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5 /home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5 /home/admin/amodem/NTNU_ROV_COM/lib/janus-c-3.0.5/CMakeFiles/plugin_016_00.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/plugin_016_00.dir/depend

