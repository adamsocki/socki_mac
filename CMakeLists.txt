cmake_minimum_required(VERSION 3.10)
project(untitled1)

# Add the GLFW library
find_package(glfw3 3.3 REQUIRED)

# Add the GLEW library
find_package(GLEW REQUIRED)

# Add the OpenGL framework
find_package(OpenGL REQUIRED)

# Add the source files
set(SOURCES src/main.cpp src/types.h src/MemoryManagement.h src/dynamic_memory.h)

# Add the executable target
add_executable(untitled1 ${SOURCES})

# Link the libraries to the target
target_link_libraries(untitled1 PRIVATE glfw GLEW::GLEW OpenGL::GL)
