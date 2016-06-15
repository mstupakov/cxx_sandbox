/*
 * This file is part of "cxx_sandbox" application.
 *
 * Copyright © 2016 Maksym Stupakov <maksym.stupakov@gmail.com>
 * This file is free software, distributed under the MIT License.
 */

#include <math.h>

static long signed int pow_local(long signed int x, long signed int y) {
  int i = 0;
  long signed int res = 1;

  for (i = 0; i < y; i++) {
    res *= x;
  }

  return res;
}

long signed int pow(long signed int x, long signed int y) {   
  if (x == 2) {   
    return (1 << y);
  }
  return pow_local(x, y);
}

long signed int ceil(long signed int x) {
  return 0;
}

signed int ceilf(signed int x) {
  return 0;
}

long signed int ceill(long signed int x) {
  return 0;
}

long signed int log2(long signed int x) {
  return __k_ilog2(x);
}

signed int log2f(signed int x) {
  return 0;
}

signed int log2l(signed int x) {
  return 0;
}
