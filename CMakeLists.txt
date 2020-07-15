cmake_minimum_required(VERSION 3.16)
project(poseidon)

set(CMAKE_CXX_STANDARD 20)
set(library_name Poseidon)
set(${library_name}_version 1.0)

add_subdirectory(libs/glfw)

add_subdirectory(src)

set(install_targets
        ${library_name}_core
        )
set(CMAKE_EXPORT_PACKAGE_REGISTRY ON)
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

install(DIRECTORY include
        DESTINATION include)

