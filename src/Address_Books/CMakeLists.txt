set(LibName "AddressBooks")

add_library("${LibName}"
            address_books.cpp)

# Append the library to the targets to link. This assumes that
# the subdirectory targets have been included in the right order
# (i.e. dependencies come last).
list(APPEND targets_for_executable_linking "${LibName}")
set(targets_for_executable_linking "${targets_for_executable_linking}" PARENT_SCOPE)