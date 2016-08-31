#if !defined(UNDEFINED)     /* f UNDEFINED hasn't been defined already it will be so now */
                            /* general structure is #if <condition> true (#elif <condition> true / #else false) #endif */
#define UNDEFINED "testing"

#endif


#if SYSTEM == SYSV
    #define HDR "sysv.h"

#elif SYSTEM == BSD
    #define HDR "bsd.h"

#elif SYSTEM == MSDOS
    #define HDR "msdos.h"

#else
    #define HDR "default.h"
#endif

#include HDR


#ifndef HDR                 /* equivalent to the first example, same with #ifdef NAME */

#define HDR "testing"

#endif
