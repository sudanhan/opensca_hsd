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

#ifndef _TAO_IDL_PACKETC_PAKD2G_H_
#define _TAO_IDL_PACKETC_PAKD2G_H_


#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#include "tao/AnyTypeCode/AnyTypeCode_methods.h"
#include "tao/AnyTypeCode/Any.h"
#include "tao/ORB.h"
#include "tao/SystemException.h"
#include "tao/UserException.h"
#include "tao/Basic_Types.h"
#include "tao/ORB_Constants.h"
#include "tao/Object.h"
#include "tao/String_Manager_T.h"
#include "tao/Objref_VarOut_T.h"
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

#include "JTRSCorbaTypesC.h"

#if TAO_MAJOR_VERSION != 2 || TAO_MINOR_VERSION != 0 || TAO_BETA_VERSION != 4
#error This file should be regenerated with TAO_IDL from version 2.0a
#endif

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO 

// TAO_IDL - Generated from 
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_root/root_ch.cpp:162
TAO_BEGIN_VERSIONED_NAMESPACE_DECL



namespace TAO
{
  class Collocation_Proxy_Broker;
  template<typename T> class Narrow_Utils;
}
TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_module/module_ch.cpp:41

namespace Packet
{

  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:784

#if !defined (_PACKET_PAYLOADSTATUS__VAR_OUT_CH_)
#define _PACKET_PAYLOADSTATUS__VAR_OUT_CH_

  class PayloadStatus;
  typedef PayloadStatus *PayloadStatus_ptr;

  typedef
    TAO_Objref_Var_T<
        PayloadStatus
      >
    PayloadStatus_var;
  
  typedef
    TAO_Objref_Out_T<
        PayloadStatus
      >
    PayloadStatus_out;

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:45

  class  PayloadStatus
    : public virtual ::CORBA::Object
  {
  public:
    friend class TAO::Narrow_Utils<PayloadStatus>;

    // TAO_IDL - Generated from
    // .\be\be_type.cpp:307
    
    typedef PayloadStatus_ptr _ptr_type;
    typedef PayloadStatus_var _var_type;
    typedef PayloadStatus_out _out_type;

    static void _tao_any_destructor (void *);

    // The static operations.
    static PayloadStatus_ptr _duplicate (PayloadStatus_ptr obj);

    static void _tao_release (PayloadStatus_ptr obj);

    static PayloadStatus_ptr _narrow (::CORBA::Object_ptr obj);
    static PayloadStatus_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static PayloadStatus_ptr _nil (void);

    virtual ::CORBA::ULong getMaxPayloadSize (
      void);

    virtual ::CORBA::ULong getMinPayloadSize (
      void);

    virtual ::CORBA::ULong getDesiredPayloadSize (
      void);

    virtual ::CORBA::ULong getMinOverrideTimeout (
      void);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:156

    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  private:
    TAO::Collocation_Proxy_Broker *the_TAO_PayloadStatus_Proxy_Broker_;
  
  protected:
    // Concrete interface only.
    PayloadStatus (void);

    // These methods traverse the inheritance tree and set the
    // parents piece of the given class in the right mode.
    virtual void Packet_PayloadStatus_setup_collocation (void);

    // Concrete non-local interface only.
    PayloadStatus (
        ::IOP::IOR *ior,
        TAO_ORB_Core *orb_core);
    
    // Non-local interface only.
    PayloadStatus (
        TAO_Stub *objref,
        ::CORBA::Boolean _tao_collocated = false,
        TAO_Abstract_ServantBase *servant = 0,
        TAO_ORB_Core *orb_core = 0);

    virtual ~PayloadStatus (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    PayloadStatus (const PayloadStatus &);

    void operator= (const PayloadStatus &);
  };

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:39

  extern  ::CORBA::TypeCode_ptr const _tc_PayloadStatus;

  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:784

#if !defined (_PACKET_PAYLOADCONTROL__VAR_OUT_CH_)
#define _PACKET_PAYLOADCONTROL__VAR_OUT_CH_

  class PayloadControl;
  typedef PayloadControl *PayloadControl_ptr;

  typedef
    TAO_Objref_Var_T<
        PayloadControl
      >
    PayloadControl_var;
  
  typedef
    TAO_Objref_Out_T<
        PayloadControl
      >
    PayloadControl_out;

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:45

  class  PayloadControl
    : public virtual ::CORBA::Object
  {
  public:
    friend class TAO::Narrow_Utils<PayloadControl>;

    // TAO_IDL - Generated from
    // .\be\be_type.cpp:307
    
    typedef PayloadControl_ptr _ptr_type;
    typedef PayloadControl_var _var_type;
    typedef PayloadControl_out _out_type;

    static void _tao_any_destructor (void *);

    // The static operations.
    static PayloadControl_ptr _duplicate (PayloadControl_ptr obj);

    static void _tao_release (PayloadControl_ptr obj);

    static PayloadControl_ptr _narrow (::CORBA::Object_ptr obj);
    static PayloadControl_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static PayloadControl_ptr _nil (void);

    virtual void setMaxPayloadSize (
      ::CORBA::ULong maxPayloadSize);

    virtual void setMinPayloadSize (
      ::CORBA::ULong minPayloadSize);

    virtual void setDesiredPayloadSize (
      ::CORBA::ULong desiredPayloadSize);

    virtual void setMinOverrideTimeout (
      ::CORBA::ULong minOverrideTimeout);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:156

    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  private:
    TAO::Collocation_Proxy_Broker *the_TAO_PayloadControl_Proxy_Broker_;
  
  protected:
    // Concrete interface only.
    PayloadControl (void);

    // These methods traverse the inheritance tree and set the
    // parents piece of the given class in the right mode.
    virtual void Packet_PayloadControl_setup_collocation (void);

    // Concrete non-local interface only.
    PayloadControl (
        ::IOP::IOR *ior,
        TAO_ORB_Core *orb_core);
    
    // Non-local interface only.
    PayloadControl (
        TAO_Stub *objref,
        ::CORBA::Boolean _tao_collocated = false,
        TAO_Abstract_ServantBase *servant = 0,
        TAO_ORB_Core *orb_core = 0);

    virtual ~PayloadControl (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    PayloadControl (const PayloadControl &);

    void operator= (const PayloadControl &);
  };

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:39

  extern  ::CORBA::TypeCode_ptr const _tc_PayloadControl;

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_typedef/typedef_ch.cpp:369

  typedef ::CORBA::UShort Stream;
  typedef ::CORBA::UShort_out Stream_out;

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:39

  extern  ::CORBA::TypeCode_ptr const _tc_Stream;

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_typedef/typedef_ch.cpp:369

  typedef ::CORBA::Octet SeqNum;
  typedef ::CORBA::Octet_out SeqNum_out;

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:39

  extern  ::CORBA::TypeCode_ptr const _tc_SeqNum;

  // TAO_IDL - Generated from
  // .\be\be_type.cpp:261

  struct StreamControlType;

  typedef
    ::TAO_Fixed_Var_T<
        StreamControlType
      >
    StreamControlType_var;
  
  typedef
    StreamControlType &
    StreamControlType_out;

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_structure/structure_ch.cpp:49

  struct  StreamControlType
  {

    // TAO_IDL - Generated from
    // .\be\be_type.cpp:307
    
    typedef StreamControlType_var _var_type;
    typedef StreamControlType_out _out_type;

    static void _tao_any_destructor (void *);
    
    ::CORBA::Boolean endOfStream;
    Packet::Stream streamed;
    Packet::SeqNum SequenceNumber;
    ::CORBA::Boolean purge;
  };

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:39

  extern  ::CORBA::TypeCode_ptr const _tc_StreamControlType;

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_typedef/typedef_ch.cpp:369

  typedef JTRS::ExtEnum PushError;
  typedef JTRS::ExtEnum_out PushError_out;

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:39

  extern  ::CORBA::TypeCode_ptr const _tc_PushError;

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_constant/constant_ch.cpp:41

  const CORBA::UShort PPKT_UNKNOWN = 1U;

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_constant/constant_ch.cpp:41

  const CORBA::UShort PPKT_ERROR_BAD_SIZE = 2U;

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_constant/constant_ch.cpp:41

  const CORBA::UShort PPKT_ERROR_STRAM_BLOCKED = 3U;

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_exception/exception_ch.cpp:43

  class  UnableToComplete : public ::CORBA::UserException
  {
  public:
    
    ::CORBA::UShort payloadSent;
    Packet::PushError errorCode;
    UnableToComplete (void);
    UnableToComplete (const UnableToComplete &);
    ~UnableToComplete (void);

    UnableToComplete &operator= (const UnableToComplete &);

    static void _tao_any_destructor (void *);

    static UnableToComplete *_downcast ( ::CORBA::Exception *);
    static const UnableToComplete *_downcast ( ::CORBA::Exception const *);

    static ::CORBA::Exception *_alloc (void);

    virtual ::CORBA::Exception *_tao_duplicate (void) const;

    virtual void _raise (void) const;

    virtual void _tao_encode (TAO_OutputCDR &cdr) const;
    virtual void _tao_decode (TAO_InputCDR &cdr);
    

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_exception/exception_ctor.cpp:56

    UnableToComplete (
        ::CORBA::UShort _tao_payloadSent,
        Packet::PushError _tao_errorCode);

    virtual ::CORBA::TypeCode_ptr _tao_type (void) const;
  };

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:39

  extern  ::CORBA::TypeCode_ptr const _tc_UnableToComplete;

  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:784

#if !defined (_PACKET_OCTETSTREAM__VAR_OUT_CH_)
#define _PACKET_OCTETSTREAM__VAR_OUT_CH_

  class OctetStream;
  typedef OctetStream *OctetStream_ptr;

  typedef
    TAO_Objref_Var_T<
        OctetStream
      >
    OctetStream_var;
  
  typedef
    TAO_Objref_Out_T<
        OctetStream
      >
    OctetStream_out;

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:45

  class  OctetStream
    : public virtual ::Packet::PayloadStatus
  
  {
  public:
    friend class TAO::Narrow_Utils<OctetStream>;

    // TAO_IDL - Generated from
    // .\be\be_type.cpp:307
    
    typedef OctetStream_ptr _ptr_type;
    typedef OctetStream_var _var_type;
    typedef OctetStream_out _out_type;

    static void _tao_any_destructor (void *);

    // The static operations.
    static OctetStream_ptr _duplicate (OctetStream_ptr obj);

    static void _tao_release (OctetStream_ptr obj);

    static OctetStream_ptr _narrow (::CORBA::Object_ptr obj);
    static OctetStream_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static OctetStream_ptr _nil (void);

    virtual void pushPakcet (
      const ::Packet::StreamControlType & control,
      const ::JTRS::OctetSequence & payload);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:156

    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  private:
    TAO::Collocation_Proxy_Broker *the_TAO_OctetStream_Proxy_Broker_;
  
  protected:
    // Concrete interface only.
    OctetStream (void);

    // These methods traverse the inheritance tree and set the
    // parents piece of the given class in the right mode.
    virtual void Packet_OctetStream_setup_collocation (void);

    // Concrete non-local interface only.
    OctetStream (
        ::IOP::IOR *ior,
        TAO_ORB_Core *orb_core);
    
    // Non-local interface only.
    OctetStream (
        TAO_Stub *objref,
        ::CORBA::Boolean _tao_collocated = false,
        TAO_Abstract_ServantBase *servant = 0,
        TAO_ORB_Core *orb_core = 0);

    virtual ~OctetStream (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    OctetStream (const OctetStream &);

    void operator= (const OctetStream &);
  };

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:39

  extern  ::CORBA::TypeCode_ptr const _tc_OctetStream;

  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:784

#if !defined (_PACKET_USHORTSTEAM__VAR_OUT_CH_)
#define _PACKET_USHORTSTEAM__VAR_OUT_CH_

  class UshortSteam;
  typedef UshortSteam *UshortSteam_ptr;

  typedef
    TAO_Objref_Var_T<
        UshortSteam
      >
    UshortSteam_var;
  
  typedef
    TAO_Objref_Out_T<
        UshortSteam
      >
    UshortSteam_out;

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:45

  class  UshortSteam
    : public virtual ::Packet::PayloadStatus
  
  {
  public:
    friend class TAO::Narrow_Utils<UshortSteam>;

    // TAO_IDL - Generated from
    // .\be\be_type.cpp:307
    
    typedef UshortSteam_ptr _ptr_type;
    typedef UshortSteam_var _var_type;
    typedef UshortSteam_out _out_type;

    static void _tao_any_destructor (void *);

    // The static operations.
    static UshortSteam_ptr _duplicate (UshortSteam_ptr obj);

    static void _tao_release (UshortSteam_ptr obj);

    static UshortSteam_ptr _narrow (::CORBA::Object_ptr obj);
    static UshortSteam_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static UshortSteam_ptr _nil (void);

    virtual void pushPacket (
      const ::Packet::StreamControlType & control,
      const ::JTRS::UshortSequence & payload);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:156

    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  private:
    TAO::Collocation_Proxy_Broker *the_TAO_UshortSteam_Proxy_Broker_;
  
  protected:
    // Concrete interface only.
    UshortSteam (void);

    // These methods traverse the inheritance tree and set the
    // parents piece of the given class in the right mode.
    virtual void Packet_UshortSteam_setup_collocation (void);

    // Concrete non-local interface only.
    UshortSteam (
        ::IOP::IOR *ior,
        TAO_ORB_Core *orb_core);
    
    // Non-local interface only.
    UshortSteam (
        TAO_Stub *objref,
        ::CORBA::Boolean _tao_collocated = false,
        TAO_Abstract_ServantBase *servant = 0,
        TAO_ORB_Core *orb_core = 0);

    virtual ~UshortSteam (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    UshortSteam (const UshortSteam &);

    void operator= (const UshortSteam &);
  };

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:39

  extern  ::CORBA::TypeCode_ptr const _tc_UshortSteam;

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_module/module_ch.cpp:70

} // module Packet

// TAO_IDL - Generated from
// .\be\be_visitor_arg_traits.cpp:68

TAO_BEGIN_VERSIONED_NAMESPACE_DECL


// Arg traits specializations.
namespace TAO
{

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:147

#if !defined (_PACKET_PAYLOADSTATUS__ARG_TRAITS_)
#define _PACKET_PAYLOADSTATUS__ARG_TRAITS_

  template<>
  class  Arg_Traits< ::Packet::PayloadStatus>
    : public
        Object_Arg_Traits_T<
            ::Packet::PayloadStatus_ptr,
            ::Packet::PayloadStatus_var,
            ::Packet::PayloadStatus_out,
            TAO::Objref_Traits<Packet::PayloadStatus>,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:147

#if !defined (_PACKET_PAYLOADCONTROL__ARG_TRAITS_)
#define _PACKET_PAYLOADCONTROL__ARG_TRAITS_

  template<>
  class  Arg_Traits< ::Packet::PayloadControl>
    : public
        Object_Arg_Traits_T<
            ::Packet::PayloadControl_ptr,
            ::Packet::PayloadControl_var,
            ::Packet::PayloadControl_out,
            TAO::Objref_Traits<Packet::PayloadControl>,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:941

  template<>
  class Arg_Traits< ::Packet::StreamControlType>
    : public
        Fixed_Size_Arg_Traits_T<
            ::Packet::StreamControlType,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:147

#if !defined (_PACKET_OCTETSTREAM__ARG_TRAITS_)
#define _PACKET_OCTETSTREAM__ARG_TRAITS_

  template<>
  class  Arg_Traits< ::Packet::OctetStream>
    : public
        Object_Arg_Traits_T<
            ::Packet::OctetStream_ptr,
            ::Packet::OctetStream_var,
            ::Packet::OctetStream_out,
            TAO::Objref_Traits<Packet::OctetStream>,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:147

#if !defined (_PACKET_USHORTSTEAM__ARG_TRAITS_)
#define _PACKET_USHORTSTEAM__ARG_TRAITS_

  template<>
  class  Arg_Traits< ::Packet::UshortSteam>
    : public
        Object_Arg_Traits_T<
            ::Packet::UshortSteam_ptr,
            ::Packet::UshortSteam_var,
            ::Packet::UshortSteam_out,
            TAO::Objref_Traits<Packet::UshortSteam>,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

#endif /* end #if !defined */
}

TAO_END_VERSIONED_NAMESPACE_DECL



// Proxy Broker Factory function pointer declarations.

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_root/root_ch.cpp:204

extern 
TAO::Collocation_Proxy_Broker *
(*Packet__TAO_PayloadStatus_Proxy_Broker_Factory_function_pointer) (
    ::CORBA::Object_ptr obj);

extern 
TAO::Collocation_Proxy_Broker *
(*Packet__TAO_PayloadControl_Proxy_Broker_Factory_function_pointer) (
    ::CORBA::Object_ptr obj);

extern 
TAO::Collocation_Proxy_Broker *
(*Packet__TAO_OctetStream_Proxy_Broker_Factory_function_pointer) (
    ::CORBA::Object_ptr obj);

extern 
TAO::Collocation_Proxy_Broker *
(*Packet__TAO_UshortSteam_Proxy_Broker_Factory_function_pointer) (
    ::CORBA::Object_ptr obj);

// TAO_IDL - Generated from
// .\be\be_visitor_traits.cpp:62

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Traits specializations.
namespace TAO
{

#if !defined (_PACKET_PAYLOADSTATUS__TRAITS_)
#define _PACKET_PAYLOADSTATUS__TRAITS_

  template<>
  struct  Objref_Traits< ::Packet::PayloadStatus>
  {
    static ::Packet::PayloadStatus_ptr duplicate (
        ::Packet::PayloadStatus_ptr p);
    static void release (
        ::Packet::PayloadStatus_ptr p);
    static ::Packet::PayloadStatus_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::Packet::PayloadStatus_ptr p,
        TAO_OutputCDR & cdr);
  };

#endif /* end #if !defined */

#if !defined (_PACKET_PAYLOADCONTROL__TRAITS_)
#define _PACKET_PAYLOADCONTROL__TRAITS_

  template<>
  struct  Objref_Traits< ::Packet::PayloadControl>
  {
    static ::Packet::PayloadControl_ptr duplicate (
        ::Packet::PayloadControl_ptr p);
    static void release (
        ::Packet::PayloadControl_ptr p);
    static ::Packet::PayloadControl_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::Packet::PayloadControl_ptr p,
        TAO_OutputCDR & cdr);
  };

#endif /* end #if !defined */

#if !defined (_PACKET_OCTETSTREAM__TRAITS_)
#define _PACKET_OCTETSTREAM__TRAITS_

  template<>
  struct  Objref_Traits< ::Packet::OctetStream>
  {
    static ::Packet::OctetStream_ptr duplicate (
        ::Packet::OctetStream_ptr p);
    static void release (
        ::Packet::OctetStream_ptr p);
    static ::Packet::OctetStream_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::Packet::OctetStream_ptr p,
        TAO_OutputCDR & cdr);
  };

#endif /* end #if !defined */

#if !defined (_PACKET_USHORTSTEAM__TRAITS_)
#define _PACKET_USHORTSTEAM__TRAITS_

  template<>
  struct  Objref_Traits< ::Packet::UshortSteam>
  {
    static ::Packet::UshortSteam_ptr duplicate (
        ::Packet::UshortSteam_ptr p);
    static void release (
        ::Packet::UshortSteam_ptr p);
    static ::Packet::UshortSteam_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::Packet::UshortSteam_ptr p,
        TAO_OutputCDR & cdr);
  };

#endif /* end #if !defined */
}
TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/any_op_ch.cpp:46



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace Packet
{
   void operator<<= ( ::CORBA::Any &, PayloadStatus_ptr); // copying
   void operator<<= ( ::CORBA::Any &, PayloadStatus_ptr *); // non-copying
   ::CORBA::Boolean operator>>= (const ::CORBA::Any &, PayloadStatus_ptr &);
}

#else


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 void operator<<= (::CORBA::Any &, Packet::PayloadStatus_ptr); // copying
 void operator<<= (::CORBA::Any &, Packet::PayloadStatus_ptr *); // non-copying
 ::CORBA::Boolean operator>>= (const ::CORBA::Any &, Packet::PayloadStatus_ptr &);
TAO_END_VERSIONED_NAMESPACE_DECL



#endif

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/any_op_ch.cpp:46



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace Packet
{
   void operator<<= ( ::CORBA::Any &, PayloadControl_ptr); // copying
   void operator<<= ( ::CORBA::Any &, PayloadControl_ptr *); // non-copying
   ::CORBA::Boolean operator>>= (const ::CORBA::Any &, PayloadControl_ptr &);
}

#else


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 void operator<<= (::CORBA::Any &, Packet::PayloadControl_ptr); // copying
 void operator<<= (::CORBA::Any &, Packet::PayloadControl_ptr *); // non-copying
 ::CORBA::Boolean operator>>= (const ::CORBA::Any &, Packet::PayloadControl_ptr &);
TAO_END_VERSIONED_NAMESPACE_DECL



#endif

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_structure/any_op_ch.cpp:44



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace Packet
{
   void operator<<= (::CORBA::Any &, const ::Packet::StreamControlType &); // copying version
   void operator<<= (::CORBA::Any &, ::Packet::StreamControlType*); // noncopying version
   ::CORBA::Boolean operator>>= (const ::CORBA::Any &, ::Packet::StreamControlType *&); // deprecated
 ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const ::Packet::StreamControlType *&);
}

#else


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 void operator<<= (::CORBA::Any &, const Packet::StreamControlType &); // copying version
 void operator<<= (::CORBA::Any &, Packet::StreamControlType*); // noncopying version
 ::CORBA::Boolean operator>>= (const ::CORBA::Any &, Packet::StreamControlType *&); // deprecated
 ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const Packet::StreamControlType *&);
TAO_END_VERSIONED_NAMESPACE_DECL



#endif

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_exception/any_op_ch.cpp:44

#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace Packet
{
  

   void operator<<= (::CORBA::Any &, const ::Packet::UnableToComplete &); // copying version
   void operator<<= (::CORBA::Any &, ::Packet::UnableToComplete*); // noncopying version
   ::CORBA::Boolean operator>>= (const ::CORBA::Any &, ::Packet::UnableToComplete *&); // deprecated
 ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const ::Packet::UnableToComplete *&);
}

#else


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



 void operator<<= (::CORBA::Any &, const Packet::UnableToComplete &); // copying version
 void operator<<= (::CORBA::Any &, Packet::UnableToComplete*); // noncopying version
 ::CORBA::Boolean operator>>= (const ::CORBA::Any &, Packet::UnableToComplete *&); // deprecated
 ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const Packet::UnableToComplete *&);
TAO_END_VERSIONED_NAMESPACE_DECL



#endif

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/any_op_ch.cpp:46



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace Packet
{
   void operator<<= ( ::CORBA::Any &, OctetStream_ptr); // copying
   void operator<<= ( ::CORBA::Any &, OctetStream_ptr *); // non-copying
   ::CORBA::Boolean operator>>= (const ::CORBA::Any &, OctetStream_ptr &);
}

#else


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 void operator<<= (::CORBA::Any &, Packet::OctetStream_ptr); // copying
 void operator<<= (::CORBA::Any &, Packet::OctetStream_ptr *); // non-copying
 ::CORBA::Boolean operator>>= (const ::CORBA::Any &, Packet::OctetStream_ptr &);
TAO_END_VERSIONED_NAMESPACE_DECL



#endif

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/any_op_ch.cpp:46



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace Packet
{
   void operator<<= ( ::CORBA::Any &, UshortSteam_ptr); // copying
   void operator<<= ( ::CORBA::Any &, UshortSteam_ptr *); // non-copying
   ::CORBA::Boolean operator>>= (const ::CORBA::Any &, UshortSteam_ptr &);
}

#else


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 void operator<<= (::CORBA::Any &, Packet::UshortSteam_ptr); // copying
 void operator<<= (::CORBA::Any &, Packet::UshortSteam_ptr *); // non-copying
 ::CORBA::Boolean operator>>= (const ::CORBA::Any &, Packet::UshortSteam_ptr &);
TAO_END_VERSIONED_NAMESPACE_DECL



#endif

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/cdr_op_ch.cpp:47

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 ::CORBA::Boolean operator<< (TAO_OutputCDR &, const Packet::PayloadStatus_ptr );
 ::CORBA::Boolean operator>> (TAO_InputCDR &, Packet::PayloadStatus_ptr &);

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/cdr_op_ch.cpp:47

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 ::CORBA::Boolean operator<< (TAO_OutputCDR &, const Packet::PayloadControl_ptr );
 ::CORBA::Boolean operator>> (TAO_InputCDR &, Packet::PayloadControl_ptr &);

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_structure/cdr_op_ch.cpp:45


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 ::CORBA::Boolean operator<< (TAO_OutputCDR &, const Packet::StreamControlType &);
 ::CORBA::Boolean operator>> (TAO_InputCDR &, Packet::StreamControlType &);

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_exception/cdr_op_ch.cpp:43
TAO_BEGIN_VERSIONED_NAMESPACE_DECL



 ::CORBA::Boolean operator<< (TAO_OutputCDR &, const Packet::UnableToComplete &);
 ::CORBA::Boolean operator>> (TAO_InputCDR &, Packet::UnableToComplete &);

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/cdr_op_ch.cpp:47

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 ::CORBA::Boolean operator<< (TAO_OutputCDR &, const Packet::OctetStream_ptr );
 ::CORBA::Boolean operator>> (TAO_InputCDR &, Packet::OctetStream_ptr &);

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/cdr_op_ch.cpp:47

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 ::CORBA::Boolean operator<< (TAO_OutputCDR &, const Packet::UshortSteam_ptr );
 ::CORBA::Boolean operator>> (TAO_InputCDR &, Packet::UshortSteam_ptr &);

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// .\be\be_codegen.cpp:1581
#if defined (__ACE_INLINE__)
#include "PacketC.inl"
#endif /* defined INLINE */

#endif /* ifndef */
