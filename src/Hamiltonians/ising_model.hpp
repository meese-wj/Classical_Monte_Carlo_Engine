#ifndef _ISING_MODEL_H
#define _ISING_MODEL_H

// Use the parameter file in this folder by default.
// But the CMake build system copies this into the 
// build directory ("Simulation_Parameters") which 
// will be recompiled when modified.
#if __has_include(<ising_model_parameters.hpp>)
    #include <ising_model_parameters.hpp>
#else  // __has_include(<ising_model_parameters.hpp>)
    #include "default_ising_model_parameters.hpp"
#endif // __has_include(<ising_model_parameters.hpp>)


#endif