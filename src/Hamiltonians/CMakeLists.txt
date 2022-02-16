add_library(Hamiltonians
            ising_model.cpp
            ising_model.hpp
            hamiltonian_base.hpp)

set_target_properties(Hamiltonians PROPERTIES LINKER_LANGUAGE CXX)

# Append the library to the targets to link. This assumes that
# the subdirectory targets have been included in the right order
# (i.e. dependencies come last).
if ( NOT( "Hamiltonians" IN_LIST "${targets_for_executable_linking}" ) )
    list(APPEND targets_for_executable_linking "Hamiltonians")
    set(targets_for_executable_linking ${targets_for_executable_linking} PARENT_SCOPE)
endif()

# Send the proper Hamiltonian file to the SimParamDir
if (ISING_MODEL)
    configure_file(default_ising_model_parameters.hpp ${SimParamDir}/ising_model_parameters.hpp)
endif()

# Link the SimParamDir folder with the Hamiltonian target to 
# make sure that everything is recompiled if the user changes
# any compile-time settings.
target_link_directories(Hamiltonians PRIVATE ${SimParamDir})