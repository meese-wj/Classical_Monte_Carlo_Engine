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
list(APPEND model_targets "${LibName}")
set(model_targets "${model_targets}" PARENT_SCOPE)