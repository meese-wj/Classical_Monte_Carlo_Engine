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
    CMCE::energy_type get_spin( const CMCE::size_type site ) const { return _spins[site]; }
    void set_spin( const CMCE::size_type site, const CMCE::energy_type value ){ _spins[site] = value; }

protected:
    void allocate_spins();
    virtual CMCE::energy_type pure_interaction_per_spin( const std::array<CMCE::size_type, Ising_Parameters::Nneighbors> & neighbors ) const;
    virtual CMCE::energy_type external_field() const;
    virtual CMCE::energy_type effective_field ( const std::array<CMCE::size_type, Ising_Parameters::Nneighbors> & neighbors ) const;
    virtual CMCE::energy_type energy_per_spin ( const CMCE::size_type site, 
                                                const std::array<CMCE::size_type, Ising_Parameters::Nneighbors> & neighbors ) const ;
    
    // TODO: Encapsulate the neighbor calculation in something else
    virtual CMCE::energy_type total_energy    ( void (*evaluate_neighbors)( const CMCE::size_type, std::array<CMCE::size_type, Ising_Parameters::Nneighbors> &) ) const;

private:
    std::array<CMCE::energy_type, Ising_Parameters::Nspins> _spins;
};

#endif