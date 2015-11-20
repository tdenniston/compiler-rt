CXXFLAGS = -std=c++11 -fPIE -g -Wall -Werror -fno-builtin -msse3 -DSANITIZER_DEBUG=0 -DTSAN_CONTAINS_UBSAN=0
CLANG=clang
DEBUG=0

CXX=$(COMPILER_HOME)/bin/clang++
AR=/data/scratch/tyler/csi/bin-intercept/ar

ifeq ($(DEBUG), 0)
  CXXFLAGS += -O3
endif

ifeq ($(USE_PROPERTIES), 1)
  CXXFLAGS += -DUSE_PROPERTIES
endif

# For interception. FIXME: move interception one level higher.
INTERCEPTION=../../interception
COMMON=../../sanitizer_common
INCLUDES= -I../.. -I../../../include
EXTRA_CXXFLAGS=-fno-exceptions -fno-rtti
NO_SYSROOT=--sysroot=.
CXXFLAGS+=$(EXTRA_CXXFLAGS)
CXXFLAGS+=$(CFLAGS)
ifeq ($(DEBUG), 0)
  CXXFLAGS+=-fomit-frame-pointer
ifeq ($(CXX), g++)
  CXXFLAGS+=-Wno-maybe-uninitialized
  CXXFLAGS+=-Wframe-larger-than=512
endif  # CXX=g++
endif  # DEBUG=0

#ifeq ($(CXX), $(CLANG)++)
  # Global constructors are banned.
  CXXFLAGS+=-Wglobal-constructors
#endif



all: libtsan.a csi_interface.o

LIBTSAN_HEADERS=$(wildcard *.h) \
		$(wildcard $(INTERCEPTION)/*.h) \
		$(wildcard $(COMMON)/*.h)
LIBTSAN_SRC=$(filter-out csi_interface.cc,$(wildcard *.cc))
LIBTSAN_ASM_SRC=$(wildcard *.S)
INTERCEPTION_SRC=$(wildcard $(INTERCEPTION)/*.cc)
COMMON_SRC=$(filter-out $(wildcard $(COMMON)/*_nolibc.cc),$(wildcard $(COMMON)/*.cc))

LIBTSAN_OBJ=$(patsubst %.cc,%.o,$(LIBTSAN_SRC)) \
	    $(patsubst %.S,%.o,$(LIBTSAN_ASM_SRC)) \
	    $(patsubst $(INTERCEPTION)/%.cc,%.o,$(INTERCEPTION_SRC)) \
	    $(patsubst $(COMMON)/%.cc,%.o,$(COMMON_SRC))

%_linux.o: %_linux.cc Makefile $(LIBTSAN_HEADERS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $<
%.o: %.cc Makefile $(LIBTSAN_HEADERS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(NO_SYSROOT) -c $<
%.o: $(INTERCEPTION)/%.cc Makefile $(LIBTSAN_HEADERS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@
%.o: $(COMMON)/%.cc Makefile $(LIBTSAN_HEADERS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@
%.o: %.S
	$(CXX) $(INCLUDES) -o $@ -c $<

csi_interface.o: csi_interface.cc
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(NO_SYSROOT) -c -emit-llvm $< -o $@

libtsan.a: $(LIBTSAN_OBJ)
	$(AR) ru $@ $(LIBTSAN_OBJ)

libtsan_dummy.a: tsan_dummy_rtl.o
	$(AR) ru $@ $<

clean:
	rm -f *.o *.a
