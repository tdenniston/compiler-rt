#include <stdio.h>
#include <stdlib.h>

long bytes_accessed;
long shorts_accessed;
long ints_accessed;
long longs_accessed;

static void __ok_destroy() {
    fprintf(stderr, "bytes accessed: %ld\n", bytes_accessed);
    fprintf(stderr, "shorts accessed: %ld\n", shorts_accessed);
    fprintf(stderr, "ints accessed: %ld\n", ints_accessed);
    fprintf(stderr, "longs accessed: %ld\n", longs_accessed);
}
extern "C" void __ok_init() {
    atexit(__ok_destroy);
}
extern "C" void __ok_before_load(void *addr, int num_bytes, int attr) {
    if (num_bytes == 1)
        bytes_accessed++;
    else if (num_bytes == 2)
        shorts_accessed++;
    else if (num_bytes == 4)
        ints_accessed++;
    else if (num_bytes == 8)
        longs_accessed++;
}
extern "C" void __ok_after_load(void *addr, int num_bytes, int attr) {
}
extern "C" void __ok_before_store(void *addr, int num_bytes, int attr) {
    if (num_bytes == 1)
        bytes_accessed++;
    else if (num_bytes == 2)
        shorts_accessed++;
    else if (num_bytes == 4)
        ints_accessed++;
    else if (num_bytes == 8)
        longs_accessed++;
}
extern "C" void __ok_after_store(void *addr, int num_bytes, int attr) {
}
extern "C" void __ok_func_entry(void *parentReturnAddr, char *funcName) {
}
extern "C" void __ok_func_exit() {
}
