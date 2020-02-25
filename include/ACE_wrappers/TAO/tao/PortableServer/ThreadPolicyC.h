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

#ifndef _TAO_PIDL_THREADPOLICYC_UGMXFW_H_
#define _TAO_PIDL_THREADPOLICYC_UGMXFW_H_


#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#include /**/ "tao/PortableServer/portableserver_export.h"
#include "tao/Basic_Types.h"
#include "tao/Object.h"
#include "tao/Objref_VarOut_T.h"
#include "tao/Arg_Traits_T.h"
#include "tao/Basic_Arguments.h"
#include "tao/Special_Basic_Arguments.h"
#include "tao/Any_Insert_Policy_T.h"
#include "tao/Basic_Argument_T.h"
#include "tao/Fixed_Size_Argument_T.h"
#include "tao/Var_Size_Argument_T.h"
#include "tao/Object_Argument_T.h"
#include /**/ "tao/Version.h"
#include /**/ "tao/Versioned_Namespace.h"

#include "tao/PolicyC.h"

#if TAO_MAJOR_VERSION != 2 || TAO_MINOR_VERSION != 0 || TAO_BETA_VERSION != 4
#error This file should be regenerated with TAO_IDL from version 2.0a
#endif

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_PortableServer_Export

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_module/module_ch.cpp:41

namespace PortableServer
{

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_enum/enum_ch.cpp:47

  enum ThreadPolicyValue
  {
    ORB_CTRL_MODEL,
    SINGLE_THREAD_MODEL
  };

  typedef ThreadPolicyValue &ThreadPolicyValue_out;

  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:784

#if !defined (_PORTABLESERVER_THREADPOLICY__VAR_OUT_CH_)
#define _PORTABLESERVER_THREADPOLICY__VAR_OUT_CH_

  class ThreadPolicy;
  typedef ThreadPolicy *ThreadPolicy_ptr;

  typedef
    TAO_Objref_Var_T<
        ThreadPolicy
      >
    ThreadPolicy_var;
  
  typedef
    TAO_Objref_Out_T<
        ThreadPolicy
      >
    ThreadPolicy_out;

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:45

  class TAO_PortableServer_Export ThreadPolicy
    : public virtual ::CORBA::Policy
  
  {
  public:

    // TAO_IDL - Generated from
    // .\be\be_type.cpp:307
    
    typedef ThreadPolicy_ptr _ptr_type;
    typedef ThreadPolicy_var _var_type;
    typedef ThreadPolicy_out _out_type;

    // The static operations.
    static ThreadPolicy_ptr _duplicate (ThreadPolicy_ptr obj);

    static void _tao_release (ThreadPolicy_ptr obj);

    static ThreadPolicy_ptr _narrow (::CORBA::Object_ptr obj);
    static ThreadPolicy_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static ThreadPolicy_ptr _nil (void);

    virtual ::PortableServer::ThreadPolicyValue value (
      void) = 0;

    virtual ::CORBA::Policy_ptr copy (
      void) = 0;

    virtual void destroy (
      void) = 0;

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:156

    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Abstract or local interface only.
    ThreadPolicy (void);

    

    virtual ~ThreadPolicy (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    ThreadPolicy (const ThreadPolicy &);

    void operator= (const ThreadPolicy &);
  };

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_module/module_ch.cpp:70

} // module PortableServer

// TAO_IDL - Generated from
// .\be\be_visitor_arg_traits.cpp:68


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL


// Arg traits specializations.
namespace TAO
{

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:898

  template<>
  class Arg_Traits< ::PortableServer::ThreadPolicyValue>
    : public
        Basic_Arg_Traits_T<
            ::PortableServer::ThreadPolicyValue,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };
}

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// .\be\be_visitor_traits.cpp:62


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Traits specializations.
namespace TAO
{

#if !defined (_PORTABLESERVER_THREADPOLICY__TRAITS_)
#define _PORTABLESERVER_THREADPOLICY__TRAITS_

  template<>
  struct TAO_PortableServer_Export Objref_Traits< ::PortableServer::ThreadPolicy>
  {
    static ::PortableServer::ThreadPolicy_ptr duplicate (
        ::PortableServer::ThreadPolicy_ptr p);
    static void release (
        ::PortableServer::ThreadPolicy_ptr p);
    static ::PortableServer::ThreadPolicy_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::PortableServer::ThreadPolicy_ptr p,
        TAO_OutputCDR & cdr);
  };

#endif /* end #if !defined */
}
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_enum/cdr_op_ch.cpp:40



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_PortableServer_Export ::CORBA::Boolean operator<< (TAO_OutputCDR &strm, PortableServer::ThreadPolicyValue _tao_enumerator);
TAO_PortableServer_Export ::CORBA::Boolean operator>> (TAO_InputCDR &strm, PortableServer::ThreadPolicyValue &_tao_enumerator);

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// .\be\be_codegen.cpp:1581


TAO_END_VERSIONED_NAMESPACE_DECL

#endif /* ifndef */

