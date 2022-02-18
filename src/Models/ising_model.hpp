#ifndef _ISING_MODEL_H
#define _ISING_MODEL_H
// This is the clean Ising model class. Note
// that the state class needs to be defined
// here.

#include "../Global_Settings/global_simulation_typedefs.hpp"
#include "cmce_model_base.hpp"
#include "Hamiltonians/hamiltonian_state_base.hpp"
#include "Hamiltonians/Ising_Hamiltonians/ising_hamiltonian.hpp"
#include "Address_Books/rect_2d_pbc_address_book.hpp"


// Ising state definition 
class Ising_State : public Hamiltonian_State<CMCE::energy_type>
{
public:
    Ising_State(){}

    CMCE::energy_type get_energy() override { return energy; }
    void update_state( const Ising_State & temp_state ) override { *this = temp_state; }

    virtual ~Ising_State() {}

protected:
    CMCE::energy_type energy    = 0.;
    CMCE::energy_type total_mag = 0.;
};

// Ising model definition
// TODO: For now, assume that it's just a 2D lattice
class Ising_Model : public CMCE::Model_Base
{
protected:
    Ising_State        _hamiltonian_state;
    Ising_Hamiltonian  _model_hamiltonian;
    Rect_2D_PBC_Address_Book_Functor<Ising_Parameters::Lx, Ising_Parameters::Ly> _contacts;

public:
    Ising_Model(){}

    virtual void initialize() override;
    virtual void determine_state() override;
    virtual CMCE::energy_type get_energy() const { return _hamiltonian_state.get_energy(); } 
    virtual void measure_observables() override;
    virtual void export_observables() override;

    virtual ~Ising_Model(){}
};

#endif // _ISING_MODEL_H