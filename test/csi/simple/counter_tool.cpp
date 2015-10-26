#include <stdio.h>
#include <stdlib.h>

long times_accessed_by_size[4];

static void __csi_destroy() {
    fprintf(stderr, "bytes accessed: %ld\n", times_accessed_by_size[0]);
    fprintf(stderr, "shorts accessed: %ld\n", times_accessed_by_size[1]);
    fprintf(stderr, "ints accessed: %ld\n", times_accessed_by_size[2]);
    fprintf(stderr, "longs accessed: %ld\n", times_accessed_by_size[3]);
}
extern "C" void __csi_init() {
    atexit(__csi_destroy);
}
extern "C" void __csi_before_load(void *addr, int num_bytes, int attr) {
    times_accessed_by_size[__builtin_ctz(num_bytes)]++;
}
extern "C" void __csi_after_load(void *addr, int num_bytes, int attr) {
}
extern "C" void __csi_before_store(void *addr, int num_bytes, int attr) {
    times_accessed_by_size[__builtin_ctz(num_bytes)]++;
}
extern "C" void __csi_after_store(void *addr, int num_bytes, int attr) {
}
extern "C" void __csi_func_entry(void *parentReturnAddr, char *funcName) {
}
extern "C" void __csi_func_exit() {
}
extern "C" void __csi_bb_entry(int id, int attr) {}
