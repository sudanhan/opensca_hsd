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


#include "FT_NotifierC.h"
#include "tao/AnyTypeCode/Null_RefCount_Policy.h"
#include "tao/AnyTypeCode/TypeCode_Constants.h"
#include "tao/AnyTypeCode/Alias_TypeCode_Static.h"
#include "tao/AnyTypeCode/Objref_TypeCode_Static.h"
#include "tao/AnyTypeCode/String_TypeCode_Static.h"
#include "tao/CDR.h"
#include "tao/Exception_Data.h"
#include "tao/Invocation_Adapter.h"
#include "tao/Object_T.h"
#include "tao/CDR.h"
#include "tao/AnyTypeCode/Any.h"
#include "tao/AnyTypeCode/Any_Impl_T.h"
#include "ace/OS_NS_string.h"

#if !defined (__ACE_INLINE__)
#include "FT_NotifierC.inl"
#endif /* !defined INLINE */

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_cs.cpp:53

// Traits specializations for FT::FaultNotifier.

FT::FaultNotifier_ptr
TAO::Objref_Traits<FT::FaultNotifier>::duplicate (
    FT::FaultNotifier_ptr p)
{
  return FT::FaultNotifier::_duplicate (p);
}

void
TAO::Objref_Traits<FT::FaultNotifier>::release (
    FT::FaultNotifier_ptr p)
{
  ::CORBA::release (p);
}

FT::FaultNotifier_ptr
TAO::Objref_Traits<FT::FaultNotifier>::nil (void)
{
  return FT::FaultNotifier::_nil ();
}

::CORBA::Boolean
TAO::Objref_Traits<FT::FaultNotifier>::marshal (
    const FT::FaultNotifier_ptr p,
    TAO_OutputCDR & cdr)
{
  return ::CORBA::Object::marshal (p, cdr);
}

// Function pointer for collocation factory initialization.
TAO::Collocation_Proxy_Broker * 
(*FT__TAO_FaultNotifier_Proxy_Broker_Factory_function_pointer) (
    ::CORBA::Object_ptr obj) = 0;

// TAO_IDL - Generated from
// e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/alias_typecode.cpp:50

static TAO::TypeCode::Alias<char const *,
                            ::CORBA::TypeCode_ptr const *,
                            TAO::Null_RefCount_Policy>
  _tao_tc_FT_FaultNotifier_ConsumerId (
    ::CORBA::tk_alias,
    "IDL:omg.org/FT/FaultNotifier/ConsumerId:1.0",
    "ConsumerId",
    &CORBA::_tc_ulonglong);
  
::CORBA::TypeCode_ptr const FT::FaultNotifier::_tc_ConsumerId =
  &_tao_tc_FT_FaultNotifier_ConsumerId;

// TAO_IDL - Generated from
// e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_cs.cpp:80

void
FT::FaultNotifier::push_structured_fault (
  const ::CosNotification::StructuredEvent & event)
{
  if (!this->is_evaluated ())
    {
      ::CORBA::Object::tao_object_initialize (this);
    }
  
  if (this->the_TAO_FaultNotifier_Proxy_Broker_ == 0)
    {
      FT_FaultNotifier_setup_collocation ();
    }
  
  TAO::Arg_Traits< void>::ret_val _tao_retval;
  TAO::Arg_Traits< ::CosNotification::StructuredEvent>::in_arg_val _tao_event (event);

  TAO::Argument *_the_tao_operation_signature [] =
    {
      &_tao_retval,
      &_tao_event
    };

  TAO::Invocation_Adapter _tao_call (
      this,
      _the_tao_operation_signature,
      2,
      "push_structured_fault",
      21,
      this->the_TAO_FaultNotifier_Proxy_Broker_
    );

  _tao_call.invoke (0, 0);
}

// TAO_IDL - Generated from
// e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_cs.cpp:80

void
FT::FaultNotifier::push_sequence_fault (
  const ::CosNotification::EventBatch & events)
{
  if (!this->is_evaluated ())
    {
      ::CORBA::Object::tao_object_initialize (this);
    }
  
  if (this->the_TAO_FaultNotifier_Proxy_Broker_ == 0)
    {
      FT_FaultNotifier_setup_collocation ();
    }
  
  TAO::Arg_Traits< void>::ret_val _tao_retval;
  TAO::Arg_Traits< ::CosNotification::EventBatch>::in_arg_val _tao_events (events);

  TAO::Argument *_the_tao_operation_signature [] =
    {
      &_tao_retval,
      &_tao_events
    };

  TAO::Invocation_Adapter _tao_call (
      this,
      _the_tao_operation_signature,
      2,
      "push_sequence_fault",
      19,
      this->the_TAO_FaultNotifier_Proxy_Broker_
    );

  _tao_call.invoke (0, 0);
}

// TAO_IDL - Generated from
// e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_cs.cpp:80

::CosNotifyFilter::Filter_ptr
FT::FaultNotifier::create_subscription_filter (
  const char * constraint_grammar)
{
  if (!this->is_evaluated ())
    {
      ::CORBA::Object::tao_object_initialize (this);
    }
  
  if (this->the_TAO_FaultNotifier_Proxy_Broker_ == 0)
    {
      FT_FaultNotifier_setup_collocation ();
    }
  
  TAO::Arg_Traits< ::CosNotifyFilter::Filter>::ret_val _tao_retval;
  TAO::Arg_Traits< char *>::in_arg_val _tao_constraint_grammar (constraint_grammar);

  TAO::Argument *_the_tao_operation_signature [] =
    {
      &_tao_retval,
      &_tao_constraint_grammar
    };

  static TAO::Exception_Data
  _tao_FT_FaultNotifier_create_subscription_filter_exceptiondata [] = 
    {
      {
        "IDL:omg.org/CosNotifyFilter/InvalidGrammar:1.0",
        CosNotifyFilter::InvalidGrammar::_alloc
#if TAO_HAS_INTERCEPTORS == 1
        , CosNotifyFilter::_tc_InvalidGrammar
#endif /* TAO_HAS_INTERCEPTORS */
      }
    };

  TAO::Invocation_Adapter _tao_call (
      this,
      _the_tao_operation_signature,
      2,
      "create_subscription_filter",
      26,
      this->the_TAO_FaultNotifier_Proxy_Broker_
    );

  _tao_call.invoke (
      _tao_FT_FaultNotifier_create_subscription_filter_exceptiondata,
      1
    );

  return _tao_retval.retn ();
}

// TAO_IDL - Generated from
// e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_cs.cpp:80

::FT::FaultNotifier::ConsumerId
FT::FaultNotifier::connect_structured_fault_consumer (
  ::CosNotifyComm::StructuredPushConsumer_ptr push_consumer,
  ::CosNotifyFilter::Filter_ptr filter)
{
  if (!this->is_evaluated ())
    {
      ::CORBA::Object::tao_object_initialize (this);
    }
  
  if (this->the_TAO_FaultNotifier_Proxy_Broker_ == 0)
    {
      FT_FaultNotifier_setup_collocation ();
    }
  
  TAO::Arg_Traits< ::CORBA::ULongLong>::ret_val _tao_retval;
  TAO::Arg_Traits< ::CosNotifyComm::StructuredPushConsumer>::in_arg_val _tao_push_consumer (push_consumer);
  TAO::Arg_Traits< ::CosNotifyFilter::Filter>::in_arg_val _tao_filter (filter);

  TAO::Argument *_the_tao_operation_signature [] =
    {
      &_tao_retval,
      &_tao_push_consumer,
      &_tao_filter
    };

  TAO::Invocation_Adapter _tao_call (
      this,
      _the_tao_operation_signature,
      3,
      "connect_structured_fault_consumer",
      33,
      this->the_TAO_FaultNotifier_Proxy_Broker_
    );

  _tao_call.invoke (0, 0);

  return _tao_retval.retn ();
}

// TAO_IDL - Generated from
// e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_cs.cpp:80

::FT::FaultNotifier::ConsumerId
FT::FaultNotifier::connect_sequence_fault_consumer (
  ::CosNotifyComm::SequencePushConsumer_ptr push_consumer,
  ::CosNotifyFilter::Filter_ptr filter)
{
  if (!this->is_evaluated ())
    {
      ::CORBA::Object::tao_object_initialize (this);
    }
  
  if (this->the_TAO_FaultNotifier_Proxy_Broker_ == 0)
    {
      FT_FaultNotifier_setup_collocation ();
    }
  
  TAO::Arg_Traits< ::CORBA::ULongLong>::ret_val _tao_retval;
  TAO::Arg_Traits< ::CosNotifyComm::SequencePushConsumer>::in_arg_val _tao_push_consumer (push_consumer);
  TAO::Arg_Traits< ::CosNotifyFilter::Filter>::in_arg_val _tao_filter (filter);

  TAO::Argument *_the_tao_operation_signature [] =
    {
      &_tao_retval,
      &_tao_push_consumer,
      &_tao_filter
    };

  TAO::Invocation_Adapter _tao_call (
      this,
      _the_tao_operation_signature,
      3,
      "connect_sequence_fault_consumer",
      31,
      this->the_TAO_FaultNotifier_Proxy_Broker_
    );

  _tao_call.invoke (0, 0);

  return _tao_retval.retn ();
}

// TAO_IDL - Generated from
// e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_cs.cpp:80

void
FT::FaultNotifier::disconnect_consumer (
  ::FT::FaultNotifier::ConsumerId connection)
{
  if (!this->is_evaluated ())
    {
      ::CORBA::Object::tao_object_initialize (this);
    }
  
  if (this->the_TAO_FaultNotifier_Proxy_Broker_ == 0)
    {
      FT_FaultNotifier_setup_collocation ();
    }
  
  TAO::Arg_Traits< void>::ret_val _tao_retval;
  TAO::Arg_Traits< ::CORBA::ULongLong>::in_arg_val _tao_connection (connection);

  TAO::Argument *_the_tao_operation_signature [] =
    {
      &_tao_retval,
      &_tao_connection
    };

  static TAO::Exception_Data
  _tao_FT_FaultNotifier_disconnect_consumer_exceptiondata [] = 
    {
      {
        "IDL:omg.org/CosEventComm/Disconnected:1.0",
        CosEventComm::Disconnected::_alloc
#if TAO_HAS_INTERCEPTORS == 1
        , CosEventComm::_tc_Disconnected
#endif /* TAO_HAS_INTERCEPTORS */
      }
    };

  TAO::Invocation_Adapter _tao_call (
      this,
      _the_tao_operation_signature,
      2,
      "disconnect_consumer",
      19,
      this->the_TAO_FaultNotifier_Proxy_Broker_
    );

  _tao_call.invoke (
      _tao_FT_FaultNotifier_disconnect_consumer_exceptiondata,
      1
    );
}

FT::FaultNotifier::FaultNotifier (void)
 : the_TAO_FaultNotifier_Proxy_Broker_ (0)
{
  this->FT_FaultNotifier_setup_collocation ();
}

void
FT::FaultNotifier::FT_FaultNotifier_setup_collocation ()
{
  if (::FT__TAO_FaultNotifier_Proxy_Broker_Factory_function_pointer)
    {
      this->the_TAO_FaultNotifier_Proxy_Broker_ =
        ::FT__TAO_FaultNotifier_Proxy_Broker_Factory_function_pointer (this);
    }
  
  this->FT_PullMonitorable_setup_collocation ();
}

FT::FaultNotifier::~FaultNotifier (void)
{}

void 
FT::FaultNotifier::_tao_any_destructor (void *_tao_void_pointer)
{
  FaultNotifier *_tao_tmp_pointer =
    static_cast<FaultNotifier *> (_tao_void_pointer);
  ::CORBA::release (_tao_tmp_pointer);
}

FT::FaultNotifier_ptr
FT::FaultNotifier::_narrow (
    ::CORBA::Object_ptr _tao_objref)
{
  return
    TAO::Narrow_Utils<FaultNotifier>::narrow (
        _tao_objref,
        "IDL:omg.org/FT/FaultNotifier:1.0",
        FT__TAO_FaultNotifier_Proxy_Broker_Factory_function_pointer
      );
}

FT::FaultNotifier_ptr
FT::FaultNotifier::_unchecked_narrow (
    ::CORBA::Object_ptr _tao_objref)
{
  return
    TAO::Narrow_Utils<FaultNotifier>::unchecked_narrow (
        _tao_objref,
        "IDL:omg.org/FT/FaultNotifier:1.0",
        FT__TAO_FaultNotifier_Proxy_Broker_Factory_function_pointer
      );
}

FT::FaultNotifier_ptr
FT::FaultNotifier::_nil (void)
{
  return 0;
}

FT::FaultNotifier_ptr
FT::FaultNotifier::_duplicate (FaultNotifier_ptr obj)
{
  if (! ::CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
FT::FaultNotifier::_tao_release (FaultNotifier_ptr obj)
{
  ::CORBA::release (obj);
}

::CORBA::Boolean
FT::FaultNotifier::_is_a (const char *value)
{
  if (
      ACE_OS::strcmp (
          value,
          "IDL:omg.org/FT/PullMonitorable:1.0"
        ) == 0 ||
      ACE_OS::strcmp (
          value,
          "IDL:omg.org/FT/FaultNotifier:1.0"
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

const char* FT::FaultNotifier::_interface_repository_id (void) const
{
  return "IDL:omg.org/FT/FaultNotifier:1.0";
}

::CORBA::Boolean
FT::FaultNotifier::marshal (TAO_OutputCDR &cdr)
{
  return (cdr << this);
}

// TAO_IDL - Generated from
// e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/objref_typecode.cpp:70

static TAO::TypeCode::Objref<char const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_FT_FaultNotifier (
    ::CORBA::tk_objref,
    "IDL:omg.org/FT/FaultNotifier:1.0",
    "FaultNotifier");
  

namespace FT
{
  ::CORBA::TypeCode_ptr const _tc_FaultNotifier =
    &_tao_tc_FT_FaultNotifier;
}

// TAO_IDL - Generated from
// e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_interface/any_op_cs.cpp:46

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



namespace TAO
{
  template<>
  ::CORBA::Boolean
  Any_Impl_T<FT::FaultNotifier>::to_object (
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

namespace FT
{
  

  /// Copying insertion.
  void
  operator<<= (
      ::CORBA::Any &_tao_any,
      FaultNotifier_ptr _tao_elem)
  {
    FaultNotifier_ptr _tao_objptr =
      FaultNotifier::_duplicate (_tao_elem);
    _tao_any <<= &_tao_objptr;
  }

  /// Non-copying insertion.
  void
  operator<<= (
      ::CORBA::Any &_tao_any,
      FaultNotifier_ptr *_tao_elem)
  {
    TAO::Any_Impl_T<FaultNotifier>::insert (
        _tao_any,
        FaultNotifier::_tao_any_destructor,
        _tc_FaultNotifier,
        *_tao_elem);
  }

  ::CORBA::Boolean
  operator>>= (
      const ::CORBA::Any &_tao_any,
      FaultNotifier_ptr &_tao_elem)
  {
    return
      TAO::Any_Impl_T<FaultNotifier>::extract (
          _tao_any,
          FaultNotifier::_tao_any_destructor,
          _tc_FaultNotifier,
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
    FT::FaultNotifier_ptr _tao_elem)
{
  FT::FaultNotifier_ptr _tao_objptr =
    FT::FaultNotifier::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

/// Non-copying insertion.
void
operator<<= (
    ::CORBA::Any &_tao_any,
    FT::FaultNotifier_ptr *_tao_elem)
{
  TAO::Any_Impl_T<FT::FaultNotifier>::insert (
      _tao_any,
      FT::FaultNotifier::_tao_any_destructor,
      FT::_tc_FaultNotifier,
      *_tao_elem);
}

::CORBA::Boolean
operator>>= (
    const ::CORBA::Any &_tao_any,
    FT::FaultNotifier_ptr &_tao_elem)
{
  return
    TAO::Any_Impl_T<FT::FaultNotifier>::extract (
        _tao_any,
        FT::FaultNotifier::_tao_any_destructor,
        FT::_tc_FaultNotifier,
        _tao_elem);
}

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




#endif

// TAO_IDL - Generated from
// e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_interface/cdr_op_cs.cpp:53


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const FT::FaultNotifier_ptr _tao_objref)
{
  ::CORBA::Object_ptr _tao_corba_obj = _tao_objref;
  return (strm << _tao_corba_obj);
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    FT::FaultNotifier_ptr &_tao_objref)
{
  ::CORBA::Object_var obj;

  if (!(strm >> obj.inout ()))
    {
      return false;
    }
  
  typedef ::FT::FaultNotifier RHS_SCOPED_NAME;

  // Narrow to the right type.
  _tao_objref =
    TAO::Narrow_Utils<RHS_SCOPED_NAME>::unchecked_narrow (
        obj.in (),
        FT__TAO_FaultNotifier_Proxy_Broker_Factory_function_pointer
      );
    
  return true;
}

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL





TAO_END_VERSIONED_NAMESPACE_DECL


