#include "csi.h"
#include <stdio.h>
#include <stdlib.h>

namespace {

void destroy() {
    fprintf(stderr, "Destroy tool\n");
}

}

extern "C" {

void __csi_init(csi_info_t info) {
    fprintf(stderr, "Initialize tool, %d modules\n", info.num_modules);
    atexit(destroy);
}

void __csi_module_init(csi_module_info_t info) {
    fprintf(stderr, "Initialize module id %d, %lu basic blocks.\n", info.module_id, info.num_basic_blocks);
}

void __csi_before_load(void *addr, int num_bytes, int attr) {
    fprintf(stderr, "Before load %p (%d bytes) attr %d\n", addr, num_bytes, attr);
}
void __csi_after_load(void *addr, int num_bytes, int attr) {
    fprintf(stderr, "After load %p (%d bytes) attr %d\n", addr, num_bytes, attr);
}
void __csi_before_store(void *addr, int num_bytes, int attr) {
    fprintf(stderr, "Before store %p (%d bytes) attr %d\n", addr, num_bytes, attr);
}
void __csi_after_store(void *addr, int num_bytes, int attr) {
    fprintf(stderr, "After store %p (%d bytes) attr %d\n", addr, num_bytes, attr);
}
void __csi_func_entry(void *parentReturnAddr, char *funcName) {
    fprintf(stderr, "Func entry, parent return addr %p func name %s.\n", parentReturnAddr, funcName);
}
void __csi_func_exit() {
    fprintf(stderr, "Func exit\n");
}
void __csi_bb_entry(csi_id_t id, const char *filename, uint32_t linestart, uint32_t lineend) {
    fprintf(stderr, "Basic block entry %d:%ld (%s: %d -- %d)\n", id.module_id, id.id,
            filename, linestart, lineend);
}
void __csi_bb_exit() {
    fprintf(stderr, "Basic block exit\n");
}

} // extern "C"
