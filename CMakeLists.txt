cmake_minimum_required(VERSION 3.26)
project(FlappyGL)

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

add_executable(${PROJECT_NAME} main.cpp
        shaders.hpp shaders.cpp
        shapes.hpp shapes.cpp
        shape.hpp
        gl.h gl.cpp
        window.hpp window.cpp
        glm.cpp glm.h
        scene/scene.h scene/scene.cpp
        game/game.h game/game.cpp
        scene/scene_shapes.cpp scene/scene_shapes.h
        game/ground.h
        game/gameobject.cpp game/gameobject.h
        collision/boundingbox.cpp
        collision/boundingbox.h
        scene/bbox.h
        settings.h
        game/bird.cpp
        game/bird.h
        game/pipe.h
        game/pipe.cpp
        game/pipe_pair.h
        game/pipe_pair.cpp
        random.h
        shape.cpp
)

target_link_libraries(${PROJECT_NAME} glew glfw ${GL_LIB})
