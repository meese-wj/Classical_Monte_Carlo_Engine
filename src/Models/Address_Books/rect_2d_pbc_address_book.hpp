#ifndef _RECT_2D_PBC_ADDRESS_BOOK_H
#define _RECT_2D_PBC_ADDRESS_BOOK_H

#include "address_book_base.hpp"                        // global typedefs are taken from this header
#include "../../Global_Settings/global_macros.hpp"      // For the branchless ternary
#include "Lattice_Utilities/rect_2d_pbc_functions.hpp"
#include <array>

#define RECT_2D_NUM_NEAREST_NEIGHBORS 4

template<CMCE::size_type Lx, CMCE::size_type Ly=Lx>
class Rect_2D_PBC_Address_Book_Functor : public Address_Book
{
public:
    Rect_2D_PBC_Address_Book_Functor(){}

    CMCE::size_type neighbor( const CMCE::size_type site, const CMCE::size_type which_neighbor  ) override;

    virtual ~Rect_2D_PBC_Address_Book_Functor(){}

protected: 
    static CMCE::size_type neighbor_0( const CMCE::size_type site );
    static CMCE::size_type neighbor_1( const CMCE::size_type site );
    static CMCE::size_type neighbor_2( const CMCE::size_type site );
    static CMCE::size_type neighbor_3( const CMCE::size_type site );

private:
    // Store an array of function pointers that will iterate
    // over the nearest neighbors
    std::array<CMCE::size_type (*) (const CMCE::size_type),
               RECT_2D_NUM_NEAREST_NEIGHBORS> _neighbor_functions { &( this -> neighbor_0 ), &( this -> neighbor_1 ),
                                                                      &( this -> neighbor_2 ), &( this -> neighbor_3 ) };
};

template<CMCE::size_type Lx, CMCE::size_type Ly>
CMCE::size_type Rect_2D_PBC_Address_Book_Functor<Lx, Ly>::neighbor( const CMCE::size_type site, const CMCE::size_type which_neighbor )
{
    return _neighbor_functions[which_neighbor](site);
}


template<CMCE::size_type Lx, CMCE::size_type Ly>
CMCE::size_type Rect_2D_PBC_Address_Book_Functor<Lx, Ly>::neighbor_0( const CMCE::size_type site )
{
    // (x, y - 1)
    CMCE::size_type xdx = site_x_index<Lx>(site);
    CMCE::size_type ydx = site_y_index<Lx>(site);
    return site_index<Lx>( xdx, BRANCHLESS_TERNARY( ydx == 0, Ly - 1, ydx - 1 ) );
}

template<CMCE::size_type Lx, CMCE::size_type Ly>
CMCE::size_type Rect_2D_PBC_Address_Book_Functor<Lx, Ly>::neighbor_1( const CMCE::size_type site )
{
    // (x - 1, y)
    CMCE::size_type xdx = site_x_index<Lx>(site);
    CMCE::size_type ydx = site_y_index<Lx>(site);
    return site_index<Lx>( BRANCHLESS_TERNARY( xdx == 0, Lx - 1, xdx - 1 ), ydx );
}

template<CMCE::size_type Lx, CMCE::size_type Ly>
CMCE::size_type Rect_2D_PBC_Address_Book_Functor<Lx, Ly>::neighbor_2( const CMCE::size_type site )
{
    // (x + 1, y)
    CMCE::size_type xdx = site_x_index<Lx>(site);
    CMCE::size_type ydx = site_y_index<Lx>(site);
    return site_index<Lx>( BRANCHLESS_TERNARY( xdx == Lx - 1, 0, xdx + 1 ), ydx );
}

template<CMCE::size_type Lx, CMCE::size_type Ly>
CMCE::size_type Rect_2D_PBC_Address_Book_Functor<Lx, Ly>::neighbor_3( const CMCE::size_type site )
{
    // (x, y + 1)
    CMCE::size_type xdx = site_x_index<Lx>(site);
    CMCE::size_type ydx = site_y_index<Lx>(site);
    return site_index<Lx>( xdx, BRANCHLESS_TERNARY( ydx == Ly - 1, 0, ydx + 1 ) );
}

#undef RECT_2D_NUM_NEAREST_NEIGHBORS 
#endif // _RECT_2D_PBC_ADDRESS_BOOK_H