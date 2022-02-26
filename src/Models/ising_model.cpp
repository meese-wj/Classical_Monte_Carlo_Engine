#include "ising_model.hpp"

void Ising_Model::initialize()
{
    _model_hamiltonian.initialize();
    CMCE::energy_type energy = _model_hamiltonian.get_energy();
    CMCE::energy_type mag = _model_hamiltonian.get_magnetization();
    _hamiltonian_state = Ising_State( energy, mag );
}