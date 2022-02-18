#ifndef _CMCE_MODEL_BASE_H
#define _CMCE_MODEL_BASE_H
// This is the base class for the models 
// used in the simulation. 
//
// By definition, each MODEL is made of a
// HAMILTONIAN as well as an ADDRESS BOOK.
// It will also contain the state adn observables 
// when I get around to making them.

#include "../Global_Settings/global_simulation_typedefs.hpp"
#include "Hamiltonians/hamiltonian_state_base.hpp"
#include "Hamiltonians/hamiltonian_base.hpp"
#include "Address_Books/address_book_base.hpp"

namespace CMCE
{

    class Model_Base
    {
    public:
        Model_Base(){}
        
        virtual void initialize() = 0;
        virtual void determine_state() = 0;
        virtual energy_type get_energy() const = 0;
        virtual void measure_observables() = 0;
        virtual void export_observables() = 0;

        // TODO: There should also be virtual 'set_state' functions
        // but I need abstract state types for that first.

        virtual ~Model_Base(){}

    private:
        // These private members must be contained in every
        // Hamiltonian:
        /* 
            Hamiltonian<State<energy_type>  hamiltonian_state;
            Hamiltonian<energy_type>        model_hamiltonian;
            Address_Book                    DoF_contacts;
            Observables<energy_t>           model_observables;
        */
    };



} // namespace CMCE


#endif // _CMCE_MODEL_BASE_H