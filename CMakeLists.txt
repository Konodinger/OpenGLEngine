cmake_minimum_required(VERSION 3.0)

SET(CMAKE_EXPORT_COMPILE_COMMANDS 1)
SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED True)
SET(CMAKE_BUILD_TYPE "debug")
add_definitions(-D_MY_OPENGL_IS_33_)

project(lilithEngine)

add_executable(${PROJECT_NAME} main.cpp
                                input/KeyboardInputWindow.cpp
                                meshing/Mesh.cpp
                                shading/Shader.cpp
                                rendering/Renderer.cpp
                                window/WorldWindow.cpp)

add_subdirectory(dep/glfw)
target_link_libraries(${PROJECT_NAME} glfw)

add_subdirectory(dep/glm)
target_link_libraries(${PROJECT_NAME} glm)

target_link_libraries(${PROJECT_NAME} ${CMAKE_DL_LIBS})

target_sources(${PROJECT_NAME} PRIVATE dep/glad/src/glad.c)
target_include_directories(${PROJECT_NAME} PRIVATE dep/glad/include/)

target_include_directories(${PROJECT_NAME} PRIVATE camera/)
target_include_directories(${PROJECT_NAME} PRIVATE input/)
target_include_directories(${PROJECT_NAME} PRIVATE meshing/)
target_include_directories(${PROJECT_NAME} PRIVATE rendering/)
target_include_directories(${PROJECT_NAME} PRIVATE shading/)
target_include_directories(${PROJECT_NAME} PRIVATE utils/)
target_include_directories(${PROJECT_NAME} PRIVATE window/)

add_custom_command(TARGET ${PROJECT_NAME}
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${PROJECT_NAME}> ${CMAKE_CURRENT_SOURCE_DIR})
