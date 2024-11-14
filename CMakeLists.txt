cmake_minimum_required(VERSION 3.29)
project(Orbis_Engine)

set(CMAKE_CXX_STANDARD 23)

find_package(OpenGL REQUIRED)
include_directories(Libraries/include)

add_executable(${PROJECT_NAME}
        src/glad.c
        src/main.cpp
        src/Shader/shaderClass.h
        src/Shader/shaderClass.cpp
        src/Shader/VBO.cpp
        src/Shader/VBO.h
        src/Shader/EBO.cpp
        src/Shader/EBO.h
        src/Shader/VAO.cpp
        src/Shader/VAO.h)



set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
add_subdirectory(Libraries/lib/glfw)

target_link_libraries(${PROJECT_NAME} OpenGL::GL glfw)
target_link_directories(${PROJECT_NAME} PUBLIC Libraries/lib)

#copy res folder to build directory
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/res $<TARGET_FILE_DIR:${PROJECT_NAME}>/res)