# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.3

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = "C:\Program Files (x86)\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\wathe\Desktop\pong

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\wathe\Desktop\pong

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	"C:\Program Files (x86)\CMake\bin\cmake-gui.exe" -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	"C:\Program Files (x86)\CMake\bin\cmake.exe" -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start C:\Users\wathe\Desktop\pong\CMakeFiles C:\Users\wathe\Desktop\pong\CMakeFiles\progress.marks
	$(MAKE) -f CMakeFiles\Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start C:\Users\wathe\Desktop\pong\CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles\Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles\Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles\Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles\Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named pong

# Build rule for target.
pong: cmake_check_build_system
	$(MAKE) -f CMakeFiles\Makefile2 pong
.PHONY : pong

# fast build rule for target.
pong/fast:
	$(MAKE) -f CMakeFiles\pong.dir\build.make CMakeFiles/pong.dir/build
.PHONY : pong/fast

bin/pong.obj: bin/pong.cpp.obj

.PHONY : bin/pong.obj

# target to build an object file
bin/pong.cpp.obj:
	$(MAKE) -f CMakeFiles\pong.dir\build.make CMakeFiles/pong.dir/bin/pong.cpp.obj
.PHONY : bin/pong.cpp.obj

bin/pong.i: bin/pong.cpp.i

.PHONY : bin/pong.i

# target to preprocess a source file
bin/pong.cpp.i:
	$(MAKE) -f CMakeFiles\pong.dir\build.make CMakeFiles/pong.dir/bin/pong.cpp.i
.PHONY : bin/pong.cpp.i

bin/pong.s: bin/pong.cpp.s

.PHONY : bin/pong.s

# target to generate assembly for a file
bin/pong.cpp.s:
	$(MAKE) -f CMakeFiles\pong.dir\build.make CMakeFiles/pong.dir/bin/pong.cpp.s
.PHONY : bin/pong.cpp.s

src/ball.obj: src/ball.cpp.obj

.PHONY : src/ball.obj

# target to build an object file
src/ball.cpp.obj:
	$(MAKE) -f CMakeFiles\pong.dir\build.make CMakeFiles/pong.dir/src/ball.cpp.obj
.PHONY : src/ball.cpp.obj

src/ball.i: src/ball.cpp.i

.PHONY : src/ball.i

# target to preprocess a source file
src/ball.cpp.i:
	$(MAKE) -f CMakeFiles\pong.dir\build.make CMakeFiles/pong.dir/src/ball.cpp.i
.PHONY : src/ball.cpp.i

src/ball.s: src/ball.cpp.s

.PHONY : src/ball.s

# target to generate assembly for a file
src/ball.cpp.s:
	$(MAKE) -f CMakeFiles\pong.dir\build.make CMakeFiles/pong.dir/src/ball.cpp.s
.PHONY : src/ball.cpp.s

src/paddle.obj: src/paddle.cpp.obj

.PHONY : src/paddle.obj

# target to build an object file
src/paddle.cpp.obj:
	$(MAKE) -f CMakeFiles\pong.dir\build.make CMakeFiles/pong.dir/src/paddle.cpp.obj
.PHONY : src/paddle.cpp.obj

src/paddle.i: src/paddle.cpp.i

.PHONY : src/paddle.i

# target to preprocess a source file
src/paddle.cpp.i:
	$(MAKE) -f CMakeFiles\pong.dir\build.make CMakeFiles/pong.dir/src/paddle.cpp.i
.PHONY : src/paddle.cpp.i

src/paddle.s: src/paddle.cpp.s

.PHONY : src/paddle.s

# target to generate assembly for a file
src/paddle.cpp.s:
	$(MAKE) -f CMakeFiles\pong.dir\build.make CMakeFiles/pong.dir/src/paddle.cpp.s
.PHONY : src/paddle.cpp.s

src/scoreboard.obj: src/scoreboard.cpp.obj

.PHONY : src/scoreboard.obj

# target to build an object file
src/scoreboard.cpp.obj:
	$(MAKE) -f CMakeFiles\pong.dir\build.make CMakeFiles/pong.dir/src/scoreboard.cpp.obj
.PHONY : src/scoreboard.cpp.obj

src/scoreboard.i: src/scoreboard.cpp.i

.PHONY : src/scoreboard.i

# target to preprocess a source file
src/scoreboard.cpp.i:
	$(MAKE) -f CMakeFiles\pong.dir\build.make CMakeFiles/pong.dir/src/scoreboard.cpp.i
.PHONY : src/scoreboard.cpp.i

src/scoreboard.s: src/scoreboard.cpp.s

.PHONY : src/scoreboard.s

# target to generate assembly for a file
src/scoreboard.cpp.s:
	$(MAKE) -f CMakeFiles\pong.dir\build.make CMakeFiles/pong.dir/src/scoreboard.cpp.s
.PHONY : src/scoreboard.cpp.s

# Help Target
help:
	@echo The following are some of the valid targets for this Makefile:
	@echo ... all (the default if no target is provided)
	@echo ... clean
	@echo ... depend
	@echo ... edit_cache
	@echo ... rebuild_cache
	@echo ... pong
	@echo ... bin/pong.obj
	@echo ... bin/pong.i
	@echo ... bin/pong.s
	@echo ... src/ball.obj
	@echo ... src/ball.i
	@echo ... src/ball.s
	@echo ... src/paddle.obj
	@echo ... src/paddle.i
	@echo ... src/paddle.s
	@echo ... src/scoreboard.obj
	@echo ... src/scoreboard.i
	@echo ... src/scoreboard.s
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles\Makefile.cmake 0
.PHONY : cmake_check_build_system

