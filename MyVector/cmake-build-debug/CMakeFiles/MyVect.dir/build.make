# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\C++\MyVect

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\C++\MyVect\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MyVect.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MyVect.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MyVect.dir/flags.make

CMakeFiles/MyVect.dir/main.cpp.obj: CMakeFiles/MyVect.dir/flags.make
CMakeFiles/MyVect.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\C++\MyVect\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MyVect.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\MyVect.dir\main.cpp.obj -c C:\C++\MyVect\main.cpp

CMakeFiles/MyVect.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyVect.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\C++\MyVect\main.cpp > CMakeFiles\MyVect.dir\main.cpp.i

CMakeFiles/MyVect.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyVect.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\C++\MyVect\main.cpp -o CMakeFiles\MyVect.dir\main.cpp.s

# Object files for target MyVect
MyVect_OBJECTS = \
"CMakeFiles/MyVect.dir/main.cpp.obj"

# External object files for target MyVect
MyVect_EXTERNAL_OBJECTS =

MyVect.exe: CMakeFiles/MyVect.dir/main.cpp.obj
MyVect.exe: CMakeFiles/MyVect.dir/build.make
MyVect.exe: CMakeFiles/MyVect.dir/linklibs.rsp
MyVect.exe: CMakeFiles/MyVect.dir/objects1.rsp
MyVect.exe: CMakeFiles/MyVect.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\C++\MyVect\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MyVect.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\MyVect.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MyVect.dir/build: MyVect.exe

.PHONY : CMakeFiles/MyVect.dir/build

CMakeFiles/MyVect.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\MyVect.dir\cmake_clean.cmake
.PHONY : CMakeFiles/MyVect.dir/clean

CMakeFiles/MyVect.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\C++\MyVect C:\C++\MyVect C:\C++\MyVect\cmake-build-debug C:\C++\MyVect\cmake-build-debug C:\C++\MyVect\cmake-build-debug\CMakeFiles\MyVect.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MyVect.dir/depend

