# Add a parameter directory to store the relevant 
# compile-time parameters. These will be the defaults
# for each model, and can be modified and recompiled 
# from this directory to protect the src.
set(SimParamDir ${CMAKE_BINARY_DIR}/Simulation_Parameters)
file(MAKE_DIRECTORY ${SimParamDir})
message(STATUS "Find compile-time parameters in ${SimParamDir}")

# This will use keep track of a list of targets for the
# main executable.
set(targets_for_executable_linking "")

# Include all files in the Global settings for everyone
include_directories(Global_Settings)

add_subdirectory(Hamiltonians)

add_subdirectory(Simulation)

target_link_libraries(${PROJECT_NAME} ${targets_for_executable_linking})
