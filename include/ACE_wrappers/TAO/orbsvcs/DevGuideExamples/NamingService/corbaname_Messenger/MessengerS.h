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

#ifndef _TAO_IDL_MESSENGERS_RLE2BX_H_
#define _TAO_IDL_MESSENGERS_RLE2BX_H_


#include "MessengerC.h"
#include "tao/PortableServer/Basic_SArguments.h"
#include "tao/PortableServer/Special_Basic_SArguments.h"
#include "tao/PortableServer/Fixed_Size_SArgument_T.h"
#include "tao/PortableServer/Var_Size_SArgument_T.h"
#include "tao/PortableServer/Object_SArg_Traits.h"
#include "tao/PortableServer/Special_Basic_SArguments.h"
#include "tao/PortableServer/UB_String_SArguments.h"
#include "tao/PortableServer/get_arg.h"
#include "tao/Special_Basic_Arguments.h"
#include "tao/UB_String_Arguments.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/Collocation_Proxy_Broker.h"
#include "tao/PortableServer/PortableServer.h"
#include "tao/PortableServer/Servant_Base.h"

// TAO_IDL - Generated from
// .\be\be_visitor_arg_traits.cpp:68

TAO_BEGIN_VERSIONED_NAMESPACE_DECL


// Arg traits specializations.
namespace TAO
{

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:147

#if !defined (_MESSENGER__SARG_TRAITS_)
#define _MESSENGER__SARG_TRAITS_

  template<>
  class  SArg_Traits< ::Messenger>
    : public
        Object_SArg_Traits_T<
            ::Messenger_ptr,
            ::Messenger_var,
            ::Messenger_out,
            TAO::Any_Insert_Policy_Noop
          >
  {
  };

#endif /* end #if !defined */
}

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_sh.cpp:78

class POA_Messenger;
typedef POA_Messenger *POA_Messenger_ptr;

class  POA_Messenger
  : public virtual PortableServer::ServantBase
{
protected:
  POA_Messenger (void);

public:
  /// Useful for template programming.
  typedef ::Messenger _stub_type;
  typedef ::Messenger_ptr _stub_ptr_type;
  typedef ::Messenger_var _stub_var_type;

  POA_Messenger (const POA_Messenger& rhs);
  virtual ~POA_Messenger (void);

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
  
  ::Messenger *_this (void);
  
  virtual const char* _interface_repository_id (void) const;

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:41

  virtual ::CORBA::Boolean send_message (
    const char * user_name,
    const char * subject,
    char *& message) = 0;

  static void send_message_skel (
      TAO_ServerRequest & server_request,
      void * servant_upcall,
      void * servant);
};
#if defined (__ACE_INLINE__)
#include "MessengerS.inl"
#endif /* defined INLINE */

#endif /* ifndef */

