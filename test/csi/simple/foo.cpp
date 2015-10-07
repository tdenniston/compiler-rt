#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>

char global_char = 1;
short global_short = 2;
int global_uint = 4;
uint64_t global = 8;

void foo(int i) {
    global_char += (char) i;
    global_short += (short) i;
    global_uint += (unsigned int) i;
    global += i;
}

// int main(int argc, char *argv[]) {
int main(void) {
    
  /*
  int n = 0;

  if (argc != 2) {
    fprintf(stderr, "Usage: foo <n>\n");
    exit(1); 
  } */

  // n = atoi(argv[1]);
  foo(99);

  return 0;
}
