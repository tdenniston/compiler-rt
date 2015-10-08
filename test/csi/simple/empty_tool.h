#include <inttypes.h>

extern "C" {
void __ok_init();

void __ok_before_load(void *addr, size_t num_bytes, int attr);
void __ok_after_load(void *addr, size_t num_bytes, int attr);
void __ok_before_store(void *addr, size_t num_bytes, int attr);
void __ok_after_store(void *addr, size_t num_bytes, int attr);
void __ok_func_entry(void *parentReturnAddr, char *funcName);
void __ok_func_exit();
}
