/*
 * This file is part of "cxx_sandbox" application.
 *
 * Copyright © 2016 Maksym Stupakov <maksym.stupakov@gmail.com>
 * This file is free software, distributed under the MIT License.
 */

#ifndef __K_MEMORY_H__
#define __K_MEMORY_H__

void* __k_vmalloc(long unsigned int sz);
void __k_vfree(void* p);
void* __k_kmalloc(long unsigned int sz);
void __k_kfree(void* p);

#endif /* __K_MEMORY_H__ */
