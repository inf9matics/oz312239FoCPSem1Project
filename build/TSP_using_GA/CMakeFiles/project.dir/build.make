# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = F:\Cmake\bin\cmake.exe

# The command to remove a file.
RM = F:\Cmake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:\VSCode\Final_Project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\VSCode\Final_Project\build

# Include any dependencies generated for this target.
include TSP_using_GA/CMakeFiles/project.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include TSP_using_GA/CMakeFiles/project.dir/compiler_depend.make

# Include the progress variables for this target.
include TSP_using_GA/CMakeFiles/project.dir/progress.make

# Include the compile flags for this target's objects.
include TSP_using_GA/CMakeFiles/project.dir/flags.make

TSP_using_GA/CMakeFiles/project.dir/main.cpp.obj: TSP_using_GA/CMakeFiles/project.dir/flags.make
TSP_using_GA/CMakeFiles/project.dir/main.cpp.obj: F:/VSCode/Final_Project/TSP_using_GA/main.cpp
TSP_using_GA/CMakeFiles/project.dir/main.cpp.obj: TSP_using_GA/CMakeFiles/project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=F:\VSCode\Final_Project\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object TSP_using_GA/CMakeFiles/project.dir/main.cpp.obj"
	cd /d F:\VSCode\Final_Project\build\TSP_using_GA && F:\MSYS2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT TSP_using_GA/CMakeFiles/project.dir/main.cpp.obj -MF CMakeFiles\project.dir\main.cpp.obj.d -o CMakeFiles\project.dir\main.cpp.obj -c F:\VSCode\Final_Project\TSP_using_GA\main.cpp

TSP_using_GA/CMakeFiles/project.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/project.dir/main.cpp.i"
	cd /d F:\VSCode\Final_Project\build\TSP_using_GA && F:\MSYS2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\VSCode\Final_Project\TSP_using_GA\main.cpp > CMakeFiles\project.dir\main.cpp.i

TSP_using_GA/CMakeFiles/project.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/project.dir/main.cpp.s"
	cd /d F:\VSCode\Final_Project\build\TSP_using_GA && F:\MSYS2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\VSCode\Final_Project\TSP_using_GA\main.cpp -o CMakeFiles\project.dir\main.cpp.s

TSP_using_GA/CMakeFiles/project.dir/utils.cpp.obj: TSP_using_GA/CMakeFiles/project.dir/flags.make
TSP_using_GA/CMakeFiles/project.dir/utils.cpp.obj: F:/VSCode/Final_Project/TSP_using_GA/utils.cpp
TSP_using_GA/CMakeFiles/project.dir/utils.cpp.obj: TSP_using_GA/CMakeFiles/project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=F:\VSCode\Final_Project\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object TSP_using_GA/CMakeFiles/project.dir/utils.cpp.obj"
	cd /d F:\VSCode\Final_Project\build\TSP_using_GA && F:\MSYS2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT TSP_using_GA/CMakeFiles/project.dir/utils.cpp.obj -MF CMakeFiles\project.dir\utils.cpp.obj.d -o CMakeFiles\project.dir\utils.cpp.obj -c F:\VSCode\Final_Project\TSP_using_GA\utils.cpp

TSP_using_GA/CMakeFiles/project.dir/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/project.dir/utils.cpp.i"
	cd /d F:\VSCode\Final_Project\build\TSP_using_GA && F:\MSYS2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\VSCode\Final_Project\TSP_using_GA\utils.cpp > CMakeFiles\project.dir\utils.cpp.i

TSP_using_GA/CMakeFiles/project.dir/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/project.dir/utils.cpp.s"
	cd /d F:\VSCode\Final_Project\build\TSP_using_GA && F:\MSYS2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\VSCode\Final_Project\TSP_using_GA\utils.cpp -o CMakeFiles\project.dir\utils.cpp.s

TSP_using_GA/CMakeFiles/project.dir/geneticAlgorithm.cpp.obj: TSP_using_GA/CMakeFiles/project.dir/flags.make
TSP_using_GA/CMakeFiles/project.dir/geneticAlgorithm.cpp.obj: F:/VSCode/Final_Project/TSP_using_GA/geneticAlgorithm.cpp
TSP_using_GA/CMakeFiles/project.dir/geneticAlgorithm.cpp.obj: TSP_using_GA/CMakeFiles/project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=F:\VSCode\Final_Project\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object TSP_using_GA/CMakeFiles/project.dir/geneticAlgorithm.cpp.obj"
	cd /d F:\VSCode\Final_Project\build\TSP_using_GA && F:\MSYS2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT TSP_using_GA/CMakeFiles/project.dir/geneticAlgorithm.cpp.obj -MF CMakeFiles\project.dir\geneticAlgorithm.cpp.obj.d -o CMakeFiles\project.dir\geneticAlgorithm.cpp.obj -c F:\VSCode\Final_Project\TSP_using_GA\geneticAlgorithm.cpp

TSP_using_GA/CMakeFiles/project.dir/geneticAlgorithm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/project.dir/geneticAlgorithm.cpp.i"
	cd /d F:\VSCode\Final_Project\build\TSP_using_GA && F:\MSYS2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\VSCode\Final_Project\TSP_using_GA\geneticAlgorithm.cpp > CMakeFiles\project.dir\geneticAlgorithm.cpp.i

TSP_using_GA/CMakeFiles/project.dir/geneticAlgorithm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/project.dir/geneticAlgorithm.cpp.s"
	cd /d F:\VSCode\Final_Project\build\TSP_using_GA && F:\MSYS2\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\VSCode\Final_Project\TSP_using_GA\geneticAlgorithm.cpp -o CMakeFiles\project.dir\geneticAlgorithm.cpp.s

# Object files for target project
project_OBJECTS = \
"CMakeFiles/project.dir/main.cpp.obj" \
"CMakeFiles/project.dir/utils.cpp.obj" \
"CMakeFiles/project.dir/geneticAlgorithm.cpp.obj"

# External object files for target project
project_EXTERNAL_OBJECTS =

TSP_using_GA/project.exe: TSP_using_GA/CMakeFiles/project.dir/main.cpp.obj
TSP_using_GA/project.exe: TSP_using_GA/CMakeFiles/project.dir/utils.cpp.obj
TSP_using_GA/project.exe: TSP_using_GA/CMakeFiles/project.dir/geneticAlgorithm.cpp.obj
TSP_using_GA/project.exe: TSP_using_GA/CMakeFiles/project.dir/build.make
TSP_using_GA/project.exe: TSP_using_GA/CMakeFiles/project.dir/linkLibs.rsp
TSP_using_GA/project.exe: TSP_using_GA/CMakeFiles/project.dir/objects1.rsp
TSP_using_GA/project.exe: TSP_using_GA/CMakeFiles/project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=F:\VSCode\Final_Project\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable project.exe"
	cd /d F:\VSCode\Final_Project\build\TSP_using_GA && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\project.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
TSP_using_GA/CMakeFiles/project.dir/build: TSP_using_GA/project.exe
.PHONY : TSP_using_GA/CMakeFiles/project.dir/build

TSP_using_GA/CMakeFiles/project.dir/clean:
	cd /d F:\VSCode\Final_Project\build\TSP_using_GA && $(CMAKE_COMMAND) -P CMakeFiles\project.dir\cmake_clean.cmake
.PHONY : TSP_using_GA/CMakeFiles/project.dir/clean

TSP_using_GA/CMakeFiles/project.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\VSCode\Final_Project F:\VSCode\Final_Project\TSP_using_GA F:\VSCode\Final_Project\build F:\VSCode\Final_Project\build\TSP_using_GA F:\VSCode\Final_Project\build\TSP_using_GA\CMakeFiles\project.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : TSP_using_GA/CMakeFiles/project.dir/depend

