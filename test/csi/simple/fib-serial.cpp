/*
 * Copyright (c) 1994-2003 Massachusetts Institute of Technology
 * Copyright (c) 2003 Bradley C. Kuszmaul
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#include <stdlib.h>
#include <stdio.h>

int fib(int n, int work) { 
  if (n < 2) { 
    return (n);
  } else {
    int x, y;
    x = fib(n - 1, work);
    y = fib(n - 2, work);
    volatile int a = 0;
    for (int i = 0; i < work; i++)
        a += i;
    return (x + y);
  }
}

int main(int argc, char *argv[]) {

  int n, work, result;

  if (argc != 3) {
    fprintf(stderr, "Usage: fib [<cilk options>] <n>\n");
    exit(1); 
  }

  n = atoi(argv[1]);
  work = atoi(argv[2]);
  result = fib(n, work);

  printf("Result: %d\n", result);

  return 0;
}
