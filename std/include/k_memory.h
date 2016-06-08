/*
 * This file is part of "cxx_sandbox" application.
 *
 * Copyright © 2016 Maksym Stupakov <maksym.stupakov@gmail.com>
 * This file is free software, distributed under the MIT License.
 */

#ifndef __MEMORY_H__
#define __MEMORY_H__

void* __k_malloc(long unsigned int sz);
void __k_free(void* p);

#endif /* __MEMORY_H__ */
