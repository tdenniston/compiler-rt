#include "csi.h"
#include <stdio.h>
#include <stdlib.h>

namespace {

void destroy() {
    fprintf(stderr, "Destroy tool\n");
}

}

extern "C" {

// void __csi_init(csi_info_t info) {
void __csi_init(uint32_t num_modules) {
    fprintf(stderr, "Initialize tool, %d modules\n", num_modules);
    atexit(destroy);
}

// void __csi_module_init(csi_module_info_t info) {
void __csi_module_init(uint32_t module_id, uint64_t num_basic_blocks) {
    fprintf(stderr, "Initialize module id %d, %lu basic blocks.\n", module_id, num_basic_blocks);
}

void __csi_before_load(void *addr, int num_bytes, unsigned unused, bool unused2, bool unused3, bool read_before_write_in_bb) {
    fprintf(stderr, "Before load %p (%d bytes) unused %d, unused2 %d, unused3 %d, read_before_write_in_bb %d\n", addr, num_bytes, unused, unused2, unused3, read_before_write_in_bb);
}
void __csi_after_load(void *addr, int num_bytes, unsigned unused, bool unused2, bool unused3, bool read_before_write_in_bb) {
    fprintf(stderr, "After load %p (%d bytes) unused %d, unused2 %d, unused3 %d, read_before_write_in_bb %d\n", addr, num_bytes, unused, unused2, unused3, read_before_write_in_bb);
}
void __csi_before_store(void *addr, int num_bytes, unsigned unused, bool unused2, bool unused3, bool read_before_write_in_bb) {
    fprintf(stderr, "Before store %p (%d bytes) unused %d, unused2 %d, unused3 %d, read_before_write_in_bb %d\n", addr, num_bytes, unused, unused2, unused3, read_before_write_in_bb);
}
void __csi_after_store(void *addr, int num_bytes, unsigned unused, bool unused2, bool unused3, bool read_before_write_in_bb) {
    fprintf(stderr, "After store %p (%d bytes) unused %d, unused2 %d, unused3 %d, read_before_write_in_bb %d\n", addr, num_bytes, unused, unused2, unused3, read_before_write_in_bb);
}

void __csi_func_entry(void *function, void *parentReturnAddr, char *funcName) {
    fprintf(stderr, "Func entry, function %p, parent return addr %p func name %s.\n", function, parentReturnAddr, funcName);
}
void __csi_func_exit() {
    fprintf(stderr, "Func exit\n");
}
// void __csi_bb_entry(csi_id_t id) {
void __csi_bb_entry(uint32_t module_id, uint64_t id) {
    fprintf(stderr, "Basic block entry %d:%ld\n", module_id, id);
}
void __csi_bb_exit() {
    fprintf(stderr, "Basic block exit\n");
}

} // extern "C"
