#include <inttypes.h>

extern "C" {
void __ok_before_load1(void *addr, int attr);
void __ok_before_load2(void *addr, int attr);
void __ok_before_load4(void *addr, int attr);
void __ok_before_load8(void *addr, int attr);
void __ok_after_load1(void *addr, int attr, int8_t val);
void __ok_after_load2(void *addr, int attr, int16_t val);
void __ok_after_load4(void *addr, int attr, int32_t val);
void __ok_after_load8(void *addr, int attr, int64_t val);
// void __ok_after_float(void *addr, int attr, float val);
// void __ok_after_double(void *addr, int attr, double val);
void __ok_before_store1(void *addr, int attr, int8_t val);
void __ok_before_store2(void *addr, int attr, int16_t val);
void __ok_before_store4(void *addr, int attr, int32_t val);
void __ok_before_store8(void *addr, int attr, int64_t val);
// void __ok_before_float(void *addr, int attr, float val);
// void __ok_before_double(void *addr, int attr, double val);
void __ok_after_store1(void *addr, int attr);
void __ok_after_store2(void *addr, int attr);
void __ok_after_store4(void *addr, int attr);
void __ok_after_store8(void *addr, int attr);
}
