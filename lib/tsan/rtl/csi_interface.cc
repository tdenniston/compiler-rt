#include "tsan_interface.h"
#include "tsan_interface_ann.h"
#include "tsan_rtl.h"
#include "sanitizer_common/sanitizer_internal_defs.h"

#define CALLERPC ((uptr)__builtin_return_address(0))

using namespace __tsan;

// This is taken from csi.h.
typedef struct {
  // Placeholders just to make sure the compiler can optimize this stuff away.
  // DD: I figure it's good to include these as a just-in-case, since the
  // paper API includes these params of this type.
  unsigned unused;
  bool unused2, unused3;
  bool read_before_write_in_bb;
} csi_acc_prop_t;

typedef struct {
  u32 module_id;
  u64 num_basic_blocks;
} csi_module_info_t;

typedef struct {
  u32 num_modules;
} csi_info_t;

typedef struct {
  u32 module_id;
  u64 id;
} csi_id_t;

extern "C" void __csi_init(csi_info_t info) {
    Initialize(cur_thread());
}
extern "C" void __csi_before_load(void *addr, int num_bytes, csi_acc_prop_t prop) {
#ifdef USE_PROPERTIES
    if (!prop.read_before_write_in_bb)
        UnalignedMemoryAccess(cur_thread(), CALLERPC, (uptr)addr, num_bytes, false, false);
#else
    UnalignedMemoryAccess(cur_thread(), CALLERPC, (uptr)addr, num_bytes, false, false);
#endif
}
extern "C" void __csi_after_load(void *addr, int num_bytes, csi_acc_prop_t prop) {
}
extern "C" void __csi_before_store(void *addr, int num_bytes, csi_acc_prop_t prop) {
    UnalignedMemoryAccess(cur_thread(), CALLERPC, (uptr)addr, num_bytes, true, false);
}
extern "C" void __csi_after_store(void *addr, int num_bytes, csi_acc_prop_t prop) {
}
extern "C" void __csi_func_entry(void *parentReturnAddr, char *funcName) {
    FuncEntry(cur_thread(), (uptr)parentReturnAddr);
}
extern "C" void __csi_func_exit() {
    FuncExit(cur_thread());
}
extern "C" void __csi_module_init(csi_module_info_t info) {}
extern "C" void __csi_bb_entry(csi_id_t id) {}
extern "C" void __csi_bb_exit() {}
