#include "csi.h"

extern "C" {

WEAK void __csi_init(csi_info_t info) {}
WEAK void __csi_module_init(csi_module_info_t info) {}
WEAK void __csi_before_load(void *addr, int num_bytes, int attr) {}
WEAK void __csi_after_load(void *addr, int num_bytes, int attr) {}
WEAK void __csi_before_store(void *addr, int num_bytes, int attr) {}
WEAK void __csi_after_store(void *addr, int num_bytes, int attr) {}
WEAK void __csi_func_entry(void *parentReturnAddr, char *funcName) {}
WEAK void __csi_func_exit() {}
WEAK void __csi_bb_entry(csi_id_t id, const char *filename, uint32_t linestart, uint32_t lineend) {}
WEAK void __csi_bb_exit() {}

} // extern "C"
