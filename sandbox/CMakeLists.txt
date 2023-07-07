add_executable(sandbox
        src/SandboxApp.h
        src/SandboxApp.cpp
        src/TestRenderLayer.h
        src/TestRenderLayer.cpp ../include/Poseidon/core/assets/AssetManager.h)

target_link_libraries(sandbox core gui rendering entrypoint)
