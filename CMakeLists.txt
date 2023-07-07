cmake_minimum_required(VERSION 3.16)
project(poseidon)

set(CMAKE_CXX_STANDARD 20)
set(library_name Poseidon)
set(${library_name}_version 1.0)

if (WIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
endif ()

include(cmake/CompileOptions.cmake)

set(include_dir include)
file(GLOB_RECURSE headers ${include_dir}/*.h)

find_package(glbinding REQUIRED)
find_package(glfw3 REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(spdlog REQUIRED)

add_subdirectory(sandbox)
add_subdirectory(src)

set(install_targets
        core
        gui
        rendering
        )

install(TARGETS
            ${install_targets}
        EXPORT
            ${library_name}Targets
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION include
        )

install(EXPORT ${library_name}Targets
        FILE ${library_name}Targets.cmake
        NAMESPACE ${library_name}::
        DESTINATION lib/cmake/${library_name}
        )

include(CMakePackageConfigHelpers)
write_basic_package_version_file("${library_name}Version.cmake"
        VERSION "1.0"
        COMPATIBILITY SameMajorVersion
        )

install(FILES "${library_name}Config.cmake"
        DESTINATION lib/cmake/${library_name})

install(DIRECTORY include/${project_name}
        DESTINATION include)

install(DIRECTORY assets/
        DESTINATION assets)

