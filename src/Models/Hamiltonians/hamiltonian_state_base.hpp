#ifndef _HAMILTONIAN_STATE_H
#define _HAMILTONIAN_STATE_H
// Use this base class to define states
// to be used with the Hamiltonians

template<typename energy_t>
class Hamiltonian_State
{
public:
    Hamiltonian_State();

    virtual energy_t get_energy() = 0;
    void update_state( const Hamiltonian_State<energy_t> & _temp_state );

    virtual ~Hamiltonian_State();
};


#endif // _HAMILTONIAN_STATE_H