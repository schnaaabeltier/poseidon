include(CMakeFindDependencyMacro)
find_dependency(spdlog)

include("${CMAKE_CURRENT_LIST_DIR}/PoseidonTargets.cmake")
message("Current list dir: ${CMAKE_CURRENT_LIST_DIR}")