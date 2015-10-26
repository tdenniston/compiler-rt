#include "csi.h"

extern "C" {

WEAK void __csi_init() {}
WEAK void __csi_module_init() {}
WEAK void __csi_before_load(void *addr, int num_bytes, int attr) {}
WEAK void __csi_after_load(void *addr, int num_bytes, int attr) {}
WEAK void __csi_before_store(void *addr, int num_bytes, int attr) {}
WEAK void __csi_after_store(void *addr, int num_bytes, int attr) {}
WEAK void __csi_func_entry(void *parentReturnAddr, char *funcName) {}
WEAK void __csi_func_exit() {}

} // extern "C"
