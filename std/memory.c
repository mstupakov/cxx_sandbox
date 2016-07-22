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

#define KMALLOC_LIMIT 4000

typedef struct {
  size_t size;
} malloc_hdr_t;

void* __attribute__((weak)) malloc(size_t sz) {
  void *p = NULL;
  
  if (sz < KMALLOC_LIMIT) {
      p = __k_kmalloc(sz + sizeof(malloc_hdr_t));
  } else {
      p = __k_vmalloc(sz + sizeof(malloc_hdr_t));
  }

  memset(p + sizeof(malloc_hdr_t), 0, sz);
  ((malloc_hdr_t*) p)->size = sz;  
  return p + sizeof(malloc_hdr_t);
}

void __attribute__((weak)) free(void *p) {
  size_t size;

  if (!p) {
    return;
  }

  size = ((malloc_hdr_t*) (p - sizeof(malloc_hdr_t)))->size;
  if (size < KMALLOC_LIMIT) {
      __k_kfree(p - sizeof(malloc_hdr_t)); 
  } else {
      __k_vfree(p - sizeof(malloc_hdr_t));
  }
}

void* __attribute__((weak)) calloc(size_t nmemb, size_t sz) {
  void *p = malloc(nmemb * sz);

  if (p) {
    memset(p, 0, nmemb * sz);	
  }
  
  return p;
}

void* __attribute__((weak)) realloc(void *p, size_t sz) {
  if (!p) {
    return malloc(sz);
  }

  if (p && !sz) {
    free(p);
    return 0;
  }

  void *ptr = malloc(sz);

  if (ptr) {
    size_t size = ((malloc_hdr_t*) (p - sizeof(malloc_hdr_t)))->size;
    memcpy(ptr, p, size);
    free(p);
  }

  return ptr;
}
