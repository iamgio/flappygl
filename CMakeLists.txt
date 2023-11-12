cmake_minimum_required(VERSION 3.20)
project(FlappyGL)

set(CMAKE_CXX_STANDARD 20)

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
        gl.h gl.cpp
        window.h window.cpp
        glm.h glm.cpp
        settings.h
        random.h
        hermite.h hermite.cpp
        scene/shape.h scene/shape.cpp
        shader/shader.h shader/shader.cpp
        shader/program.h shader/program.cpp
        shader/programs.h shader/programs.cpp
        scene/shapes.h scene/shapes.cpp
        scene/scene.h scene/scene.cpp
        scene/scene_shapes.h scene/scene_shapes.cpp
        game/game.h game/game.cpp
        game/ground.h
        game/gameobject.h game/gameobject.cpp
        game/bird.h game/bird.cpp
        game/pipe.h game/pipe.cpp
        game/pipe_pair.h game/pipe_pair.cpp
        game/scoreincreaser.h
        game/background_details.h
        collision/boundingbox.h collision/boundingbox.cpp
        text/text.h text/text.cpp
        lib/gltext.h
)

target_link_libraries(${PROJECT_NAME} glew glfw ${GL_LIB})
