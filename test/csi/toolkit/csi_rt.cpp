#include "csi_rt.h"

extern "C" {

static bool __csi_rt_initialized = false;

void __csi_rt_init_program() {
    if (!__csi_rt_initialized) {
        __csi_rt_initialized = true;
        // Call whole program init function.
        __csi_init();
    }
}

}
