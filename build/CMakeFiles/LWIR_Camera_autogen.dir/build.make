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
CMAKE_SOURCE_DIR = /home/jetson/Downloads/project/lwir_camera

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jetson/Downloads/project/lwir_camera/build

# Utility rule file for LWIR_Camera_autogen.

# Include the progress variables for this target.
include CMakeFiles/LWIR_Camera_autogen.dir/progress.make

CMakeFiles/LWIR_Camera_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/jetson/Downloads/project/lwir_camera/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target LWIR_Camera"
	/usr/bin/cmake -E cmake_autogen /home/jetson/Downloads/project/lwir_camera/build/CMakeFiles/LWIR_Camera_autogen.dir/AutogenInfo.json ""

LWIR_Camera_autogen: CMakeFiles/LWIR_Camera_autogen
LWIR_Camera_autogen: CMakeFiles/LWIR_Camera_autogen.dir/build.make

.PHONY : LWIR_Camera_autogen

# Rule to build all files generated by this target.
CMakeFiles/LWIR_Camera_autogen.dir/build: LWIR_Camera_autogen

.PHONY : CMakeFiles/LWIR_Camera_autogen.dir/build

CMakeFiles/LWIR_Camera_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LWIR_Camera_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LWIR_Camera_autogen.dir/clean

CMakeFiles/LWIR_Camera_autogen.dir/depend:
	cd /home/jetson/Downloads/project/lwir_camera/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jetson/Downloads/project/lwir_camera /home/jetson/Downloads/project/lwir_camera /home/jetson/Downloads/project/lwir_camera/build /home/jetson/Downloads/project/lwir_camera/build /home/jetson/Downloads/project/lwir_camera/build/CMakeFiles/LWIR_Camera_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LWIR_Camera_autogen.dir/depend

