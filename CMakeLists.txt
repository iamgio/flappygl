cmake_minimum_required(VERSION 3.26)
project(PROJECT_NAME) #[[Change]]

set(CMAKE_CXX_STANDARD 17)

set(LIB_PATH /opt/homebrew/Cellar)

include_directories(${LIB_PATH}/glfw/3.3.8/include)
link_directories(${LIB_PATH}/glfw/3.3.8/lib)

include_directories(${LIB_PATH}/glew/2.2.0_1/include)
link_directories(${LIB_PATH}/glew/2.2.0_1/lib)

include_directories(${LIB_PATH}/glm/0.9.9.8/include)
link_directories(${LIB_PATH}/glm/0.9.9.8/lib)

find_library(GL_LIB opengl)
add_definitions(-DGLEW_STATIC)

add_executable(${PROJECT_NAME} main.cpp shaders.cpp shaders.hpp shapes.hpp colors.hpp colors.cpp shapes.cpp shape.hpp)

target_link_libraries(${PROJECT_NAME} glew glfw ${GL_LIB})
