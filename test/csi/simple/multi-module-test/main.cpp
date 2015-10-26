#include <iostream>
#include <cstdlib>
#include <sys/time.h>

#include "a.h"
#include "b.h"

int c() {
    std::cout << "In c.\n";
    return 3;
}

int d() {
    return 4;
}

int main() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    srandom(tv.tv_sec + tv.tv_usec/1000000);
    long r = random();
    int result = 0;

    std::cout << "In main.\n";
    result += a() + b() + c();
    if (r < RAND_MAX/2) {
        result += d();
    }

    std::cout << "Result was: " << result << "\n";
    return 0;
}
