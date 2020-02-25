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

#ifndef _TAO_IDL_MESSENGERC_GZITBN_H_
#define _TAO_IDL_MESSENGERC_GZITBN_H_


#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#include "tao/ORB.h"
#include "tao/SystemException.h"
#include "tao/Basic_Types.h"
#include "tao/ORB_Constants.h"
#include "tao/Object.h"
#include "tao/Objref_VarOut_T.h"
#include "tao/Arg_Traits_T.h"
#include "tao/Basic_Arguments.h"
#include "tao/Special_Basic_Arguments.h"
#include "tao/Any_Insert_Policy_T.h"
#include "tao/Fixed_Size_Argument_T.h"
#include "tao/Var_Size_Argument_T.h"
#include "tao/Object_Argument_T.h"
#include "tao/Special_Basic_Arguments.h"
#include "tao/UB_String_Arguments.h"
#include /**/ "tao/Version.h"
#include /**/ "tao/Versioned_Namespace.h"

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
// .\be\be_interface.cpp:784

#if !defined (_MESSENGER__VAR_OUT_CH_)
#define _MESSENGER__VAR_OUT_CH_

class Messenger;
typedef Messenger *Messenger_ptr;

typedef
  TAO_Objref_Var_T<
      Messenger
    >
  Messenger_var;

typedef
  TAO_Objref_Out_T<
      Messenger
    >
  Messenger_out;

#endif /* end #if !defined */

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:45

class  Messenger
  : public virtual ::CORBA::Object
{
public:
  friend class TAO::Narrow_Utils<Messenger>;

  // TAO_IDL - Generated from
  // .\be\be_type.cpp:307
  
  typedef Messenger_ptr _ptr_type;
  typedef Messenger_var _var_type;
  typedef Messenger_out _out_type;

  // The static operations.
  static Messenger_ptr _duplicate (Messenger_ptr obj);

  static void _tao_release (Messenger_ptr obj);

  static Messenger_ptr _narrow (::CORBA::Object_ptr obj);
  static Messenger_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
  static Messenger_ptr _nil (void);

  virtual ::CORBA::Boolean send_message (
    const char * user_name,
    const char * subject,
    char *& message);

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:156

  virtual ::CORBA::Boolean _is_a (const char *type_id);
  virtual const char* _interface_repository_id (void) const;
  virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);

private:
  TAO::Collocation_Proxy_Broker *the_TAO_Messenger_Proxy_Broker_;

protected:
  // Concrete interface only.
  Messenger (void);

  // These methods traverse the inheritance tree and set the
  // parents piece of the given class in the right mode.
  virtual void Messenger_setup_collocation (void);

  // Concrete non-local interface only.
  Messenger (
      ::IOP::IOR *ior,
      TAO_ORB_Core *orb_core);
  
  // Non-local interface only.
  Messenger (
      TAO_Stub *objref,
      ::CORBA::Boolean _tao_collocated = false,
      TAO_Abstract_ServantBase *servant = 0,
      TAO_ORB_Core *orb_core = 0);

  virtual ~Messenger (void);

private:
  // Private and unimplemented for concrete interfaces.
  Messenger (const Messenger &);

  void operator= (const Messenger &);
};

// TAO_IDL - Generated from
// .\be\be_visitor_arg_traits.cpp:68

TAO_BEGIN_VERSIONED_NAMESPACE_DECL


// Arg traits specializations.
namespace TAO
{

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:147

#if !defined (_MESSENGER__ARG_TRAITS_)
#define _MESSENGER__ARG_TRAITS_

  template<>
  class  Arg_Traits< ::Messenger>
    : public
        Object_Arg_Traits_T<
            ::Messenger_ptr,
            ::Messenger_var,
            ::Messenger_out,
            TAO::Objref_Traits<Messenger>,
            TAO::Any_Insert_Policy_Noop
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
(*_TAO_Messenger_Proxy_Broker_Factory_function_pointer) (
    ::CORBA::Object_ptr obj);

// TAO_IDL - Generated from
// .\be\be_visitor_traits.cpp:62

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Traits specializations.
namespace TAO
{

#if !defined (_MESSENGER__TRAITS_)
#define _MESSENGER__TRAITS_

  template<>
  struct  Objref_Traits< ::Messenger>
  {
    static ::Messenger_ptr duplicate (
        ::Messenger_ptr p);
    static void release (
        ::Messenger_ptr p);
    static ::Messenger_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::Messenger_ptr p,
        TAO_OutputCDR & cdr);
  };

#endif /* end #if !defined */
}
TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/cdr_op_ch.cpp:47

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 ::CORBA::Boolean operator<< (TAO_OutputCDR &, const Messenger_ptr );
 ::CORBA::Boolean operator>> (TAO_InputCDR &, Messenger_ptr &);

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// .\be\be_codegen.cpp:1581
#if defined (__ACE_INLINE__)
#include "MessengerC.inl"
#endif /* defined INLINE */

#endif /* ifndef */

