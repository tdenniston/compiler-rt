TOOLKIT = ../../toolkit

# Toolkit rules go before including 'common.mk' so that they are
# preferentially matched.
$(TOOLKIT)/%.o: $(TOOLKIT)/%.cpp
	make -C $(TOOLKIT) $*

# By default link with the null tool.  To use another tool, do
# e.g. 'make foo TOOL=print_tool'
TOOL ?= null_tool
TOOL_OBJ = $(patsubst %,$(TOOLKIT)/%.o,$(TOOL))

#COV_FLAGS = -fprofile-instr-generate -fcoverage-mapping
COV_FLAGS=

include ../../common.mk

OBJECTS=a.o b.o

default: main

main: main.o $(OBJECTS) $(TOOL_OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -flto $(COV_FLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) -c $(EXTRA) -fcsi -emit-llvm $(COV_FLAGS) $^ -o $@

main.o: main.cpp
	$(CXX) -c $(EXTRA) -fcsi -emit-llvm $(COV_FLAGS) $^ -o $@

clean:
	rm -f main *.o
