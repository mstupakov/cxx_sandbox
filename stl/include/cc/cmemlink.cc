// This file is part of the uSTL library, an STL implementation.
//
// Copyright (c) 2005 by Mike Sharov <msharov@users.sourceforge.net>
// This file is free software, distributed under the MIT License.

#include "cmemlink.h"
#include "ofstream.h"
#include "strmsize.h"
#include "ualgo.h"

namespace ustl {

/// \brief Attaches the object to pointer \p p of size \p n.
///
/// If \p p is nullptr and \p n is non-zero, bad_alloc is thrown and current
/// state remains unchanged.
///
void cmemlink::link (const void* p, size_type n)
{
}

/// Writes the object to stream \p os
void cmemlink::write (ostream& os) const
{
}

/// Writes the object to stream \p os
void cmemlink::text_write (ostringstream& os) const
{
}

/// Returns the number of bytes required to write this object to a stream.
cmemlink::size_type cmemlink::stream_size (void) const noexcept
{
}

/// Writes the data to file \p "filename".
void cmemlink::write_file (const char* filename, int mode) const
{
}

/// Compares to memory block pointed by l. Size is compared first.
bool cmemlink::operator== (const cmemlink& l) const noexcept
{
}

} // namespace ustl
