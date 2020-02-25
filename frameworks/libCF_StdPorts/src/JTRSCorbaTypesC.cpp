// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v2.0a
 * TAO and the TAO IDL Compiler have been developed by:
 *       Center for Distributed Object Computing
 *       Washington University
 *       St. Louis, MO
 *       USA
 *       http://www.cs.wustl.edu/~schmidt/doc-center.html
 * and
 *       Distributed Object Computing Laboratory
 *       University of California at Irvine
 *       Irvine, CA
 *       USA
 * and
 *       Institute for Software Integrated Systems
 *       Vanderbilt University
 *       Nashville, TN
 *       USA
 *       http://www.isis.vanderbilt.edu/
 *
 * Information about TAO is available at:
 *     http://www.cs.wustl.edu/~schmidt/TAO.html
 **/

// TAO_IDL - Generated from
// .\be\be_codegen.cpp:375


#include "../include/JTRSCorbaTypesC.h"
#include "tao/AnyTypeCode/Null_RefCount_Policy.h"
#include "tao/AnyTypeCode/TypeCode_Constants.h"
#include "tao/AnyTypeCode/Alias_TypeCode_Static.h"
#include "tao/AnyTypeCode/Sequence_TypeCode_Static.h"
#include "tao/AnyTypeCode/Struct_TypeCode_Static.h"
#include "tao/AnyTypeCode/TypeCode_Struct_Field.h"
#include "tao/CDR.h"
#include "tao/SystemException.h"
#include "tao/CDR.h"
#include "tao/AnyTypeCode/Any_Dual_Impl_T.h"
#include "ace/OS_NS_string.h"

#if !defined (__ACE_INLINE__)
#include "../include/JTRSCorbaTypesC.inl"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/alias_typecode.cpp:50

static TAO::TypeCode::Alias<char const *,
                            ::CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_JTRS_ExtEnum (
    ::CORBA::tk_alias,
    "IDL:JTRS/ExtEnum:1.0",
    "ExtEnum",
    &CORBA::_tc_ushort);
  

namespace JTRS
{
  ::CORBA::TypeCode_ptr const _tc_ExtEnum =
    &_tao_tc_JTRS_ExtEnum;
}

// TAO_IDL - Generated from 
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_JTRS_EXTENUMSEQUENCE_CS_)
#define _JTRS_EXTENUMSEQUENCE_CS_

JTRS::ExtEnumSequence::ExtEnumSequence (void)
{}

JTRS::ExtEnumSequence::ExtEnumSequence (
    ::CORBA::ULong max)
  : ::TAO::unbounded_value_sequence<
        ExtEnum
      > (max)
{}

JTRS::ExtEnumSequence::ExtEnumSequence (
    ::CORBA::ULong max,
    ::CORBA::ULong length,
    ::CORBA::UShort * buffer,
    ::CORBA::Boolean release
  )
  : ::TAO::unbounded_value_sequence<
        ExtEnum
      >
    (max, length, buffer, release)
{}

JTRS::ExtEnumSequence::ExtEnumSequence (
    const ExtEnumSequence &seq)
  : ::TAO::unbounded_value_sequence<
        ExtEnum
      > (seq)
{}

JTRS::ExtEnumSequence::~ExtEnumSequence (void)
{}

void JTRS::ExtEnumSequence::_tao_any_destructor (
    void * _tao_void_pointer)
{
  ExtEnumSequence * _tao_tmp_pointer =
    static_cast<ExtEnumSequence *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/alias_typecode.cpp:50



// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/typecode_defn.cpp:460


#ifndef _TAO_TYPECODE_JTRS_ExtEnumSequence_GUARD
#define _TAO_TYPECODE_JTRS_ExtEnumSequence_GUARD

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

namespace TAO
{
  namespace TypeCode
  {
    namespace
    {
      TAO::TypeCode::Sequence< ::CORBA::TypeCode_ptr const *,
                              TAO::Null_RefCount_Policy>
        JTRS_ExtEnumSequence_0 (
          ::CORBA::tk_sequence,
          &JTRS::_tc_ExtEnum,
          0U);
        
      ::CORBA::TypeCode_ptr const tc_JTRS_ExtEnumSequence_0 =
        &JTRS_ExtEnumSequence_0;
    }
  }
}

TAO_END_VERSIONED_NAMESPACE_DECL

#endif /* _TAO_TYPECODE_JTRS_ExtEnumSequence_GUARD */

static TAO::TypeCode::Alias<char const *,
                            ::CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_JTRS_ExtEnumSequence (
    ::CORBA::tk_alias,
    "IDL:JTRS/ExtEnumSequence:1.0",
    "ExtEnumSequence",
    &TAO::TypeCode::tc_JTRS_ExtEnumSequence_0);
  

namespace JTRS
{
  ::CORBA::TypeCode_ptr const _tc_ExtEnumSequence =
    &_tao_tc_JTRS_ExtEnumSequence;
}

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/alias_typecode.cpp:50

static TAO::TypeCode::Alias<char const *,
                            ::CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_JTRS_OctetSequence (
    ::CORBA::tk_alias,
    "IDL:JTRS/OctetSequence:1.0",
    "OctetSequence",
    &CF::_tc_OctetSequence);
  

namespace JTRS
{
  ::CORBA::TypeCode_ptr const _tc_OctetSequence =
    &_tao_tc_JTRS_OctetSequence;
}

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/alias_typecode.cpp:50

static TAO::TypeCode::Alias<char const *,
                            ::CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_JTRS_StringSequence (
    ::CORBA::tk_alias,
    "IDL:JTRS/StringSequence:1.0",
    "StringSequence",
    &CF::_tc_StringSequence);
  

namespace JTRS
{
  ::CORBA::TypeCode_ptr const _tc_StringSequence =
    &_tao_tc_JTRS_StringSequence;
}

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/alias_typecode.cpp:50

static TAO::TypeCode::Alias<char const *,
                            ::CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_JTRS_BooleanSequence (
    ::CORBA::tk_alias,
    "IDL:JTRS/BooleanSequence:1.0",
    "BooleanSequence",
    &PortTypes::_tc_BooleanSequence);
  

namespace JTRS
{
  ::CORBA::TypeCode_ptr const _tc_BooleanSequence =
    &_tao_tc_JTRS_BooleanSequence;
}

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/alias_typecode.cpp:50

static TAO::TypeCode::Alias<char const *,
                            ::CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_JTRS_CharSequence (
    ::CORBA::tk_alias,
    "IDL:JTRS/CharSequence:1.0",
    "CharSequence",
    &PortTypes::_tc_CharSequence);
  

namespace JTRS
{
  ::CORBA::TypeCode_ptr const _tc_CharSequence =
    &_tao_tc_JTRS_CharSequence;
}

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/alias_typecode.cpp:50

static TAO::TypeCode::Alias<char const *,
                            ::CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_JTRS_LongLongSequence (
    ::CORBA::tk_alias,
    "IDL:JTRS/LongLongSequence:1.0",
    "LongLongSequence",
    &PortTypes::_tc_LongLongSequence);
  

namespace JTRS
{
  ::CORBA::TypeCode_ptr const _tc_LongLongSequence =
    &_tao_tc_JTRS_LongLongSequence;
}

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/alias_typecode.cpp:50

static TAO::TypeCode::Alias<char const *,
                            ::CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_JTRS_LongSequence (
    ::CORBA::tk_alias,
    "IDL:JTRS/LongSequence:1.0",
    "LongSequence",
    &PortTypes::_tc_LongSequence);
  

namespace JTRS
{
  ::CORBA::TypeCode_ptr const _tc_LongSequence =
    &_tao_tc_JTRS_LongSequence;
}

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/alias_typecode.cpp:50

static TAO::TypeCode::Alias<char const *,
                            ::CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_JTRS_ShortSequence (
    ::CORBA::tk_alias,
    "IDL:JTRS/ShortSequence:1.0",
    "ShortSequence",
    &PortTypes::_tc_ShortSequence);
  

namespace JTRS
{
  ::CORBA::TypeCode_ptr const _tc_ShortSequence =
    &_tao_tc_JTRS_ShortSequence;
}

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/alias_typecode.cpp:50

static TAO::TypeCode::Alias<char const *,
                            ::CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_JTRS_UlongLongSequence (
    ::CORBA::tk_alias,
    "IDL:JTRS/UlongLongSequence:1.0",
    "UlongLongSequence",
    &PortTypes::_tc_UlongLongSequence);
  

namespace JTRS
{
  ::CORBA::TypeCode_ptr const _tc_UlongLongSequence =
    &_tao_tc_JTRS_UlongLongSequence;
}

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/alias_typecode.cpp:50

static TAO::TypeCode::Alias<char const *,
                            ::CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_JTRS_UlongSequence (
    ::CORBA::tk_alias,
    "IDL:JTRS/UlongSequence:1.0",
    "UlongSequence",
    &PortTypes::_tc_UlongSequence);
  

namespace JTRS
{
  ::CORBA::TypeCode_ptr const _tc_UlongSequence =
    &_tao_tc_JTRS_UlongSequence;
}

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/alias_typecode.cpp:50

static TAO::TypeCode::Alias<char const *,
                            ::CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_JTRS_UshortSequence (
    ::CORBA::tk_alias,
    "IDL:JTRS/UshortSequence:1.0",
    "UshortSequence",
    &PortTypes::_tc_UshortSequence);
  

namespace JTRS
{
  ::CORBA::TypeCode_ptr const _tc_UshortSequence =
    &_tao_tc_JTRS_UshortSequence;
}

// TAO_IDL - Generated from 
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_exception/exception_cs.cpp:101

JTRS::InvalidParameter::InvalidParameter (void)
  : ::CORBA::UserException (
        "IDL:JTRS/InvalidParameter:1.0",
        "InvalidParameter"
      )
{
}

JTRS::InvalidParameter::~InvalidParameter (void)
{
}

JTRS::InvalidParameter::InvalidParameter (const ::JTRS::InvalidParameter &_tao_excp)
  : ::CORBA::UserException (
        _tao_excp._rep_id (),
        _tao_excp._name ()
      )
{
}

JTRS::InvalidParameter&
JTRS::InvalidParameter::operator= (const ::JTRS::InvalidParameter &_tao_excp)
{
  this->::CORBA::UserException::operator= (_tao_excp);
  return *this;
}

void JTRS::InvalidParameter::_tao_any_destructor (void *_tao_void_pointer)
{
  InvalidParameter *_tao_tmp_pointer =
    static_cast<InvalidParameter *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

JTRS::InvalidParameter *
JTRS::InvalidParameter::_downcast ( ::CORBA::Exception *_tao_excp)
{
  return dynamic_cast<InvalidParameter *> (_tao_excp);
}

const JTRS::InvalidParameter *
JTRS::InvalidParameter::_downcast ( ::CORBA::Exception const *_tao_excp)
{
  return dynamic_cast<const InvalidParameter *> (_tao_excp);
}

::CORBA::Exception *JTRS::InvalidParameter::_alloc (void)
{
  ::CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::JTRS::InvalidParameter, 0);
  return retval;
}

::CORBA::Exception *
JTRS::InvalidParameter::_tao_duplicate (void) const
{
  ::CORBA::Exception *result = 0;
  ACE_NEW_RETURN (
      result,
      ::JTRS::InvalidParameter (*this),
      0
    );
  return result;
}

void JTRS::InvalidParameter::_raise (void) const
{
  throw *this;
}

void JTRS::InvalidParameter::_tao_encode (TAO_OutputCDR &cdr) const
{
  if (!(cdr << *this))
    {
      throw ::CORBA::MARSHAL ();
    }
}

void JTRS::InvalidParameter::_tao_decode (TAO_InputCDR &cdr)
{
  if (!(cdr >> *this))
    {
      throw ::CORBA::MARSHAL ();
    }
}

// TAO extension - the virtual _type method.
::CORBA::TypeCode_ptr JTRS::InvalidParameter::_tao_type (void) const
{
  return ::JTRS::_tc_InvalidParameter;
}

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/struct_typecode.cpp:86

static TAO::TypeCode::Struct_Field<
  char const *,
  ::CORBA::TypeCode_ptr const *> const * const 
    _tao_fields_JTRS_InvalidParameter = 0;
  
static TAO::TypeCode::Struct<
  char const *,
  ::CORBA::TypeCode_ptr const *,
  TAO::TypeCode::Struct_Field<
    char const *,
    ::CORBA::TypeCode_ptr const *> const *,
  TAO::Null_RefCount_Policy>
_tao_tc_JTRS_InvalidParameter (
  ::CORBA::tk_except,
  "IDL:JTRS/InvalidParameter:1.0",
  "InvalidParameter",
  _tao_fields_JTRS_InvalidParameter,
  0);


namespace JTRS
{
  ::CORBA::TypeCode_ptr const _tc_InvalidParameter =
    &_tao_tc_JTRS_InvalidParameter;
}

// TAO_IDL - Generated from 
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_exception/exception_cs.cpp:101

JTRS::Unsupported::Unsupported (void)
  : ::CORBA::UserException (
        "IDL:JTRS/Unsupported:1.0",
        "Unsupported"
      )
{
}

JTRS::Unsupported::~Unsupported (void)
{
}

JTRS::Unsupported::Unsupported (const ::JTRS::Unsupported &_tao_excp)
  : ::CORBA::UserException (
        _tao_excp._rep_id (),
        _tao_excp._name ()
      )
{
}

JTRS::Unsupported&
JTRS::Unsupported::operator= (const ::JTRS::Unsupported &_tao_excp)
{
  this->::CORBA::UserException::operator= (_tao_excp);
  return *this;
}

void JTRS::Unsupported::_tao_any_destructor (void *_tao_void_pointer)
{
  Unsupported *_tao_tmp_pointer =
    static_cast<Unsupported *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

JTRS::Unsupported *
JTRS::Unsupported::_downcast ( ::CORBA::Exception *_tao_excp)
{
  return dynamic_cast<Unsupported *> (_tao_excp);
}

const JTRS::Unsupported *
JTRS::Unsupported::_downcast ( ::CORBA::Exception const *_tao_excp)
{
  return dynamic_cast<const Unsupported *> (_tao_excp);
}

::CORBA::Exception *JTRS::Unsupported::_alloc (void)
{
  ::CORBA::Exception *retval = 0;
  ACE_NEW_RETURN (retval, ::JTRS::Unsupported, 0);
  return retval;
}

::CORBA::Exception *
JTRS::Unsupported::_tao_duplicate (void) const
{
  ::CORBA::Exception *result = 0;
  ACE_NEW_RETURN (
      result,
      ::JTRS::Unsupported (*this),
      0
    );
  return result;
}

void JTRS::Unsupported::_raise (void) const
{
  throw *this;
}

void JTRS::Unsupported::_tao_encode (TAO_OutputCDR &cdr) const
{
  if (!(cdr << *this))
    {
      throw ::CORBA::MARSHAL ();
    }
}

void JTRS::Unsupported::_tao_decode (TAO_InputCDR &cdr)
{
  if (!(cdr >> *this))
    {
      throw ::CORBA::MARSHAL ();
    }
}

// TAO extension - the virtual _type method.
::CORBA::TypeCode_ptr JTRS::Unsupported::_tao_type (void) const
{
  return ::JTRS::_tc_Unsupported;
}

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/struct_typecode.cpp:86

static TAO::TypeCode::Struct_Field<
  char const *,
  ::CORBA::TypeCode_ptr const *> const * const 
    _tao_fields_JTRS_Unsupported = 0;
  
static TAO::TypeCode::Struct<
  char const *,
  ::CORBA::TypeCode_ptr const *,
  TAO::TypeCode::Struct_Field<
    char const *,
    ::CORBA::TypeCode_ptr const *> const *,
  TAO::Null_RefCount_Policy>
_tao_tc_JTRS_Unsupported (
  ::CORBA::tk_except,
  "IDL:JTRS/Unsupported:1.0",
  "Unsupported",
  _tao_fields_JTRS_Unsupported,
  0);


namespace JTRS
{
  ::CORBA::TypeCode_ptr const _tc_Unsupported =
    &_tao_tc_JTRS_Unsupported;
}

// TAO_IDL - Generated from 
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_sequence/any_op_cs.cpp:46


TAO_BEGIN_VERSIONED_NAMESPACE_DECL


TAO_END_VERSIONED_NAMESPACE_DECL



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace JTRS
{
  
  // Copying insertion.
  void operator<<= (
      ::CORBA::Any &_tao_any,
      const ::JTRS::ExtEnumSequence &_tao_elem
    )
  {
    if (0 == &_tao_elem) // Trying to de-reference NULL object
      _tao_any <<= static_cast< ::JTRS::ExtEnumSequence *>( 0 ); // Use non-copying insertion of a NULL
    else
      TAO::Any_Dual_Impl_T< ::JTRS::ExtEnumSequence>::insert_copy (
          _tao_any,
          ::JTRS::ExtEnumSequence::_tao_any_destructor,
          ::JTRS::_tc_ExtEnumSequence,
          _tao_elem
        );
  }

  // Non-copying insertion.
  void operator<<= (
      ::CORBA::Any &_tao_any,
      ::JTRS::ExtEnumSequence *_tao_elem
    )
  {
    TAO::Any_Dual_Impl_T< ::JTRS::ExtEnumSequence>::insert (
        _tao_any,
        ::JTRS::ExtEnumSequence::_tao_any_destructor,
        ::JTRS::_tc_ExtEnumSequence,
        _tao_elem
      );
  }

  // Extraction to non-const pointer (deprecated).
  ::CORBA::Boolean operator>>= (
      const ::CORBA::Any &_tao_any,
      ::JTRS::ExtEnumSequence *&_tao_elem
    )
  {
    return _tao_any >>= const_cast<
        const ::JTRS::ExtEnumSequence *&> (
        _tao_elem
      );
  }

  // Extraction to const pointer.
  ::CORBA::Boolean operator>>= (
      const ::CORBA::Any &_tao_any,
      const ::JTRS::ExtEnumSequence *&_tao_elem
    )
  {
    return
      TAO::Any_Dual_Impl_T< ::JTRS::ExtEnumSequence>::extract (
          _tao_any,
          ::JTRS::ExtEnumSequence::_tao_any_destructor,
          ::JTRS::_tc_ExtEnumSequence,
          _tao_elem
        );
  }
}

#else


TAO_BEGIN_VERSIONED_NAMESPACE_DECL


// Copying insertion.
void operator<<= (
    ::CORBA::Any &_tao_any,
    const JTRS::ExtEnumSequence &_tao_elem
  )
{
  if (0 == &_tao_elem) // Trying to de-reference NULL object
    _tao_any <<= static_cast<JTRS::ExtEnumSequence *>( 0 ); // Use non-copying insertion of a NULL
  else
    TAO::Any_Dual_Impl_T<JTRS::ExtEnumSequence>::insert_copy (
        _tao_any,
        JTRS::ExtEnumSequence::_tao_any_destructor,
        JTRS::_tc_ExtEnumSequence,
        _tao_elem
      );
}

// Non-copying insertion.
void operator<<= (
    ::CORBA::Any &_tao_any,
    JTRS::ExtEnumSequence *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<JTRS::ExtEnumSequence>::insert (
      _tao_any,
      JTRS::ExtEnumSequence::_tao_any_destructor,
      JTRS::_tc_ExtEnumSequence,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
::CORBA::Boolean operator>>= (
    const ::CORBA::Any &_tao_any,
    JTRS::ExtEnumSequence *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const JTRS::ExtEnumSequence *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
::CORBA::Boolean operator>>= (
    const ::CORBA::Any &_tao_any,
    const JTRS::ExtEnumSequence *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<JTRS::ExtEnumSequence>::extract (
        _tao_any,
        JTRS::ExtEnumSequence::_tao_any_destructor,
        JTRS::_tc_ExtEnumSequence,
        _tao_elem
      );
}
TAO_END_VERSIONED_NAMESPACE_DECL



#endif

// TAO_IDL - Generated from 
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_exception/any_op_cs.cpp:45
TAO_BEGIN_VERSIONED_NAMESPACE_DECL



namespace TAO
{
  template<>
  ::CORBA::Boolean
  Any_Dual_Impl_T<JTRS::InvalidParameter>::demarshal_value (
      TAO_InputCDR & cdr
    )
  {
    ::CORBA::String_var id;

    if (!(cdr >> id.out ()))
      {
        return false;
      }
    
    try
      {
        this->value_->_tao_decode (cdr);
      }
    catch (const ::CORBA::Exception &)
      {
        return false;
      }

    return true;
  }
}
TAO_END_VERSIONED_NAMESPACE_DECL



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace JTRS
{
  

  // Copying insertion.
  void operator<<= (
      ::CORBA::Any &_tao_any,
      const ::JTRS::InvalidParameter &_tao_elem
    )
  {
    TAO::Any_Dual_Impl_T< ::JTRS::InvalidParameter>::insert_copy (
        _tao_any,
        ::JTRS::InvalidParameter::_tao_any_destructor,
        ::JTRS::_tc_InvalidParameter,
        _tao_elem
      );
  }

  // Non-copying insertion.
  void operator<<= (
      ::CORBA::Any &_tao_any,
      ::JTRS::InvalidParameter *_tao_elem
    )
  {
    TAO::Any_Dual_Impl_T< ::JTRS::InvalidParameter>::insert (
        _tao_any,
        ::JTRS::InvalidParameter::_tao_any_destructor,
        ::JTRS::_tc_InvalidParameter,
        _tao_elem
      );
  }

  // Extraction to non-const pointer (deprecated).
  ::CORBA::Boolean operator>>= (
      const ::CORBA::Any &_tao_any,
      ::JTRS::InvalidParameter *&_tao_elem
    )
  {
    return _tao_any >>= const_cast<
        const ::JTRS::InvalidParameter *&> (
        _tao_elem
      );
  }

  // Extraction to const pointer.
  ::CORBA::Boolean operator>>= (
      const ::CORBA::Any &_tao_any,
      const ::JTRS::InvalidParameter *&_tao_elem
    )
  {
    return
      TAO::Any_Dual_Impl_T< ::JTRS::InvalidParameter>::extract (
          _tao_any,
          ::JTRS::InvalidParameter::_tao_any_destructor,
          ::JTRS::_tc_InvalidParameter,
          _tao_elem
        );
  }
}

#else

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// Copying insertion.
void operator<<= (
    ::CORBA::Any &_tao_any,
    const JTRS::InvalidParameter &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<JTRS::InvalidParameter>::insert_copy (
      _tao_any,
      JTRS::InvalidParameter::_tao_any_destructor,
      JTRS::_tc_InvalidParameter,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    ::CORBA::Any &_tao_any,
    JTRS::InvalidParameter *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<JTRS::InvalidParameter>::insert (
      _tao_any,
      JTRS::InvalidParameter::_tao_any_destructor,
      JTRS::_tc_InvalidParameter,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
::CORBA::Boolean operator>>= (
    const ::CORBA::Any &_tao_any,
    JTRS::InvalidParameter *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const JTRS::InvalidParameter *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
::CORBA::Boolean operator>>= (
    const ::CORBA::Any &_tao_any,
    const JTRS::InvalidParameter *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<JTRS::InvalidParameter>::extract (
        _tao_any,
        JTRS::InvalidParameter::_tao_any_destructor,
        JTRS::_tc_InvalidParameter,
        _tao_elem
      );
}
TAO_END_VERSIONED_NAMESPACE_DECL



#endif

// TAO_IDL - Generated from 
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_exception/any_op_cs.cpp:45
TAO_BEGIN_VERSIONED_NAMESPACE_DECL



namespace TAO
{
  template<>
  ::CORBA::Boolean
  Any_Dual_Impl_T<JTRS::Unsupported>::demarshal_value (
      TAO_InputCDR & cdr
    )
  {
    ::CORBA::String_var id;

    if (!(cdr >> id.out ()))
      {
        return false;
      }
    
    try
      {
        this->value_->_tao_decode (cdr);
      }
    catch (const ::CORBA::Exception &)
      {
        return false;
      }

    return true;
  }
}
TAO_END_VERSIONED_NAMESPACE_DECL



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace JTRS
{
  

  // Copying insertion.
  void operator<<= (
      ::CORBA::Any &_tao_any,
      const ::JTRS::Unsupported &_tao_elem
    )
  {
    TAO::Any_Dual_Impl_T< ::JTRS::Unsupported>::insert_copy (
        _tao_any,
        ::JTRS::Unsupported::_tao_any_destructor,
        ::JTRS::_tc_Unsupported,
        _tao_elem
      );
  }

  // Non-copying insertion.
  void operator<<= (
      ::CORBA::Any &_tao_any,
      ::JTRS::Unsupported *_tao_elem
    )
  {
    TAO::Any_Dual_Impl_T< ::JTRS::Unsupported>::insert (
        _tao_any,
        ::JTRS::Unsupported::_tao_any_destructor,
        ::JTRS::_tc_Unsupported,
        _tao_elem
      );
  }

  // Extraction to non-const pointer (deprecated).
  ::CORBA::Boolean operator>>= (
      const ::CORBA::Any &_tao_any,
      ::JTRS::Unsupported *&_tao_elem
    )
  {
    return _tao_any >>= const_cast<
        const ::JTRS::Unsupported *&> (
        _tao_elem
      );
  }

  // Extraction to const pointer.
  ::CORBA::Boolean operator>>= (
      const ::CORBA::Any &_tao_any,
      const ::JTRS::Unsupported *&_tao_elem
    )
  {
    return
      TAO::Any_Dual_Impl_T< ::JTRS::Unsupported>::extract (
          _tao_any,
          ::JTRS::Unsupported::_tao_any_destructor,
          ::JTRS::_tc_Unsupported,
          _tao_elem
        );
  }
}

#else

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// Copying insertion.
void operator<<= (
    ::CORBA::Any &_tao_any,
    const JTRS::Unsupported &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<JTRS::Unsupported>::insert_copy (
      _tao_any,
      JTRS::Unsupported::_tao_any_destructor,
      JTRS::_tc_Unsupported,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    ::CORBA::Any &_tao_any,
    JTRS::Unsupported *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<JTRS::Unsupported>::insert (
      _tao_any,
      JTRS::Unsupported::_tao_any_destructor,
      JTRS::_tc_Unsupported,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
::CORBA::Boolean operator>>= (
    const ::CORBA::Any &_tao_any,
    JTRS::Unsupported *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const JTRS::Unsupported *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
::CORBA::Boolean operator>>= (
    const ::CORBA::Any &_tao_any,
    const JTRS::Unsupported *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<JTRS::Unsupported>::extract (
        _tao_any,
        JTRS::Unsupported::_tao_any_destructor,
        JTRS::_tc_Unsupported,
        _tao_elem
      );
}
TAO_END_VERSIONED_NAMESPACE_DECL



#endif

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_sequence/cdr_op_cs.cpp:90
#if !defined _TAO_CDR_OP_JTRS_ExtEnumSequence_CPP_
#define _TAO_CDR_OP_JTRS_ExtEnumSequence_CPP_

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const JTRS::ExtEnumSequence &_tao_sequence)
{
  return TAO::marshal_sequence(strm, _tao_sequence);
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    JTRS::ExtEnumSequence &_tao_sequence)
{
  return TAO::demarshal_sequence(strm, _tao_sequence);
}


TAO_END_VERSIONED_NAMESPACE_DECL

#endif /* _TAO_CDR_OP_JTRS_ExtEnumSequence_CPP_ */

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_exception/cdr_op_cs.cpp:49
TAO_BEGIN_VERSIONED_NAMESPACE_DECL



::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const JTRS::InvalidParameter &_tao_aggregate
  )
{
  // Marshal the repository ID.
  return (strm << _tao_aggregate._rep_id ());
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &,
    JTRS::InvalidParameter&
  )
{
  return true;
}

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_exception/cdr_op_cs.cpp:49
TAO_BEGIN_VERSIONED_NAMESPACE_DECL



::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const JTRS::Unsupported &_tao_aggregate
  )
{
  // Marshal the repository ID.
  return (strm << _tao_aggregate._rep_id ());
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &,
    JTRS::Unsupported&
  )
{
  return true;
}

TAO_END_VERSIONED_NAMESPACE_DECL


