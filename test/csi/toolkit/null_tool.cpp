#include "csi.h"

extern "C" {

// WEAK void __csi_init(csi_info_t info) {}
// WEAK void __csi_module_init(csi_module_info_t info) {}
WEAK void __csi_init(uint32_t num_modules) {}
WEAK void __csi_module_init(uint32_t module_id, uint64_t num_basic_blocks) {}
// WEAK void __csi_before_load(void *addr, int num_bytes, csi_acc_prop_t prop) {}
// WEAK void __csi_after_load(void *addr, int num_bytes, csi_acc_prop_t prop) {}
// WEAK void __csi_before_store(void *addr, int num_bytes, csi_acc_prop_t prop) {}
// WEAK void __csi_after_store(void *addr, int num_bytes, csi_acc_prop_t prop) {}
WEAK void __csi_before_load(void *addr, int num_bytes, unsigned unused, bool unused2, bool unused3, bool read_before_write_in_bb) {}
WEAK void __csi_after_load(void *addr, int num_bytes, unsigned unused, bool unused2, bool unused3, bool read_before_write_in_bb) {}
WEAK void __csi_before_store(void *addr, int num_bytes, unsigned unused, bool unused2, bool unused3, bool read_before_write_in_bb) {}
WEAK void __csi_after_store(void *addr, int num_bytes, unsigned unused, bool unused2, bool unused3, bool read_before_write_in_bb) {}

WEAK void __csi_func_entry(void *function, void *parentReturnAddr, char *funcName) {}
WEAK void __csi_func_exit() {}
// WEAK void __csi_bb_entry(csi_id_t id) {}
WEAK void __csi_bb_entry(uint32_t module_id, uint64_t id) {}
WEAK void __csi_bb_exit() {}

} // extern "C"
