/*
 * This file is part of "cxx_sandbox" application.
 *
 * Copyright © 2016 Maksym Stupakov <maksym.stupakov@gmail.com>
 * This file is free software, distributed under the MIT License.
 */

#include <stdlib.h>
#include <libgen.h>

#define ___USER___
#include <k_io.h>

void __assert_fail(void) {}

long int strtol(const char *nptr, char **endptr, int base) {   
  long res = 0;
  __k_kstrtoul(nptr, base, &res);
  return res;
}

long long int strtoll(const char *nptr, char **endptr, int base) {   
  long long res = 0;
  __k_kstrtoll(nptr, base, &res);
  return res;
}

int rand(void) {
  int i = 0;
  
  __k_get_random_bytes(&i, sizeof(i));
  return i;
}

int rand_r(unsigned int *seedp) {
  return 0;
}

void srand(unsigned int seed) {
}