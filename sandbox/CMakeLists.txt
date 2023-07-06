add_executable(sandbox
        src/SandboxApp.h
        src/SandboxApp.cpp
        src/TestRenderLayer.h
        src/TestRenderLayer.cpp)

target_link_libraries(sandbox core gui rendering entrypoint)
