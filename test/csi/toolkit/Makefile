include ../common.mk

TOOLS := empty_tool counter_tool
OBJECTS := $(patsubst %,%.o,$(TOOLS))

all: $(TOOLS)
$(TOOLS): $(OBJECTS)

%.o: %.cpp
	$(CXX) -O3 -c -emit-llvm $^ -o $@

%.ll: %.cpp
	$(CXX) -O0 -S $(EXTRA) -fcsi -emit-llvm $^ -o $@

# Disable implict link step (we just want the object file).
%: %.o ;

clean:
	-rm -f $(TOOLS) $(OBJECTS)
