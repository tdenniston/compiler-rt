#include "csi.h"
#include <stdio.h>
#include <stdlib.h>

extern "C" {
int a, b, c, d;

void print() {
    printf("%d %d %d %d\n", a, b, c, d);
}

void __csi_init(csi_info_t info) {
    atexit(print);
}

void __csi_before_load(void *addr, int num_bytes, csi_acc_prop_t prop) {
    if (!prop.read_before_write_in_bb)
        a++;
}

void __csi_before_store(void *addr, int num_bytes, csi_acc_prop_t prop) {
    c++;
}

} // extern "C"

