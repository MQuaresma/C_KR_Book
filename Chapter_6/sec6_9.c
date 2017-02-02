#include <stdio.h>
#include "sec6_9.h"

main(){

    flags f;
    f.is_keyword = 1;
    f.is_extern = 0;
    f.is_static = 1;

    if(f.is_keyword) puts("Symbol is keyword");
    if(f.is_extern) puts("Symbol is extern");
    if(f.is_static) puts("Symbol is static");

    printf("Current size of flags structure: %zu\n", sizeof(flags));

    return 0;
}
