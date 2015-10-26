TARGETS := fib-serial foo memops

default: $(TARGETS)

include ../common.mk

EXTRA = -v -mllvm -debug-only="csi_func"
CFLAGS += $(EXTRA)
CXXFLAGS += $(EXTRA)
LTOFLAGS = -B/usr/lib/gold-ld -flto

fib-serial: fib-serial.o
foo: foo.o empty_tool.o
memops: memops.o counter_tool.o

foo.o: foo.cpp
	$(CXX) -O0 -c $(EXTRA) -fcsi $^ -o $@

memops.o: memops.cpp
	$(CXX) -c $(EXTRA) -fcsi -emit-llvm $^ -o $@

empty_tool.o: empty_tool.cpp
	$(CXX) -O3 -c -emit-llvm $^ -o $@

counter_tool.o: counter_tool.cpp
	$(CXX) -O3 -c -emit-llvm $^ -o $@

empty_tool.ll: empty_tool.cpp
	$(CXX) -O3 -S $(EXTRA) -emit-llvm $^ -o $@

# The right file extention for bitcode is *.ll
%.ll: %.cpp
	$(CXX) -O0 -S $(EXTRA) -fcsi -emit-llvm $^ -o $@

%.bc: %.cpp
	$(CXX) -O0 -S -fsanitize=thread -emit-llvm -c $^ -o $@

%.s: %.cpp
	$(CXX) -S -O3 $^ -o $@

%: %.o
	$(CXX) $^ $(LDFLAGS) -O3 $(LTOFLAGS) $(LDLIBS) -o $@

clean:
	-rm -f $(TARGETS) *.o *.s *.ll *.bc
