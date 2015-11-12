#include "csi.h"
#include <cassert>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>

namespace {

// Return the smallest multiple N of y such that x <= y * N
#define CEILING(x,y) (((x) + (y) - 1) / (y))

class Bitset {
private:
    typedef unsigned char elt_t;
    static const unsigned _eltbits = sizeof(elt_t) * 8;

    unsigned _nbits, _nelts;
    elt_t *_data;

    inline void bit2elt(unsigned bit, unsigned &elt, unsigned &off) const {
        elt = bit / _eltbits;
        off = bit % _eltbits;
    }

public:
    Bitset() : _nbits(0), _nelts(0), _data(NULL) {}

    Bitset(unsigned N) {
        allocate(N);
    }

    void allocate(unsigned N) {
        _nbits = N;
        _nelts = CEILING(_nbits, _eltbits);
        _data = (elt_t *)calloc(_nelts, sizeof(elt_t));
        assert(_data);
    }

    inline void set(unsigned bit) {
        unsigned elt, off;
        bit2elt(bit, elt, off);
        _data[elt] |= 1 << off;
    }

    inline void clear(unsigned bit) {
        unsigned elt, off;
        bit2elt(bit, elt, off);
        _data[elt] &= ~(1 << off);
    }

    inline bool isset(unsigned bit) {
        unsigned elt, off;
        bit2elt(bit, elt, off);
        return _data[elt] & (1 << off);
    }

    unsigned count() const {
        unsigned result = 0;
        for (unsigned i = 0; i < _nelts; i++) {
            result += __builtin_popcount(_data[i]);
        }
        return result;
    }

    unsigned size() const {
        return _nbits;
    }
};

std::vector<Bitset> *bitsets = NULL;
std::vector<std::string> *filenames = NULL;
std::vector<std::vector<std::pair<uint32_t, uint32_t>>> *linenumbers = NULL;

void destroy() {
    unsigned num_basic_blocks = 0, num_covered = 0;
    for (unsigned i = 0; i < bitsets->size(); i++) {
        num_basic_blocks += bitsets->at(i).size();
        num_covered += bitsets->at(i).count();
    }
    printf("\Covered code region report:\n\n");
    printf("%20s | %20s\n", "Line Number Range", "File");
    printf("-------------------------------------------\n");
    for (unsigned i = 0; i < bitsets->size(); i++) {
        std::string filename = filenames->at(i);
        for (unsigned bb = 0; bb < bitsets->at(i).size(); bb++) {
            if (bitsets->at(i).isset(bb)) {
                std::pair<uint32_t, uint32_t> ln = linenumbers->at(i)[bb];
                printf("% 6d    -- % 6d  | %20s\n", ln.first, ln.second, filename.c_str());
            }
        }
    }

    printf("-------------------------------------------\n");
    printf("Code coverage summary:\n");
    printf("%d/%d (%.02f%%) basic blocks executed.\n", num_covered, num_basic_blocks,
           ((float)num_covered/num_basic_blocks)*100);
}

}

extern "C" {

void __csi_init(csi_info_t info) {
    atexit(destroy);
    bitsets = new std::vector<Bitset>(info.num_modules);
    filenames = new std::vector<std::string>(info.num_modules);
    linenumbers = new std::vector<std::vector<std::pair<uint32_t, uint32_t>>>(info.num_modules);
}

void __csi_module_init(csi_module_info_t info) {
    assert(bitsets && info.module_id < bitsets->size());
    bitsets->at(info.module_id).allocate(info.num_basic_blocks);
    linenumbers->at(info.module_id).resize(info.num_basic_blocks);
}

void __csi_bb_entry(csi_id_t id, const char *filename, uint32_t linestart, uint32_t lineend) {
    assert(bitsets && id.module_id < bitsets->size());
    assert(id.id < (*bitsets)[id.module_id].size());
    if (!(*bitsets)[id.module_id].isset(id.id)) {
        (*linenumbers)[id.module_id][id.id] = std::make_pair(linestart, lineend);
    }
    if ((*filenames)[id.module_id].empty()) {
        (*filenames)[id.module_id] = std::string(filename);
    }

    (*bitsets)[id.module_id].set(id.id);
}

} // extern "C"
