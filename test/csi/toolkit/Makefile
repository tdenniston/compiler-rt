include ../common.mk

CXXFLAGS += -Wno-error

LINK ?= $(COMPILER_HOME)/bin/llvm-link

TOOLS := print_tool counter_tool
OBJECTS := $(patsubst %,%.o,$(TOOLS))

all: $(TOOLS)

csi_rt.o: csi_rt.cpp
	$(CXX) -O3 -c -emit-llvm $^ -o $@

null_tool.o: null_tool.cpp csi_rt.o
	$(CXX) -O3 -c -emit-llvm $< -o $@
	$(LINK) $@ csi_rt.o -o $@

$(OBJECTS): %.o: %.cpp null_tool.o
	$(CXX) -O3 -c -emit-llvm $< -o $@
	$(LINK) $@ null_tool.o -o $@

%.ll: %.cpp
	$(CXX) -O0 -S $(EXTRA) -fcsi -emit-llvm $^ null_tool.o -o $@

# Disable implict link step (we just want the object file).
%: %.o ;

clean:
	-rm -f null_tool null_tool.o csi_rt.o $(TOOLS) $(OBJECTS)
