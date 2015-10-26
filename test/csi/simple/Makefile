TARGETS := fib-serial foo memops
TOOLKIT = ../toolkit

default: $(TARGETS)

# Toolkit rules go before including 'common.mk' so that they are
# preferentially matched.
$(TOOLKIT)/%.o: $(TOOLKIT)/%.cpp
	make -C $(TOOLKIT) $*

include ../common.mk

EXTRA = -mllvm -debug-only="csi_func"
CFLAGS += $(EXTRA)
CXXFLAGS += $(EXTRA)

# By default link with the null tool.  To use another tool, do
# e.g. 'make foo TOOL=print_tool'
TOOL ?= null_tool
TOOL_OBJ = $(patsubst %,$(TOOLKIT)/%.o,$(TOOL))

fib-serial: fib-serial.o
foo: foo.o $(TOOL_OBJ)
memops: memops.o $(TOOL_OBJ)

foo.o: foo.cpp
	$(CXX) -O0 -c $(EXTRA) -fcsi $^ -o $@

memops.o: memops.cpp
	$(CXX) -c $(EXTRA) -fcsi -emit-llvm $^ -o $@

# The right file extention for bitcode is *.ll
%.ll: %.cpp
	$(CXX) -O0 -S $(EXTRA) -fcsi -emit-llvm $^ -o $@

%.bc: %.cpp
	/usr/local/llvm-cilk/bin/clang++ -O0 -S -fsanitize=thread -emit-llvm -c $^ -o $@

%.s: %.cpp
	$(CXX) -S -O3 $^ -o $@

%: %.o
	$(CXX) $^ $(LDFLAGS) -O3 -flto $(LDLIBS) -o $@

clean:
	-rm -f $(TARGETS) *.o *.s *.ll *.bc
	make -C $(TOOLKIT) clean
