/*
 * This file is part of "cxx_sandbox" application.
 *
 * Copyright © 2016 Maksym Stupakov <maksym.stupakov@gmail.com>
 * This file is free software, distributed under the MIT License.
 */

#include <stdlib.h>
 
int __cxa_guard_acquire(void* p) {
  return 0;
}

void __cxa_guard_release(void* p) {
}

void __cxa_guard_abort(void* p) {
}

void __cxa_pure_virtual(void) {
}

char* __cxa_demangle(const char* mangled_name,
                     char* output_buffer, size_t* length,
                     int* status) {
  return 0;
}

