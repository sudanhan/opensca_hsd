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


#include "RtecEventCommC.h"
#include "tao/AnyTypeCode/Null_RefCount_Policy.h"
#include "tao/AnyTypeCode/TypeCode_Constants.h"
#include "tao/AnyTypeCode/Alias_TypeCode_Static.h"
#include "tao/AnyTypeCode/Objref_TypeCode_Static.h"
#include "tao/AnyTypeCode/Sequence_TypeCode_Static.h"
#include "tao/AnyTypeCode/Struct_TypeCode_Static.h"
#include "tao/AnyTypeCode/TypeCode_Struct_Field.h"
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
#include "RtecEventCommC.inl"
#endif /* !defined INLINE */

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/alias_typecode.cpp:50

static TAO::TypeCode::Alias<char const *,
                            ::CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_RtecEventComm_EventData (
    ::CORBA::tk_alias,
    "IDL:RtecEventComm/EventData:1.0",
    "EventData",
    &_tc_RtecEventData);
  

namespace RtecEventComm
{
  ::CORBA::TypeCode_ptr const _tc_EventData =
    &_tao_tc_RtecEventComm_EventData;
}

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/alias_typecode.cpp:50

static TAO::TypeCode::Alias<char const *,
                            ::CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_RtecEventComm_Time (
    ::CORBA::tk_alias,
    "IDL:RtecEventComm/Time:1.0",
    "Time",
    &TimeBase::_tc_TimeT);
  

namespace RtecEventComm
{
  ::CORBA::TypeCode_ptr const _tc_Time =
    &_tao_tc_RtecEventComm_Time;
}

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/alias_typecode.cpp:50

static TAO::TypeCode::Alias<char const *,
                            ::CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_RtecEventComm_EventSourceID (
    ::CORBA::tk_alias,
    "IDL:RtecEventComm/EventSourceID:1.0",
    "EventSourceID",
    &CORBA::_tc_long);
  

namespace RtecEventComm
{
  ::CORBA::TypeCode_ptr const _tc_EventSourceID =
    &_tao_tc_RtecEventComm_EventSourceID;
}

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/alias_typecode.cpp:50

static TAO::TypeCode::Alias<char const *,
                            ::CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_RtecEventComm_EventType (
    ::CORBA::tk_alias,
    "IDL:RtecEventComm/EventType:1.0",
    "EventType",
    &CORBA::_tc_long);
  

namespace RtecEventComm
{
  ::CORBA::TypeCode_ptr const _tc_EventType =
    &_tao_tc_RtecEventComm_EventType;
}

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/struct_typecode.cpp:86

static TAO::TypeCode::Struct_Field<
  char const *,
  ::CORBA::TypeCode_ptr const *> const 
    _tao_fields_RtecEventComm_EventHeader[] =
      {
        { "type", &RtecEventComm::_tc_EventType },
        { "source", &RtecEventComm::_tc_EventSourceID },
        { "ttl", &CORBA::_tc_long },
        { "creation_time", &RtecEventComm::_tc_Time },
        { "ec_recv_time", &RtecEventComm::_tc_Time },
        { "ec_send_time", &RtecEventComm::_tc_Time }
      };
  
static TAO::TypeCode::Struct<
  char const *,
  ::CORBA::TypeCode_ptr const *,
  TAO::TypeCode::Struct_Field<
    char const *,
    ::CORBA::TypeCode_ptr const *> const *,
  TAO::Null_RefCount_Policy>
_tao_tc_RtecEventComm_EventHeader (
  ::CORBA::tk_struct,
  "IDL:RtecEventComm/EventHeader:1.0",
  "EventHeader",
  _tao_fields_RtecEventComm_EventHeader,
  6);


namespace RtecEventComm
{
  ::CORBA::TypeCode_ptr const _tc_EventHeader =
    &_tao_tc_RtecEventComm_EventHeader;
}

// TAO_IDL - Generated from 
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_structure/structure_cs.cpp:58

void 
RtecEventComm::EventHeader::_tao_any_destructor (
    void *_tao_void_pointer)
{
  EventHeader *_tao_tmp_pointer =
    static_cast<EventHeader *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/struct_typecode.cpp:86

static TAO::TypeCode::Struct_Field<
  char const *,
  ::CORBA::TypeCode_ptr const *> const 
    _tao_fields_RtecEventComm_Event[] =
      {
        { "header", &RtecEventComm::_tc_EventHeader },
        { "data", &RtecEventComm::_tc_EventData }
      };
  
static TAO::TypeCode::Struct<
  char const *,
  ::CORBA::TypeCode_ptr const *,
  TAO::TypeCode::Struct_Field<
    char const *,
    ::CORBA::TypeCode_ptr const *> const *,
  TAO::Null_RefCount_Policy>
_tao_tc_RtecEventComm_Event (
  ::CORBA::tk_struct,
  "IDL:RtecEventComm/Event:1.0",
  "Event",
  _tao_fields_RtecEventComm_Event,
  2);


namespace RtecEventComm
{
  ::CORBA::TypeCode_ptr const _tc_Event =
    &_tao_tc_RtecEventComm_Event;
}

// TAO_IDL - Generated from 
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_structure/structure_cs.cpp:58

void 
RtecEventComm::Event::_tao_any_destructor (
    void *_tao_void_pointer)
{
  Event *_tao_tmp_pointer =
    static_cast<Event *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

// TAO_IDL - Generated from 
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_RTECEVENTCOMM_EVENTSET_CS_)
#define _RTECEVENTCOMM_EVENTSET_CS_

RtecEventComm::EventSet::EventSet (void)
{}

RtecEventComm::EventSet::EventSet (
    ::CORBA::ULong max)
  : ::TAO::unbounded_value_sequence<
        Event
      > (max)
{}

RtecEventComm::EventSet::EventSet (
    ::CORBA::ULong max,
    ::CORBA::ULong length,
    RtecEventComm::Event * buffer,
    ::CORBA::Boolean release
  )
  : ::TAO::unbounded_value_sequence<
        Event
      >
    (max, length, buffer, release)
{}

RtecEventComm::EventSet::EventSet (
    const EventSet &seq)
  : ::TAO::unbounded_value_sequence<
        Event
      > (seq)
{}

RtecEventComm::EventSet::~EventSet (void)
{}

void RtecEventComm::EventSet::_tao_any_destructor (
    void * _tao_void_pointer)
{
  EventSet * _tao_tmp_pointer =
    static_cast<EventSet *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/alias_typecode.cpp:50



// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/typecode_defn.cpp:460


#ifndef _TAO_TYPECODE_RtecEventComm_EventSet_GUARD
#define _TAO_TYPECODE_RtecEventComm_EventSet_GUARD


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

namespace TAO
{
  namespace TypeCode
  {
    namespace
    {
      TAO::TypeCode::Sequence< ::CORBA::TypeCode_ptr const *,
                              TAO::Null_RefCount_Policy>
        RtecEventComm_EventSet_0 (
          ::CORBA::tk_sequence,
          &RtecEventComm::_tc_Event,
          0U);
        
      ::CORBA::TypeCode_ptr const tc_RtecEventComm_EventSet_0 =
        &RtecEventComm_EventSet_0;
    }
  }
}

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL


#endif /* _TAO_TYPECODE_RtecEventComm_EventSet_GUARD */

static TAO::TypeCode::Alias<char const *,
                            ::CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_RtecEventComm_EventSet (
    ::CORBA::tk_alias,
    "IDL:RtecEventComm/EventSet:1.0",
    "EventSet",
    &TAO::TypeCode::tc_RtecEventComm_EventSet_0);
  

namespace RtecEventComm
{
  ::CORBA::TypeCode_ptr const _tc_EventSet =
    &_tao_tc_RtecEventComm_EventSet;
}

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_cs.cpp:53

// Traits specializations for RtecEventComm::PushConsumer.

RtecEventComm::PushConsumer_ptr
TAO::Objref_Traits<RtecEventComm::PushConsumer>::duplicate (
    RtecEventComm::PushConsumer_ptr p)
{
  return RtecEventComm::PushConsumer::_duplicate (p);
}

void
TAO::Objref_Traits<RtecEventComm::PushConsumer>::release (
    RtecEventComm::PushConsumer_ptr p)
{
  ::CORBA::release (p);
}

RtecEventComm::PushConsumer_ptr
TAO::Objref_Traits<RtecEventComm::PushConsumer>::nil (void)
{
  return RtecEventComm::PushConsumer::_nil ();
}

::CORBA::Boolean
TAO::Objref_Traits<RtecEventComm::PushConsumer>::marshal (
    const RtecEventComm::PushConsumer_ptr p,
    TAO_OutputCDR & cdr)
{
  return ::CORBA::Object::marshal (p, cdr);
}

// Function pointer for collocation factory initialization.
TAO::Collocation_Proxy_Broker * 
(*RtecEventComm__TAO_PushConsumer_Proxy_Broker_Factory_function_pointer) (
    ::CORBA::Object_ptr obj) = 0;

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_cs.cpp:80

void
RtecEventComm::PushConsumer::push (
  const ::RtecEventComm::EventSet & data)
{
  if (!this->is_evaluated ())
    {
      ::CORBA::Object::tao_object_initialize (this);
    }
  
  if (this->the_TAO_PushConsumer_Proxy_Broker_ == 0)
    {
      RtecEventComm_PushConsumer_setup_collocation ();
    }
  
  TAO::Arg_Traits< void>::ret_val _tao_retval;
  TAO::Arg_Traits< ::RtecEventComm::EventSet>::in_arg_val _tao_data (data);

  TAO::Argument *_the_tao_operation_signature [] =
    {
      &_tao_retval,
      &_tao_data
    };

  TAO::Invocation_Adapter _tao_call (
      this,
      _the_tao_operation_signature,
      2,
      "push",
      4,
      this->the_TAO_PushConsumer_Proxy_Broker_,
      TAO::TAO_ONEWAY_INVOCATION
    );

  _tao_call.invoke (0, 0);
}

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_cs.cpp:80

void
RtecEventComm::PushConsumer::disconnect_push_consumer (
  void)
{
  if (!this->is_evaluated ())
    {
      ::CORBA::Object::tao_object_initialize (this);
    }
  
  if (this->the_TAO_PushConsumer_Proxy_Broker_ == 0)
    {
      RtecEventComm_PushConsumer_setup_collocation ();
    }
  
  TAO::Arg_Traits< void>::ret_val _tao_retval;

  TAO::Argument *_the_tao_operation_signature [] =
    {
      &_tao_retval
    };

  TAO::Invocation_Adapter _tao_call (
      this,
      _the_tao_operation_signature,
      1,
      "disconnect_push_consumer",
      24,
      this->the_TAO_PushConsumer_Proxy_Broker_
    );

  _tao_call.invoke (0, 0);
}

RtecEventComm::PushConsumer::PushConsumer (void)
 : the_TAO_PushConsumer_Proxy_Broker_ (0)
{
  this->RtecEventComm_PushConsumer_setup_collocation ();
}

void
RtecEventComm::PushConsumer::RtecEventComm_PushConsumer_setup_collocation ()
{
  if (::RtecEventComm__TAO_PushConsumer_Proxy_Broker_Factory_function_pointer)
    {
      this->the_TAO_PushConsumer_Proxy_Broker_ =
        ::RtecEventComm__TAO_PushConsumer_Proxy_Broker_Factory_function_pointer (this);
    }
}

RtecEventComm::PushConsumer::~PushConsumer (void)
{}

void 
RtecEventComm::PushConsumer::_tao_any_destructor (void *_tao_void_pointer)
{
  PushConsumer *_tao_tmp_pointer =
    static_cast<PushConsumer *> (_tao_void_pointer);
  ::CORBA::release (_tao_tmp_pointer);
}

RtecEventComm::PushConsumer_ptr
RtecEventComm::PushConsumer::_narrow (
    ::CORBA::Object_ptr _tao_objref)
{
  return
    TAO::Narrow_Utils<PushConsumer>::narrow (
        _tao_objref,
        "IDL:RtecEventComm/PushConsumer:1.0",
        RtecEventComm__TAO_PushConsumer_Proxy_Broker_Factory_function_pointer
      );
}

RtecEventComm::PushConsumer_ptr
RtecEventComm::PushConsumer::_unchecked_narrow (
    ::CORBA::Object_ptr _tao_objref)
{
  return
    TAO::Narrow_Utils<PushConsumer>::unchecked_narrow (
        _tao_objref,
        "IDL:RtecEventComm/PushConsumer:1.0",
        RtecEventComm__TAO_PushConsumer_Proxy_Broker_Factory_function_pointer
      );
}

RtecEventComm::PushConsumer_ptr
RtecEventComm::PushConsumer::_nil (void)
{
  return 0;
}

RtecEventComm::PushConsumer_ptr
RtecEventComm::PushConsumer::_duplicate (PushConsumer_ptr obj)
{
  if (! ::CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
RtecEventComm::PushConsumer::_tao_release (PushConsumer_ptr obj)
{
  ::CORBA::release (obj);
}

::CORBA::Boolean
RtecEventComm::PushConsumer::_is_a (const char *value)
{
  if (
      ACE_OS::strcmp (
          value,
          "IDL:RtecEventComm/PushConsumer:1.0"
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

const char* RtecEventComm::PushConsumer::_interface_repository_id (void) const
{
  return "IDL:RtecEventComm/PushConsumer:1.0";
}

::CORBA::Boolean
RtecEventComm::PushConsumer::marshal (TAO_OutputCDR &cdr)
{
  return (cdr << this);
}

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/objref_typecode.cpp:70

static TAO::TypeCode::Objref<char const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_RtecEventComm_PushConsumer (
    ::CORBA::tk_objref,
    "IDL:RtecEventComm/PushConsumer:1.0",
    "PushConsumer");
  

namespace RtecEventComm
{
  ::CORBA::TypeCode_ptr const _tc_PushConsumer =
    &_tao_tc_RtecEventComm_PushConsumer;
}

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_cs.cpp:53

// Traits specializations for RtecEventComm::PushSupplier.

RtecEventComm::PushSupplier_ptr
TAO::Objref_Traits<RtecEventComm::PushSupplier>::duplicate (
    RtecEventComm::PushSupplier_ptr p)
{
  return RtecEventComm::PushSupplier::_duplicate (p);
}

void
TAO::Objref_Traits<RtecEventComm::PushSupplier>::release (
    RtecEventComm::PushSupplier_ptr p)
{
  ::CORBA::release (p);
}

RtecEventComm::PushSupplier_ptr
TAO::Objref_Traits<RtecEventComm::PushSupplier>::nil (void)
{
  return RtecEventComm::PushSupplier::_nil ();
}

::CORBA::Boolean
TAO::Objref_Traits<RtecEventComm::PushSupplier>::marshal (
    const RtecEventComm::PushSupplier_ptr p,
    TAO_OutputCDR & cdr)
{
  return ::CORBA::Object::marshal (p, cdr);
}

// Function pointer for collocation factory initialization.
TAO::Collocation_Proxy_Broker * 
(*RtecEventComm__TAO_PushSupplier_Proxy_Broker_Factory_function_pointer) (
    ::CORBA::Object_ptr obj) = 0;

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_cs.cpp:80

void
RtecEventComm::PushSupplier::disconnect_push_supplier (
  void)
{
  if (!this->is_evaluated ())
    {
      ::CORBA::Object::tao_object_initialize (this);
    }
  
  if (this->the_TAO_PushSupplier_Proxy_Broker_ == 0)
    {
      RtecEventComm_PushSupplier_setup_collocation ();
    }
  
  TAO::Arg_Traits< void>::ret_val _tao_retval;

  TAO::Argument *_the_tao_operation_signature [] =
    {
      &_tao_retval
    };

  TAO::Invocation_Adapter _tao_call (
      this,
      _the_tao_operation_signature,
      1,
      "disconnect_push_supplier",
      24,
      this->the_TAO_PushSupplier_Proxy_Broker_
    );

  _tao_call.invoke (0, 0);
}

RtecEventComm::PushSupplier::PushSupplier (void)
 : the_TAO_PushSupplier_Proxy_Broker_ (0)
{
  this->RtecEventComm_PushSupplier_setup_collocation ();
}

void
RtecEventComm::PushSupplier::RtecEventComm_PushSupplier_setup_collocation ()
{
  if (::RtecEventComm__TAO_PushSupplier_Proxy_Broker_Factory_function_pointer)
    {
      this->the_TAO_PushSupplier_Proxy_Broker_ =
        ::RtecEventComm__TAO_PushSupplier_Proxy_Broker_Factory_function_pointer (this);
    }
}

RtecEventComm::PushSupplier::~PushSupplier (void)
{}

void 
RtecEventComm::PushSupplier::_tao_any_destructor (void *_tao_void_pointer)
{
  PushSupplier *_tao_tmp_pointer =
    static_cast<PushSupplier *> (_tao_void_pointer);
  ::CORBA::release (_tao_tmp_pointer);
}

RtecEventComm::PushSupplier_ptr
RtecEventComm::PushSupplier::_narrow (
    ::CORBA::Object_ptr _tao_objref)
{
  return
    TAO::Narrow_Utils<PushSupplier>::narrow (
        _tao_objref,
        "IDL:RtecEventComm/PushSupplier:1.0",
        RtecEventComm__TAO_PushSupplier_Proxy_Broker_Factory_function_pointer
      );
}

RtecEventComm::PushSupplier_ptr
RtecEventComm::PushSupplier::_unchecked_narrow (
    ::CORBA::Object_ptr _tao_objref)
{
  return
    TAO::Narrow_Utils<PushSupplier>::unchecked_narrow (
        _tao_objref,
        "IDL:RtecEventComm/PushSupplier:1.0",
        RtecEventComm__TAO_PushSupplier_Proxy_Broker_Factory_function_pointer
      );
}

RtecEventComm::PushSupplier_ptr
RtecEventComm::PushSupplier::_nil (void)
{
  return 0;
}

RtecEventComm::PushSupplier_ptr
RtecEventComm::PushSupplier::_duplicate (PushSupplier_ptr obj)
{
  if (! ::CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
RtecEventComm::PushSupplier::_tao_release (PushSupplier_ptr obj)
{
  ::CORBA::release (obj);
}

::CORBA::Boolean
RtecEventComm::PushSupplier::_is_a (const char *value)
{
  if (
      ACE_OS::strcmp (
          value,
          "IDL:RtecEventComm/PushSupplier:1.0"
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

const char* RtecEventComm::PushSupplier::_interface_repository_id (void) const
{
  return "IDL:RtecEventComm/PushSupplier:1.0";
}

::CORBA::Boolean
RtecEventComm::PushSupplier::marshal (TAO_OutputCDR &cdr)
{
  return (cdr << this);
}

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/objref_typecode.cpp:70

static TAO::TypeCode::Objref<char const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_RtecEventComm_PushSupplier (
    ::CORBA::tk_objref,
    "IDL:RtecEventComm/PushSupplier:1.0",
    "PushSupplier");
  

namespace RtecEventComm
{
  ::CORBA::TypeCode_ptr const _tc_PushSupplier =
    &_tao_tc_RtecEventComm_PushSupplier;
}

// TAO_IDL - Generated from 
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_structure/any_op_cs.cpp:45



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace RtecEventComm
{
  // Copying insertion.
  void operator<<= (
      ::CORBA::Any &_tao_any,
      const ::RtecEventComm::EventHeader &_tao_elem
    )
  {
    if (0 == &_tao_elem) // Trying to de-reference NULL object
      _tao_any <<= static_cast< ::RtecEventComm::EventHeader *>( 0 ); // Use non-copying insertion of a NULL
    else
      TAO::Any_Dual_Impl_T< ::RtecEventComm::EventHeader>::insert_copy (
          _tao_any,
          ::RtecEventComm::EventHeader::_tao_any_destructor,
          ::RtecEventComm::_tc_EventHeader,
          _tao_elem
        );
  }

  // Non-copying insertion.
  void operator<<= (
      ::CORBA::Any &_tao_any, ::
      RtecEventComm::EventHeader *_tao_elem
    )
  {
    TAO::Any_Dual_Impl_T< ::RtecEventComm::EventHeader>::insert (
        _tao_any,
        ::RtecEventComm::EventHeader::_tao_any_destructor,
        ::RtecEventComm::_tc_EventHeader,
        _tao_elem
      );
  }

  // Extraction to non-const pointer (deprecated).
  ::CORBA::Boolean operator>>= (
      const ::CORBA::Any &_tao_any,
      ::RtecEventComm::EventHeader *&_tao_elem
    )
  {
    return _tao_any >>= const_cast<
        const ::RtecEventComm::EventHeader *&> (
        _tao_elem
      );
  }

  // Extraction to const pointer.
  ::CORBA::Boolean operator>>= (
      const ::CORBA::Any &_tao_any,
      const ::RtecEventComm::EventHeader *&_tao_elem
    )
  {
    return
      TAO::Any_Dual_Impl_T< ::RtecEventComm::EventHeader>::extract (
          _tao_any,
          ::RtecEventComm::EventHeader::_tao_any_destructor,
          ::RtecEventComm::_tc_EventHeader,
          _tao_elem
        );
  }
}

#else


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Copying insertion.
void operator<<= (
    ::CORBA::Any &_tao_any,
    const RtecEventComm::EventHeader &_tao_elem
  )
{
  if (0 == &_tao_elem) // Trying to de-reference NULL object
    _tao_any <<= static_cast<RtecEventComm::EventHeader *>( 0 ); // Use non-copying insertion of a NULL
  else
    TAO::Any_Dual_Impl_T<RtecEventComm::EventHeader>::insert_copy (
        _tao_any,
        RtecEventComm::EventHeader::_tao_any_destructor,
        RtecEventComm::_tc_EventHeader,
        _tao_elem
      );
}

// Non-copying insertion.
void operator<<= (
    ::CORBA::Any &_tao_any,
    RtecEventComm::EventHeader *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<RtecEventComm::EventHeader>::insert (
      _tao_any,
      RtecEventComm::EventHeader::_tao_any_destructor,
      RtecEventComm::_tc_EventHeader,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
::CORBA::Boolean operator>>= (
    const ::CORBA::Any &_tao_any,
    RtecEventComm::EventHeader *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const RtecEventComm::EventHeader *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
::CORBA::Boolean operator>>= (
    const ::CORBA::Any &_tao_any,
    const RtecEventComm::EventHeader *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<RtecEventComm::EventHeader>::extract (
        _tao_any,
        RtecEventComm::EventHeader::_tao_any_destructor,
        RtecEventComm::_tc_EventHeader,
        _tao_elem
      );
}
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




#endif

// TAO_IDL - Generated from 
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_structure/any_op_cs.cpp:45



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace RtecEventComm
{
  // Copying insertion.
  void operator<<= (
      ::CORBA::Any &_tao_any,
      const ::RtecEventComm::Event &_tao_elem
    )
  {
    if (0 == &_tao_elem) // Trying to de-reference NULL object
      _tao_any <<= static_cast< ::RtecEventComm::Event *>( 0 ); // Use non-copying insertion of a NULL
    else
      TAO::Any_Dual_Impl_T< ::RtecEventComm::Event>::insert_copy (
          _tao_any,
          ::RtecEventComm::Event::_tao_any_destructor,
          ::RtecEventComm::_tc_Event,
          _tao_elem
        );
  }

  // Non-copying insertion.
  void operator<<= (
      ::CORBA::Any &_tao_any, ::
      RtecEventComm::Event *_tao_elem
    )
  {
    TAO::Any_Dual_Impl_T< ::RtecEventComm::Event>::insert (
        _tao_any,
        ::RtecEventComm::Event::_tao_any_destructor,
        ::RtecEventComm::_tc_Event,
        _tao_elem
      );
  }

  // Extraction to non-const pointer (deprecated).
  ::CORBA::Boolean operator>>= (
      const ::CORBA::Any &_tao_any,
      ::RtecEventComm::Event *&_tao_elem
    )
  {
    return _tao_any >>= const_cast<
        const ::RtecEventComm::Event *&> (
        _tao_elem
      );
  }

  // Extraction to const pointer.
  ::CORBA::Boolean operator>>= (
      const ::CORBA::Any &_tao_any,
      const ::RtecEventComm::Event *&_tao_elem
    )
  {
    return
      TAO::Any_Dual_Impl_T< ::RtecEventComm::Event>::extract (
          _tao_any,
          ::RtecEventComm::Event::_tao_any_destructor,
          ::RtecEventComm::_tc_Event,
          _tao_elem
        );
  }
}

#else


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Copying insertion.
void operator<<= (
    ::CORBA::Any &_tao_any,
    const RtecEventComm::Event &_tao_elem
  )
{
  if (0 == &_tao_elem) // Trying to de-reference NULL object
    _tao_any <<= static_cast<RtecEventComm::Event *>( 0 ); // Use non-copying insertion of a NULL
  else
    TAO::Any_Dual_Impl_T<RtecEventComm::Event>::insert_copy (
        _tao_any,
        RtecEventComm::Event::_tao_any_destructor,
        RtecEventComm::_tc_Event,
        _tao_elem
      );
}

// Non-copying insertion.
void operator<<= (
    ::CORBA::Any &_tao_any,
    RtecEventComm::Event *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<RtecEventComm::Event>::insert (
      _tao_any,
      RtecEventComm::Event::_tao_any_destructor,
      RtecEventComm::_tc_Event,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
::CORBA::Boolean operator>>= (
    const ::CORBA::Any &_tao_any,
    RtecEventComm::Event *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const RtecEventComm::Event *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
::CORBA::Boolean operator>>= (
    const ::CORBA::Any &_tao_any,
    const RtecEventComm::Event *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<RtecEventComm::Event>::extract (
        _tao_any,
        RtecEventComm::Event::_tao_any_destructor,
        RtecEventComm::_tc_Event,
        _tao_elem
      );
}
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




#endif

// TAO_IDL - Generated from 
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_sequence/any_op_cs.cpp:46



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace RtecEventComm
{
  
  // Copying insertion.
  void operator<<= (
      ::CORBA::Any &_tao_any,
      const ::RtecEventComm::EventSet &_tao_elem
    )
  {
    if (0 == &_tao_elem) // Trying to de-reference NULL object
      _tao_any <<= static_cast< ::RtecEventComm::EventSet *>( 0 ); // Use non-copying insertion of a NULL
    else
      TAO::Any_Dual_Impl_T< ::RtecEventComm::EventSet>::insert_copy (
          _tao_any,
          ::RtecEventComm::EventSet::_tao_any_destructor,
          ::RtecEventComm::_tc_EventSet,
          _tao_elem
        );
  }

  // Non-copying insertion.
  void operator<<= (
      ::CORBA::Any &_tao_any,
      ::RtecEventComm::EventSet *_tao_elem
    )
  {
    TAO::Any_Dual_Impl_T< ::RtecEventComm::EventSet>::insert (
        _tao_any,
        ::RtecEventComm::EventSet::_tao_any_destructor,
        ::RtecEventComm::_tc_EventSet,
        _tao_elem
      );
  }

  // Extraction to non-const pointer (deprecated).
  ::CORBA::Boolean operator>>= (
      const ::CORBA::Any &_tao_any,
      ::RtecEventComm::EventSet *&_tao_elem
    )
  {
    return _tao_any >>= const_cast<
        const ::RtecEventComm::EventSet *&> (
        _tao_elem
      );
  }

  // Extraction to const pointer.
  ::CORBA::Boolean operator>>= (
      const ::CORBA::Any &_tao_any,
      const ::RtecEventComm::EventSet *&_tao_elem
    )
  {
    return
      TAO::Any_Dual_Impl_T< ::RtecEventComm::EventSet>::extract (
          _tao_any,
          ::RtecEventComm::EventSet::_tao_any_destructor,
          ::RtecEventComm::_tc_EventSet,
          _tao_elem
        );
  }
}

#else



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL


// Copying insertion.
void operator<<= (
    ::CORBA::Any &_tao_any,
    const RtecEventComm::EventSet &_tao_elem
  )
{
  if (0 == &_tao_elem) // Trying to de-reference NULL object
    _tao_any <<= static_cast<RtecEventComm::EventSet *>( 0 ); // Use non-copying insertion of a NULL
  else
    TAO::Any_Dual_Impl_T<RtecEventComm::EventSet>::insert_copy (
        _tao_any,
        RtecEventComm::EventSet::_tao_any_destructor,
        RtecEventComm::_tc_EventSet,
        _tao_elem
      );
}

// Non-copying insertion.
void operator<<= (
    ::CORBA::Any &_tao_any,
    RtecEventComm::EventSet *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<RtecEventComm::EventSet>::insert (
      _tao_any,
      RtecEventComm::EventSet::_tao_any_destructor,
      RtecEventComm::_tc_EventSet,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
::CORBA::Boolean operator>>= (
    const ::CORBA::Any &_tao_any,
    RtecEventComm::EventSet *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const RtecEventComm::EventSet *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
::CORBA::Boolean operator>>= (
    const ::CORBA::Any &_tao_any,
    const RtecEventComm::EventSet *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<RtecEventComm::EventSet>::extract (
        _tao_any,
        RtecEventComm::EventSet::_tao_any_destructor,
        RtecEventComm::_tc_EventSet,
        _tao_elem
      );
}
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




#endif

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/any_op_cs.cpp:46

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



namespace TAO
{
  template<>
  ::CORBA::Boolean
  Any_Impl_T<RtecEventComm::PushConsumer>::to_object (
      ::CORBA::Object_ptr &_tao_elem
    ) const
  {
    _tao_elem = ::CORBA::Object::_duplicate (this->value_);
    return true;
  }
}
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace RtecEventComm
{
  

  /// Copying insertion.
  void
  operator<<= (
      ::CORBA::Any &_tao_any,
      PushConsumer_ptr _tao_elem)
  {
    PushConsumer_ptr _tao_objptr =
      PushConsumer::_duplicate (_tao_elem);
    _tao_any <<= &_tao_objptr;
  }

  /// Non-copying insertion.
  void
  operator<<= (
      ::CORBA::Any &_tao_any,
      PushConsumer_ptr *_tao_elem)
  {
    TAO::Any_Impl_T<PushConsumer>::insert (
        _tao_any,
        PushConsumer::_tao_any_destructor,
        _tc_PushConsumer,
        *_tao_elem);
  }

  ::CORBA::Boolean
  operator>>= (
      const ::CORBA::Any &_tao_any,
      PushConsumer_ptr &_tao_elem)
  {
    return
      TAO::Any_Impl_T<PushConsumer>::extract (
          _tao_any,
          PushConsumer::_tao_any_destructor,
          _tc_PushConsumer,
          _tao_elem);
  }
}

#else


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



/// Copying insertion.
void
operator<<= (
    ::CORBA::Any &_tao_any,
    RtecEventComm::PushConsumer_ptr _tao_elem)
{
  RtecEventComm::PushConsumer_ptr _tao_objptr =
    RtecEventComm::PushConsumer::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

/// Non-copying insertion.
void
operator<<= (
    ::CORBA::Any &_tao_any,
    RtecEventComm::PushConsumer_ptr *_tao_elem)
{
  TAO::Any_Impl_T<RtecEventComm::PushConsumer>::insert (
      _tao_any,
      RtecEventComm::PushConsumer::_tao_any_destructor,
      RtecEventComm::_tc_PushConsumer,
      *_tao_elem);
}

::CORBA::Boolean
operator>>= (
    const ::CORBA::Any &_tao_any,
    RtecEventComm::PushConsumer_ptr &_tao_elem)
{
  return
    TAO::Any_Impl_T<RtecEventComm::PushConsumer>::extract (
        _tao_any,
        RtecEventComm::PushConsumer::_tao_any_destructor,
        RtecEventComm::_tc_PushConsumer,
        _tao_elem);
}

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




#endif

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/any_op_cs.cpp:46

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



namespace TAO
{
  template<>
  ::CORBA::Boolean
  Any_Impl_T<RtecEventComm::PushSupplier>::to_object (
      ::CORBA::Object_ptr &_tao_elem
    ) const
  {
    _tao_elem = ::CORBA::Object::_duplicate (this->value_);
    return true;
  }
}
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace RtecEventComm
{
  

  /// Copying insertion.
  void
  operator<<= (
      ::CORBA::Any &_tao_any,
      PushSupplier_ptr _tao_elem)
  {
    PushSupplier_ptr _tao_objptr =
      PushSupplier::_duplicate (_tao_elem);
    _tao_any <<= &_tao_objptr;
  }

  /// Non-copying insertion.
  void
  operator<<= (
      ::CORBA::Any &_tao_any,
      PushSupplier_ptr *_tao_elem)
  {
    TAO::Any_Impl_T<PushSupplier>::insert (
        _tao_any,
        PushSupplier::_tao_any_destructor,
        _tc_PushSupplier,
        *_tao_elem);
  }

  ::CORBA::Boolean
  operator>>= (
      const ::CORBA::Any &_tao_any,
      PushSupplier_ptr &_tao_elem)
  {
    return
      TAO::Any_Impl_T<PushSupplier>::extract (
          _tao_any,
          PushSupplier::_tao_any_destructor,
          _tc_PushSupplier,
          _tao_elem);
  }
}

#else


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



/// Copying insertion.
void
operator<<= (
    ::CORBA::Any &_tao_any,
    RtecEventComm::PushSupplier_ptr _tao_elem)
{
  RtecEventComm::PushSupplier_ptr _tao_objptr =
    RtecEventComm::PushSupplier::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

/// Non-copying insertion.
void
operator<<= (
    ::CORBA::Any &_tao_any,
    RtecEventComm::PushSupplier_ptr *_tao_elem)
{
  TAO::Any_Impl_T<RtecEventComm::PushSupplier>::insert (
      _tao_any,
      RtecEventComm::PushSupplier::_tao_any_destructor,
      RtecEventComm::_tc_PushSupplier,
      *_tao_elem);
}

::CORBA::Boolean
operator>>= (
    const ::CORBA::Any &_tao_any,
    RtecEventComm::PushSupplier_ptr &_tao_elem)
{
  return
    TAO::Any_Impl_T<RtecEventComm::PushSupplier>::extract (
        _tao_any,
        RtecEventComm::PushSupplier::_tao_any_destructor,
        RtecEventComm::_tc_PushSupplier,
        _tao_elem);
}

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




#endif

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_structure/cdr_op_cs.cpp:52


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const RtecEventComm::EventHeader &_tao_aggregate)
{
  return
    (strm << _tao_aggregate.type) &&
    (strm << _tao_aggregate.source) &&
    (strm << _tao_aggregate.ttl) &&
    (strm << _tao_aggregate.creation_time) &&
    (strm << _tao_aggregate.ec_recv_time) &&
    (strm << _tao_aggregate.ec_send_time);
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    RtecEventComm::EventHeader &_tao_aggregate)
{
  return
    (strm >> _tao_aggregate.type) &&
    (strm >> _tao_aggregate.source) &&
    (strm >> _tao_aggregate.ttl) &&
    (strm >> _tao_aggregate.creation_time) &&
    (strm >> _tao_aggregate.ec_recv_time) &&
    (strm >> _tao_aggregate.ec_send_time);
}

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_structure/cdr_op_cs.cpp:52


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const RtecEventComm::Event &_tao_aggregate)
{
  return
    (strm << _tao_aggregate.header) &&
    (strm << _tao_aggregate.data);
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    RtecEventComm::Event &_tao_aggregate)
{
  return
    (strm >> _tao_aggregate.header) &&
    (strm >> _tao_aggregate.data);
}

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_sequence/cdr_op_cs.cpp:90
#if !defined _TAO_CDR_OP_RtecEventComm_EventSet_CPP_
#define _TAO_CDR_OP_RtecEventComm_EventSet_CPP_


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const RtecEventComm::EventSet &_tao_sequence)
{
  return TAO::marshal_sequence(strm, _tao_sequence);
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    RtecEventComm::EventSet &_tao_sequence)
{
  return TAO::demarshal_sequence(strm, _tao_sequence);
}


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL


#endif /* _TAO_CDR_OP_RtecEventComm_EventSet_CPP_ */

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/cdr_op_cs.cpp:53


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const RtecEventComm::PushConsumer_ptr _tao_objref)
{
  ::CORBA::Object_ptr _tao_corba_obj = _tao_objref;
  return (strm << _tao_corba_obj);
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    RtecEventComm::PushConsumer_ptr &_tao_objref)
{
  ::CORBA::Object_var obj;

  if (!(strm >> obj.inout ()))
    {
      return false;
    }
  
  typedef ::RtecEventComm::PushConsumer RHS_SCOPED_NAME;

  // Narrow to the right type.
  _tao_objref =
    TAO::Narrow_Utils<RHS_SCOPED_NAME>::unchecked_narrow (
        obj.in (),
        RtecEventComm__TAO_PushConsumer_Proxy_Broker_Factory_function_pointer
      );
    
  return true;
}

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/cdr_op_cs.cpp:53


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const RtecEventComm::PushSupplier_ptr _tao_objref)
{
  ::CORBA::Object_ptr _tao_corba_obj = _tao_objref;
  return (strm << _tao_corba_obj);
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    RtecEventComm::PushSupplier_ptr &_tao_objref)
{
  ::CORBA::Object_var obj;

  if (!(strm >> obj.inout ()))
    {
      return false;
    }
  
  typedef ::RtecEventComm::PushSupplier RHS_SCOPED_NAME;

  // Narrow to the right type.
  _tao_objref =
    TAO::Narrow_Utils<RHS_SCOPED_NAME>::unchecked_narrow (
        obj.in (),
        RtecEventComm__TAO_PushSupplier_Proxy_Broker_Factory_function_pointer
      );
    
  return true;
}

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL





TAO_END_VERSIONED_NAMESPACE_DECL


