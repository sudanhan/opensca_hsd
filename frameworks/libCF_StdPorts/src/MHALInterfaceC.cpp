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


#include "../include/MHALInterfaceC.h"
#include "tao/AnyTypeCode/Null_RefCount_Policy.h"
#include "tao/AnyTypeCode/TypeCode_Constants.h"
#include "tao/AnyTypeCode/Alias_TypeCode_Static.h"
#include "tao/AnyTypeCode/Objref_TypeCode_Static.h"
#include "tao/AnyTypeCode/Sequence_TypeCode_Static.h"
#include "tao/CDR.h"
#include "tao/Exception_Data.h"
#include "tao/Invocation_Adapter.h"
#include "tao/Object_T.h"
#include "tao/CDR.h"
#include "tao/AnyTypeCode/Any.h"
#include "tao/AnyTypeCode/Any_Impl_T.h"
#include "tao/AnyTypeCode/Any_Dual_Impl_T.h"
#include "ace/OS_NS_string.h"

#if !defined (__ACE_INLINE__)
#include "../include/MHALInterfaceC.inl"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_cs.cpp:53

// Traits specializations for MHAL::MHALPacketConsumer.

MHAL::MHALPacketConsumer_ptr
TAO::Objref_Traits<MHAL::MHALPacketConsumer>::duplicate (
    MHAL::MHALPacketConsumer_ptr p)
{
  return MHAL::MHALPacketConsumer::_duplicate (p);
}

void
TAO::Objref_Traits<MHAL::MHALPacketConsumer>::release (
    MHAL::MHALPacketConsumer_ptr p)
{
  ::CORBA::release (p);
}

MHAL::MHALPacketConsumer_ptr
TAO::Objref_Traits<MHAL::MHALPacketConsumer>::nil (void)
{
  return MHAL::MHALPacketConsumer::_nil ();
}

::CORBA::Boolean
TAO::Objref_Traits<MHAL::MHALPacketConsumer>::marshal (
    const MHAL::MHALPacketConsumer_ptr p,
    TAO_OutputCDR & cdr)
{
  return ::CORBA::Object::marshal (p, cdr);
}

// Function pointer for collocation factory initialization.
TAO::Collocation_Proxy_Broker * 
(*MHAL__TAO_MHALPacketConsumer_Proxy_Broker_Factory_function_pointer) (
    ::CORBA::Object_ptr obj) = 0;

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_cs.cpp:80

void
MHAL::MHALPacketConsumer::pushPacket (
  ::CORBA::UShort logicalDest,
  const ::JTRS::OctetSequence & payload)
{
  if (!this->is_evaluated ())
    {
      ::CORBA::Object::tao_object_initialize (this);
    }
  
  if (this->the_TAO_MHALPacketConsumer_Proxy_Broker_ == 0)
    {
      MHAL_MHALPacketConsumer_setup_collocation ();
    }
  
  TAO::Arg_Traits< void>::ret_val _tao_retval;
  TAO::Arg_Traits< ::CORBA::UShort>::in_arg_val _tao_logicalDest (logicalDest);
  TAO::Arg_Traits< ::JTRS::OctetSequence>::in_arg_val _tao_payload (payload);

  TAO::Argument *_the_tao_operation_signature [] =
    {
      &_tao_retval,
      &_tao_logicalDest,
      &_tao_payload
    };

  TAO::Invocation_Adapter _tao_call (
      this,
      _the_tao_operation_signature,
      3,
      "pushPacket",
      10,
      this->the_TAO_MHALPacketConsumer_Proxy_Broker_
    );

  _tao_call.invoke (0, 0);
}

MHAL::MHALPacketConsumer::MHALPacketConsumer (void)
 : the_TAO_MHALPacketConsumer_Proxy_Broker_ (0)
{
  this->MHAL_MHALPacketConsumer_setup_collocation ();
}

void
MHAL::MHALPacketConsumer::MHAL_MHALPacketConsumer_setup_collocation ()
{
  if (::MHAL__TAO_MHALPacketConsumer_Proxy_Broker_Factory_function_pointer)
    {
      this->the_TAO_MHALPacketConsumer_Proxy_Broker_ =
        ::MHAL__TAO_MHALPacketConsumer_Proxy_Broker_Factory_function_pointer (this);
    }
  
  this->Packet_PayloadStatus_setup_collocation ();
}

MHAL::MHALPacketConsumer::~MHALPacketConsumer (void)
{}

void 
MHAL::MHALPacketConsumer::_tao_any_destructor (void *_tao_void_pointer)
{
  MHALPacketConsumer *_tao_tmp_pointer =
    static_cast<MHALPacketConsumer *> (_tao_void_pointer);
  ::CORBA::release (_tao_tmp_pointer);
}

MHAL::MHALPacketConsumer_ptr
MHAL::MHALPacketConsumer::_narrow (
    ::CORBA::Object_ptr _tao_objref)
{
  return
    TAO::Narrow_Utils<MHALPacketConsumer>::narrow (
        _tao_objref,
        "IDL:MHAL/MHALPacketConsumer:1.0",
        MHAL__TAO_MHALPacketConsumer_Proxy_Broker_Factory_function_pointer
      );
}

MHAL::MHALPacketConsumer_ptr
MHAL::MHALPacketConsumer::_unchecked_narrow (
    ::CORBA::Object_ptr _tao_objref)
{
  return
    TAO::Narrow_Utils<MHALPacketConsumer>::unchecked_narrow (
        _tao_objref,
        "IDL:MHAL/MHALPacketConsumer:1.0",
        MHAL__TAO_MHALPacketConsumer_Proxy_Broker_Factory_function_pointer
      );
}

MHAL::MHALPacketConsumer_ptr
MHAL::MHALPacketConsumer::_nil (void)
{
  return 0;
}

MHAL::MHALPacketConsumer_ptr
MHAL::MHALPacketConsumer::_duplicate (MHALPacketConsumer_ptr obj)
{
  if (! ::CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
MHAL::MHALPacketConsumer::_tao_release (MHALPacketConsumer_ptr obj)
{
  ::CORBA::release (obj);
}

::CORBA::Boolean
MHAL::MHALPacketConsumer::_is_a (const char *value)
{
  if (
      ACE_OS::strcmp (
          value,
          "IDL:Packet/PayloadStatus:1.0"
        ) == 0 ||
      ACE_OS::strcmp (
          value,
          "IDL:MHAL/MHALPacketConsumer:1.0"
        ) == 0 ||
      ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/Object:1.0"
        ) == 0
    )
    {
      return true; // success using local knowledge
    }
  else
    {
      return this->::CORBA::Object::_is_a (value);
    }
}

const char* MHAL::MHALPacketConsumer::_interface_repository_id (void) const
{
  return "IDL:MHAL/MHALPacketConsumer:1.0";
}

::CORBA::Boolean
MHAL::MHALPacketConsumer::marshal (TAO_OutputCDR &cdr)
{
  return (cdr << this);
}

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/objref_typecode.cpp:70

static TAO::TypeCode::Objref<char const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_MHAL_MHALPacketConsumer (
    ::CORBA::tk_objref,
    "IDL:MHAL/MHALPacketConsumer:1.0",
    "MHALPacketConsumer");
  

namespace MHAL
{
  ::CORBA::TypeCode_ptr const _tc_MHALPacketConsumer =
    &_tao_tc_MHAL_MHALPacketConsumer;
}

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_cs.cpp:53

// Traits specializations for MHAL::PF_MHALPacketConsumer.

MHAL::PF_MHALPacketConsumer_ptr
TAO::Objref_Traits<MHAL::PF_MHALPacketConsumer>::duplicate (
    MHAL::PF_MHALPacketConsumer_ptr p)
{
  return MHAL::PF_MHALPacketConsumer::_duplicate (p);
}

void
TAO::Objref_Traits<MHAL::PF_MHALPacketConsumer>::release (
    MHAL::PF_MHALPacketConsumer_ptr p)
{
  ::CORBA::release (p);
}

MHAL::PF_MHALPacketConsumer_ptr
TAO::Objref_Traits<MHAL::PF_MHALPacketConsumer>::nil (void)
{
  return MHAL::PF_MHALPacketConsumer::_nil ();
}

::CORBA::Boolean
TAO::Objref_Traits<MHAL::PF_MHALPacketConsumer>::marshal (
    const MHAL::PF_MHALPacketConsumer_ptr p,
    TAO_OutputCDR & cdr)
{
  return ::CORBA::Object::marshal (p, cdr);
}

// Function pointer for collocation factory initialization.
TAO::Collocation_Proxy_Broker * 
(*MHAL__TAO_PF_MHALPacketConsumer_Proxy_Broker_Factory_function_pointer) (
    ::CORBA::Object_ptr obj) = 0;

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/alias_typecode.cpp:50

static TAO::TypeCode::Alias<char const *,
                            ::CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_MHAL_PF_MHALPacketConsumer_MHALPhysicalDestination (
    ::CORBA::tk_alias,
    "IDL:MHAL/PF_MHALPacketConsumer/MHALPhysicalDestination:1.0",
    "MHALPhysicalDestination",
    &CORBA::_tc_ushort);
  
::CORBA::TypeCode_ptr const MHAL::PF_MHALPacketConsumer::_tc_MHALPhysicalDestination =
  &_tao_tc_MHAL_PF_MHALPacketConsumer_MHALPhysicalDestination;

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_cs.cpp:80

void
MHAL::PF_MHALPacketConsumer::addTxRoute (
  ::CORBA::UShort logicalDest,
  ::MHAL::PF_MHALPacketConsumer::MHALPhysicalDestination physicalDest)
{
  if (!this->is_evaluated ())
    {
      ::CORBA::Object::tao_object_initialize (this);
    }
  
  if (this->the_TAO_PF_MHALPacketConsumer_Proxy_Broker_ == 0)
    {
      MHAL_PF_MHALPacketConsumer_setup_collocation ();
    }
  
  TAO::Arg_Traits< void>::ret_val _tao_retval;
  TAO::Arg_Traits< ::CORBA::UShort>::in_arg_val _tao_logicalDest (logicalDest);
  TAO::Arg_Traits< ::CORBA::UShort>::in_arg_val _tao_physicalDest (physicalDest);

  TAO::Argument *_the_tao_operation_signature [] =
    {
      &_tao_retval,
      &_tao_logicalDest,
      &_tao_physicalDest
    };

  TAO::Invocation_Adapter _tao_call (
      this,
      _the_tao_operation_signature,
      3,
      "addTxRoute",
      10,
      this->the_TAO_PF_MHALPacketConsumer_Proxy_Broker_
    );

  _tao_call.invoke (0, 0);
}

MHAL::PF_MHALPacketConsumer::PF_MHALPacketConsumer (void)
 : the_TAO_PF_MHALPacketConsumer_Proxy_Broker_ (0)
{
  this->MHAL_PF_MHALPacketConsumer_setup_collocation ();
}

void
MHAL::PF_MHALPacketConsumer::MHAL_PF_MHALPacketConsumer_setup_collocation ()
{
  if (::MHAL__TAO_PF_MHALPacketConsumer_Proxy_Broker_Factory_function_pointer)
    {
      this->the_TAO_PF_MHALPacketConsumer_Proxy_Broker_ =
        ::MHAL__TAO_PF_MHALPacketConsumer_Proxy_Broker_Factory_function_pointer (this);
    }
  
  this->MHAL_MHALPacketConsumer_setup_collocation ();
}

MHAL::PF_MHALPacketConsumer::~PF_MHALPacketConsumer (void)
{}

void 
MHAL::PF_MHALPacketConsumer::_tao_any_destructor (void *_tao_void_pointer)
{
  PF_MHALPacketConsumer *_tao_tmp_pointer =
    static_cast<PF_MHALPacketConsumer *> (_tao_void_pointer);
  ::CORBA::release (_tao_tmp_pointer);
}

MHAL::PF_MHALPacketConsumer_ptr
MHAL::PF_MHALPacketConsumer::_narrow (
    ::CORBA::Object_ptr _tao_objref)
{
  return
    TAO::Narrow_Utils<PF_MHALPacketConsumer>::narrow (
        _tao_objref,
        "IDL:MHAL/PF_MHALPacketConsumer:1.0",
        MHAL__TAO_PF_MHALPacketConsumer_Proxy_Broker_Factory_function_pointer
      );
}

MHAL::PF_MHALPacketConsumer_ptr
MHAL::PF_MHALPacketConsumer::_unchecked_narrow (
    ::CORBA::Object_ptr _tao_objref)
{
  return
    TAO::Narrow_Utils<PF_MHALPacketConsumer>::unchecked_narrow (
        _tao_objref,
        "IDL:MHAL/PF_MHALPacketConsumer:1.0",
        MHAL__TAO_PF_MHALPacketConsumer_Proxy_Broker_Factory_function_pointer
      );
}

MHAL::PF_MHALPacketConsumer_ptr
MHAL::PF_MHALPacketConsumer::_nil (void)
{
  return 0;
}

MHAL::PF_MHALPacketConsumer_ptr
MHAL::PF_MHALPacketConsumer::_duplicate (PF_MHALPacketConsumer_ptr obj)
{
  if (! ::CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
MHAL::PF_MHALPacketConsumer::_tao_release (PF_MHALPacketConsumer_ptr obj)
{
  ::CORBA::release (obj);
}

::CORBA::Boolean
MHAL::PF_MHALPacketConsumer::_is_a (const char *value)
{
  if (
      ACE_OS::strcmp (
          value,
          "IDL:Packet/PayloadStatus:1.0"
        ) == 0 ||
      ACE_OS::strcmp (
          value,
          "IDL:MHAL/MHALPacketConsumer:1.0"
        ) == 0 ||
      ACE_OS::strcmp (
          value,
          "IDL:MHAL/PF_MHALPacketConsumer:1.0"
        ) == 0 ||
      ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/Object:1.0"
        ) == 0
    )
    {
      return true; // success using local knowledge
    }
  else
    {
      return this->::CORBA::Object::_is_a (value);
    }
}

const char* MHAL::PF_MHALPacketConsumer::_interface_repository_id (void) const
{
  return "IDL:MHAL/PF_MHALPacketConsumer:1.0";
}

::CORBA::Boolean
MHAL::PF_MHALPacketConsumer::marshal (TAO_OutputCDR &cdr)
{
  return (cdr << this);
}

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/objref_typecode.cpp:70

static TAO::TypeCode::Objref<char const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_MHAL_PF_MHALPacketConsumer (
    ::CORBA::tk_objref,
    "IDL:MHAL/PF_MHALPacketConsumer:1.0",
    "PF_MHALPacketConsumer");
  

namespace MHAL
{
  ::CORBA::TypeCode_ptr const _tc_PF_MHALPacketConsumer =
    &_tao_tc_MHAL_PF_MHALPacketConsumer;
}

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_cs.cpp:53

// Traits specializations for MHAL::WF_MHALPacketConsumer.

MHAL::WF_MHALPacketConsumer_ptr
TAO::Objref_Traits<MHAL::WF_MHALPacketConsumer>::duplicate (
    MHAL::WF_MHALPacketConsumer_ptr p)
{
  return MHAL::WF_MHALPacketConsumer::_duplicate (p);
}

void
TAO::Objref_Traits<MHAL::WF_MHALPacketConsumer>::release (
    MHAL::WF_MHALPacketConsumer_ptr p)
{
  ::CORBA::release (p);
}

MHAL::WF_MHALPacketConsumer_ptr
TAO::Objref_Traits<MHAL::WF_MHALPacketConsumer>::nil (void)
{
  return MHAL::WF_MHALPacketConsumer::_nil ();
}

::CORBA::Boolean
TAO::Objref_Traits<MHAL::WF_MHALPacketConsumer>::marshal (
    const MHAL::WF_MHALPacketConsumer_ptr p,
    TAO_OutputCDR & cdr)
{
  return ::CORBA::Object::marshal (p, cdr);
}

// Function pointer for collocation factory initialization.
TAO::Collocation_Proxy_Broker * 
(*MHAL__TAO_WF_MHALPacketConsumer_Proxy_Broker_Factory_function_pointer) (
    ::CORBA::Object_ptr obj) = 0;

// TAO_IDL - Generated from 
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_MHAL_WF_MHALPACKETCONSUMER_RXROUTESEQUENCE_CS_)
#define _MHAL_WF_MHALPACKETCONSUMER_RXROUTESEQUENCE_CS_

MHAL::WF_MHALPacketConsumer::RxRouteSequence::RxRouteSequence (void)
{}

MHAL::WF_MHALPacketConsumer::RxRouteSequence::RxRouteSequence (
    ::CORBA::ULong max)
  : ::TAO::unbounded_value_sequence<
        ::CORBA::UShort
      > (max)
{}

MHAL::WF_MHALPacketConsumer::RxRouteSequence::RxRouteSequence (
    ::CORBA::ULong max,
    ::CORBA::ULong length,
    ::CORBA::UShort * buffer,
    ::CORBA::Boolean release
  )
  : ::TAO::unbounded_value_sequence<
        ::CORBA::UShort
      >
    (max, length, buffer, release)
{}

MHAL::WF_MHALPacketConsumer::RxRouteSequence::RxRouteSequence (
    const RxRouteSequence &seq)
  : ::TAO::unbounded_value_sequence<
        ::CORBA::UShort
      > (seq)
{}

MHAL::WF_MHALPacketConsumer::RxRouteSequence::~RxRouteSequence (void)
{}

void MHAL::WF_MHALPacketConsumer::RxRouteSequence::_tao_any_destructor (
    void * _tao_void_pointer)
{
  RxRouteSequence * _tao_tmp_pointer =
    static_cast<RxRouteSequence *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/alias_typecode.cpp:50



// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/typecode_defn.cpp:460


#ifndef _TAO_TYPECODE_MHAL_WF_MHALPacketConsumer_RxRouteSequence_GUARD
#define _TAO_TYPECODE_MHAL_WF_MHALPacketConsumer_RxRouteSequence_GUARD

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

namespace TAO
{
  namespace TypeCode
  {
    namespace
    {
      TAO::TypeCode::Sequence< ::CORBA::TypeCode_ptr const *,
                              TAO::Null_RefCount_Policy>
        MHAL_WF_MHALPacketConsumer_RxRouteSequence_0 (
          ::CORBA::tk_sequence,
          &CORBA::_tc_ushort,
          0U);
        
      ::CORBA::TypeCode_ptr const tc_MHAL_WF_MHALPacketConsumer_RxRouteSequence_0 =
        &MHAL_WF_MHALPacketConsumer_RxRouteSequence_0;
    }
  }
}

TAO_END_VERSIONED_NAMESPACE_DECL

#endif /* _TAO_TYPECODE_MHAL_WF_MHALPacketConsumer_RxRouteSequence_GUARD */

static TAO::TypeCode::Alias<char const *,
                            ::CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_MHAL_WF_MHALPacketConsumer_RxRouteSequence (
    ::CORBA::tk_alias,
    "IDL:MHAL/WF_MHALPacketConsumer/RxRouteSequence:1.0",
    "RxRouteSequence",
    &TAO::TypeCode::tc_MHAL_WF_MHALPacketConsumer_RxRouteSequence_0);
  
::CORBA::TypeCode_ptr const MHAL::WF_MHALPacketConsumer::_tc_RxRouteSequence =
  &_tao_tc_MHAL_WF_MHALPacketConsumer_RxRouteSequence;

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_cs.cpp:80

::MHAL::WF_MHALPacketConsumer::RxRouteSequence *
MHAL::WF_MHALPacketConsumer::getRxRoutes (
  void)
{
  if (!this->is_evaluated ())
    {
      ::CORBA::Object::tao_object_initialize (this);
    }
  
  if (this->the_TAO_WF_MHALPacketConsumer_Proxy_Broker_ == 0)
    {
      MHAL_WF_MHALPacketConsumer_setup_collocation ();
    }
  
  TAO::Arg_Traits< ::MHAL::WF_MHALPacketConsumer::RxRouteSequence>::ret_val _tao_retval;

  TAO::Argument *_the_tao_operation_signature [] =
    {
      &_tao_retval
    };

  TAO::Invocation_Adapter _tao_call (
      this,
      _the_tao_operation_signature,
      1,
      "getRxRoutes",
      11,
      this->the_TAO_WF_MHALPacketConsumer_Proxy_Broker_
    );

  _tao_call.invoke (0, 0);

  return _tao_retval.retn ();
}

MHAL::WF_MHALPacketConsumer::WF_MHALPacketConsumer (void)
 : the_TAO_WF_MHALPacketConsumer_Proxy_Broker_ (0)
{
  this->MHAL_WF_MHALPacketConsumer_setup_collocation ();
}

void
MHAL::WF_MHALPacketConsumer::MHAL_WF_MHALPacketConsumer_setup_collocation ()
{
  if (::MHAL__TAO_WF_MHALPacketConsumer_Proxy_Broker_Factory_function_pointer)
    {
      this->the_TAO_WF_MHALPacketConsumer_Proxy_Broker_ =
        ::MHAL__TAO_WF_MHALPacketConsumer_Proxy_Broker_Factory_function_pointer (this);
    }
  
  this->MHAL_MHALPacketConsumer_setup_collocation ();
}

MHAL::WF_MHALPacketConsumer::~WF_MHALPacketConsumer (void)
{}

void 
MHAL::WF_MHALPacketConsumer::_tao_any_destructor (void *_tao_void_pointer)
{
  WF_MHALPacketConsumer *_tao_tmp_pointer =
    static_cast<WF_MHALPacketConsumer *> (_tao_void_pointer);
  ::CORBA::release (_tao_tmp_pointer);
}

MHAL::WF_MHALPacketConsumer_ptr
MHAL::WF_MHALPacketConsumer::_narrow (
    ::CORBA::Object_ptr _tao_objref)
{
  return
    TAO::Narrow_Utils<WF_MHALPacketConsumer>::narrow (
        _tao_objref,
        "IDL:MHAL/WF_MHALPacketConsumer:1.0",
        MHAL__TAO_WF_MHALPacketConsumer_Proxy_Broker_Factory_function_pointer
      );
}

MHAL::WF_MHALPacketConsumer_ptr
MHAL::WF_MHALPacketConsumer::_unchecked_narrow (
    ::CORBA::Object_ptr _tao_objref)
{
  return
    TAO::Narrow_Utils<WF_MHALPacketConsumer>::unchecked_narrow (
        _tao_objref,
        "IDL:MHAL/WF_MHALPacketConsumer:1.0",
        MHAL__TAO_WF_MHALPacketConsumer_Proxy_Broker_Factory_function_pointer
      );
}

MHAL::WF_MHALPacketConsumer_ptr
MHAL::WF_MHALPacketConsumer::_nil (void)
{
  return 0;
}

MHAL::WF_MHALPacketConsumer_ptr
MHAL::WF_MHALPacketConsumer::_duplicate (WF_MHALPacketConsumer_ptr obj)
{
  if (! ::CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
MHAL::WF_MHALPacketConsumer::_tao_release (WF_MHALPacketConsumer_ptr obj)
{
  ::CORBA::release (obj);
}

::CORBA::Boolean
MHAL::WF_MHALPacketConsumer::_is_a (const char *value)
{
  if (
      ACE_OS::strcmp (
          value,
          "IDL:Packet/PayloadStatus:1.0"
        ) == 0 ||
      ACE_OS::strcmp (
          value,
          "IDL:MHAL/MHALPacketConsumer:1.0"
        ) == 0 ||
      ACE_OS::strcmp (
          value,
          "IDL:MHAL/WF_MHALPacketConsumer:1.0"
        ) == 0 ||
      ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/Object:1.0"
        ) == 0
    )
    {
      return true; // success using local knowledge
    }
  else
    {
      return this->::CORBA::Object::_is_a (value);
    }
}

const char* MHAL::WF_MHALPacketConsumer::_interface_repository_id (void) const
{
  return "IDL:MHAL/WF_MHALPacketConsumer:1.0";
}

::CORBA::Boolean
MHAL::WF_MHALPacketConsumer::marshal (TAO_OutputCDR &cdr)
{
  return (cdr << this);
}

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/objref_typecode.cpp:70

static TAO::TypeCode::Objref<char const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_MHAL_WF_MHALPacketConsumer (
    ::CORBA::tk_objref,
    "IDL:MHAL/WF_MHALPacketConsumer:1.0",
    "WF_MHALPacketConsumer");
  

namespace MHAL
{
  ::CORBA::TypeCode_ptr const _tc_WF_MHALPacketConsumer =
    &_tao_tc_MHAL_WF_MHALPacketConsumer;
}

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/any_op_cs.cpp:46
TAO_BEGIN_VERSIONED_NAMESPACE_DECL



namespace TAO
{
  template<>
  ::CORBA::Boolean
  Any_Impl_T<MHAL::MHALPacketConsumer>::to_object (
      ::CORBA::Object_ptr &_tao_elem
    ) const
  {
    _tao_elem = ::CORBA::Object::_duplicate (this->value_);
    return true;
  }
}
TAO_END_VERSIONED_NAMESPACE_DECL



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace MHAL
{
  

  /// Copying insertion.
  void
  operator<<= (
      ::CORBA::Any &_tao_any,
      MHALPacketConsumer_ptr _tao_elem)
  {
    MHALPacketConsumer_ptr _tao_objptr =
      MHALPacketConsumer::_duplicate (_tao_elem);
    _tao_any <<= &_tao_objptr;
  }

  /// Non-copying insertion.
  void
  operator<<= (
      ::CORBA::Any &_tao_any,
      MHALPacketConsumer_ptr *_tao_elem)
  {
    TAO::Any_Impl_T<MHALPacketConsumer>::insert (
        _tao_any,
        MHALPacketConsumer::_tao_any_destructor,
        _tc_MHALPacketConsumer,
        *_tao_elem);
  }

  ::CORBA::Boolean
  operator>>= (
      const ::CORBA::Any &_tao_any,
      MHALPacketConsumer_ptr &_tao_elem)
  {
    return
      TAO::Any_Impl_T<MHALPacketConsumer>::extract (
          _tao_any,
          MHALPacketConsumer::_tao_any_destructor,
          _tc_MHALPacketConsumer,
          _tao_elem);
  }
}

#else

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



/// Copying insertion.
void
operator<<= (
    ::CORBA::Any &_tao_any,
    MHAL::MHALPacketConsumer_ptr _tao_elem)
{
  MHAL::MHALPacketConsumer_ptr _tao_objptr =
    MHAL::MHALPacketConsumer::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

/// Non-copying insertion.
void
operator<<= (
    ::CORBA::Any &_tao_any,
    MHAL::MHALPacketConsumer_ptr *_tao_elem)
{
  TAO::Any_Impl_T<MHAL::MHALPacketConsumer>::insert (
      _tao_any,
      MHAL::MHALPacketConsumer::_tao_any_destructor,
      MHAL::_tc_MHALPacketConsumer,
      *_tao_elem);
}

::CORBA::Boolean
operator>>= (
    const ::CORBA::Any &_tao_any,
    MHAL::MHALPacketConsumer_ptr &_tao_elem)
{
  return
    TAO::Any_Impl_T<MHAL::MHALPacketConsumer>::extract (
        _tao_any,
        MHAL::MHALPacketConsumer::_tao_any_destructor,
        MHAL::_tc_MHALPacketConsumer,
        _tao_elem);
}

TAO_END_VERSIONED_NAMESPACE_DECL



#endif

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/any_op_cs.cpp:46
TAO_BEGIN_VERSIONED_NAMESPACE_DECL



namespace TAO
{
  template<>
  ::CORBA::Boolean
  Any_Impl_T<MHAL::PF_MHALPacketConsumer>::to_object (
      ::CORBA::Object_ptr &_tao_elem
    ) const
  {
    _tao_elem = ::CORBA::Object::_duplicate (this->value_);
    return true;
  }
}
TAO_END_VERSIONED_NAMESPACE_DECL



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace MHAL
{
  

  /// Copying insertion.
  void
  operator<<= (
      ::CORBA::Any &_tao_any,
      PF_MHALPacketConsumer_ptr _tao_elem)
  {
    PF_MHALPacketConsumer_ptr _tao_objptr =
      PF_MHALPacketConsumer::_duplicate (_tao_elem);
    _tao_any <<= &_tao_objptr;
  }

  /// Non-copying insertion.
  void
  operator<<= (
      ::CORBA::Any &_tao_any,
      PF_MHALPacketConsumer_ptr *_tao_elem)
  {
    TAO::Any_Impl_T<PF_MHALPacketConsumer>::insert (
        _tao_any,
        PF_MHALPacketConsumer::_tao_any_destructor,
        _tc_PF_MHALPacketConsumer,
        *_tao_elem);
  }

  ::CORBA::Boolean
  operator>>= (
      const ::CORBA::Any &_tao_any,
      PF_MHALPacketConsumer_ptr &_tao_elem)
  {
    return
      TAO::Any_Impl_T<PF_MHALPacketConsumer>::extract (
          _tao_any,
          PF_MHALPacketConsumer::_tao_any_destructor,
          _tc_PF_MHALPacketConsumer,
          _tao_elem);
  }
}

#else

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



/// Copying insertion.
void
operator<<= (
    ::CORBA::Any &_tao_any,
    MHAL::PF_MHALPacketConsumer_ptr _tao_elem)
{
  MHAL::PF_MHALPacketConsumer_ptr _tao_objptr =
    MHAL::PF_MHALPacketConsumer::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

/// Non-copying insertion.
void
operator<<= (
    ::CORBA::Any &_tao_any,
    MHAL::PF_MHALPacketConsumer_ptr *_tao_elem)
{
  TAO::Any_Impl_T<MHAL::PF_MHALPacketConsumer>::insert (
      _tao_any,
      MHAL::PF_MHALPacketConsumer::_tao_any_destructor,
      MHAL::_tc_PF_MHALPacketConsumer,
      *_tao_elem);
}

::CORBA::Boolean
operator>>= (
    const ::CORBA::Any &_tao_any,
    MHAL::PF_MHALPacketConsumer_ptr &_tao_elem)
{
  return
    TAO::Any_Impl_T<MHAL::PF_MHALPacketConsumer>::extract (
        _tao_any,
        MHAL::PF_MHALPacketConsumer::_tao_any_destructor,
        MHAL::_tc_PF_MHALPacketConsumer,
        _tao_elem);
}

TAO_END_VERSIONED_NAMESPACE_DECL



#endif

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/any_op_cs.cpp:46
TAO_BEGIN_VERSIONED_NAMESPACE_DECL



namespace TAO
{
  template<>
  ::CORBA::Boolean
  Any_Impl_T<MHAL::WF_MHALPacketConsumer>::to_object (
      ::CORBA::Object_ptr &_tao_elem
    ) const
  {
    _tao_elem = ::CORBA::Object::_duplicate (this->value_);
    return true;
  }
}
TAO_END_VERSIONED_NAMESPACE_DECL



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace MHAL
{
  

  /// Copying insertion.
  void
  operator<<= (
      ::CORBA::Any &_tao_any,
      WF_MHALPacketConsumer_ptr _tao_elem)
  {
    WF_MHALPacketConsumer_ptr _tao_objptr =
      WF_MHALPacketConsumer::_duplicate (_tao_elem);
    _tao_any <<= &_tao_objptr;
  }

  /// Non-copying insertion.
  void
  operator<<= (
      ::CORBA::Any &_tao_any,
      WF_MHALPacketConsumer_ptr *_tao_elem)
  {
    TAO::Any_Impl_T<WF_MHALPacketConsumer>::insert (
        _tao_any,
        WF_MHALPacketConsumer::_tao_any_destructor,
        _tc_WF_MHALPacketConsumer,
        *_tao_elem);
  }

  ::CORBA::Boolean
  operator>>= (
      const ::CORBA::Any &_tao_any,
      WF_MHALPacketConsumer_ptr &_tao_elem)
  {
    return
      TAO::Any_Impl_T<WF_MHALPacketConsumer>::extract (
          _tao_any,
          WF_MHALPacketConsumer::_tao_any_destructor,
          _tc_WF_MHALPacketConsumer,
          _tao_elem);
  }
}

#else

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



/// Copying insertion.
void
operator<<= (
    ::CORBA::Any &_tao_any,
    MHAL::WF_MHALPacketConsumer_ptr _tao_elem)
{
  MHAL::WF_MHALPacketConsumer_ptr _tao_objptr =
    MHAL::WF_MHALPacketConsumer::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

/// Non-copying insertion.
void
operator<<= (
    ::CORBA::Any &_tao_any,
    MHAL::WF_MHALPacketConsumer_ptr *_tao_elem)
{
  TAO::Any_Impl_T<MHAL::WF_MHALPacketConsumer>::insert (
      _tao_any,
      MHAL::WF_MHALPacketConsumer::_tao_any_destructor,
      MHAL::_tc_WF_MHALPacketConsumer,
      *_tao_elem);
}

::CORBA::Boolean
operator>>= (
    const ::CORBA::Any &_tao_any,
    MHAL::WF_MHALPacketConsumer_ptr &_tao_elem)
{
  return
    TAO::Any_Impl_T<MHAL::WF_MHALPacketConsumer>::extract (
        _tao_any,
        MHAL::WF_MHALPacketConsumer::_tao_any_destructor,
        MHAL::_tc_WF_MHALPacketConsumer,
        _tao_elem);
}

TAO_END_VERSIONED_NAMESPACE_DECL



#endif

// TAO_IDL - Generated from 
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_sequence/any_op_cs.cpp:46


TAO_BEGIN_VERSIONED_NAMESPACE_DECL


TAO_END_VERSIONED_NAMESPACE_DECL



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace MHAL
{
  
  // Copying insertion.
  void operator<<= (
      ::CORBA::Any &_tao_any,
      const ::MHAL::WF_MHALPacketConsumer::RxRouteSequence &_tao_elem
    )
  {
    if (0 == &_tao_elem) // Trying to de-reference NULL object
      _tao_any <<= static_cast< ::MHAL::WF_MHALPacketConsumer::RxRouteSequence *>( 0 ); // Use non-copying insertion of a NULL
    else
      TAO::Any_Dual_Impl_T< ::MHAL::WF_MHALPacketConsumer::RxRouteSequence>::insert_copy (
          _tao_any,
          ::MHAL::WF_MHALPacketConsumer::RxRouteSequence::_tao_any_destructor,
          ::MHAL::WF_MHALPacketConsumer::_tc_RxRouteSequence,
          _tao_elem
        );
  }

  // Non-copying insertion.
  void operator<<= (
      ::CORBA::Any &_tao_any,
      ::MHAL::WF_MHALPacketConsumer::RxRouteSequence *_tao_elem
    )
  {
    TAO::Any_Dual_Impl_T< ::MHAL::WF_MHALPacketConsumer::RxRouteSequence>::insert (
        _tao_any,
        ::MHAL::WF_MHALPacketConsumer::RxRouteSequence::_tao_any_destructor,
        ::MHAL::WF_MHALPacketConsumer::_tc_RxRouteSequence,
        _tao_elem
      );
  }

  // Extraction to non-const pointer (deprecated).
  ::CORBA::Boolean operator>>= (
      const ::CORBA::Any &_tao_any,
      ::MHAL::WF_MHALPacketConsumer::RxRouteSequence *&_tao_elem
    )
  {
    return _tao_any >>= const_cast<
        const ::MHAL::WF_MHALPacketConsumer::RxRouteSequence *&> (
        _tao_elem
      );
  }

  // Extraction to const pointer.
  ::CORBA::Boolean operator>>= (
      const ::CORBA::Any &_tao_any,
      const ::MHAL::WF_MHALPacketConsumer::RxRouteSequence *&_tao_elem
    )
  {
    return
      TAO::Any_Dual_Impl_T< ::MHAL::WF_MHALPacketConsumer::RxRouteSequence>::extract (
          _tao_any,
          ::MHAL::WF_MHALPacketConsumer::RxRouteSequence::_tao_any_destructor,
          ::MHAL::WF_MHALPacketConsumer::_tc_RxRouteSequence,
          _tao_elem
        );
  }
}

#else


TAO_BEGIN_VERSIONED_NAMESPACE_DECL


// Copying insertion.
void operator<<= (
    ::CORBA::Any &_tao_any,
    const MHAL::WF_MHALPacketConsumer::RxRouteSequence &_tao_elem
  )
{
  if (0 == &_tao_elem) // Trying to de-reference NULL object
    _tao_any <<= static_cast<MHAL::WF_MHALPacketConsumer::RxRouteSequence *>( 0 ); // Use non-copying insertion of a NULL
  else
    TAO::Any_Dual_Impl_T<MHAL::WF_MHALPacketConsumer::RxRouteSequence>::insert_copy (
        _tao_any,
        MHAL::WF_MHALPacketConsumer::RxRouteSequence::_tao_any_destructor,
        MHAL::WF_MHALPacketConsumer::_tc_RxRouteSequence,
        _tao_elem
      );
}

// Non-copying insertion.
void operator<<= (
    ::CORBA::Any &_tao_any,
    MHAL::WF_MHALPacketConsumer::RxRouteSequence *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<MHAL::WF_MHALPacketConsumer::RxRouteSequence>::insert (
      _tao_any,
      MHAL::WF_MHALPacketConsumer::RxRouteSequence::_tao_any_destructor,
      MHAL::WF_MHALPacketConsumer::_tc_RxRouteSequence,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
::CORBA::Boolean operator>>= (
    const ::CORBA::Any &_tao_any,
    MHAL::WF_MHALPacketConsumer::RxRouteSequence *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const MHAL::WF_MHALPacketConsumer::RxRouteSequence *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
::CORBA::Boolean operator>>= (
    const ::CORBA::Any &_tao_any,
    const MHAL::WF_MHALPacketConsumer::RxRouteSequence *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<MHAL::WF_MHALPacketConsumer::RxRouteSequence>::extract (
        _tao_any,
        MHAL::WF_MHALPacketConsumer::RxRouteSequence::_tao_any_destructor,
        MHAL::WF_MHALPacketConsumer::_tc_RxRouteSequence,
        _tao_elem
      );
}
TAO_END_VERSIONED_NAMESPACE_DECL



#endif

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/cdr_op_cs.cpp:53

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const MHAL::MHALPacketConsumer_ptr _tao_objref)
{
  ::CORBA::Object_ptr _tao_corba_obj = _tao_objref;
  return (strm << _tao_corba_obj);
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    MHAL::MHALPacketConsumer_ptr &_tao_objref)
{
  ::CORBA::Object_var obj;

  if (!(strm >> obj.inout ()))
    {
      return false;
    }
  
  typedef ::MHAL::MHALPacketConsumer RHS_SCOPED_NAME;

  // Narrow to the right type.
  _tao_objref =
    TAO::Narrow_Utils<RHS_SCOPED_NAME>::unchecked_narrow (
        obj.in (),
        MHAL__TAO_MHALPacketConsumer_Proxy_Broker_Factory_function_pointer
      );
    
  return true;
}

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/cdr_op_cs.cpp:53

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const MHAL::PF_MHALPacketConsumer_ptr _tao_objref)
{
  ::CORBA::Object_ptr _tao_corba_obj = _tao_objref;
  return (strm << _tao_corba_obj);
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    MHAL::PF_MHALPacketConsumer_ptr &_tao_objref)
{
  ::CORBA::Object_var obj;

  if (!(strm >> obj.inout ()))
    {
      return false;
    }
  
  typedef ::MHAL::PF_MHALPacketConsumer RHS_SCOPED_NAME;

  // Narrow to the right type.
  _tao_objref =
    TAO::Narrow_Utils<RHS_SCOPED_NAME>::unchecked_narrow (
        obj.in (),
        MHAL__TAO_PF_MHALPacketConsumer_Proxy_Broker_Factory_function_pointer
      );
    
  return true;
}

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_sequence/cdr_op_cs.cpp:90
#if !defined _TAO_CDR_OP_MHAL_WF_MHALPacketConsumer_RxRouteSequence_CPP_
#define _TAO_CDR_OP_MHAL_WF_MHALPacketConsumer_RxRouteSequence_CPP_

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const MHAL::WF_MHALPacketConsumer::RxRouteSequence &_tao_sequence)
{
  return TAO::marshal_sequence(strm, _tao_sequence);
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    MHAL::WF_MHALPacketConsumer::RxRouteSequence &_tao_sequence)
{
  return TAO::demarshal_sequence(strm, _tao_sequence);
}


TAO_END_VERSIONED_NAMESPACE_DECL

#endif /* _TAO_CDR_OP_MHAL_WF_MHALPacketConsumer_RxRouteSequence_CPP_ */

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/cdr_op_cs.cpp:53

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const MHAL::WF_MHALPacketConsumer_ptr _tao_objref)
{
  ::CORBA::Object_ptr _tao_corba_obj = _tao_objref;
  return (strm << _tao_corba_obj);
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    MHAL::WF_MHALPacketConsumer_ptr &_tao_objref)
{
  ::CORBA::Object_var obj;

  if (!(strm >> obj.inout ()))
    {
      return false;
    }
  
  typedef ::MHAL::WF_MHALPacketConsumer RHS_SCOPED_NAME;

  // Narrow to the right type.
  _tao_objref =
    TAO::Narrow_Utils<RHS_SCOPED_NAME>::unchecked_narrow (
        obj.in (),
        MHAL__TAO_WF_MHALPacketConsumer_Proxy_Broker_Factory_function_pointer
      );
    
  return true;
}

TAO_END_VERSIONED_NAMESPACE_DECL



