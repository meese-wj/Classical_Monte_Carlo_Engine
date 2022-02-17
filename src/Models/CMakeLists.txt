set(LibName "Models")
set(model_targets "")

add_library("${LibName}" cmce_models.hpp)

set_target_properties("${LibName}" PROPERTIES LINKER_LANGUAGE CXX)

add_subdirectory(Hamiltonians)

add_subdirectory(Address_Books)

list(REMOVE_DUPLICATES model_targets)
target_link_libraries("${LibName}" "${model_targets}")

list(APPEND targets_for_executable_linking "${LibName}")
set(targets_for_executable_linking "${targets_for_executable_linking}" PARENT_SCOPE)