# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_SOURCE_DIR = /home/pi/Documents/VisionVest/pmd-sensor/libroyale-3.20.0.62-LINUX-arm-32Bit/samples

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/Documents/VisionVest/pmd-sensor/libroyale-3.20.0.62-LINUX-arm-32Bit/samples/build

# Include any dependencies generated for this target.
include cpp/sampleRecordRRF/CMakeFiles/sampleRecordRRF.dir/depend.make

# Include the progress variables for this target.
include cpp/sampleRecordRRF/CMakeFiles/sampleRecordRRF.dir/progress.make

# Include the compile flags for this target's objects.
include cpp/sampleRecordRRF/CMakeFiles/sampleRecordRRF.dir/flags.make

cpp/sampleRecordRRF/CMakeFiles/sampleRecordRRF.dir/sampleRecordRRF.cpp.o: cpp/sampleRecordRRF/CMakeFiles/sampleRecordRRF.dir/flags.make
cpp/sampleRecordRRF/CMakeFiles/sampleRecordRRF.dir/sampleRecordRRF.cpp.o: ../cpp/sampleRecordRRF/sampleRecordRRF.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Documents/VisionVest/pmd-sensor/libroyale-3.20.0.62-LINUX-arm-32Bit/samples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object cpp/sampleRecordRRF/CMakeFiles/sampleRecordRRF.dir/sampleRecordRRF.cpp.o"
	cd /home/pi/Documents/VisionVest/pmd-sensor/libroyale-3.20.0.62-LINUX-arm-32Bit/samples/build/cpp/sampleRecordRRF && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sampleRecordRRF.dir/sampleRecordRRF.cpp.o -c /home/pi/Documents/VisionVest/pmd-sensor/libroyale-3.20.0.62-LINUX-arm-32Bit/samples/cpp/sampleRecordRRF/sampleRecordRRF.cpp

cpp/sampleRecordRRF/CMakeFiles/sampleRecordRRF.dir/sampleRecordRRF.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sampleRecordRRF.dir/sampleRecordRRF.cpp.i"
	cd /home/pi/Documents/VisionVest/pmd-sensor/libroyale-3.20.0.62-LINUX-arm-32Bit/samples/build/cpp/sampleRecordRRF && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Documents/VisionVest/pmd-sensor/libroyale-3.20.0.62-LINUX-arm-32Bit/samples/cpp/sampleRecordRRF/sampleRecordRRF.cpp > CMakeFiles/sampleRecordRRF.dir/sampleRecordRRF.cpp.i

cpp/sampleRecordRRF/CMakeFiles/sampleRecordRRF.dir/sampleRecordRRF.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sampleRecordRRF.dir/sampleRecordRRF.cpp.s"
	cd /home/pi/Documents/VisionVest/pmd-sensor/libroyale-3.20.0.62-LINUX-arm-32Bit/samples/build/cpp/sampleRecordRRF && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Documents/VisionVest/pmd-sensor/libroyale-3.20.0.62-LINUX-arm-32Bit/samples/cpp/sampleRecordRRF/sampleRecordRRF.cpp -o CMakeFiles/sampleRecordRRF.dir/sampleRecordRRF.cpp.s

cpp/sampleRecordRRF/CMakeFiles/sampleRecordRRF.dir/sampleRecordRRF.cpp.o.requires:

.PHONY : cpp/sampleRecordRRF/CMakeFiles/sampleRecordRRF.dir/sampleRecordRRF.cpp.o.requires

cpp/sampleRecordRRF/CMakeFiles/sampleRecordRRF.dir/sampleRecordRRF.cpp.o.provides: cpp/sampleRecordRRF/CMakeFiles/sampleRecordRRF.dir/sampleRecordRRF.cpp.o.requires
	$(MAKE) -f cpp/sampleRecordRRF/CMakeFiles/sampleRecordRRF.dir/build.make cpp/sampleRecordRRF/CMakeFiles/sampleRecordRRF.dir/sampleRecordRRF.cpp.o.provides.build
.PHONY : cpp/sampleRecordRRF/CMakeFiles/sampleRecordRRF.dir/sampleRecordRRF.cpp.o.provides

cpp/sampleRecordRRF/CMakeFiles/sampleRecordRRF.dir/sampleRecordRRF.cpp.o.provides.build: cpp/sampleRecordRRF/CMakeFiles/sampleRecordRRF.dir/sampleRecordRRF.cpp.o


# Object files for target sampleRecordRRF
sampleRecordRRF_OBJECTS = \
"CMakeFiles/sampleRecordRRF.dir/sampleRecordRRF.cpp.o"

# External object files for target sampleRecordRRF
sampleRecordRRF_EXTERNAL_OBJECTS =

cpp/sampleRecordRRF/sampleRecordRRF: cpp/sampleRecordRRF/CMakeFiles/sampleRecordRRF.dir/sampleRecordRRF.cpp.o
cpp/sampleRecordRRF/sampleRecordRRF: cpp/sampleRecordRRF/CMakeFiles/sampleRecordRRF.dir/build.make
cpp/sampleRecordRRF/sampleRecordRRF: cpp/sampleRecordRRF/CMakeFiles/sampleRecordRRF.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/Documents/VisionVest/pmd-sensor/libroyale-3.20.0.62-LINUX-arm-32Bit/samples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sampleRecordRRF"
	cd /home/pi/Documents/VisionVest/pmd-sensor/libroyale-3.20.0.62-LINUX-arm-32Bit/samples/build/cpp/sampleRecordRRF && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sampleRecordRRF.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
cpp/sampleRecordRRF/CMakeFiles/sampleRecordRRF.dir/build: cpp/sampleRecordRRF/sampleRecordRRF

.PHONY : cpp/sampleRecordRRF/CMakeFiles/sampleRecordRRF.dir/build

cpp/sampleRecordRRF/CMakeFiles/sampleRecordRRF.dir/requires: cpp/sampleRecordRRF/CMakeFiles/sampleRecordRRF.dir/sampleRecordRRF.cpp.o.requires

.PHONY : cpp/sampleRecordRRF/CMakeFiles/sampleRecordRRF.dir/requires

cpp/sampleRecordRRF/CMakeFiles/sampleRecordRRF.dir/clean:
	cd /home/pi/Documents/VisionVest/pmd-sensor/libroyale-3.20.0.62-LINUX-arm-32Bit/samples/build/cpp/sampleRecordRRF && $(CMAKE_COMMAND) -P CMakeFiles/sampleRecordRRF.dir/cmake_clean.cmake
.PHONY : cpp/sampleRecordRRF/CMakeFiles/sampleRecordRRF.dir/clean

cpp/sampleRecordRRF/CMakeFiles/sampleRecordRRF.dir/depend:
	cd /home/pi/Documents/VisionVest/pmd-sensor/libroyale-3.20.0.62-LINUX-arm-32Bit/samples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/Documents/VisionVest/pmd-sensor/libroyale-3.20.0.62-LINUX-arm-32Bit/samples /home/pi/Documents/VisionVest/pmd-sensor/libroyale-3.20.0.62-LINUX-arm-32Bit/samples/cpp/sampleRecordRRF /home/pi/Documents/VisionVest/pmd-sensor/libroyale-3.20.0.62-LINUX-arm-32Bit/samples/build /home/pi/Documents/VisionVest/pmd-sensor/libroyale-3.20.0.62-LINUX-arm-32Bit/samples/build/cpp/sampleRecordRRF /home/pi/Documents/VisionVest/pmd-sensor/libroyale-3.20.0.62-LINUX-arm-32Bit/samples/build/cpp/sampleRecordRRF/CMakeFiles/sampleRecordRRF.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : cpp/sampleRecordRRF/CMakeFiles/sampleRecordRRF.dir/depend

