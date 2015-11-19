// A program that just tests memory throughput. Used to measure the overhead of
// the instrumentation calls.
// It can be timed using the unix time utility.

#include <stdio.h>
#include <stdlib.h>

#define NUM_BILLION_ITERATIONS 1l  // how many billion iterations to run

void run_test();

int main(int argc, char *argv[]) {
    printf("Running %ldB iterations\n", NUM_BILLION_ITERATIONS);
    run_test();
    return 0;
}

void run_test() {
    int x = rand();  // Prevent the compiler from optimizing away the entire method

    volatile char a = 0;  // Force the compiler to use memory rather than registers
    volatile short b = 0;
    volatile int c = 0;
    volatile long d = 0;

    for (long j = 0; j < NUM_BILLION_ITERATIONS * 1000000000l; j++) {
        a += x;
        b += x;
        c += x;
        d += x;
    }
}
