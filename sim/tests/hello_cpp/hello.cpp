#include <cstring>

#define SC_SIM_OUTPORT (0xf0000000)

static void sc_puts(const char *str, long strlen) {
    volatile char *out_ptr = (volatile char *)SC_SIM_OUTPORT;
    const char *in_ptr = (const char *)str;
    for (long len = strlen; len > 0; --len) *out_ptr = *in_ptr++;
}

static constexpr auto kHello = "Hello from SCR1!\n";

int main() {
    sc_puts(kHello, strlen(kHello));
    return 0;
}