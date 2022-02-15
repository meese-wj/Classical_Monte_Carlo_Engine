#ifndef _ISING_HAMILTONIAN_PARAMETERS_H
#define _ISING_HAMILTONIAN_PARAMETERS_H

#include <global_simulation_typedefs.hpp>

namespace Ising_Parameters
{
    // Modify the parameters as you see fit below

    // Size of the system
    // TODO: encapsulate these within a lattice?
    constexpr CMCE::size_type Lx = 8;
    constexpr CMCE::size_type Ly = Lx;
    constexpr CMCE::size_type Nspins = Lx * Ly;

    // Energy scales of the model
    constexpr CMCE::energy_type Jexchange = -1.0;            // Jexchange < 0 is ferromagnetic
    constexpr CMCE::energy_type hexternal = 0. * Jexchange;  // External field scale in units of Jexchange
    constexpr CMCE::energy_type spin_magnitude = 1.0;        // Value of the spin moments (this should always be 1.0 probably)
}

#endif // _ISING_HAMILTONIAN_PARAMETERS_H