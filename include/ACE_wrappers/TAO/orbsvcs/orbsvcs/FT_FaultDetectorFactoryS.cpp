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
// .\be\be_codegen.cpp:651

#ifndef _TAO_IDL_FT_FAULTDETECTORFACTORYS_C9FJD5_CPP_
#define _TAO_IDL_FT_FAULTDETECTORFACTORYS_C9FJD5_CPP_


#include "FT_FaultDetectorFactoryS.h"
#include "tao/PortableServer/Operation_Table_Perfect_Hash.h"
#include "tao/PortableServer/Upcall_Command.h"
#include "tao/PortableServer/Upcall_Wrapper.h"
#include "tao/TAO_Server_Request.h"
#include "tao/ORB_Core.h"
#include "tao/Profile.h"
#include "tao/Stub.h"
#include "tao/IFR_Client_Adapter.h"
#include "tao/Object_T.h"
#include "tao/AnyTypeCode/TypeCode.h"
#include "tao/AnyTypeCode/DynamicC.h"
#include "tao/CDR.h"
#include "tao/operation_details.h"
#include "tao/PortableInterceptor.h"
#include "ace/Dynamic_Service.h"
#include "ace/Malloc_Allocator.h"

#if !defined (__ACE_INLINE__)
#include "FT_FaultDetectorFactoryS.inl"
#endif /* !defined INLINE */

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// .\be\be_interface.cpp:1714

class TAO_FT_FaultDetectorFactory_Perfect_Hash_OpTable
  : public TAO_Perfect_Hash_OpTable
{
private:
  unsigned int hash (const char *str, unsigned int len);

public:
  const TAO_operation_db_entry * lookup (const char *str, unsigned int len);
};

/* C++ code produced by gperf version 2.8 (ACE version) */
/* Command-line: ace_gperf -m -M -J -c -C -D -E -T -f 0 -F 0,0 -a -o -t -p -K opname -L C++ -Z TAO_FT_FaultDetectorFactory_Perfect_Hash_OpTable -N lookup  */
unsigned int
TAO_FT_FaultDetectorFactory_Perfect_Hash_OpTable::hash (const char *str, unsigned int len)
{
  static const unsigned char asso_values[] =
    {
     29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
     29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
     29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
     29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
     29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
     29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
     29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
     29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
     29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
     29, 29, 29, 29, 29,  0, 29,  0, 29, 10,
      5,  5, 29, 29, 29, 15, 29, 29, 29, 29,
      0, 29, 29, 29, 29,  0,  0, 29, 29, 29,
     29, 29, 29, 29, 29, 29, 29, 29,
    };
  return len + asso_values[(int) str[len - 1]] + asso_values[(int) str[0]];
}

const TAO_operation_db_entry *
TAO_FT_FaultDetectorFactory_Perfect_Hash_OpTable::lookup (const char *str, unsigned int len)
{
  enum
    {
      TOTAL_KEYWORDS = 10,
      MIN_WORD_LENGTH = 5,
      MAX_WORD_LENGTH = 17,
      MIN_HASH_VALUE = 5,
      MAX_HASH_VALUE = 28,
      HASH_VALUE_RANGE = 24,
      DUPLICATES = 0,
      WORDLIST_SIZE = 15
    };

  static const TAO_operation_db_entry wordlist[] =
    {
      {"",0,0},{"",0,0},{"",0,0},{"",0,0},{"",0,0},
      {"_is_a", &POA_FT::FaultDetectorFactory::_is_a_skel, 0},
      {"",0,0},{"",0,0},
      {"shutdown", &POA_FT::FaultDetectorFactory::shutdown_skel, 0},
      {"",0,0},
      {"_component", &POA_FT::FaultDetectorFactory::_component_skel, 0},
      {"",0,0},{"",0,0},
      {"_non_existent", &POA_FT::FaultDetectorFactory::_non_existent_skel, 0},
      {"",0,0},
      {"_interface", &POA_FT::FaultDetectorFactory::_interface_skel, 0},
      {"",0,0},{"",0,0},
      {"delete_object", &POA_FT::FaultDetectorFactory::delete_object_skel, 0},
      {"_repository_id", &POA_FT::FaultDetectorFactory::_repository_id_skel, 0},
      {"",0,0},{"",0,0},{"",0,0},
      {"create_object", &POA_FT::FaultDetectorFactory::create_object_skel, 0},
      {"",0,0},{"",0,0},{"",0,0},
      {"change_properties", &POA_FT::FaultDetectorFactory::change_properties_skel, 0},
      {"is_alive", &POA_FT::FaultDetectorFactory::is_alive_skel, 0},
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      unsigned int key = hash (str, len);

      if (key <= MAX_HASH_VALUE && key >= MIN_HASH_VALUE)
        {
          const char *s = wordlist[key].opname;

          if (*str == *s && !ACE_OS::strncmp (str + 1, s + 1, len - 1))
            return &wordlist[key];
        }
    }
  return 0;
}

static TAO_FT_FaultDetectorFactory_Perfect_Hash_OpTable tao_FT_FaultDetectorFactory_optable;

// TAO_IDL - Generated from
// e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ss.cpp:1029

TAO::Collocation_Proxy_Broker *
FT__TAO_FaultDetectorFactory_Proxy_Broker_Factory_function ( ::CORBA::Object_ptr)
{
  return reinterpret_cast<TAO::Collocation_Proxy_Broker *> (0xdead); // Dummy
}

int
FT__TAO_FaultDetectorFactory_Proxy_Broker_Factory_Initializer (size_t)
{
  FT__TAO_FaultDetectorFactory_Proxy_Broker_Factory_function_pointer = 
    FT__TAO_FaultDetectorFactory_Proxy_Broker_Factory_function;
  
  return 0;
}

static int
FT__TAO_FaultDetectorFactory_Proxy_Broker_Stub_Factory_Initializer_Scarecrow =
  FT__TAO_FaultDetectorFactory_Proxy_Broker_Factory_Initializer (
      reinterpret_cast<size_t> (FT__TAO_FaultDetectorFactory_Proxy_Broker_Factory_Initializer));


// TAO_IDL - Generated from 
// e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ss.cpp:97

POA_FT::FaultDetectorFactory::FaultDetectorFactory (void)
  : TAO_ServantBase ()
{
  this->optable_ = &tao_FT_FaultDetectorFactory_optable;
}

POA_FT::FaultDetectorFactory::FaultDetectorFactory (const FaultDetectorFactory& rhs)
  : TAO_Abstract_ServantBase (rhs),
    TAO_ServantBase (rhs),
    POA_PortableGroup::GenericFactory (rhs),
    POA_FT::PullMonitorable (rhs)
{
}

POA_FT::FaultDetectorFactory::~FaultDetectorFactory (void)
{
}

namespace POA_FT
{
  

  // TAO_IDL - Generated from
  // e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_operation/upcall_command_ss.cpp:81

  class change_properties_FaultDetectorFactory
    : public TAO::Upcall_Command
  {
  public:
    inline change_properties_FaultDetectorFactory (
      POA_FT::FaultDetectorFactory * servant,
      TAO_Operation_Details const * operation_details,
      TAO::Argument * const args[])
      : servant_ (servant)
        , operation_details_ (operation_details)
        , args_ (args)
    {
    }

    virtual void execute (void)
    {
      TAO::SArg_Traits< ::PortableGroup::Properties>::in_arg_type arg_1 =
        TAO::Portable_Server::get_in_arg< ::PortableGroup::Properties> (
          this->operation_details_,
          this->args_,
          1);
        
      this->servant_->change_properties (
        arg_1);
    }
  
  private:
    POA_FT::FaultDetectorFactory * const servant_;
    TAO_Operation_Details const * const operation_details_;
    TAO::Argument * const * const args_;
  };
}

// TAO_IDL - Generated from 
// e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_ss.cpp:173

void POA_FT::FaultDetectorFactory::change_properties_skel (
    TAO_ServerRequest & server_request,
    void * TAO_INTERCEPTOR (servant_upcall),
    void * servant)
{
#if TAO_HAS_INTERCEPTORS == 1
  static ::CORBA::TypeCode_ptr const exceptions[] = 
    {
      PortableGroup::_tc_InvalidProperty
    };
  static ::CORBA::ULong const nexceptions = 1;
#endif /* TAO_HAS_INTERCEPTORS */

  TAO::SArg_Traits< void>::ret_val retval;
  TAO::SArg_Traits< ::PortableGroup::Properties>::in_arg_val _tao_property_set;

  TAO::Argument * const args[] =
    {
      &retval,
      &_tao_property_set
    };
  
  static size_t const nargs = 2;

  POA_FT::FaultDetectorFactory * const impl =
    static_cast<POA_FT::FaultDetectorFactory *> (servant);

  change_properties_FaultDetectorFactory command (
    impl,
    server_request.operation_details (),
    args);
  
  TAO::Upcall_Wrapper upcall_wrapper;
  upcall_wrapper.upcall (server_request
                         , args
                         , nargs
                         , command
#if TAO_HAS_INTERCEPTORS == 1
                         , servant_upcall
                         , exceptions
                         , nexceptions
#endif  /* TAO_HAS_INTERCEPTORS == 1 */
                         );
}


namespace POA_FT
{
  

  // TAO_IDL - Generated from
  // e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_operation/upcall_command_ss.cpp:81

  class shutdown_FaultDetectorFactory
    : public TAO::Upcall_Command
  {
  public:
    inline shutdown_FaultDetectorFactory (
      POA_FT::FaultDetectorFactory * servant)
      : servant_ (servant)
    {
    }

    virtual void execute (void)
    {
      this->servant_->shutdown ();
    }
  
  private:
    POA_FT::FaultDetectorFactory * const servant_;
  };
}

// TAO_IDL - Generated from 
// e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_ss.cpp:173

void POA_FT::FaultDetectorFactory::shutdown_skel (
    TAO_ServerRequest & server_request,
    void * TAO_INTERCEPTOR (servant_upcall),
    void * servant)
{
#if TAO_HAS_INTERCEPTORS == 1
  static ::CORBA::TypeCode_ptr const * const exceptions = 0;
  static ::CORBA::ULong const nexceptions = 0;
#endif /* TAO_HAS_INTERCEPTORS */

  TAO::SArg_Traits< void>::ret_val retval;

  TAO::Argument * const args[] =
    {
      &retval
    };
  
  static size_t const nargs = 1;

  POA_FT::FaultDetectorFactory * const impl =
    static_cast<POA_FT::FaultDetectorFactory *> (servant);

  shutdown_FaultDetectorFactory command (
    impl);
  
  TAO::Upcall_Wrapper upcall_wrapper;
  upcall_wrapper.upcall (server_request
                         , args
                         , nargs
                         , command
#if TAO_HAS_INTERCEPTORS == 1
                         , servant_upcall
                         , exceptions
                         , nexceptions
#endif  /* TAO_HAS_INTERCEPTORS == 1 */
                         );
}



// TAO_IDL - Generated from 
// e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ss.cpp:170


namespace POA_FT
{
  

  // TAO_IDL - Generated from
  // e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_operation/upcall_command_ss.cpp:81

  class _is_a_FaultDetectorFactory_Upcall_Command
    : public TAO::Upcall_Command
  {
  public:
    inline _is_a_FaultDetectorFactory_Upcall_Command (
      POA_FT::FaultDetectorFactory * servant,
      TAO_Operation_Details const * operation_details,
      TAO::Argument * const args[])
      : servant_ (servant)
        , operation_details_ (operation_details)
        , args_ (args)
    {
    }

    virtual void execute (void)
    {
      TAO::SArg_Traits< ::ACE_InputCDR::to_boolean>::ret_arg_type retval =
        TAO::Portable_Server::get_ret_arg< ::ACE_InputCDR::to_boolean> (
          this->operation_details_,
          this->args_);
      
      TAO::SArg_Traits< char *>::in_arg_type arg_1 =
        TAO::Portable_Server::get_in_arg< char *> (
          this->operation_details_,
          this->args_,
          1);
        
      retval =
        this->servant_-> _is_a (
          arg_1);
    }
  
  private:
    POA_FT::FaultDetectorFactory * const servant_;
    TAO_Operation_Details const * const operation_details_;
    TAO::Argument * const * const args_;
  };
}

void POA_FT::FaultDetectorFactory::_is_a_skel (
    TAO_ServerRequest & server_request, 
    void * TAO_INTERCEPTOR (servant_upcall),
    void * servant)
{
#if TAO_HAS_INTERCEPTORS == 1
  static ::CORBA::TypeCode_ptr const * const exceptions = 0;
  static ::CORBA::ULong const nexceptions = 0;
#endif /* TAO_HAS_INTERCEPTORS */

  TAO::SArg_Traits< ::ACE_InputCDR::to_boolean>::ret_val retval;
  TAO::SArg_Traits< char *>::in_arg_val _tao_repository_id;

  TAO::Argument * const args[] =
    {
      &retval,
      &_tao_repository_id
    };
  
  static size_t const nargs = 2;

  POA_FT::FaultDetectorFactory * const impl =
    static_cast<POA_FT::FaultDetectorFactory *> (servant);
  
  _is_a_FaultDetectorFactory_Upcall_Command command (
    impl,
    server_request.operation_details (),
    args);
  
  TAO::Upcall_Wrapper upcall_wrapper;
  upcall_wrapper.upcall (server_request
                         , args
                         , nargs
                         , command
#if TAO_HAS_INTERCEPTORS == 1
                         , servant_upcall
                         , exceptions
                         , nexceptions
#endif  /* TAO_HAS_INTERCEPTORS == 1 */
                         );
}


namespace POA_FT
{
  

  // TAO_IDL - Generated from
  // e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_operation/upcall_command_ss.cpp:81

  class _non_existent_FaultDetectorFactory_Upcall_Command
    : public TAO::Upcall_Command
  {
  public:
    inline _non_existent_FaultDetectorFactory_Upcall_Command (
      POA_FT::FaultDetectorFactory * servant,
      TAO_Operation_Details const * operation_details,
      TAO::Argument * const args[])
      : servant_ (servant)
        , operation_details_ (operation_details)
        , args_ (args)
    {
    }

    virtual void execute (void)
    {
      TAO::SArg_Traits< ::ACE_InputCDR::to_boolean>::ret_arg_type retval =
        TAO::Portable_Server::get_ret_arg< ::ACE_InputCDR::to_boolean> (
          this->operation_details_,
          this->args_);
      
      retval =
        this->servant_-> _non_existent ();
    }
  
  private:
    POA_FT::FaultDetectorFactory * const servant_;
    TAO_Operation_Details const * const operation_details_;
    TAO::Argument * const * const args_;
  };
}

void POA_FT::FaultDetectorFactory::_non_existent_skel (
    TAO_ServerRequest & server_request, 
    void * TAO_INTERCEPTOR (servant_upcall),
    void * servant)
{
#if TAO_HAS_INTERCEPTORS == 1
  static ::CORBA::TypeCode_ptr const * const exceptions = 0;
  static ::CORBA::ULong const nexceptions = 0;
#endif /* TAO_HAS_INTERCEPTORS */

  TAO::SArg_Traits< ::ACE_InputCDR::to_boolean>::ret_val retval;

  TAO::Argument * const args[] =
    {
      &retval
    };
  
  static size_t const nargs = 1;

  POA_FT::FaultDetectorFactory * const impl =
    static_cast<POA_FT::FaultDetectorFactory *> (servant);
  
  _non_existent_FaultDetectorFactory_Upcall_Command command (
    impl,
    server_request.operation_details (),
    args);
  
  TAO::Upcall_Wrapper upcall_wrapper;
  upcall_wrapper.upcall (server_request
                         , args
                         , nargs
                         , command
#if TAO_HAS_INTERCEPTORS == 1
                         , servant_upcall
                         , exceptions
                         , nexceptions
#endif  /* TAO_HAS_INTERCEPTORS == 1 */
                         );
}

namespace POA_FT
{
  

  // TAO_IDL - Generated from
  // e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_operation/upcall_command_ss.cpp:81

  class _repository_id_FaultDetectorFactory_Upcall_Command
    : public TAO::Upcall_Command
  {
  public:
    inline _repository_id_FaultDetectorFactory_Upcall_Command (
      POA_FT::FaultDetectorFactory * servant,
      TAO_Operation_Details const * operation_details,
      TAO::Argument * const args[])
      : servant_ (servant)
        , operation_details_ (operation_details)
        , args_ (args)
    {
    }

    virtual void execute (void)
    {
      TAO::SArg_Traits< char *>::ret_arg_type retval =
        TAO::Portable_Server::get_ret_arg< char *> (
          this->operation_details_,
          this->args_);
      
      retval =
        this->servant_-> _repository_id ();
    }
  
  private:
    POA_FT::FaultDetectorFactory * const servant_;
    TAO_Operation_Details const * const operation_details_;
    TAO::Argument * const * const args_;
  };
}

void POA_FT::FaultDetectorFactory::_repository_id_skel (
    TAO_ServerRequest & server_request, 
    void * TAO_INTERCEPTOR (servant_upcall),
    void * servant)
{
#if TAO_HAS_INTERCEPTORS == 1
  static ::CORBA::TypeCode_ptr const * const exceptions = 0;
  static ::CORBA::ULong const nexceptions = 0;
#endif /* TAO_HAS_INTERCEPTORS */

  TAO::SArg_Traits< char *>::ret_val retval;

  TAO::Argument * const args[] =
    {
      &retval
    };
  
  static size_t const nargs = 1;

  POA_FT::FaultDetectorFactory * const impl =
    static_cast<POA_FT::FaultDetectorFactory *> (servant);
  
  _repository_id_FaultDetectorFactory_Upcall_Command command (
    impl,
    server_request.operation_details (),
    args);
  
  TAO::Upcall_Wrapper upcall_wrapper;
  upcall_wrapper.upcall (server_request
                         , args
                         , nargs
                         , command
#if TAO_HAS_INTERCEPTORS == 1
                         , servant_upcall
                         , exceptions
                         , nexceptions
#endif  /* TAO_HAS_INTERCEPTORS == 1 */
                         );
}

// TAO_IDL - Generated from 
// e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ss.cpp:525

void POA_FT::FaultDetectorFactory::_interface_skel (
    TAO_ServerRequest & server_request, 
    void * /* servant_upcall */,
    void * servant)
{
  TAO_IFR_Client_Adapter *_tao_adapter =
    ACE_Dynamic_Service<TAO_IFR_Client_Adapter>::instance (
        TAO_ORB_Core::ifr_client_adapter_name ()
      );
    
  if (!_tao_adapter)
    {
      throw ::CORBA::INTF_REPOS (::CORBA::OMGVMCID | 1, ::CORBA::COMPLETED_NO);
    }
  
  POA_FT::FaultDetectorFactory * const impl =
    static_cast<POA_FT::FaultDetectorFactory *> (servant);
  ::CORBA::InterfaceDef_ptr _tao_retval = impl->_get_interface ();
  server_request.init_reply ();
  TAO_OutputCDR &_tao_out = *server_request.outgoing ();

  ::CORBA::Boolean const _tao_result =
    _tao_adapter->interfacedef_cdr_insert (_tao_out, _tao_retval);
  
  _tao_adapter->dispose (_tao_retval);

  if (!_tao_result)
    {
      throw ::CORBA::MARSHAL ();
    }
}


namespace POA_FT
{
  

  // TAO_IDL - Generated from
  // e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_operation/upcall_command_ss.cpp:81

  class _get_component_FaultDetectorFactory_Upcall_Command
    : public TAO::Upcall_Command
  {
  public:
    inline _get_component_FaultDetectorFactory_Upcall_Command (
      POA_FT::FaultDetectorFactory * servant,
      TAO_Operation_Details const * operation_details,
      TAO::Argument * const args[])
      : servant_ (servant)
        , operation_details_ (operation_details)
        , args_ (args)
    {
    }

    virtual void execute (void)
    {
      TAO::SArg_Traits< ::CORBA::Object>::ret_arg_type retval =
        TAO::Portable_Server::get_ret_arg< ::CORBA::Object> (
          this->operation_details_,
          this->args_);
      
      retval =
        this->servant_-> _get_component ();
    }
  
  private:
    POA_FT::FaultDetectorFactory * const servant_;
    TAO_Operation_Details const * const operation_details_;
    TAO::Argument * const * const args_;
  };
}

void POA_FT::FaultDetectorFactory::_component_skel (
    TAO_ServerRequest & server_request, 
    void * TAO_INTERCEPTOR (servant_upcall),
    void * servant
  )
{
#if TAO_HAS_INTERCEPTORS == 1
  static ::CORBA::TypeCode_ptr const * const exceptions = 0;
  static ::CORBA::ULong const nexceptions = 0;
#endif /* TAO_HAS_INTERCEPTORS */

  TAO::SArg_Traits< ::CORBA::Object>::ret_val retval;

  TAO::Argument * const args[] =
    {
      &retval
    };
  
  static size_t const nargs = 1;

  POA_FT::FaultDetectorFactory * const impl =
    static_cast<POA_FT::FaultDetectorFactory *> (servant);
  
  _get_component_FaultDetectorFactory_Upcall_Command command (
    impl,
    server_request.operation_details (),
    args);
  
  TAO::Upcall_Wrapper upcall_wrapper;
  upcall_wrapper.upcall (server_request
                         , args
                         , nargs
                         , command
#if TAO_HAS_INTERCEPTORS == 1
                         , servant_upcall
                         , exceptions
                         , nexceptions
#endif  /* TAO_HAS_INTERCEPTORS == 1 */
                         );
}

::CORBA::Boolean POA_FT::FaultDetectorFactory::_is_a (const char* value)
{
  return
    (
      ACE_OS::strcmp (
          value,
          "IDL:omg.org/PortableGroup/GenericFactory:1.0"
        ) == 0 ||
      ACE_OS::strcmp (
          value,
          "IDL:omg.org/FT/PullMonitorable:1.0"
        ) == 0 ||
      ACE_OS::strcmp (
          value,
          "IDL:omg.org/FT/FaultDetectorFactory:1.0"
        ) == 0 ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/Object:1.0"
        )
    );
}

const char* POA_FT::FaultDetectorFactory::_interface_repository_id (void) const
{
  return "IDL:omg.org/FT/FaultDetectorFactory:1.0";
}

// TAO_IDL - Generated from
// e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ss.cpp:966

void POA_FT::FaultDetectorFactory::_dispatch (TAO_ServerRequest & req, void * servant_upcall)
{
  this->synchronous_upcall_dispatch (req, servant_upcall, this);
}

// TAO_IDL - Generated from
// e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ss.cpp:884

FT::FaultDetectorFactory *
POA_FT::FaultDetectorFactory::_this (void)
{
  TAO_Stub *stub = this->_create_stub ();

  TAO_Stub_Auto_Ptr safe_stub (stub);
  ::CORBA::Object_ptr tmp = CORBA::Object_ptr ();

  ::CORBA::Boolean const _tao_opt_colloc =
    stub->servant_orb_var ()->orb_core ()->optimize_collocation_objects ();
  
  ACE_NEW_RETURN (
      tmp,
      ::CORBA::Object (stub, _tao_opt_colloc, this),
      0
    );
  
  ::CORBA::Object_var obj = tmp;
  (void) safe_stub.release ();

  typedef ::FT::FaultDetectorFactory STUB_SCOPED_NAME;
  return
    TAO::Narrow_Utils<STUB_SCOPED_NAME>::unchecked_narrow (
        obj.in (),
        FT__TAO_FaultDetectorFactory_Proxy_Broker_Factory_function_pointer
      );
}

TAO_END_VERSIONED_NAMESPACE_DECL



#endif /* ifndef */

