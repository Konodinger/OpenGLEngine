# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\berge\Documents\Cours\igr\TP00-OpenGL\src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\berge\Documents\Cours\igr\TP00-OpenGL\src

# Include any dependencies generated for this target.
include dep/glfw/examples/CMakeFiles/splitview.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include dep/glfw/examples/CMakeFiles/splitview.dir/compiler_depend.make

# Include the progress variables for this target.
include dep/glfw/examples/CMakeFiles/splitview.dir/progress.make

# Include the compile flags for this target's objects.
include dep/glfw/examples/CMakeFiles/splitview.dir/flags.make

dep/glfw/examples/CMakeFiles/splitview.dir/splitview.c.obj: dep/glfw/examples/CMakeFiles/splitview.dir/flags.make
dep/glfw/examples/CMakeFiles/splitview.dir/splitview.c.obj: dep/glfw/examples/CMakeFiles/splitview.dir/includes_C.rsp
dep/glfw/examples/CMakeFiles/splitview.dir/splitview.c.obj: dep/glfw/examples/splitview.c
dep/glfw/examples/CMakeFiles/splitview.dir/splitview.c.obj: dep/glfw/examples/CMakeFiles/splitview.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\berge\Documents\Cours\igr\TP00-OpenGL\src\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object dep/glfw/examples/CMakeFiles/splitview.dir/splitview.c.obj"
	cd /d C:\Users\berge\Documents\Cours\igr\TP00-OpenGL\src\dep\glfw\examples && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT dep/glfw/examples/CMakeFiles/splitview.dir/splitview.c.obj -MF CMakeFiles\splitview.dir\splitview.c.obj.d -o CMakeFiles\splitview.dir\splitview.c.obj -c C:\Users\berge\Documents\Cours\igr\TP00-OpenGL\src\dep\glfw\examples\splitview.c

dep/glfw/examples/CMakeFiles/splitview.dir/splitview.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/splitview.dir/splitview.c.i"
	cd /d C:\Users\berge\Documents\Cours\igr\TP00-OpenGL\src\dep\glfw\examples && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\berge\Documents\Cours\igr\TP00-OpenGL\src\dep\glfw\examples\splitview.c > CMakeFiles\splitview.dir\splitview.c.i

dep/glfw/examples/CMakeFiles/splitview.dir/splitview.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/splitview.dir/splitview.c.s"
	cd /d C:\Users\berge\Documents\Cours\igr\TP00-OpenGL\src\dep\glfw\examples && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\berge\Documents\Cours\igr\TP00-OpenGL\src\dep\glfw\examples\splitview.c -o CMakeFiles\splitview.dir\splitview.c.s

dep/glfw/examples/CMakeFiles/splitview.dir/glfw.rc.obj: dep/glfw/examples/CMakeFiles/splitview.dir/flags.make
dep/glfw/examples/CMakeFiles/splitview.dir/glfw.rc.obj: dep/glfw/examples/glfw.rc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\berge\Documents\Cours\igr\TP00-OpenGL\src\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building RC object dep/glfw/examples/CMakeFiles/splitview.dir/glfw.rc.obj"
	cd /d C:\Users\berge\Documents\Cours\igr\TP00-OpenGL\src\dep\glfw\examples && C:\MinGW\bin\windres.exe -O coff $(RC_DEFINES) $(RC_INCLUDES) $(RC_FLAGS) C:\Users\berge\Documents\Cours\igr\TP00-OpenGL\src\dep\glfw\examples\glfw.rc CMakeFiles\splitview.dir\glfw.rc.obj

dep/glfw/examples/CMakeFiles/splitview.dir/__/deps/glad_gl.c.obj: dep/glfw/examples/CMakeFiles/splitview.dir/flags.make
dep/glfw/examples/CMakeFiles/splitview.dir/__/deps/glad_gl.c.obj: dep/glfw/examples/CMakeFiles/splitview.dir/includes_C.rsp
dep/glfw/examples/CMakeFiles/splitview.dir/__/deps/glad_gl.c.obj: dep/glfw/deps/glad_gl.c
dep/glfw/examples/CMakeFiles/splitview.dir/__/deps/glad_gl.c.obj: dep/glfw/examples/CMakeFiles/splitview.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\berge\Documents\Cours\igr\TP00-OpenGL\src\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object dep/glfw/examples/CMakeFiles/splitview.dir/__/deps/glad_gl.c.obj"
	cd /d C:\Users\berge\Documents\Cours\igr\TP00-OpenGL\src\dep\glfw\examples && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT dep/glfw/examples/CMakeFiles/splitview.dir/__/deps/glad_gl.c.obj -MF CMakeFiles\splitview.dir\__\deps\glad_gl.c.obj.d -o CMakeFiles\splitview.dir\__\deps\glad_gl.c.obj -c C:\Users\berge\Documents\Cours\igr\TP00-OpenGL\src\dep\glfw\deps\glad_gl.c

dep/glfw/examples/CMakeFiles/splitview.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/splitview.dir/__/deps/glad_gl.c.i"
	cd /d C:\Users\berge\Documents\Cours\igr\TP00-OpenGL\src\dep\glfw\examples && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\berge\Documents\Cours\igr\TP00-OpenGL\src\dep\glfw\deps\glad_gl.c > CMakeFiles\splitview.dir\__\deps\glad_gl.c.i

dep/glfw/examples/CMakeFiles/splitview.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/splitview.dir/__/deps/glad_gl.c.s"
	cd /d C:\Users\berge\Documents\Cours\igr\TP00-OpenGL\src\dep\glfw\examples && C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\berge\Documents\Cours\igr\TP00-OpenGL\src\dep\glfw\deps\glad_gl.c -o CMakeFiles\splitview.dir\__\deps\glad_gl.c.s

# Object files for target splitview
splitview_OBJECTS = \
"CMakeFiles/splitview.dir/splitview.c.obj" \
"CMakeFiles/splitview.dir/glfw.rc.obj" \
"CMakeFiles/splitview.dir/__/deps/glad_gl.c.obj"

# External object files for target splitview
splitview_EXTERNAL_OBJECTS =

dep/glfw/examples/splitview.exe: dep/glfw/examples/CMakeFiles/splitview.dir/splitview.c.obj
dep/glfw/examples/splitview.exe: dep/glfw/examples/CMakeFiles/splitview.dir/glfw.rc.obj
dep/glfw/examples/splitview.exe: dep/glfw/examples/CMakeFiles/splitview.dir/__/deps/glad_gl.c.obj
dep/glfw/examples/splitview.exe: dep/glfw/examples/CMakeFiles/splitview.dir/build.make
dep/glfw/examples/splitview.exe: dep/glfw/src/libglfw3.a
dep/glfw/examples/splitview.exe: dep/glfw/examples/CMakeFiles/splitview.dir/linklibs.rsp
dep/glfw/examples/splitview.exe: dep/glfw/examples/CMakeFiles/splitview.dir/objects1.rsp
dep/glfw/examples/splitview.exe: dep/glfw/examples/CMakeFiles/splitview.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\berge\Documents\Cours\igr\TP00-OpenGL\src\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable splitview.exe"
	cd /d C:\Users\berge\Documents\Cours\igr\TP00-OpenGL\src\dep\glfw\examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\splitview.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
dep/glfw/examples/CMakeFiles/splitview.dir/build: dep/glfw/examples/splitview.exe
.PHONY : dep/glfw/examples/CMakeFiles/splitview.dir/build

dep/glfw/examples/CMakeFiles/splitview.dir/clean:
	cd /d C:\Users\berge\Documents\Cours\igr\TP00-OpenGL\src\dep\glfw\examples && $(CMAKE_COMMAND) -P CMakeFiles\splitview.dir\cmake_clean.cmake
.PHONY : dep/glfw/examples/CMakeFiles/splitview.dir/clean

dep/glfw/examples/CMakeFiles/splitview.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\berge\Documents\Cours\igr\TP00-OpenGL\src C:\Users\berge\Documents\Cours\igr\TP00-OpenGL\src\dep\glfw\examples C:\Users\berge\Documents\Cours\igr\TP00-OpenGL\src C:\Users\berge\Documents\Cours\igr\TP00-OpenGL\src\dep\glfw\examples C:\Users\berge\Documents\Cours\igr\TP00-OpenGL\src\dep\glfw\examples\CMakeFiles\splitview.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : dep/glfw/examples/CMakeFiles/splitview.dir/depend

