cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Classical_Monte_Carlo_Engine)

# Toggle compile-time options
option(RECT_2D_PBC "Use a rectangular lattice in 2D with periodic boundaries." ON)
option(ISING_MODEL  "Turn on the Ising model." ON)

# Turn on compile definitions

# Lattice compile-time definitions
if (RECT_2D_PBC)
add_definitions(-DRECT_2D_PBC)
endif()


# Model compile-time definitions
if (ISING_MODEL)
    add_definitions(-DISING_MODEL)
endif()

add_subdirectory(src)