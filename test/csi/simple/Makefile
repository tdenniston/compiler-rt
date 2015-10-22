TARGETS := fib-serial foo memops

default: $(TARGETS)

include ../common.mk

EXTRA = -v -mllvm -debug-only="ok_func"
CFLAGS += $(EXTRA)
CXXFLAGS += $(EXTRA) 

fib-serial: fib-serial.o
foo: foo.o empty_tool.o
memops: memops.o counter_tool.o

foo.o: foo.cpp
	$(CXX) -O0 -c $(EXTRA) -fopenkimono $^ -o $@

memops.o: memops.cpp
	$(CXX) -c $(EXTRA) -fopenkimono -emit-llvm $^ -o $@

empty_tool.o: empty_tool.cpp
	$(CXX) -O3 -c -emit-llvm $^ -o $@

counter_tool.o: counter_tool.cpp
	$(CXX) -O3 -c -emit-llvm $^ -o $@

empty_tool.ll: empty_tool.cpp
	$(CXX) -O3 -S $(EXTRA) -emit-llvm $^ -o $@

# The right file extention for bitcode is *.ll
%.ll: %.cpp
	$(CXX) -O0 -S $(EXTRA) -fopenkimono -emit-llvm $^ -o $@

%.bc: %.cpp
	/usr/local/llvm-cilk/bin/clang++ -O0 -S -fsanitize=thread -emit-llvm -c $^ -o $@

%.s: %.cpp
	$(CXX) -S -O3 $^ -o $@

%: %.o
	$(CXX) $^ $(LDFLAGS) -O3 -flto $(LDLIBS) -o $@

clean:
	-rm -f $(TARGETS) *.o *.s *.ll *.bc
