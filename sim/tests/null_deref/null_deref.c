#include "stdint.h"
#include "stddef.h"

void simple() {
    volatile uint32_t a = *(volatile uint32_t*) NULL;
}

int main()
{
    volatile uint32_t a = *(volatile  uint32_t*) NULL;
    simple();
    return 0;
}