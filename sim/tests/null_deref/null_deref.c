#include "stdint.h"
#include "stddef.h"
#include "riscv_csr_encoding.h"

// #define STORE
// #define USE_TDU_BREAK

void simple()
{
    volatile uint32_t a = *(volatile uint32_t *)NULL;
}

#ifdef STORE
void foo(volatile uint32_t *p)
{
    *p = 0xDEADF00D;
}
#else
void foo(volatile uint32_t *p)
{
    volatile uint32_t a = *p;
}
#endif

int main()
{
#ifdef USE_TDU_BREAK
    set_csr(mcontrol, MCONTROL_M | MCONTROL_EXECUTE |
                          MCONTROL_STORE |
                          MCONTROL_LOAD);
#endif
    simple();
    foo(NULL);
    return 0;
}