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
extern "C" void __ok_before_load1(void *addr, int attr) {
    bytes_accessed++;
}
extern "C" void __ok_before_load2(void *addr, int attr) {
    shorts_accessed++;
}
extern "C" void __ok_before_load4(void *addr, int attr) {
    ints_accessed++;
}
extern "C" void __ok_before_load8(void *addr, int attr) {
    longs_accessed++;
}
extern "C" void __ok_after_load1(void *addr, int attr) {
}
extern "C" void __ok_after_load2(void *addr, int attr) {
}
extern "C" void __ok_after_load4(void *addr, int attr) {
}
extern "C" void __ok_after_load8(void *addr, int attr) {
}
// extern "C" void __ok_after_float(void *addr, int attr) {}
// extern "C" void __ok_after_double(void *addr, int attr) {}
extern "C" void __ok_before_store1(void *addr, int attr) {
    bytes_accessed++;
}
extern "C" void __ok_before_store2(void *addr, int attr) {
    shorts_accessed++;
}
extern "C" void __ok_before_store4(void *addr, int attr) {
    ints_accessed++;
}
extern "C" void __ok_before_store8(void *addr, int attr) {
    longs_accessed++;
}
// extern "C" void __ok_before_float(void *addr, int attr) {}
// extern "C" void __ok_before_double(void *addr, int attr) {}
extern "C" void __ok_after_store1(void *addr, int attr) {
}
extern "C" void __ok_after_store2(void *addr, int attr) {
}
extern "C" void __ok_after_store4(void *addr, int attr) {
}
extern "C" void __ok_after_store8(void *addr, int attr) {
}
extern "C" void __ok_func_entry(void *parentReturnAddr, char *funcName) {
}
extern "C" void __ok_func_exit() {
}
