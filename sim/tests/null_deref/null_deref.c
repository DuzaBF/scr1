#include "stdint.h"
#include "stddef.h"

// #define STORE

void simple() {
    volatile uint32_t a = *(volatile uint32_t*) NULL;
}

#ifdef STORE
void foo(volatile uint32_t* p) {
     *p = 0xDEADF00D;
}
#else 
void foo(volatile uint32_t* p) {
    volatile uint32_t a = *p;
}
#endif

int main()
{
    simple();
    foo(NULL);
    return 0;
}