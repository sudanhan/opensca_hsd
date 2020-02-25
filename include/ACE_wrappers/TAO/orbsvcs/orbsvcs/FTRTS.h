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
// .\be\be_codegen.cpp:460

#ifndef _TAO_IDL_FTRTS_ZJ5ZKT_H_
#define _TAO_IDL_FTRTS_ZJ5ZKT_H_


#include "FTRTC.h"
#include "tao/IOPS.h"
#include "tao/PortableServer/Basic_SArguments.h"
#include "tao/PortableServer/Special_Basic_SArguments.h"
#include "tao/PortableServer/Fixed_Size_SArgument_T.h"
#include "tao/PortableServer/Var_Size_SArgument_T.h"
#include "tao/PortableServer/Object_SArg_Traits.h"
#include "tao/PortableServer/UB_String_SArguments.h"
#include "tao/PortableServer/Object_SArg_Traits.h"
#include "tao/PortableServer/get_arg.h"
#include "tao/Special_Basic_Arguments.h"
#include "tao/UB_String_Arguments.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/Messaging/MessagingS.h"
#include "tao/Collocation_Proxy_Broker.h"
#include "tao/PortableServer/PortableServer.h"
#include "tao/PortableServer/Servant_Base.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// .\be\be_visitor_arg_traits.cpp:68


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL


// Arg traits specializations.
namespace TAO
{

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:308

#if !defined (_MESSAGING_EXCEPTIONHOLDER__SARG_TRAITS_)
#define _MESSAGING_EXCEPTIONHOLDER__SARG_TRAITS_

  template<>
  class SArg_Traits< ::Messaging::ExceptionHolder>
    : public
        Object_SArg_Traits_T<
            ::Messaging::ExceptionHolder *,
            ::Messaging::ExceptionHolder_var,
            ::Messaging::ExceptionHolder_out,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:941

  template<>
  class SArg_Traits< ::FTRT::FTTransactionDepthServiceContext>
    : public
        Fixed_Size_SArg_Traits_T<
            ::FTRT::FTTransactionDepthServiceContext,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:941

  template<>
  class SArg_Traits< ::FTRT::FTSequenceNumberServiceContext>
    : public
        Fixed_Size_SArg_Traits_T<
            ::FTRT::FTSequenceNumberServiceContext,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:941

  template<>
  class SArg_Traits< ::FTRT::FTForwardServiceContext>
    : public
        Var_Size_SArg_Traits_T<
            ::FTRT::FTForwardServiceContext,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:679

  template<>
  class SArg_Traits< ::FTRT::State>
    : public
        Var_Size_SArg_Traits_T<
            ::FTRT::State,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:147

#if !defined (_FTRT_UPDATEABLE__SARG_TRAITS_)
#define _FTRT_UPDATEABLE__SARG_TRAITS_

  template<>
  class  SArg_Traits< ::FTRT::Updateable>
    : public
        Object_SArg_Traits_T<
            ::FTRT::Updateable_ptr,
            ::FTRT::Updateable_var,
            ::FTRT::Updateable_out,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:147

#if !defined (_FTRT_AMI_UPDATEABLEHANDLER__SARG_TRAITS_)
#define _FTRT_AMI_UPDATEABLEHANDLER__SARG_TRAITS_

  template<>
  class  SArg_Traits< ::FTRT::AMI_UpdateableHandler>
    : public
        Object_SArg_Traits_T<
            ::FTRT::AMI_UpdateableHandler_ptr,
            ::FTRT::AMI_UpdateableHandler_var,
            ::FTRT::AMI_UpdateableHandler_out,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

#endif /* end #if !defined */
}

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_module/module_sh.cpp:41

namespace POA_FTRT
{
  

  // TAO_IDL - Generated from
  // e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_sh.cpp:78

  class Updateable;
  typedef Updateable *Updateable_ptr;

  class TAO_FtRtEvent_Export Updateable
    : public virtual PortableServer::ServantBase
  {
  protected:
    Updateable (void);
  
  public:
    /// Useful for template programming.
    typedef ::FTRT::Updateable _stub_type;
    typedef ::FTRT::Updateable_ptr _stub_ptr_type;
    typedef ::FTRT::Updateable_var _stub_var_type;

    Updateable (const Updateable& rhs);
    virtual ~Updateable (void);

    virtual ::CORBA::Boolean _is_a (const char* logical_type_id);

    static void _is_a_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant);
    
    static void _non_existent_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant);
    
    static void _interface_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant);
    
    static void _component_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant);
    
    static void _repository_id_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant);
    
    virtual void _dispatch (
        TAO_ServerRequest & req,
        void * servant_upcall);
    
    ::FTRT::Updateable *_this (void);
    
    virtual const char* _interface_repository_id (void) const;

    // TAO_IDL - Generated from
    // e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:41

    virtual void set_update (
      const ::FTRT::State & s) = 0;

    static void set_update_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant);

    // TAO_IDL - Generated from
    // e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:41

    virtual void oneway_set_update (
      const ::FTRT::State & s) = 0;

    static void oneway_set_update_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant);
  };

  // TAO_IDL - Generated from
  // e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_sh.cpp:78

  class AMI_UpdateableHandler;
  typedef AMI_UpdateableHandler *AMI_UpdateableHandler_ptr;

  class TAO_FtRtEvent_Export AMI_UpdateableHandler
    : public virtual POA_Messaging::ReplyHandler
  {
  protected:
    AMI_UpdateableHandler (void);
  
  public:
    /// Useful for template programming.
    typedef ::FTRT::AMI_UpdateableHandler _stub_type;
    typedef ::FTRT::AMI_UpdateableHandler_ptr _stub_ptr_type;
    typedef ::FTRT::AMI_UpdateableHandler_var _stub_var_type;

    AMI_UpdateableHandler (const AMI_UpdateableHandler& rhs);
    virtual ~AMI_UpdateableHandler (void);

    virtual ::CORBA::Boolean _is_a (const char* logical_type_id);

    static void _is_a_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant);
    
    static void _non_existent_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant);
    
    static void _interface_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant);
    
    static void _component_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant);
    
    static void _repository_id_skel (
        TAO_ServerRequest & req,
        void * servant_upcall,
        void * servant);
    
    virtual void _dispatch (
        TAO_ServerRequest & req,
        void * servant_upcall);
    
    ::FTRT::AMI_UpdateableHandler *_this (void);
    
    virtual const char* _interface_repository_id (void) const;

    // TAO_IDL - Generated from
    // e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:41

    virtual void set_update (
      void) = 0;

    static void set_update_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant);

    // TAO_IDL - Generated from
    // e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:41

    virtual void set_update_excep (
      ::Messaging::ExceptionHolder * excep_holder) = 0;

    static void set_update_excep_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant);
  };

// TAO_IDL - Generated from
// e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_module/module_sh.cpp:72

} // module FTRT

TAO_END_VERSIONED_NAMESPACE_DECL


#if defined (__ACE_INLINE__)
#include "FTRTS.inl"
#endif /* defined INLINE */

#endif /* ifndef */

