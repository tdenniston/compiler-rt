#ifndef __CSI_H__
#define __CSI_H__

#include <stdint.h>

#ifdef __cplusplus
#define EXTERN_C extern "C" {
#define EXTERN_C_END }
#else
#define EXTERN_C
#define EXTERN_C_END
#endif

#define WEAK __attribute__((weak))

// API function signatures
EXTERN_C

typedef struct {
  uint32_t module_id;
  uint64_t num_basic_blocks;
} csi_module_info_t;

typedef struct {
  uint32_t num_modules;
} csi_info_t;

typedef struct {
  uint32_t module_id;
  uint64_t id;
} csi_id_t;

WEAK void __csi_init(csi_info_t info);
WEAK void __csi_module_init(csi_module_info_t info);
WEAK void __csi_before_load(void *addr, int num_bytes, int attr);
WEAK void __csi_after_load(void *addr, int num_bytes, int attr);
WEAK void __csi_before_store(void *addr, int num_bytes, int attr);
WEAK void __csi_after_store(void *addr, int num_bytes, int attr);
WEAK void __csi_func_entry(void *function, void *parentReturnAddr, char *funcName);
WEAK void __csi_func_exit();
WEAK void __csi_bb_entry(csi_id_t id);
WEAK void __csi_bb_exit();

EXTERN_C_END

#endif
