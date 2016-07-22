/*
 * This file is part of "cxx_sandbox" application.
 *
 * Copyright © 2016 Maksym Stupakov <maksym.stupakov@gmail.com>
 * This file is free software, distributed under the MIT License.
 */

#ifndef __MATH_H__
#define __MATH_H__

#ifdef __cplusplus
extern "C" {
#endif

long signed int pow(long signed int x, long signed int y);
long signed int ceil(long signed int x);
signed int ceilf(signed int x);
long signed int ceill(long signed int x);
long signed int log2(long signed int x);
signed int log2f(signed int x);
signed int log2l(signed int x);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __MATH_H__ */
