#include "csi.h"
#include <stdio.h>
#include <stdlib.h>

extern "C" {
long times_accessed_by_size[4];

WEAK void __csi_destroy() {
    fprintf(stderr, "bytes accessed: %ld\n", times_accessed_by_size[0]);
    fprintf(stderr, "shorts accessed: %ld\n", times_accessed_by_size[1]);
    fprintf(stderr, "ints accessed: %ld\n", times_accessed_by_size[2]);
    fprintf(stderr, "longs accessed: %ld\n", times_accessed_by_size[3]);
}
WEAK void __csi_init() {
    atexit(__csi_destroy);
}
WEAK void __csi_before_load(void *addr, int num_bytes, int attr) {
    times_accessed_by_size[__builtin_ctz(num_bytes)]++;
}
WEAK void __csi_after_load(void *addr, int num_bytes, int attr) {
}
WEAK void __csi_before_store(void *addr, int num_bytes, int attr) {
    times_accessed_by_size[__builtin_ctz(num_bytes)]++;
}
WEAK void __csi_after_store(void *addr, int num_bytes, int attr) {
}
WEAK void __csi_func_entry(void *parentReturnAddr, char *funcName) {
}
WEAK void __csi_func_exit() {
}

}
