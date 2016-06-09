/*
 * This file is part of "cxx_sandbox" application.
 *
 * Copyright © 2016 Maksym Stupakov <maksym.stupakov@gmail.com>
 * This file is free software, distributed under the MIT License.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <k_memory.h>

typedef struct {
  size_t size;
} malloc_hdr_t;

void *malloc(size_t sz) {
  printf("Func: %s, line: %u, %u\r\n", __PRETTY_FUNCTION__, __LINE__, sz);

  void *p = __k_malloc(sz + sizeof(malloc_hdr_t));
  ((malloc_hdr_t*) p)->size = sz;  
  return p + sizeof(malloc_hdr_t);
}

void free(void *p) {
  printf("Func: %s, line: %u, %x\r\n", __PRETTY_FUNCTION__, __LINE__, p);

  if (!p) {
    return;
  }
  
  __k_free(p - sizeof(malloc_hdr_t));
}

void *calloc(size_t nmemb, size_t sz) {
  printf("Func: %s, line: %u\r\n", __PRETTY_FUNCTION__, __LINE__);

  void *p = malloc(nmemb * sz);

  if (p) {
    memset(p, 0, nmemb * sz);	
  }
  
  return p;
}

void *realloc(void *p, size_t sz) {
  printf("Func: %s, line: %u, %x, %u\r\n", __PRETTY_FUNCTION__, __LINE__, p, sz);

  if (!p) {
    return malloc(sz);
  }

  if (p && !sz) {
    free(p);
    return 0;
  }

  void *ptr = malloc(sz);

  printf("Func: %s, line: %u, %p, %d\r\n", __FUNCTION__, __LINE__, p, sz);

  if (ptr) {
    size_t size = ((malloc_hdr_t*) (p - sizeof(malloc_hdr_t)))->size;
    memcpy(ptr, p, size);
    free(p);
  }

  return ptr;
}
