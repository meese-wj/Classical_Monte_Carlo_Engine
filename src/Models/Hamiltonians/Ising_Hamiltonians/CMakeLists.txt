set(LibName "Ising_Hamiltonians")

add_library("${LibName}" ising_hamiltonian.cpp)

list(APPEND ham_targets "${LibName}")
set(ham_targets "${ham_targets}" PARENT_SCOPE)

# Send the proper Hamiltonian file to the SimParamDir
if (ISING_MODEL)
    configure_file(default_ising_hamiltonian_parameters.hpp ${SimParamDir}/ising_hamiltonian_parameters.hpp)
endif()

# Link the SimParamDir folder with the Hamiltonian target to 
# make sure that everything is recompiled if the user changes
# any compile-time settings.
target_link_directories("${LibName}" PRIVATE ${SimParamDir})