// Implementation of the Ising Hamiltonian

#include "ising_model.hpp"


// Public member functions:

void Ising_Hamiltonian::initialize() override
{
    allocate_spins();
}


// Protected member functions:
void Ising_Hamiltonian::allocate_spins()
{
    for ( auto & spin : _spins )
        spin = Ising_Parameters::spin_magitude;
}