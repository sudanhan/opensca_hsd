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
// .\be\be_codegen.cpp:150

#ifndef _TAO_IDL_FTRTC_ZJ5ZKT_H_
#define _TAO_IDL_FTRTC_ZJ5ZKT_H_


#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#include /**/ "orbsvcs/FtRtEvent/Utils/ftrtevent_export.h"
#include "tao/AnyTypeCode/AnyTypeCode_methods.h"
#include "tao/AnyTypeCode/Any.h"
#include "tao/Valuetype/ValueBase.h"
#include "tao/Valuetype/Valuetype_Adapter_Factory_Impl.h"
#include "tao/ORB.h"
#include "tao/SystemException.h"
#include "tao/UserException.h"
#include "tao/Basic_Types.h"
#include "tao/ORB_Constants.h"
#include "tao/Object.h"
#include "tao/String_Manager_T.h"
#include "tao/Messaging/Messaging.h"
#include "tao/AnyTypeCode/IOPA.h"
#include "tao/Sequence_T.h"
#include "tao/Valuetype/Value_VarOut_T.h"
#include "tao/Objref_VarOut_T.h"
#include "tao/Seq_Var_T.h"
#include "tao/Seq_Out_T.h"
#include "tao/VarOut_T.h"
#include "tao/Arg_Traits_T.h"
#include "tao/Basic_Arguments.h"
#include "tao/Special_Basic_Arguments.h"
#include "tao/Any_Insert_Policy_T.h"
#include "tao/Fixed_Size_Argument_T.h"
#include "tao/Var_Size_Argument_T.h"
#include "tao/Object_Argument_T.h"
#include /**/ "tao/Version.h"
#include /**/ "tao/Versioned_Namespace.h"

#include "tao/IOPC.h"

#if TAO_MAJOR_VERSION != 2 || TAO_MINOR_VERSION != 0 || TAO_BETA_VERSION != 4
#error This file should be regenerated with TAO_IDL from version 2.0a
#endif

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_FtRtEvent_Export

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from 
// e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_root/root_ch.cpp:162

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



namespace TAO
{
  class Collocation_Proxy_Broker;
  template<typename T> class Narrow_Utils;
}
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_module/module_ch.cpp:41

namespace FTRT
{

  // TAO_IDL - Generated from
  // e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_typedef/typedef_ch.cpp:369

  typedef ::CORBA::Long TransactionDepth;
  typedef ::CORBA::Long_out TransactionDepth_out;

  // TAO_IDL - Generated from
  // e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:39

  extern TAO_FtRtEvent_Export ::CORBA::TypeCode_ptr const _tc_TransactionDepth;

  // TAO_IDL - Generated from
  // e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_typedef/typedef_ch.cpp:369

  typedef ::CORBA::ULong SequenceNumber;
  typedef ::CORBA::ULong_out SequenceNumber_out;

  // TAO_IDL - Generated from
  // e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:39

  extern TAO_FtRtEvent_Export ::CORBA::TypeCode_ptr const _tc_SequenceNumber;

  // TAO_IDL - Generated from
  // e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_constant/constant_ch.cpp:41

  const CORBA::ULong FT_TRANSACTION_DEPTH = 30U;

  // TAO_IDL - Generated from
  // e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_constant/constant_ch.cpp:41

  const CORBA::ULong FT_SEQUENCE_NUMBER = 31U;

  // TAO_IDL - Generated from
  // e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_constant/constant_ch.cpp:41

  const CORBA::ULong FT_FORWARD = 32U;

  // TAO_IDL - Generated from
  // .\be\be_type.cpp:261

  struct FTTransactionDepthServiceContext;

  typedef
    ::TAO_Fixed_Var_T<
        FTTransactionDepthServiceContext
      >
    FTTransactionDepthServiceContext_var;
  
  typedef
    FTTransactionDepthServiceContext &
    FTTransactionDepthServiceContext_out;

  // TAO_IDL - Generated from
  // e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_structure/structure_ch.cpp:49

  struct TAO_FtRtEvent_Export FTTransactionDepthServiceContext
  {

    // TAO_IDL - Generated from
    // .\be\be_type.cpp:307
    
    typedef FTTransactionDepthServiceContext_var _var_type;
    typedef FTTransactionDepthServiceContext_out _out_type;

    static void _tao_any_destructor (void *);
    
    FTRT::TransactionDepth transaction_depth;
  };

  // TAO_IDL - Generated from
  // e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:39

  extern TAO_FtRtEvent_Export ::CORBA::TypeCode_ptr const _tc_FTTransactionDepthServiceContext;

  // TAO_IDL - Generated from
  // .\be\be_type.cpp:261

  struct FTSequenceNumberServiceContext;

  typedef
    ::TAO_Fixed_Var_T<
        FTSequenceNumberServiceContext
      >
    FTSequenceNumberServiceContext_var;
  
  typedef
    FTSequenceNumberServiceContext &
    FTSequenceNumberServiceContext_out;

  // TAO_IDL - Generated from
  // e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_structure/structure_ch.cpp:49

  struct TAO_FtRtEvent_Export FTSequenceNumberServiceContext
  {

    // TAO_IDL - Generated from
    // .\be\be_type.cpp:307
    
    typedef FTSequenceNumberServiceContext_var _var_type;
    typedef FTSequenceNumberServiceContext_out _out_type;

    static void _tao_any_destructor (void *);
    
    FTRT::SequenceNumber sequence_number;
  };

  // TAO_IDL - Generated from
  // e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:39

  extern TAO_FtRtEvent_Export ::CORBA::TypeCode_ptr const _tc_FTSequenceNumberServiceContext;

  // TAO_IDL - Generated from
  // .\be\be_type.cpp:261

  struct FTForwardServiceContext;

  typedef
    ::TAO_Var_Var_T<
        FTForwardServiceContext
      >
    FTForwardServiceContext_var;
  
  typedef
    ::TAO_Out_T<
        FTForwardServiceContext
      >
    FTForwardServiceContext_out;

  // TAO_IDL - Generated from
  // e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_structure/structure_ch.cpp:49

  struct TAO_FtRtEvent_Export FTForwardServiceContext
  {

    // TAO_IDL - Generated from
    // .\be\be_type.cpp:307
    
    typedef FTForwardServiceContext_var _var_type;
    typedef FTForwardServiceContext_out _out_type;

    static void _tao_any_destructor (void *);
    
    ::CORBA::Object_var forward;
  };

  // TAO_IDL - Generated from
  // e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:39

  extern TAO_FtRtEvent_Export ::CORBA::TypeCode_ptr const _tc_FTForwardServiceContext;

  // TAO_IDL - Generated from
  // e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_exception/exception_ch.cpp:43

  class TAO_FtRtEvent_Export OutOfSequence : public ::CORBA::UserException
  {
  public:
    
    FTRT::SequenceNumber current;
    OutOfSequence (void);
    OutOfSequence (const OutOfSequence &);
    ~OutOfSequence (void);

    OutOfSequence &operator= (const OutOfSequence &);

    static void _tao_any_destructor (void *);

    static OutOfSequence *_downcast ( ::CORBA::Exception *);
    static const OutOfSequence *_downcast ( ::CORBA::Exception const *);

    static ::CORBA::Exception *_alloc (void);

    virtual ::CORBA::Exception *_tao_duplicate (void) const;

    virtual void _raise (void) const;

    virtual void _tao_encode (TAO_OutputCDR &cdr) const;
    virtual void _tao_decode (TAO_InputCDR &cdr);
    

    // TAO_IDL - Generated from
    // e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_exception/exception_ctor.cpp:56

    OutOfSequence (
        FTRT::SequenceNumber _tao_current);

    virtual ::CORBA::TypeCode_ptr _tao_type (void) const;
  };

  // TAO_IDL - Generated from
  // e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:39

  extern TAO_FtRtEvent_Export ::CORBA::TypeCode_ptr const _tc_OutOfSequence;

  // TAO_IDL - Generated from
  // e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_exception/exception_ch.cpp:43

  class TAO_FtRtEvent_Export TransactionDepthTooHigh : public ::CORBA::UserException
  {
  public:
    
    TransactionDepthTooHigh (void);
    TransactionDepthTooHigh (const TransactionDepthTooHigh &);
    ~TransactionDepthTooHigh (void);

    TransactionDepthTooHigh &operator= (const TransactionDepthTooHigh &);

    static void _tao_any_destructor (void *);

    static TransactionDepthTooHigh *_downcast ( ::CORBA::Exception *);
    static const TransactionDepthTooHigh *_downcast ( ::CORBA::Exception const *);

    static ::CORBA::Exception *_alloc (void);

    virtual ::CORBA::Exception *_tao_duplicate (void) const;

    virtual void _raise (void) const;

    virtual void _tao_encode (TAO_OutputCDR &cdr) const;
    virtual void _tao_decode (TAO_InputCDR &cdr);
    

    virtual ::CORBA::TypeCode_ptr _tao_type (void) const;
  };

  // TAO_IDL - Generated from
  // e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:39

  extern TAO_FtRtEvent_Export ::CORBA::TypeCode_ptr const _tc_TransactionDepthTooHigh;

  // TAO_IDL - Generated from
  // e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_sequence/sequence_ch.cpp:100

#if !defined (_FTRT_STATE_CH_)
#define _FTRT_STATE_CH_

  class State;

  typedef
    ::TAO_FixedSeq_Var_T<
        State
      >
    State_var;

  typedef
    ::TAO_Seq_Out_T<
        State
      >
    State_out;

  class TAO_FtRtEvent_Export State
    : public
        ::TAO::unbounded_value_sequence<
            ::CORBA::Octet
          >
  {
  public:
    State (void);
    State ( ::CORBA::ULong max);
    State (
      ::CORBA::ULong max,
      ::CORBA::ULong length,
      ::CORBA::Octet* buffer, 
      ::CORBA::Boolean release = false);
    State (const State &);
    virtual ~State (void);
    

    // TAO_IDL - Generated from
    // .\be\be_type.cpp:307
    
    typedef State_var _var_type;
    typedef State_out _out_type;

    static void _tao_any_destructor (void *);

    

#if (TAO_NO_COPY_OCTET_SEQUENCES == 1)
    State (
        ::CORBA::ULong length,
        const ACE_Message_Block* mb
      )
      : ::TAO::unbounded_value_sequence< ::CORBA::Octet> (length, mb) {}
#endif /* TAO_NO_COPY_OCTET_SEQUENCE == 1 */
  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:39

  extern TAO_FtRtEvent_Export ::CORBA::TypeCode_ptr const _tc_State;

  // TAO_IDL - Generated from
  // e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_exception/exception_ch.cpp:43

  class TAO_FtRtEvent_Export InvalidUpdate : public ::CORBA::UserException
  {
  public:
    
    InvalidUpdate (void);
    InvalidUpdate (const InvalidUpdate &);
    ~InvalidUpdate (void);

    InvalidUpdate &operator= (const InvalidUpdate &);

    static void _tao_any_destructor (void *);

    static InvalidUpdate *_downcast ( ::CORBA::Exception *);
    static const InvalidUpdate *_downcast ( ::CORBA::Exception const *);

    static ::CORBA::Exception *_alloc (void);

    virtual ::CORBA::Exception *_tao_duplicate (void) const;

    virtual void _raise (void) const;

    virtual void _tao_encode (TAO_OutputCDR &cdr) const;
    virtual void _tao_decode (TAO_InputCDR &cdr);
    

    virtual ::CORBA::TypeCode_ptr _tao_type (void) const;
  };

  // TAO_IDL - Generated from
  // e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:39

  extern TAO_FtRtEvent_Export ::CORBA::TypeCode_ptr const _tc_InvalidUpdate;

  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:784

#if !defined (_FTRT_UPDATEABLE__VAR_OUT_CH_)
#define _FTRT_UPDATEABLE__VAR_OUT_CH_

  class AMI_UpdateableHandler;
  typedef AMI_UpdateableHandler *AMI_UpdateableHandler_ptr;

  class Updateable;
  typedef Updateable *Updateable_ptr;

  typedef
    TAO_Objref_Var_T<
        Updateable
      >
    Updateable_var;
  
  typedef
    TAO_Objref_Out_T<
        Updateable
      >
    Updateable_out;

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:45

  class TAO_FtRtEvent_Export Updateable
    : public virtual ::CORBA::Object
  {
  public:
    friend class TAO::Narrow_Utils<Updateable>;

    // TAO_IDL - Generated from
    // .\be\be_type.cpp:307
    
    typedef Updateable_ptr _ptr_type;
    typedef Updateable_var _var_type;
    typedef Updateable_out _out_type;

    static void _tao_any_destructor (void *);

    // The static operations.
    static Updateable_ptr _duplicate (Updateable_ptr obj);

    static void _tao_release (Updateable_ptr obj);

    static Updateable_ptr _narrow (::CORBA::Object_ptr obj);
    static Updateable_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static Updateable_ptr _nil (void);

    virtual void set_update (
      const ::FTRT::State & s);

    virtual void oneway_set_update (
      const ::FTRT::State & s);

    virtual void sendc_set_update (
      ::FTRT::AMI_UpdateableHandler_ptr ami_handler,
      const ::FTRT::State & s);

    // TAO_IDL - Generated from
    // e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:156

    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  private:
    TAO::Collocation_Proxy_Broker *the_TAO_Updateable_Proxy_Broker_;
  
  protected:
    // Concrete interface only.
    Updateable (void);

    // These methods traverse the inheritance tree and set the
    // parents piece of the given class in the right mode.
    virtual void FTRT_Updateable_setup_collocation (void);

    // Concrete non-local interface only.
    Updateable (
        ::IOP::IOR *ior,
        TAO_ORB_Core *orb_core);
    
    // Non-local interface only.
    Updateable (
        TAO_Stub *objref,
        ::CORBA::Boolean _tao_collocated = false,
        TAO_Abstract_ServantBase *servant = 0,
        TAO_ORB_Core *orb_core = 0);

    virtual ~Updateable (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    Updateable (const Updateable &);

    void operator= (const Updateable &);
  };

  // TAO_IDL - Generated from
  // e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:39

  extern TAO_FtRtEvent_Export ::CORBA::TypeCode_ptr const _tc_Updateable;

  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:784

#if !defined (_FTRT_AMI_UPDATEABLEHANDLER__VAR_OUT_CH_)
#define _FTRT_AMI_UPDATEABLEHANDLER__VAR_OUT_CH_

  class AMI_UpdateableHandler;
  typedef AMI_UpdateableHandler *AMI_UpdateableHandler_ptr;

  typedef
    TAO_Objref_Var_T<
        AMI_UpdateableHandler
      >
    AMI_UpdateableHandler_var;
  
  typedef
    TAO_Objref_Out_T<
        AMI_UpdateableHandler
      >
    AMI_UpdateableHandler_out;

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:45

  class TAO_FtRtEvent_Export AMI_UpdateableHandler
    : public virtual ::Messaging::ReplyHandler
  
  {
  public:
    friend class TAO::Narrow_Utils<AMI_UpdateableHandler>;

    // TAO_IDL - Generated from
    // .\be\be_type.cpp:307
    
    typedef AMI_UpdateableHandler_ptr _ptr_type;
    typedef AMI_UpdateableHandler_var _var_type;
    typedef AMI_UpdateableHandler_out _out_type;

    static void _tao_any_destructor (void *);

    // The static operations.
    static AMI_UpdateableHandler_ptr _duplicate (AMI_UpdateableHandler_ptr obj);

    static void _tao_release (AMI_UpdateableHandler_ptr obj);

    static AMI_UpdateableHandler_ptr _narrow (::CORBA::Object_ptr obj);
    static AMI_UpdateableHandler_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static AMI_UpdateableHandler_ptr _nil (void);

    virtual void set_update (
      void);

    static void 
    set_update_reply_stub (
      TAO_InputCDR &_tao_reply_cdr,
      ::Messaging::ReplyHandler_ptr _tao_reply_handler,
      ::CORBA::ULong reply_status);

    virtual void set_update_excep (
      ::Messaging::ExceptionHolder * excep_holder);

    // TAO_IDL - Generated from
    // e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:156

    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  private:
    TAO::Collocation_Proxy_Broker *the_TAO_AMI_UpdateableHandler_Proxy_Broker_;
  
  protected:
    // Concrete interface only.
    AMI_UpdateableHandler (void);

    // These methods traverse the inheritance tree and set the
    // parents piece of the given class in the right mode.
    virtual void FTRT_AMI_UpdateableHandler_setup_collocation (void);

    // Concrete non-local interface only.
    AMI_UpdateableHandler (
        ::IOP::IOR *ior,
        TAO_ORB_Core *orb_core);
    
    // Non-local interface only.
    AMI_UpdateableHandler (
        TAO_Stub *objref,
        ::CORBA::Boolean _tao_collocated = false,
        TAO_Abstract_ServantBase *servant = 0,
        TAO_ORB_Core *orb_core = 0);

    virtual ~AMI_UpdateableHandler (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    AMI_UpdateableHandler (const AMI_UpdateableHandler &);

    void operator= (const AMI_UpdateableHandler &);
  };

  // TAO_IDL - Generated from
  // e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:39

  extern TAO_FtRtEvent_Export ::CORBA::TypeCode_ptr const _tc_AMI_UpdateableHandler;

// TAO_IDL - Generated from
// e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_module/module_ch.cpp:70

} // module FTRT

// TAO_IDL - Generated from
// .\be\be_visitor_arg_traits.cpp:68


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL


// Arg traits specializations.
namespace TAO
{

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:308

#if !defined (_MESSAGING_EXCEPTIONHOLDER__ARG_TRAITS_)
#define _MESSAGING_EXCEPTIONHOLDER__ARG_TRAITS_

  template<>
  class Arg_Traits< ::Messaging::ExceptionHolder>
    : public
        Object_Arg_Traits_T<
            ::Messaging::ExceptionHolder *,
            ::Messaging::ExceptionHolder_var,
            ::Messaging::ExceptionHolder_out,
            TAO::Value_Traits<Messaging::ExceptionHolder>,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:941

  template<>
  class Arg_Traits< ::FTRT::FTTransactionDepthServiceContext>
    : public
        Fixed_Size_Arg_Traits_T<
            ::FTRT::FTTransactionDepthServiceContext,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:941

  template<>
  class Arg_Traits< ::FTRT::FTSequenceNumberServiceContext>
    : public
        Fixed_Size_Arg_Traits_T<
            ::FTRT::FTSequenceNumberServiceContext,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:941

  template<>
  class Arg_Traits< ::FTRT::FTForwardServiceContext>
    : public
        Var_Size_Arg_Traits_T<
            ::FTRT::FTForwardServiceContext,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:679

  template<>
  class Arg_Traits< ::FTRT::State>
    : public
        Var_Size_Arg_Traits_T<
            ::FTRT::State,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:147

#if !defined (_FTRT_UPDATEABLE__ARG_TRAITS_)
#define _FTRT_UPDATEABLE__ARG_TRAITS_

  template<>
  class  Arg_Traits< ::FTRT::Updateable>
    : public
        Object_Arg_Traits_T<
            ::FTRT::Updateable_ptr,
            ::FTRT::Updateable_var,
            ::FTRT::Updateable_out,
            TAO::Objref_Traits<FTRT::Updateable>,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:147

#if !defined (_FTRT_AMI_UPDATEABLEHANDLER__ARG_TRAITS_)
#define _FTRT_AMI_UPDATEABLEHANDLER__ARG_TRAITS_

  template<>
  class  Arg_Traits< ::FTRT::AMI_UpdateableHandler>
    : public
        Object_Arg_Traits_T<
            ::FTRT::AMI_UpdateableHandler_ptr,
            ::FTRT::AMI_UpdateableHandler_var,
            ::FTRT::AMI_UpdateableHandler_out,
            TAO::Objref_Traits<FTRT::AMI_UpdateableHandler>,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

#endif /* end #if !defined */
}

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// Proxy Broker Factory function pointer declarations.

// TAO_IDL - Generated from
// e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_root/root_ch.cpp:204

extern TAO_FtRtEvent_Export
TAO::Collocation_Proxy_Broker *
(*FTRT__TAO_Updateable_Proxy_Broker_Factory_function_pointer) (
    ::CORBA::Object_ptr obj);

extern TAO_FtRtEvent_Export
TAO::Collocation_Proxy_Broker *
(*FTRT__TAO_AMI_UpdateableHandler_Proxy_Broker_Factory_function_pointer) (
    ::CORBA::Object_ptr obj);

// TAO_IDL - Generated from
// e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_valuetype/obv_module.cpp:45

namespace OBV_FTRT
{
}

// TAO_IDL - Generated from
// .\be\be_visitor_traits.cpp:62


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Traits specializations.
namespace TAO
{

#if !defined (_FTRT_UPDATEABLE__TRAITS_)
#define _FTRT_UPDATEABLE__TRAITS_

  template<>
  struct TAO_FtRtEvent_Export Objref_Traits< ::FTRT::Updateable>
  {
    static ::FTRT::Updateable_ptr duplicate (
        ::FTRT::Updateable_ptr p);
    static void release (
        ::FTRT::Updateable_ptr p);
    static ::FTRT::Updateable_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::FTRT::Updateable_ptr p,
        TAO_OutputCDR & cdr);
  };

#endif /* end #if !defined */

#if !defined (_FTRT_AMI_UPDATEABLEHANDLER__TRAITS_)
#define _FTRT_AMI_UPDATEABLEHANDLER__TRAITS_

  template<>
  struct TAO_FtRtEvent_Export Objref_Traits< ::FTRT::AMI_UpdateableHandler>
  {
    static ::FTRT::AMI_UpdateableHandler_ptr duplicate (
        ::FTRT::AMI_UpdateableHandler_ptr p);
    static void release (
        ::FTRT::AMI_UpdateableHandler_ptr p);
    static ::FTRT::AMI_UpdateableHandler_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::FTRT::AMI_UpdateableHandler_ptr p,
        TAO_OutputCDR & cdr);
  };

#endif /* end #if !defined */
}
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_structure/any_op_ch.cpp:44



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace FTRT
{
  TAO_FtRtEvent_Export void operator<<= (::CORBA::Any &, const ::FTRT::FTTransactionDepthServiceContext &); // copying version
  TAO_FtRtEvent_Export void operator<<= (::CORBA::Any &, ::FTRT::FTTransactionDepthServiceContext*); // noncopying version
  TAO_FtRtEvent_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, ::FTRT::FTTransactionDepthServiceContext *&); // deprecated
TAO_FtRtEvent_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const ::FTRT::FTTransactionDepthServiceContext *&);
}

#else



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_FtRtEvent_Export void operator<<= (::CORBA::Any &, const FTRT::FTTransactionDepthServiceContext &); // copying version
TAO_FtRtEvent_Export void operator<<= (::CORBA::Any &, FTRT::FTTransactionDepthServiceContext*); // noncopying version
TAO_FtRtEvent_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, FTRT::FTTransactionDepthServiceContext *&); // deprecated
TAO_FtRtEvent_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const FTRT::FTTransactionDepthServiceContext *&);
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




#endif

// TAO_IDL - Generated from
// e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_structure/any_op_ch.cpp:44



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace FTRT
{
  TAO_FtRtEvent_Export void operator<<= (::CORBA::Any &, const ::FTRT::FTSequenceNumberServiceContext &); // copying version
  TAO_FtRtEvent_Export void operator<<= (::CORBA::Any &, ::FTRT::FTSequenceNumberServiceContext*); // noncopying version
  TAO_FtRtEvent_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, ::FTRT::FTSequenceNumberServiceContext *&); // deprecated
TAO_FtRtEvent_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const ::FTRT::FTSequenceNumberServiceContext *&);
}

#else



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_FtRtEvent_Export void operator<<= (::CORBA::Any &, const FTRT::FTSequenceNumberServiceContext &); // copying version
TAO_FtRtEvent_Export void operator<<= (::CORBA::Any &, FTRT::FTSequenceNumberServiceContext*); // noncopying version
TAO_FtRtEvent_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, FTRT::FTSequenceNumberServiceContext *&); // deprecated
TAO_FtRtEvent_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const FTRT::FTSequenceNumberServiceContext *&);
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




#endif

// TAO_IDL - Generated from
// e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_structure/any_op_ch.cpp:44



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace FTRT
{
  TAO_FtRtEvent_Export void operator<<= (::CORBA::Any &, const ::FTRT::FTForwardServiceContext &); // copying version
  TAO_FtRtEvent_Export void operator<<= (::CORBA::Any &, ::FTRT::FTForwardServiceContext*); // noncopying version
  TAO_FtRtEvent_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, ::FTRT::FTForwardServiceContext *&); // deprecated
TAO_FtRtEvent_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const ::FTRT::FTForwardServiceContext *&);
}

#else



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_FtRtEvent_Export void operator<<= (::CORBA::Any &, const FTRT::FTForwardServiceContext &); // copying version
TAO_FtRtEvent_Export void operator<<= (::CORBA::Any &, FTRT::FTForwardServiceContext*); // noncopying version
TAO_FtRtEvent_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, FTRT::FTForwardServiceContext *&); // deprecated
TAO_FtRtEvent_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const FTRT::FTForwardServiceContext *&);
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




#endif

// TAO_IDL - Generated from
// e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_exception/any_op_ch.cpp:44

#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace FTRT
{
  

  TAO_FtRtEvent_Export void operator<<= (::CORBA::Any &, const ::FTRT::OutOfSequence &); // copying version
  TAO_FtRtEvent_Export void operator<<= (::CORBA::Any &, ::FTRT::OutOfSequence*); // noncopying version
  TAO_FtRtEvent_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, ::FTRT::OutOfSequence *&); // deprecated
TAO_FtRtEvent_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const ::FTRT::OutOfSequence *&);
}

#else



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



TAO_FtRtEvent_Export void operator<<= (::CORBA::Any &, const FTRT::OutOfSequence &); // copying version
TAO_FtRtEvent_Export void operator<<= (::CORBA::Any &, FTRT::OutOfSequence*); // noncopying version
TAO_FtRtEvent_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, FTRT::OutOfSequence *&); // deprecated
TAO_FtRtEvent_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const FTRT::OutOfSequence *&);
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




#endif

// TAO_IDL - Generated from
// e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_exception/any_op_ch.cpp:44

#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace FTRT
{
  

  TAO_FtRtEvent_Export void operator<<= (::CORBA::Any &, const ::FTRT::TransactionDepthTooHigh &); // copying version
  TAO_FtRtEvent_Export void operator<<= (::CORBA::Any &, ::FTRT::TransactionDepthTooHigh*); // noncopying version
  TAO_FtRtEvent_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, ::FTRT::TransactionDepthTooHigh *&); // deprecated
TAO_FtRtEvent_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const ::FTRT::TransactionDepthTooHigh *&);
}

#else



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



TAO_FtRtEvent_Export void operator<<= (::CORBA::Any &, const FTRT::TransactionDepthTooHigh &); // copying version
TAO_FtRtEvent_Export void operator<<= (::CORBA::Any &, FTRT::TransactionDepthTooHigh*); // noncopying version
TAO_FtRtEvent_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, FTRT::TransactionDepthTooHigh *&); // deprecated
TAO_FtRtEvent_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const FTRT::TransactionDepthTooHigh *&);
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




#endif

// TAO_IDL - Generated from
// e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_sequence/any_op_ch.cpp:47



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace FTRT
{
  TAO_FtRtEvent_Export void operator<<= ( ::CORBA::Any &, const ::FTRT::State &); // copying version
  TAO_FtRtEvent_Export void operator<<= ( ::CORBA::Any &, ::FTRT::State*); // noncopying version
  TAO_FtRtEvent_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, ::FTRT::State *&); // deprecated
  TAO_FtRtEvent_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const ::FTRT::State *&);
}

#else



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_FtRtEvent_Export void operator<<= ( ::CORBA::Any &, const FTRT::State &); // copying version
TAO_FtRtEvent_Export void operator<<= ( ::CORBA::Any &, FTRT::State*); // noncopying version
TAO_FtRtEvent_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, FTRT::State *&); // deprecated
TAO_FtRtEvent_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const FTRT::State *&);
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




#endif

// TAO_IDL - Generated from
// e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_exception/any_op_ch.cpp:44

#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace FTRT
{
  

  TAO_FtRtEvent_Export void operator<<= (::CORBA::Any &, const ::FTRT::InvalidUpdate &); // copying version
  TAO_FtRtEvent_Export void operator<<= (::CORBA::Any &, ::FTRT::InvalidUpdate*); // noncopying version
  TAO_FtRtEvent_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, ::FTRT::InvalidUpdate *&); // deprecated
TAO_FtRtEvent_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const ::FTRT::InvalidUpdate *&);
}

#else



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



TAO_FtRtEvent_Export void operator<<= (::CORBA::Any &, const FTRT::InvalidUpdate &); // copying version
TAO_FtRtEvent_Export void operator<<= (::CORBA::Any &, FTRT::InvalidUpdate*); // noncopying version
TAO_FtRtEvent_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, FTRT::InvalidUpdate *&); // deprecated
TAO_FtRtEvent_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const FTRT::InvalidUpdate *&);
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




#endif

// TAO_IDL - Generated from
// e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_interface/any_op_ch.cpp:46



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace FTRT
{
  TAO_FtRtEvent_Export void operator<<= ( ::CORBA::Any &, Updateable_ptr); // copying
  TAO_FtRtEvent_Export void operator<<= ( ::CORBA::Any &, Updateable_ptr *); // non-copying
  TAO_FtRtEvent_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, Updateable_ptr &);
}

#else



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_FtRtEvent_Export void operator<<= (::CORBA::Any &, FTRT::Updateable_ptr); // copying
TAO_FtRtEvent_Export void operator<<= (::CORBA::Any &, FTRT::Updateable_ptr *); // non-copying
TAO_FtRtEvent_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, FTRT::Updateable_ptr &);
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




#endif

// TAO_IDL - Generated from
// e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_interface/any_op_ch.cpp:46



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace FTRT
{
  TAO_FtRtEvent_Export void operator<<= ( ::CORBA::Any &, AMI_UpdateableHandler_ptr); // copying
  TAO_FtRtEvent_Export void operator<<= ( ::CORBA::Any &, AMI_UpdateableHandler_ptr *); // non-copying
  TAO_FtRtEvent_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, AMI_UpdateableHandler_ptr &);
}

#else



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_FtRtEvent_Export void operator<<= (::CORBA::Any &, FTRT::AMI_UpdateableHandler_ptr); // copying
TAO_FtRtEvent_Export void operator<<= (::CORBA::Any &, FTRT::AMI_UpdateableHandler_ptr *); // non-copying
TAO_FtRtEvent_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, FTRT::AMI_UpdateableHandler_ptr &);
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




#endif

// TAO_IDL - Generated from
// e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_structure/cdr_op_ch.cpp:45



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_FtRtEvent_Export ::CORBA::Boolean operator<< (TAO_OutputCDR &, const FTRT::FTTransactionDepthServiceContext &);
TAO_FtRtEvent_Export ::CORBA::Boolean operator>> (TAO_InputCDR &, FTRT::FTTransactionDepthServiceContext &);

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_structure/cdr_op_ch.cpp:45



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_FtRtEvent_Export ::CORBA::Boolean operator<< (TAO_OutputCDR &, const FTRT::FTSequenceNumberServiceContext &);
TAO_FtRtEvent_Export ::CORBA::Boolean operator>> (TAO_InputCDR &, FTRT::FTSequenceNumberServiceContext &);

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_structure/cdr_op_ch.cpp:45



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_FtRtEvent_Export ::CORBA::Boolean operator<< (TAO_OutputCDR &, const FTRT::FTForwardServiceContext &);
TAO_FtRtEvent_Export ::CORBA::Boolean operator>> (TAO_InputCDR &, FTRT::FTForwardServiceContext &);

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_exception/cdr_op_ch.cpp:43

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



TAO_FtRtEvent_Export ::CORBA::Boolean operator<< (TAO_OutputCDR &, const FTRT::OutOfSequence &);
TAO_FtRtEvent_Export ::CORBA::Boolean operator>> (TAO_InputCDR &, FTRT::OutOfSequence &);

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_exception/cdr_op_ch.cpp:43

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



TAO_FtRtEvent_Export ::CORBA::Boolean operator<< (TAO_OutputCDR &, const FTRT::TransactionDepthTooHigh &);
TAO_FtRtEvent_Export ::CORBA::Boolean operator>> (TAO_InputCDR &, FTRT::TransactionDepthTooHigh &);

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_sequence/cdr_op_ch.cpp:61

#if !defined _TAO_CDR_OP_FTRT_State_H_
#define _TAO_CDR_OP_FTRT_State_H_

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL


TAO_FtRtEvent_Export ::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const FTRT::State &_tao_sequence);
TAO_FtRtEvent_Export ::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    FTRT::State &_tao_sequence);

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




#endif /* _TAO_CDR_OP_FTRT_State_H_ */

// TAO_IDL - Generated from
// e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_exception/cdr_op_ch.cpp:43

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



TAO_FtRtEvent_Export ::CORBA::Boolean operator<< (TAO_OutputCDR &, const FTRT::InvalidUpdate &);
TAO_FtRtEvent_Export ::CORBA::Boolean operator>> (TAO_InputCDR &, FTRT::InvalidUpdate &);

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_interface/cdr_op_ch.cpp:47


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_FtRtEvent_Export ::CORBA::Boolean operator<< (TAO_OutputCDR &, const FTRT::Updateable_ptr );
TAO_FtRtEvent_Export ::CORBA::Boolean operator>> (TAO_InputCDR &, FTRT::Updateable_ptr &);

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_interface/cdr_op_ch.cpp:47


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_FtRtEvent_Export ::CORBA::Boolean operator<< (TAO_OutputCDR &, const FTRT::AMI_UpdateableHandler_ptr );
TAO_FtRtEvent_Export ::CORBA::Boolean operator>> (TAO_InputCDR &, FTRT::AMI_UpdateableHandler_ptr &);

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// .\be\be_codegen.cpp:1581


TAO_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "FTRTC.inl"
#endif /* defined INLINE */

#endif /* ifndef */

