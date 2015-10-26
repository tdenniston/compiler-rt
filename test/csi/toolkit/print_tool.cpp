#include "csi.h"
#include <stdio.h>
#include <stdlib.h>

extern "C" {

void __csi_destroy() {
    fprintf(stderr, "Destroy tool\n");
}
void __csi_init() {
    fprintf(stderr, "Initialize tool\n");
    atexit(__csi_destroy);
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

} // extern "C"
