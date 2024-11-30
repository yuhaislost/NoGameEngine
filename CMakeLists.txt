cmake_minimum_required(VERSION 3.23.0)

MESSAGE("Mode: ${CMAKE_BUILD_TYPE}")

set(CMAKE_CXX_STANDARD 17)
set(SourceFiles-Core
  NoGameEngine-core/src/main.cpp
  NoGameEngine-core/src/graphics/window.cpp
  NoGameEngine-core/src/graphics/shader.cpp
  NoGameEngine-core/src/math/mat4.cpp
  NoGameEngine-core/src/math/vec2.cpp
  NoGameEngine-core/src/math/vec3.cpp
  NoGameEngine-core/src/math/vec4.cpp
  NoGameEngine-core/src/graphics/buffers/buffer.cpp
  NoGameEngine-core/src/graphics/buffers/indexbuffer.cpp
  NoGameEngine-core/src/graphics/buffers/vertexarray.cpp
  NoGameEngine-core/src/graphics/simple2drenderer.cpp
  NoGameEngine-core/src/graphics/batchrenderer2d.cpp
  NoGameEngine-core/src/graphics/sprite.cpp
  NoGameEngine-core/src/graphics/staticsprite.cpp
  NoGameEngine-core/src/graphics/layers/layer.cpp
  NoGameEngine-core/src/graphics/layers/tilelayer.cpp
  NoGameEngine-core/src/graphics/layers/group.cpp
)

set(SourceFiles-Depend
  Dependencies/GLEW/src/glew.c
)

set(includeFiles-Core NoGameEngine-core/include)
set (includeFiles-Depend 
  Dependencies/GLEW/include
  Dependencies/GLFW/include
)

add_compile_options(
  -DGLEW_STATIC
  "$<$<CONFIG:RELEASE>:-O2>"
)

find_package( OpenGL REQUIRED )

if (OPENGL_FOUND)
  MESSAGE("OpenGL Correctly Found")
else (OPENGL_FOUND)
  MESSAGE("OpenGL environment missing")
endif()

project(NoGameEngine)


include_directories( ${OPENGL_INCLUDE_DIRS} ${includeFiles-Core} ${includeFiles-Depend})

set( GLFW_BUILD_DOCS OFF CACHE BOOL  "GLFW lib only" )
set( GLFW_INSTALL OFF CACHE BOOL  "GLFW lib only" )

add_executable(${PROJECT_NAME} ${SourceFiles-Core} ${SourceFiles-Depend})
target_link_directories( ${PROJECT_NAME} PRIVATE Dependencies/GLFW )
target_link_libraries( ${PROJECT_NAME} PRIVATE ${OPENGL_LIBRARIES} glfw3)
# target_link_directories( ${PROJECT_NAME} PRIVATE Dependencies)
# target_link_libraries( ${PROJECT_NAME} PRIVATE glew32s.lib)
# target_link_libraries( ${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/Dependencies/glew32s.lib)

