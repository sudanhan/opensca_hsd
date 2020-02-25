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

#ifndef _TAO_IDL_COSTRADINGREPOSS_AUR1HL_H_
#define _TAO_IDL_COSTRADINGREPOSS_AUR1HL_H_


#include "CosTradingReposC.h"
#include "tao/BooleanSeqS.h"
#include "tao/CharSeqS.h"
#include "tao/DoubleSeqS.h"
#include "tao/FloatSeqS.h"
#include "tao/LongDoubleSeqS.h"
#include "tao/LongSeqS.h"
#include "tao/OctetSeqS.h"
#include "tao/ShortSeqS.h"
#include "tao/StringSeqS.h"
#include "tao/ULongSeqS.h"
#include "tao/UShortSeqS.h"
#include "tao/WCharSeqS.h"
#include "tao/WStringSeqS.h"
#include "tao/LongLongSeqS.h"
#include "tao/ULongLongSeqS.h"
#include "tao/PolicyS.h"
#include "tao/Policy_ManagerS.h"
#include "tao/Policy_CurrentS.h"
#include "tao/ServicesS.h"
#include "tao/ParameterModeS.h"
#include "tao/orb_typesS.h"
#include "tao/Typecode_typesS.h"
#include "tao/WrongTransactionS.h"
#include "CosTradingS.h"
#include "tao/PortableServer/Basic_SArguments.h"
#include "tao/PortableServer/Special_Basic_SArguments.h"
#include "tao/PortableServer/Fixed_Size_SArgument_T.h"
#include "tao/PortableServer/Var_Size_SArgument_T.h"
#include "tao/PortableServer/Object_SArg_Traits.h"
#include "tao/PortableServer/UB_String_SArguments.h"
#include "tao/PortableServer/TypeCode_SArg_Traits.h"
#include "tao/PortableServer/get_arg.h"
#include "tao/Special_Basic_Arguments.h"
#include "tao/UB_String_Arguments.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/Collocation_Proxy_Broker.h"
#include "tao/PortableServer/PortableServer.h"
#include "tao/PortableServer/Servant_Base.h"

#include /**/ "orbsvcs/Trader/trading_skel_export.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_Trading_Skel_Export

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// .\be\be_visitor_arg_traits.cpp:68


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL


// Arg traits specializations.
namespace TAO
{

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:147

#if !defined (_COSTRADINGREPOS_SERVICETYPEREPOSITORY__SARG_TRAITS_)
#define _COSTRADINGREPOS_SERVICETYPEREPOSITORY__SARG_TRAITS_

  template<>
  class  SArg_Traits< ::CosTradingRepos::ServiceTypeRepository>
    : public
        Object_SArg_Traits_T<
            ::CosTradingRepos::ServiceTypeRepository_ptr,
            ::CosTradingRepos::ServiceTypeRepository_var,
            ::CosTradingRepos::ServiceTypeRepository_out,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:679

  template<>
  class SArg_Traits< ::CosTradingRepos::ServiceTypeRepository::ServiceTypeNameSeq>
    : public
        Var_Size_SArg_Traits_T<
            ::CosTradingRepos::ServiceTypeRepository::ServiceTypeNameSeq,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:898

  template<>
  class SArg_Traits< ::CosTradingRepos::ServiceTypeRepository::PropertyMode>
    : public
        Basic_SArg_Traits_T<
            ::CosTradingRepos::ServiceTypeRepository::PropertyMode,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:941

  template<>
  class SArg_Traits< ::CosTradingRepos::ServiceTypeRepository::PropStruct>
    : public
        Var_Size_SArg_Traits_T<
            ::CosTradingRepos::ServiceTypeRepository::PropStruct,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:679

  template<>
  class SArg_Traits< ::CosTradingRepos::ServiceTypeRepository::PropStructSeq>
    : public
        Var_Size_SArg_Traits_T<
            ::CosTradingRepos::ServiceTypeRepository::PropStructSeq,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:941

  template<>
  class SArg_Traits< ::CosTradingRepos::ServiceTypeRepository::IncarnationNumber>
    : public
        Fixed_Size_SArg_Traits_T<
            ::CosTradingRepos::ServiceTypeRepository::IncarnationNumber,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:941

  template<>
  class SArg_Traits< ::CosTradingRepos::ServiceTypeRepository::TypeStruct>
    : public
        Var_Size_SArg_Traits_T<
            ::CosTradingRepos::ServiceTypeRepository::TypeStruct,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:898

  template<>
  class SArg_Traits< ::CosTradingRepos::ServiceTypeRepository::ListOption>
    : public
        Basic_SArg_Traits_T<
            ::CosTradingRepos::ServiceTypeRepository::ListOption,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:1052

  template<>
  class SArg_Traits< ::CosTradingRepos::ServiceTypeRepository::SpecifiedServiceTypes>
    : public
        Fixed_Size_SArg_Traits_T<
            ::CosTradingRepos::ServiceTypeRepository::SpecifiedServiceTypes,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:679

  template<>
  class SArg_Traits< ::CosTradingSequences::ShortSeq>
    : public
        Var_Size_SArg_Traits_T<
            ::CosTradingSequences::ShortSeq,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:679

  template<>
  class SArg_Traits< ::CosTradingSequences::UShortSeq>
    : public
        Var_Size_SArg_Traits_T<
            ::CosTradingSequences::UShortSeq,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:679

  template<>
  class SArg_Traits< ::CosTradingSequences::LongSeq>
    : public
        Var_Size_SArg_Traits_T<
            ::CosTradingSequences::LongSeq,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:679

  template<>
  class SArg_Traits< ::CosTradingSequences::ULongSeq>
    : public
        Var_Size_SArg_Traits_T<
            ::CosTradingSequences::ULongSeq,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:679

  template<>
  class SArg_Traits< ::CosTradingSequences::BooleanSeq>
    : public
        Var_Size_SArg_Traits_T<
            ::CosTradingSequences::BooleanSeq,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:679

  template<>
  class SArg_Traits< ::CosTradingSequences::FloatSeq>
    : public
        Var_Size_SArg_Traits_T<
            ::CosTradingSequences::FloatSeq,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:679

  template<>
  class SArg_Traits< ::CosTradingSequences::DoubleSeq>
    : public
        Var_Size_SArg_Traits_T<
            ::CosTradingSequences::DoubleSeq,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:679

  template<>
  class SArg_Traits< ::CosTradingSequences::StringSeq>
    : public
        Var_Size_SArg_Traits_T<
            ::CosTradingSequences::StringSeq,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };
}

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_module/module_sh.cpp:41

namespace POA_CosTradingRepos
{
  

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_sh.cpp:78

  class ServiceTypeRepository;
  typedef ServiceTypeRepository *ServiceTypeRepository_ptr;

  class TAO_Trading_Skel_Export ServiceTypeRepository
    : public virtual PortableServer::ServantBase
  {
  protected:
    ServiceTypeRepository (void);
  
  public:
    /// Useful for template programming.
    typedef ::CosTradingRepos::ServiceTypeRepository _stub_type;
    typedef ::CosTradingRepos::ServiceTypeRepository_ptr _stub_ptr_type;
    typedef ::CosTradingRepos::ServiceTypeRepository_var _stub_var_type;

    ServiceTypeRepository (const ServiceTypeRepository& rhs);
    virtual ~ServiceTypeRepository (void);

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
    
    ::CosTradingRepos::ServiceTypeRepository *_this (void);
    
    virtual const char* _interface_repository_id (void) const;

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:41

    virtual ::CosTradingRepos::ServiceTypeRepository::IncarnationNumber incarnation (
      void) = 0;

    static void _get_incarnation_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:41

    virtual ::CosTradingRepos::ServiceTypeRepository::IncarnationNumber add_type (
      const char * name,
      const char * if_name,
      const ::CosTradingRepos::ServiceTypeRepository::PropStructSeq & props,
      const ::CosTradingRepos::ServiceTypeRepository::ServiceTypeNameSeq & super_types) = 0;

    static void add_type_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:41

    virtual void remove_type (
      const char * name) = 0;

    static void remove_type_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:41

    virtual ::CosTradingRepos::ServiceTypeRepository::ServiceTypeNameSeq * list_types (
      const ::CosTradingRepos::ServiceTypeRepository::SpecifiedServiceTypes & which_types) = 0;

    static void list_types_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:41

    virtual ::CosTradingRepos::ServiceTypeRepository::TypeStruct * describe_type (
      const char * name) = 0;

    static void describe_type_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:41

    virtual ::CosTradingRepos::ServiceTypeRepository::TypeStruct * fully_describe_type (
      const char * name) = 0;

    static void fully_describe_type_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:41

    virtual void mask_type (
      const char * name) = 0;

    static void mask_type_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:41

    virtual void unmask_type (
      const char * name) = 0;

    static void unmask_type_skel (
        TAO_ServerRequest & server_request,
        void * servant_upcall,
        void * servant);
  };

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_module/module_sh.cpp:72

} // module CosTradingRepos

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_module/module_sh.cpp:41

namespace POA_CosTradingSequences
{
  

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_module/module_sh.cpp:72

} // module CosTradingSequences

TAO_END_VERSIONED_NAMESPACE_DECL


#if defined (__ACE_INLINE__)
#include "CosTradingReposS.inl"
#endif /* defined INLINE */

#endif /* ifndef */

