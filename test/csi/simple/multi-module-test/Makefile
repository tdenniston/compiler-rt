TOOLKIT = ../../toolkit

# Toolkit rules go before including 'common.mk' so that they are
# preferentially matched.
$(TOOLKIT)/%.o: $(TOOLKIT)/%.cpp
	make -C $(TOOLKIT) $*

include ../../common.mk

OBJECTS=a.o b.o

default: main

main: main.o $(OBJECTS) $(TOOLKIT)/print_tool.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -flto $^ -o $@

%.o: %.cpp
	$(CXX) -c $(EXTRA) -fcsi -emit-llvm $^ -o $@

clean:
	rm -f main *.o
