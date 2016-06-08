/*
 * This file is part of "cxx_sandbox" application.
 *
 * Copyright © 2016 Maksym Stupakov <maksym.stupakov@gmail.com>
 * This file is free software, distributed under the MIT License.
 */

#include <stdlib.h>
#include <string.h>

#define ___USER___
#include <k_memory.h>

typedef struct {
  size_t size;
} malloc_hdr_t;

void *malloc(size_t sz) {
  void *p = __k_malloc(sz + sizeof(malloc_hdr_t));
  ((malloc_hdr_t*) p)->size = sz;  
  return p + sizeof(malloc_hdr_t);
}

void free(void *p) {
  __k_free(p - sizeof(malloc_hdr_t));
}

void *calloc(size_t nmemb, size_t sz) {
  void *p = malloc(nmemb * sz);

  if (p) {
    memset(p, 0, nmemb * sz);	
  }
  
  return p;
}

void *realloc(void *p, size_t sz) {
  void *ptr = malloc(sz);

  if (ptr) {
    size_t size = ((malloc_hdr_t*) (p - sizeof(malloc_hdr_t)))->size;
    memcpy(ptr, p, size);
    free(p);
  }

  return ptr;
}
