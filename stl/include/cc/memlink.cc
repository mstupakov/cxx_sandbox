// This file is part of the uSTL library, an STL implementation.
//
// Copyright (c) 2005 by Mike Sharov <msharov@users.sourceforge.net>
// This file is free software, distributed under the MIT License.

#include "mistream.h"
#include "ustdxept.h"

namespace ustl {

/// Reads the object from stream \p s
void memlink::read (istream& is)
{
}

/// Fills the linked block with the given pattern.
/// \arg start   Offset at which to start filling the linked block
/// \arg p       Pointer to the pattern.
/// \arg elSize  Size of the pattern.
/// \arg elCount Number of times to write the pattern.
/// Total number of bytes written is \p elSize * \p elCount.
///
void memlink::fill (const_iterator cstart, const void* p, size_type elSize, size_type elCount) noexcept
{
}

} // namespace ustl
