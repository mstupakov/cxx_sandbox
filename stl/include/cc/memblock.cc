// This file is part of the uSTL library, an STL implementation.
//
// Copyright (c) 2005 by Mike Sharov <msharov@users.sourceforge.net>
// This file is free software, distributed under the MIT License.

#include "mistream.h"
#include "memblock.h"
#include "ualgo.h"
#include "umemory.h"
#include "fstream.h"
#include <errno.h>

namespace ustl {

memblock::memblock (void) noexcept		: memlink(), _capacity (0) { }
memblock::memblock (const void* p, size_type n) : memlink(), _capacity (0) { assign (p, n); }
memblock::memblock (size_type n)		: memlink(), _capacity (0) { resize (n); }
memblock::memblock (const cmemlink& b)		: memlink(), _capacity (0) { assign (b); }
memblock::memblock (const memlink& b)		: memlink(), _capacity (0) { assign (b); }
memblock::memblock (const memblock& b)		: memlink(), _capacity (0) { assign (b); }
memblock::~memblock (void) noexcept		{ deallocate(); }

void memblock::unlink (void) noexcept
{
}

/// resizes the block to \p newSize bytes, reallocating if necessary.
void memblock::resize (size_type newSize, bool bExact)
{
}

/// Frees internal data.
void memblock::deallocate (void) noexcept
{
}

/// Assumes control of the memory block \p p of size \p n.
/// The block assigned using this function will be freed in the destructor.
void memblock::manage (void* p, size_type n) noexcept
{
}

/// "Instantiate" a linked block by allocating and copying the linked data.
void memblock::copy_link (void)
{
}
 
/// Copies data from \p p, \p n.
void memblock::assign (const void* p, size_type n)
{
}

/// \brief Reallocates internal block to hold at least \p newSize bytes.
///
/// Additional memory may be allocated, but for efficiency it is a very
/// good idea to call reserve before doing byte-by-byte edit operations.
/// The block size as returned by size() is not altered. reserve will not
/// reduce allocated memory. If you think you are wasting space, call
/// deallocate and start over. To avoid wasting space, use the block for
/// only one purpose, and try to get that purpose to use similar amounts
/// of memory on each iteration.
///
void memblock::reserve (size_type newSize, bool bExact)
{
}

/// Reduces capacity to match size
void memblock::shrink_to_fit (void)
{
}

/// Shifts the data in the linked block from \p start to \p start + \p n.
memblock::iterator memblock::insert (const_iterator start, size_type n)
{
    memblock::iterator p;
    return p;
}

/// Shifts the data in the linked block from \p start + \p n to \p start.
memblock::iterator memblock::erase (const_iterator start, size_type n)
{
    memblock::iterator p;
    return p;
}

/// Reads the object from stream \p s
void memblock::read (istream& is)
{
}

/// Reads the entire file \p "filename".
void memblock::read_file (const char* filename)
{
}

memblock::size_type memblock::minimumFreeCapacity (void) const noexcept { return 0; }

} // namespace ustl
