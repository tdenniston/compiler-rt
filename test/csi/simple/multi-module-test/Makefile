TOOLKIT = ../../toolkit

# Toolkit rules go before including 'common.mk' so that they are
# preferentially matched.
$(TOOLKIT)/%.o: $(TOOLKIT)/%.cpp
	make -C $(TOOLKIT) $*

# By default link with the null tool.  To use another tool, do
# e.g. 'make foo TOOL=print_tool'
TOOL ?= null_tool
TOOL_OBJ = $(patsubst %,$(TOOLKIT)/%.o,$(TOOL))


include ../../common.mk

OBJECTS=a.o b.o

default: main

main: main.o $(OBJECTS) $(TOOL_OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -flto $^ -o $@

%.o: %.cpp
	$(CXX) -c $(EXTRA) -fcsi -emit-llvm $^ -o $@

clean:
	rm -f main *.o
