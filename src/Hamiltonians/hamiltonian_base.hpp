#ifndef _HAMILTONIAN_BASE_H
#define _HAMILTONIAN_BASE_H
// Abstract base class for the Hamiltonians

template<typename energy_t>
class Hamiltonian
{
public:
    Hamiltonian();
    virtual energy_t get_energy() = 0;
    virtual void measure_observables() = 0;
    virtual ~Hamiltonian();
};


#endif  // _HAMILTONIAN_BASE_H