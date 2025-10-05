# Any C++ source files needed to build this target (shell-app).
add_executable(pid_controller_example pid_controller.cpp main.cpp)

# Any include directories needed to build this target.
# Note: we do not need to specify the include directories for the
# dependent libraries, they are automatically included.

target_include_directories(pid_controller_example PUBLIC ${CMAKE_SOURCE_DIR}/include)



  
