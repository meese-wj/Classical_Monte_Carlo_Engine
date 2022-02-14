#ifndef _ISING_MODEL_H
#define _ISING_MODEL_H

#include "hamiltonian_base.hpp"  // Template base class for the Hamiltonians

// Use the parameter file in this folder by default.
// But the CMake build system copies this into the 
// build directory ("Simulation_Parameters") which 
// will be recompiled when modified.
#if __has_include(<ising_model_parameters.hpp>)
    #include <ising_model_parameters.hpp>
#else  // __has_include(<ising_model_parameters.hpp>)
    #include "default_ising_model_parameters.hpp"
#endif // __has_include(<ising_model_parameters.hpp>)

#include <array>
#include <cstdint>

template<typename energy_t, std::uint32_t Nspins>
class Ising_Model : public Hamiltonian<energy_t>
{
public:
    const char model_name [] = "Ising_Model";

    Hamiltonian(){};
    virtual void initialize();
    virtual energy_t get_energy();
    virtual change_state( const energy_t probability );
    virtual void measure_observables();
    virtual ~Hamiltonian(){};

    std::uint32_t get_size() const { return Nspins; }

private:
    std::array<energy_t, Nspins> _spins;
};

#endif