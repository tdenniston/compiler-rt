.SUFFIXES:

TARGETS := mini_bench_local mini_bench_shared start_many_threads

default: $(TARGETS)

TSAN_DIR=..

INSTRUMENTATION ?= none

include myconfig.mk
CC=clang
CXX=clang++

CFLAGS_Instrumentation_none =
CFLAGS_Instrumentation_tsan = -fsanitize=thread
CFLAGS_Instrumentation_csi = -fcsi

CFLAGS += ${CFLAGS_Instrumentation_${INSTRUMENTATION}}
CFLAGS += -O3 -emit-llvm
LDFLAGS += -O3 -flto -ldl -lpthread -lrt -lm -Wl,--whole-archive $(TSAN_DIR)/rtl/libtsan.a -Wl,--no-whole-archive

%.o : %.cc
	$(CXX) -c $(CFLAGS) $^ -o $@

% : %.o
	$(CXX) $(LDFLAGS) $^ -o $@

.PHONY : clean
clean:
	-rm -f $(TARGETS) *.o
