#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

// Return smallest integral multiple 'ny' of y such that x <= ny
#define CEILING(x,y) (((x) + (y) - 1) / (y))

typedef uint32_t bitset_elt_t;
typedef struct {
    bitset_elt_t *data; // dense bit vector.
    uint32_t ndata; // # of elements in 'data' array.
    uint32_t nbits; // # of bits contained in this bitset.
} bitset_t;

void bitset_init(bitset_t *bitset, uint32_t nbits) {
    if (!bitset) return;
    uint32_t ndata = CEILING(nbits, sizeof(bitset_elt_t)*8) / 8;
    bitset->data = (bitset_elt_t *)calloc(ndata, sizeof(bitset_elt_t));
    bitset->ndata = ndata;
    bitset->nbits = nbits;
}

void bitset_destroy(bitset_t *bitset) {
    if (!bitset) return;
    free(bitset->data);
    bitset->data = NULL;
    bitset->ndata = 0;
    bitset->nbits = 0;
}

void bitset_bit_to_data_index(uint32_t bit_idx, uint32_t *out_data_idx, uint32_t *out_data_off) {
    if (out_data_idx) *out_data_idx = bit_idx / (sizeof(bitset_elt_t) * 8);
    if (out_data_off) *out_data_off = bit_idx % (sizeof(bitset_elt_t) * 8);
}

void bitset_set(bitset_t *bitset, uint32_t idx) {
    uint32_t elt, off;
    bitset_bit_to_data_index(idx, &elt, &off);
    bitset->data[elt] |= 1 << off;
}

void bitset_unset(bitset_t *bitset, uint32_t idx) {
    uint32_t elt, off;
    bitset_bit_to_data_index(idx, &elt, &off);
    bitset->data[elt] &= ~(1 << off);
}

unsigned bitset_get(bitset_t *bitset, uint32_t idx) {
    uint32_t elt, off;
    bitset_bit_to_data_index(idx, &elt, &off);
    return (bitset->data[elt] >> off) & 1;
}

static bitset_t bbs;

void __csi_destroy() {
    unsigned set = 0;
    for (unsigned i = 0; i < bbs.nbits; i++) {
        unsigned bit = bitset_get(&bbs, i);
        if (bit) {
            set++;
        } else {
            printf("Basic block %d not executed.\n", i);
        }
    }
    printf("%d/%d (%.2f%%) basic blocks executed.\n",
           set, bbs.nbits, 100*(float)set/bbs.nbits);
}

extern "C" {

// This must match the definition in CodeSpectatorInterface.cpp.
typedef struct {
    int64_t num_basic_blocks;
} csi_info_t;

void __csi_init(csi_info_t info) {
    atexit(__csi_destroy);
    bitset_init(&bbs, info.num_basic_blocks);
}

void __csi_before_load(void *addr, int num_bytes, int attr) {}
void __csi_after_load(void *addr, int num_bytes, int attr) {}
void __csi_before_store(void *addr, int num_bytes, int attr) {}
void __csi_after_store(void *addr, int num_bytes, int attr) {}
void __csi_func_entry(void *parentReturnAddr, char *funcName) {}
void __csi_func_exit() {}

void __csi_bb_entry(int32_t id, int32_t attr) {
    bitset_set(&bbs, id);
}
}
