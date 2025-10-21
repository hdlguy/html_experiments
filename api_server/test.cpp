
#include <stdio.h>

extern "C" {
#include "libinstrument.h"
}

int main()
{
    if (dummy_pass()==0) printf("dummy_pass() passed\n"); else printf("dummy_pass() failed\n");
    if (dummy_fail()==0) printf("dummy_fail() passed\n"); else printf("dummy_fail() failed\n");

    return(0);
}
