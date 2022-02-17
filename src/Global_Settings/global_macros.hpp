#ifndef _CMCE_GLOBAL_MACROS_H
#define _CMCE_GLOBAL_MACROS_H
// Use this header to define useful global headers

// Should be read as: cond ? a : b 
// But this way is branchless
#define BRANCHLESS_TERNARY( cond, a, b ) ( (a) * ( cond ) + (b) * (!( cond )) )

#endif // _CMCE_GLOBAL_MACROS_H