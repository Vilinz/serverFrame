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


# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_COMMAND = /home/vilingif/Desktop/cmake/cmake/bin/cmake

# The command to remove a file.
RM = /home/vilingif/Desktop/cmake/cmake/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vilingif/Desktop/serverFrame

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vilingif/Desktop/serverFrame

# Include any dependencies generated for this target.
include CMakeFiles/vilin.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/vilin.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/vilin.dir/flags.make

CMakeFiles/vilin.dir/vilin/log/log.cc.o: CMakeFiles/vilin.dir/flags.make
CMakeFiles/vilin.dir/vilin/log/log.cc.o: vilin/log/log.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vilingif/Desktop/serverFrame/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/vilin.dir/vilin/log/log.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) -D__FILE__=\"vilin/log/log.cc\" $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/vilin.dir/vilin/log/log.cc.o -c /home/vilingif/Desktop/serverFrame/vilin/log/log.cc

CMakeFiles/vilin.dir/vilin/log/log.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vilin.dir/vilin/log/log.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) -D__FILE__=\"vilin/log/log.cc\" $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vilingif/Desktop/serverFrame/vilin/log/log.cc > CMakeFiles/vilin.dir/vilin/log/log.cc.i

CMakeFiles/vilin.dir/vilin/log/log.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vilin.dir/vilin/log/log.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) -D__FILE__=\"vilin/log/log.cc\" $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vilingif/Desktop/serverFrame/vilin/log/log.cc -o CMakeFiles/vilin.dir/vilin/log/log.cc.s

CMakeFiles/vilin.dir/vilin/util.cc.o: CMakeFiles/vilin.dir/flags.make
CMakeFiles/vilin.dir/vilin/util.cc.o: vilin/util.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vilingif/Desktop/serverFrame/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/vilin.dir/vilin/util.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) -D__FILE__=\"vilin/util.cc\" $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/vilin.dir/vilin/util.cc.o -c /home/vilingif/Desktop/serverFrame/vilin/util.cc

CMakeFiles/vilin.dir/vilin/util.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vilin.dir/vilin/util.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) -D__FILE__=\"vilin/util.cc\" $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vilingif/Desktop/serverFrame/vilin/util.cc > CMakeFiles/vilin.dir/vilin/util.cc.i

CMakeFiles/vilin.dir/vilin/util.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vilin.dir/vilin/util.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) -D__FILE__=\"vilin/util.cc\" $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vilingif/Desktop/serverFrame/vilin/util.cc -o CMakeFiles/vilin.dir/vilin/util.cc.s

CMakeFiles/vilin.dir/vilin/config.cc.o: CMakeFiles/vilin.dir/flags.make
CMakeFiles/vilin.dir/vilin/config.cc.o: vilin/config.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vilingif/Desktop/serverFrame/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/vilin.dir/vilin/config.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) -D__FILE__=\"vilin/config.cc\" $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/vilin.dir/vilin/config.cc.o -c /home/vilingif/Desktop/serverFrame/vilin/config.cc

CMakeFiles/vilin.dir/vilin/config.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vilin.dir/vilin/config.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) -D__FILE__=\"vilin/config.cc\" $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vilingif/Desktop/serverFrame/vilin/config.cc > CMakeFiles/vilin.dir/vilin/config.cc.i

CMakeFiles/vilin.dir/vilin/config.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vilin.dir/vilin/config.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) -D__FILE__=\"vilin/config.cc\" $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vilingif/Desktop/serverFrame/vilin/config.cc -o CMakeFiles/vilin.dir/vilin/config.cc.s

CMakeFiles/vilin.dir/vilin/thread.cc.o: CMakeFiles/vilin.dir/flags.make
CMakeFiles/vilin.dir/vilin/thread.cc.o: vilin/thread.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vilingif/Desktop/serverFrame/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/vilin.dir/vilin/thread.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) -D__FILE__=\"vilin/thread.cc\" $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/vilin.dir/vilin/thread.cc.o -c /home/vilingif/Desktop/serverFrame/vilin/thread.cc

CMakeFiles/vilin.dir/vilin/thread.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vilin.dir/vilin/thread.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) -D__FILE__=\"vilin/thread.cc\" $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vilingif/Desktop/serverFrame/vilin/thread.cc > CMakeFiles/vilin.dir/vilin/thread.cc.i

CMakeFiles/vilin.dir/vilin/thread.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vilin.dir/vilin/thread.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) -D__FILE__=\"vilin/thread.cc\" $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vilingif/Desktop/serverFrame/vilin/thread.cc -o CMakeFiles/vilin.dir/vilin/thread.cc.s

# Object files for target vilin
vilin_OBJECTS = \
"CMakeFiles/vilin.dir/vilin/log/log.cc.o" \
"CMakeFiles/vilin.dir/vilin/util.cc.o" \
"CMakeFiles/vilin.dir/vilin/config.cc.o" \
"CMakeFiles/vilin.dir/vilin/thread.cc.o"

# External object files for target vilin
vilin_EXTERNAL_OBJECTS =

lib/libvilin.so: CMakeFiles/vilin.dir/vilin/log/log.cc.o
lib/libvilin.so: CMakeFiles/vilin.dir/vilin/util.cc.o
lib/libvilin.so: CMakeFiles/vilin.dir/vilin/config.cc.o
lib/libvilin.so: CMakeFiles/vilin.dir/vilin/thread.cc.o
lib/libvilin.so: CMakeFiles/vilin.dir/build.make
lib/libvilin.so: CMakeFiles/vilin.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vilingif/Desktop/serverFrame/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX shared library lib/libvilin.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vilin.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/vilin.dir/build: lib/libvilin.so

.PHONY : CMakeFiles/vilin.dir/build

CMakeFiles/vilin.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/vilin.dir/cmake_clean.cmake
.PHONY : CMakeFiles/vilin.dir/clean

CMakeFiles/vilin.dir/depend:
	cd /home/vilingif/Desktop/serverFrame && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vilingif/Desktop/serverFrame /home/vilingif/Desktop/serverFrame /home/vilingif/Desktop/serverFrame /home/vilingif/Desktop/serverFrame /home/vilingif/Desktop/serverFrame/CMakeFiles/vilin.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/vilin.dir/depend

