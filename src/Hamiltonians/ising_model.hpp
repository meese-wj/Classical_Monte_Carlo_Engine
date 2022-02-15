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
#include <global_simulation_typedefs.hpp>

class Ising_Hamiltonian : public Hamiltonian<CMCE::energy_type>
{
public:
    const std::string hamiltonian_name = "Ising";

    Ising_Hamiltonian() {};
    virtual void initialize() override;
    virtual CMCE::energy_type get_energy() override;
    virtual void change_state( const CMCE::energy_type probability ) override;
    virtual void measure_observables() override;
    virtual ~Ising_Hamiltonian() {};

    CMCE::size_type get_size() const { return Ising_Parameters::Nspins; }

protected:
    void allocate_spins();

private:
    std::array<CMCE::energy_type, Ising_Parameters::Nspins> _spins;
};

#endif