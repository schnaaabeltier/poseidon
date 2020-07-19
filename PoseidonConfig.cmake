include(CMakeFindDependencyMacro)
find_dependency(glbinding)
find_dependency(glfw3)
find_dependency(spdlog)

include("${CMAKE_CURRENT_LIST_DIR}/PoseidonTargets.cmake")