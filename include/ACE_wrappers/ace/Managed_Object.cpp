// $Id: Managed_Object.cpp 14 2007-02-01 15:49:12Z mitza $

#ifndef ACE_MANAGED_OBJECT_CPP
#define ACE_MANAGED_OBJECT_CPP

#include "ace/Managed_Object.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if !defined (__ACE_INLINE__)
#include "ace/Managed_Object.inl"
#endif /* __ACE_INLINE__ */

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

template <class TYPE>
ACE_Cleanup_Adapter<TYPE>::~ACE_Cleanup_Adapter (void)
{
}

ACE_END_VERSIONED_NAMESPACE_DECL

#endif /* ACE_MANAGED_OBJECT_CPP */
