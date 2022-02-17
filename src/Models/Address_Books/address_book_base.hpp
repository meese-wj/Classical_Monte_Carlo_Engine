#ifndef _ADDRESS_BOOK_BASE_H
#define _ADDRESS_BOOK_BASE_H
// Base class header for the Address Books which
// control geometrical functions related to connecting
// the degrees of freedom.

#include <global_simulation_typedefs.hpp>

class Address_Book
{
public:
    Address_Book(){}
    
    // This is the only function that matters really.
    virtual CMCE::size_type neighbor( const CMCE::size_type site, const CMCE::size_type which_neighbor ) = 0;

    virtual ~Address_Book(){}
};

#endif // _ADDRESS_BOOK_BASE_H