set(ham_targets "")
add_subdirectory(Ising_Hamiltonians)

set(LibName "Hamiltonians")
add_library("${LibName}"
            hamiltonian_base.hpp)

set_target_properties("${LibName}" PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries("${LibName}" "${ham_targets}")

# Append the library to the targets to link. This assumes that
# the subdirectory targets have been included in the right order
# (i.e. dependencies come last).
list(APPEND targets_for_executable_linking "${LibName}")
set(targets_for_executable_linking "${targets_for_executable_linking}" PARENT_SCOPE)

# Link the SimParamDir folder with the Hamiltonian target to 
# make sure that everything is recompiled if the user changes
# any compile-time settings.
target_link_directories("${LibName}" PRIVATE ${SimParamDir})