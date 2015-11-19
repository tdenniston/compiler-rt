#include "csi.h"
#include <cassert>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>
#include <map>
#include <set>
#include <stack>

namespace {

std::stack<std::string> *call_stack = NULL;
std::map<std::string, std::set<std::string> > *CG = NULL;

void push_func(const std::string &name) {
    call_stack->push(name);
}

void pop_func() {
    call_stack->pop();
}

void add_call_edge(const char *f, const char *g) {
    assert(CG);
    std::string sf(f), sg(g);
    if (CG->find(sf) == CG->end()) {
        CG->insert(std::make_pair(sf, std::set<std::string>()));
    }
    CG->find(sf)->second.insert(sg);
}

void destroy() {
    for (auto it : *CG) {
        std::cout << "Function " << it.first << " calls: \n";
        for (auto it2 : it.second) {
            std::cout << "   " << it2 << "\n";
        }
    }
}

}

extern "C" {

void __csi_init(csi_info_t info) {
    atexit(destroy);
    call_stack = new std::stack<std::string>();
    CG = new std::map<std::string, std::set<std::string> >();
}

void __csi_func_entry(void *function, void *parentReturnAddr, char *funcName) {
    assert(call_stack);
    if (!call_stack->empty()) {
        add_call_edge(call_stack->top().c_str(), funcName);
    }
    push_func(funcName);
}

void __csi_func_exit() {
    pop_func();
}

} // extern "C"
