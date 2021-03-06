// -*- C++ -*- Common throw conditions.
// Copyright (C) 1994, 1995, 1996, 1997, 1998, 1999, 2000, 2001, 2009, 2011
// Free Software Foundation
//
// This file is part of GCC.
//
// GCC is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3, or (at your option)
// any later version.
//
// GCC is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// Under Section 7 of GPL version 3, you are granted additional
// permissions described in the GCC Runtime Library Exception, version
// 3.1, as published by the Free Software Foundation.
//
// You should have received a copy of the GNU General Public License and
// a copy of the GCC Runtime Library Exception along with this program;
// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
// <http://www.gnu.org/licenses/>.

#include "typeinfo"
#include <exception>
#include <cstdlib>
#include "cxxabi.h"
//#include "unwind-cxx.h"
//#include <bits/exception_defines.h>

extern "C" void
__cxxabiv1::__cxa_bad_cast ()
{
#ifdef __EXCEPTIONS
  throw std::bad_cast();
#else
  std::abort();
#endif
}

extern "C" void
__cxxabiv1::__cxa_bad_typeid ()
{
#ifdef __EXCEPTIONS
  throw std::bad_typeid();
#else
  std::abort();
#endif
}

