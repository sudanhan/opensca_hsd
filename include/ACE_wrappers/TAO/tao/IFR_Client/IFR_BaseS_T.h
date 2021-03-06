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
// .\be\be_codegen.cpp:598

#ifndef _TAO_IDL_IFR_BASES_T_GVX5SL_H_
#define _TAO_IDL_IFR_BASES_T_GVX5SL_H_



TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from 
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_root/root_sth.cpp:70

namespace POA_CORBA
{

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/tie_sh.cpp:78

  // TIE class: Refer to CORBA v2.2, Section 20.34.4
  template <class T>
  class  IRObject_tie : public IRObject
  {
  public:
    /// the T& ctor
    IRObject_tie (T &t);
    /// ctor taking a POA
    IRObject_tie (T &t, PortableServer::POA_ptr poa);
    /// ctor taking pointer and an ownership flag
    IRObject_tie (T *tp, ::CORBA::Boolean release = true);
    /// ctor with T*, ownership flag and a POA
    IRObject_tie (
        T *tp,
        PortableServer::POA_ptr poa,
        ::CORBA::Boolean release = true
      );
    /// dtor

    ~IRObject_tie (void);
    // TIE specific functions
    /// return the underlying object
    T *_tied_object (void);
    /// set the underlying object
    void _tied_object (T &obj);
    /// set the underlying object and the ownership flag
    void _tied_object (T *obj, ::CORBA::Boolean release = true);
    /// do we own it
    ::CORBA::Boolean _is_owner (void);
    /// set the ownership

    void _is_owner ( ::CORBA::Boolean b);
    // overridden ServantBase operations
    PortableServer::POA_ptr _default_POA (void);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    ::CORBA::DefinitionKind def_kind (
      void);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    void destroy (
      void);
  
  private:
    T *ptr_;
    PortableServer::POA_var poa_;
    ::CORBA::Boolean rel_;

    // copy and assignment are not allowed
    IRObject_tie (const IRObject_tie &);
    void operator= (const IRObject_tie &);
  };

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/tie_sh.cpp:78

  // TIE class: Refer to CORBA v2.2, Section 20.34.4
  template <class T>
  class  Contained_tie : public Contained
  {
  public:
    /// the T& ctor
    Contained_tie (T &t);
    /// ctor taking a POA
    Contained_tie (T &t, PortableServer::POA_ptr poa);
    /// ctor taking pointer and an ownership flag
    Contained_tie (T *tp, ::CORBA::Boolean release = true);
    /// ctor with T*, ownership flag and a POA
    Contained_tie (
        T *tp,
        PortableServer::POA_ptr poa,
        ::CORBA::Boolean release = true
      );
    /// dtor

    ~Contained_tie (void);
    // TIE specific functions
    /// return the underlying object
    T *_tied_object (void);
    /// set the underlying object
    void _tied_object (T &obj);
    /// set the underlying object and the ownership flag
    void _tied_object (T *obj, ::CORBA::Boolean release = true);
    /// do we own it
    ::CORBA::Boolean _is_owner (void);
    /// set the ownership

    void _is_owner ( ::CORBA::Boolean b);
    // overridden ServantBase operations
    PortableServer::POA_ptr _default_POA (void);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    ::CORBA::DefinitionKind def_kind (
      void);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    void destroy (
      void);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    char * id (
      void);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    void id (
      const char *);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    char * name (
      void);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    void name (
      const char *);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    char * version (
      void);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    void version (
      const char *);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    ::CORBA::Container_ptr defined_in (
      void);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    char * absolute_name (
      void);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    ::CORBA::Repository_ptr containing_repository (
      void);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    ::CORBA::Contained::Description * describe (
      void);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    void move (
      ::CORBA::Container_ptr,
      const char *,
      const char *);
  
  private:
    T *ptr_;
    PortableServer::POA_var poa_;
    ::CORBA::Boolean rel_;

    // copy and assignment are not allowed
    Contained_tie (const Contained_tie &);
    void operator= (const Contained_tie &);
  };

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/tie_sh.cpp:78

  // TIE class: Refer to CORBA v2.2, Section 20.34.4
  template <class T>
  class  Container_tie : public Container
  {
  public:
    /// the T& ctor
    Container_tie (T &t);
    /// ctor taking a POA
    Container_tie (T &t, PortableServer::POA_ptr poa);
    /// ctor taking pointer and an ownership flag
    Container_tie (T *tp, ::CORBA::Boolean release = true);
    /// ctor with T*, ownership flag and a POA
    Container_tie (
        T *tp,
        PortableServer::POA_ptr poa,
        ::CORBA::Boolean release = true
      );
    /// dtor

    ~Container_tie (void);
    // TIE specific functions
    /// return the underlying object
    T *_tied_object (void);
    /// set the underlying object
    void _tied_object (T &obj);
    /// set the underlying object and the ownership flag
    void _tied_object (T *obj, ::CORBA::Boolean release = true);
    /// do we own it
    ::CORBA::Boolean _is_owner (void);
    /// set the ownership

    void _is_owner ( ::CORBA::Boolean b);
    // overridden ServantBase operations
    PortableServer::POA_ptr _default_POA (void);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    ::CORBA::DefinitionKind def_kind (
      void);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    void destroy (
      void);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    ::CORBA::Contained_ptr lookup (
      const char *);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    ::CORBA::ContainedSeq * contents (
      ::CORBA::DefinitionKind,
      ::CORBA::Boolean);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    ::CORBA::ContainedSeq * lookup_name (
      const char *,
      ::CORBA::Long,
      ::CORBA::DefinitionKind,
      ::CORBA::Boolean);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    ::CORBA::Container::DescriptionSeq * describe_contents (
      ::CORBA::DefinitionKind,
      ::CORBA::Boolean,
      ::CORBA::Long);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    ::CORBA::ModuleDef_ptr create_module (
      const char *,
      const char *,
      const char *);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    ::CORBA::ConstantDef_ptr create_constant (
      const char *,
      const char *,
      const char *,
      ::CORBA::IDLType_ptr,
      const ::CORBA::Any &);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    ::CORBA::StructDef_ptr create_struct (
      const char *,
      const char *,
      const char *,
      const ::CORBA::StructMemberSeq &);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    ::CORBA::UnionDef_ptr create_union (
      const char *,
      const char *,
      const char *,
      ::CORBA::IDLType_ptr,
      const ::CORBA::UnionMemberSeq &);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    ::CORBA::EnumDef_ptr create_enum (
      const char *,
      const char *,
      const char *,
      const ::CORBA::EnumMemberSeq &);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    ::CORBA::AliasDef_ptr create_alias (
      const char *,
      const char *,
      const char *,
      ::CORBA::IDLType_ptr);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    ::CORBA::InterfaceDef_ptr create_interface (
      const char *,
      const char *,
      const char *,
      const ::CORBA::InterfaceDefSeq &);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    ::CORBA::ValueDef_ptr create_value (
      const char *,
      const char *,
      const char *,
      ::CORBA::Boolean,
      ::CORBA::Boolean,
      ::CORBA::ValueDef_ptr,
      ::CORBA::Boolean,
      const ::CORBA::ValueDefSeq &,
      const ::CORBA::InterfaceDefSeq &,
      const ::CORBA::InitializerSeq &);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    ::CORBA::ValueBoxDef_ptr create_value_box (
      const char *,
      const char *,
      const char *,
      ::CORBA::IDLType_ptr);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    ::CORBA::ExceptionDef_ptr create_exception (
      const char *,
      const char *,
      const char *,
      const ::CORBA::StructMemberSeq &);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    ::CORBA::NativeDef_ptr create_native (
      const char *,
      const char *,
      const char *);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    ::CORBA::AbstractInterfaceDef_ptr create_abstract_interface (
      const char *,
      const char *,
      const char *,
      const ::CORBA::AbstractInterfaceDefSeq &);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    ::CORBA::LocalInterfaceDef_ptr create_local_interface (
      const char *,
      const char *,
      const char *,
      const ::CORBA::InterfaceDefSeq &);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    ::CORBA::ExtValueDef_ptr create_ext_value (
      const char *,
      const char *,
      const char *,
      ::CORBA::Boolean,
      ::CORBA::Boolean,
      ::CORBA::ValueDef_ptr,
      ::CORBA::Boolean,
      const ::CORBA::ValueDefSeq &,
      const ::CORBA::InterfaceDefSeq &,
      const ::CORBA::ExtInitializerSeq &);
  
  private:
    T *ptr_;
    PortableServer::POA_var poa_;
    ::CORBA::Boolean rel_;

    // copy and assignment are not allowed
    Container_tie (const Container_tie &);
    void operator= (const Container_tie &);
  };

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/tie_sh.cpp:78

  // TIE class: Refer to CORBA v2.2, Section 20.34.4
  template <class T>
  class  IDLType_tie : public IDLType
  {
  public:
    /// the T& ctor
    IDLType_tie (T &t);
    /// ctor taking a POA
    IDLType_tie (T &t, PortableServer::POA_ptr poa);
    /// ctor taking pointer and an ownership flag
    IDLType_tie (T *tp, ::CORBA::Boolean release = true);
    /// ctor with T*, ownership flag and a POA
    IDLType_tie (
        T *tp,
        PortableServer::POA_ptr poa,
        ::CORBA::Boolean release = true
      );
    /// dtor

    ~IDLType_tie (void);
    // TIE specific functions
    /// return the underlying object
    T *_tied_object (void);
    /// set the underlying object
    void _tied_object (T &obj);
    /// set the underlying object and the ownership flag
    void _tied_object (T *obj, ::CORBA::Boolean release = true);
    /// do we own it
    ::CORBA::Boolean _is_owner (void);
    /// set the ownership

    void _is_owner ( ::CORBA::Boolean b);
    // overridden ServantBase operations
    PortableServer::POA_ptr _default_POA (void);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    ::CORBA::DefinitionKind def_kind (
      void);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    void destroy (
      void);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    ::CORBA::TypeCode_ptr type (
      void);
  
  private:
    T *ptr_;
    PortableServer::POA_var poa_;
    ::CORBA::Boolean rel_;

    // copy and assignment are not allowed
    IDLType_tie (const IDLType_tie &);
    void operator= (const IDLType_tie &);
  };

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/tie_sh.cpp:78

  // TIE class: Refer to CORBA v2.2, Section 20.34.4
  template <class T>
  class  TypedefDef_tie : public TypedefDef
  {
  public:
    /// the T& ctor
    TypedefDef_tie (T &t);
    /// ctor taking a POA
    TypedefDef_tie (T &t, PortableServer::POA_ptr poa);
    /// ctor taking pointer and an ownership flag
    TypedefDef_tie (T *tp, ::CORBA::Boolean release = true);
    /// ctor with T*, ownership flag and a POA
    TypedefDef_tie (
        T *tp,
        PortableServer::POA_ptr poa,
        ::CORBA::Boolean release = true
      );
    /// dtor

    ~TypedefDef_tie (void);
    // TIE specific functions
    /// return the underlying object
    T *_tied_object (void);
    /// set the underlying object
    void _tied_object (T &obj);
    /// set the underlying object and the ownership flag
    void _tied_object (T *obj, ::CORBA::Boolean release = true);
    /// do we own it
    ::CORBA::Boolean _is_owner (void);
    /// set the ownership

    void _is_owner ( ::CORBA::Boolean b);
    // overridden ServantBase operations
    PortableServer::POA_ptr _default_POA (void);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    ::CORBA::DefinitionKind def_kind (
      void);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    void destroy (
      void);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    char * id (
      void);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    void id (
      const char *);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    char * name (
      void);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    void name (
      const char *);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    char * version (
      void);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    void version (
      const char *);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    ::CORBA::Container_ptr defined_in (
      void);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    char * absolute_name (
      void);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    ::CORBA::Repository_ptr containing_repository (
      void);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    ::CORBA::Contained::Description * describe (
      void);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    void move (
      ::CORBA::Container_ptr,
      const char *,
      const char *);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/tie_sh.cpp:57

    ::CORBA::TypeCode_ptr type (
      void);
  
  private:
    T *ptr_;
    PortableServer::POA_var poa_;
    ::CORBA::Boolean rel_;

    // copy and assignment are not allowed
    TypedefDef_tie (const TypedefDef_tie &);
    void operator= (const TypedefDef_tie &);
  };
} // module CORBA

// TAO_IDL - Generated from 
// .\be\be_codegen.cpp:1748


TAO_END_VERSIONED_NAMESPACE_DECL



#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "IFR_BaseS_T.cpp"
#endif /* defined REQUIRED SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("IFR_BaseS_T.cpp")
#endif /* defined REQUIRED PRAGMA */

#endif /* ifndef */

