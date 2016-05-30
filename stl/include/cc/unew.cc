// This file is part of the uSTL library, an STL implementation.
//
// Copyright (c) 2005 by Mike Sharov <msharov@users.sourceforge.net>
// This file is free software, distributed under the MIT License.

#include "unew.h"

void* tmalloc (size_t n)
{
    void* p = malloc (n);
    return p;
}

void nfree (void* p) noexcept
{
    if (p)
	free (p);
}


void* operator new (size_t n)	{ return tmalloc(n); }
void* operator new[] (size_t n)	{ return tmalloc(n); }

void  operator delete (void* p) noexcept	{ nfree(p); }
void  operator delete[] (void* p) noexcept	{ nfree(p); }
