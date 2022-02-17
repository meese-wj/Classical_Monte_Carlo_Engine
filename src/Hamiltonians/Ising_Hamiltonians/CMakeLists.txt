set(LibName "Ising_Hamiltonians")

add_library("${LibName}" ising_hamiltonian.cpp)

list(APPEND ham_targets "${LibName}")
set(ham_targets "${ham_targets}" PARENT_SCOPE)

# Send the proper Hamiltonian file to the SimParamDir
if (ISING_MODEL)
    configure_file(default_ising_hamiltonian_parameters.hpp ${SimParamDir}/ising_hamiltonian_parameters.hpp)
endif()