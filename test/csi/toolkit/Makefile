include ../common.mk

CXXFLAGS += -Wno-error

LINK ?= $(COMPILER_HOME)/bin/llvm-link

TOOLS := print_tool counter_tool code-coverage call-graph instrument_function prof_lite
OBJECTS := $(patsubst %,%.o,$(TOOLS))

all: $(TOOLS)

null_tool.o: null_tool.cpp
	$(CXX) -O3 -c -emit-llvm $< -o $@

cilkprof.o: null_tool.o cilkprof/
	$(CC) -O3 -Wall -g -std=gnu11 -c -emit-llvm cilkprof/cilkprof.c -o $@
	$(LINK) $@ null_tool.o -o $@

$(OBJECTS): %.o: %.cpp null_tool.o
	$(CXX) -std=c++11 -O3 -c -emit-llvm $< -o $@
	$(LINK) $@ null_tool.o -o $@

%.ll: %.cpp
	$(CXX) -O0 -S $(EXTRA) -fcsi -emit-llvm $^ null_tool.o -o $@

# Disable implict link step (we just want the object file).
%: %.o ;

clean:
	-rm -f prof_lite.o null_tool null_tool.o $(TOOLS) $(OBJECTS)
