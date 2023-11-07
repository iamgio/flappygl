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

include_directories(${LIB_PATH}/freetype/2.13.2/include/freetype2)
link_directories(${LIB_PATH}/freetype/2.13.2/lib)

find_library(GL_LIB opengl)
add_definitions(-DGLEW_STATIC)

add_executable(${PROJECT_NAME} main.cpp
        shader.h shader.cpp
        program.h program.cpp
        shapes.h shapes.cpp
        shape.h
        gl.h gl.cpp
        window.h window.cpp
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
        game/scoreincreaser.h
        lib/gltext.h
        lib/hermite.h
        text/text.cpp
        text/text.h
        lib/hermite.h
        programs.cpp
        programs.h
)

target_link_libraries(${PROJECT_NAME} glew glfw freetype ${GL_LIB})
