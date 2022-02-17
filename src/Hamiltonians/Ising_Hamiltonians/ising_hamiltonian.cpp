// Implementation of the Ising Hamiltonian

#include "ising_hamiltonian.hpp"


// Public member functions:

void Ising_Hamiltonian::initialize()
{
    allocate_spins();
}


// Protected member functions:
void Ising_Hamiltonian::allocate_spins()
{
    for ( auto & spin : _spins )
        spin = Ising_Parameters::spin_magnitude;
}

CMCE::energy_type Ising_Hamiltonian::pure_interaction_per_spin( const std::array<CMCE::size_type, Ising_Parameters::Nneighbors> & neighbors ) const
{
    CMCE::energy_type temp_interaction = 0.;
    for ( const auto & neighbor : neighbors )
        temp_interaction += Ising_Parameters::Jexchange * get_spin( neighbor );
    return temp_interaction;
}

CMCE::energy_type Ising_Hamiltonian::external_field() const
{
    return Ising_Parameters::hexternal;
}

CMCE::energy_type Ising_Hamiltonian::effective_field ( const std::array<CMCE::size_type, Ising_Parameters::Nneighbors> & neighbors ) const
{
    return pure_interaction_per_spin( neighbors ) + external_field( );
}

CMCE::energy_type Ising_Hamiltonian::energy_per_spin ( const CMCE::size_type site, 
                                                       const std::array<CMCE::size_type, Ising_Parameters::Nneighbors> & neighbors ) const
{
    return -1.0 * effective_field( neighbors ) * get_spin( site );
}

CMCE::energy_type Ising_Hamiltonian::total_energy( void (*evaluate_neighbors)( const CMCE::size_type, std::array<CMCE::size_type, Ising_Parameters::Nneighbors> &) ) const
{
    CMCE::energy_type temp_energy = 0.;
    std::array<CMCE::size_type, Ising_Parameters::Nneighbors> temp_neighbors;
    for ( CMCE::size_type site = 0; site != Ising_Parameters::Nspins; ++site )
    {
        evaluate_neighbors( site, temp_neighbors );
        temp_energy -= 0.5 * external_field() * get_spin( site );  // Necessary to account for the double-counting of bonds
        temp_energy += energy_per_spin( site, temp_neighbors );
    }
    return temp_energy;
}