#include "tsan_interface.h"
#include "tsan_interface_ann.h"
#include "tsan_rtl.h"
#include "sanitizer_common/sanitizer_internal_defs.h"

#define CALLERPC ((uptr)__builtin_return_address(0))

using namespace __tsan;

extern "C" void __csi_init() {
    Initialize(cur_thread());
}
extern "C" void __csi_before_load(void *addr, int num_bytes, int attr) {
    UnalignedMemoryAccess(cur_thread(), CALLERPC, (uptr)addr, num_bytes, false, false);
}
extern "C" void __csi_after_load(void *addr, int num_bytes, int attr) {
}
extern "C" void __csi_before_store(void *addr, int num_bytes, int attr) {
    UnalignedMemoryAccess(cur_thread(), CALLERPC, (uptr)addr, num_bytes, true, false);
}
extern "C" void __csi_after_store(void *addr, int num_bytes, int attr) {
}
extern "C" void __csi_func_entry(void *parentReturnAddr, char *funcName) {
    FuncEntry(cur_thread(), (uptr)parentReturnAddr);
}
extern "C" void __csi_func_exit() {
    FuncExit(cur_thread());
}
