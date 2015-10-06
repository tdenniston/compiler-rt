#include <stdio.h>
#include <inttypes.h>

extern "C" void __ok_before_load1(void *addr, int attr) { 
    fprintf(stderr, "Before load1, addr %p.\n", addr);
}
extern "C" void __ok_before_load2(void *addr, int attr) { 
    fprintf(stderr, "Before load2, addr %p.\n", addr);
}
extern "C" void __ok_before_load4(void *addr, int attr) { 
    fprintf(stderr, "Before load4, addr %p.\n", addr);
}
extern "C" void __ok_before_load8(void *addr, int attr) { 
    fprintf(stderr, "Before load8, addr %p.\n", addr);
}
extern "C" void __ok_after_load1(void *addr, int attr, int8_t val) { 
    fprintf(stderr, "After load1, addr %p val %d.\n", addr, val);
}
extern "C" void __ok_after_load2(void *addr, int attr, int16_t val) { 
    fprintf(stderr, "After load2, addr %p val %d.\n", addr, val);
}
extern "C" void __ok_after_load4(void *addr, int attr, int32_t val) { 
    fprintf(stderr, "After load4, addr %p val %d.\n", addr, val);
}
extern "C" void __ok_after_load8(void *addr, int attr, int64_t val) { 
    fprintf(stderr, "After load8, addr %p val %ld.\n", addr, val);
}
// extern "C" void __ok_after_float(void *addr, int attr, float val) { }
// extern "C" void __ok_after_double(void *addr, int attr, double val) { }
extern "C" void __ok_before_store1(void *addr, int attr, int8_t val) { 
    fprintf(stderr, "Before store1, addr %p val %d.\n", addr, val);
}
extern "C" void __ok_before_store2(void *addr, int attr, int16_t val) { 
    fprintf(stderr, "Before store2, addr %p val %d.\n", addr, val);
}
extern "C" void __ok_before_store4(void *addr, int attr, int32_t val) {
    fprintf(stderr, "Before store4, addr %p val %d.\n", addr, val);
}
extern "C" void __ok_before_store8(void *addr, int attr, int64_t val) { 
    fprintf(stderr, "Before store8, addr %p val %ld.\n", addr, val);
}
// void __ok_before_float(void *addr, int attr, float val) { }
// void __ok_before_double(void *addr, int attr, double val) { }
extern "C" void __ok_after_store1(void *addr, int attr) { 
    fprintf(stderr, "After store1, addr %p.\n", addr);
}
extern "C" void __ok_after_store2(void *addr, int attr) { 
    fprintf(stderr, "After store2, addr %p.\n", addr);
}
extern "C" void __ok_after_store4(void *addr, int attr) {
    fprintf(stderr, "After store4, addr %p.\n", addr);
}                         
extern "C" void __ok_after_store8(void *addr, int attr) { 
    fprintf(stderr, "After store8, addr %p.\n", addr);
}
extern "C" void __ok_func_entry(void *parentReturnAddr, char *funcName) { 
    fprintf(stderr, "Func entry, parent return addr %p func name %s.\n", parentReturnAddr, funcName);
}
extern "C" void __ok_func_exit() { 
    fprintf(stderr, "Func exit.\n");
}
