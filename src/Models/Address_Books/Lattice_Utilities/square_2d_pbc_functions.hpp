#ifndef _SQUARE_2D_PBC_FUNCTIONS_H
#define _SQUARE_2D_PBC_FUNCTIONS_H

#include <global_simulation_typedefs.hpp>

#define xy_to_index( x, y, Lx ) (y * Lx + x)
#define index_to_x( site, Lx ) (site % Lx)
#define index_to_y( site, Lx ) (site / Lx)

// Compile-time inline functions
template<CMCE::size_type Lx>
constexpr CMCE::size_type site_index( const CMCE::size_type site_x, const CMCE::size_type site_y )
{
    return xy_to_index( site_x, site_y, Lx );
}

template<CMCE::size_type Lx>
constexpr CMCE::size_type site_x_index( const CMCE::size_type site )
{
    return index_to_x( site, Lx );
}

template<CMCE::size_type Lx>
constexpr CMCE::size_type site_y_index( const CMCE::size_type site )
{
    return index_to_y( site, Lx );
}

// Run-time inline functions
constexpr CMCE::size_type site_index( const CMCE::size_type site_x, const CMCE::size_type site_y, const CMCE::size_type Lx )
{
    return xy_to_index( site_x, site_y, Lx );
}

constexpr CMCE::size_type site_x_index( const CMCE::size_type site, const CMCE::size_type Lx )
{
    return index_to_x( site, Lx );
}

constexpr CMCE::size_type site_y_index( const CMCE::size_type site, const CMCE::size_type Lx )
{
    return index_to_y( site, Lx );
}

#undef xy_to_index
#undef index_to_x
#undef index_to_y

#endif // _SQUARE_2D_PBC_FUNCTIONS_H