
# This will use keep track of a list of targets for the
# main executable.
set(targets_for_executable_linking "")

# This will collect all of the parameter files and then
# put them in the build folder.
set(parameter_files "")

add_subdirectory(Global_Settings)

add_subdirectory(Hamiltonians)

add_subdirectory(Simulation)

target_link_libraries(${PROJECT_NAME} ${targets_for_executable_linking})
