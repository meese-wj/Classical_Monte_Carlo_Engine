set(LibName "Lattice_Utilities")

add_library("${LibName}"
            rect_2d_pbc_functions.hpp)

set_target_properties("${LibName}" PROPERTIES LINKER_LANGUAGE CXX )

list(APPEND address_book_targets "${LibName}")
set(address_book_targets "${address_book_targets}" PARENT_SCOPE)