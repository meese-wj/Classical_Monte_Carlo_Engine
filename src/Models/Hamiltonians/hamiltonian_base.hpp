#ifndef _HAMILTONIAN_BASE_H
#define _HAMILTONIAN_BASE_H
// Abstract base class for the Hamiltonians

#include <string>

template<typename energy_t>
class Hamiltonian
{
public:
    const std::string hamiltonian_name;

    Hamiltonian();
    virtual void initialize() = 0;
    virtual energy_t get_energy() = 0;
    virtual void change_state( const energy_t probability ) = 0;
    virtual void measure_observables() = 0;
    virtual ~Hamiltonian();

private:
};


#endif  // _HAMILTONIAN_BASE_H