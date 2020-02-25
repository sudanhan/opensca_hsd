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

#ifndef _TAO_IDL_TIMESERVICEC_FXEIIK_H_
#define _TAO_IDL_TIMESERVICEC_FXEIIK_H_


#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#include /**/ "orbsvcs/Time/time_export.h"
#include "tao/AnyTypeCode/AnyTypeCode_methods.h"
#include "tao/AnyTypeCode/Any.h"
#include "tao/ORB.h"
#include "tao/SystemException.h"
#include "tao/UserException.h"
#include "tao/Basic_Types.h"
#include "tao/ORB_Constants.h"
#include "tao/Object.h"
#include "tao/AnyTypeCode/TimeBaseA.h"
#include "tao/Objref_VarOut_T.h"
#include "tao/VarOut_T.h"
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

#include "tao/TimeBaseC.h"

#if TAO_MAJOR_VERSION != 2 || TAO_MINOR_VERSION != 0 || TAO_BETA_VERSION != 4
#error This file should be regenerated with TAO_IDL from version 2.0a
#endif

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_Time_Export

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from 
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_root/root_ch.cpp:162

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
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_module/module_ch.cpp:41

namespace CosTime
{

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_enum/enum_ch.cpp:47

  enum TimeComparison
  {
    TCEqualTo,
    TCLessThan,
    TCGreaterThan,
    TCIndeterminate
  };

  typedef TimeComparison &TimeComparison_out;

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:39

  extern TAO_Time_Export ::CORBA::TypeCode_ptr const _tc_TimeComparison;

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_enum/enum_ch.cpp:47

  enum ComparisonType
  {
    IntervalC,
    MidC
  };

  typedef ComparisonType &ComparisonType_out;

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:39

  extern TAO_Time_Export ::CORBA::TypeCode_ptr const _tc_ComparisonType;

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_enum/enum_ch.cpp:47

  enum OverlapType
  {
    OTContainer,
    OTContained,
    OTOverlap,
    OTNoOverlap
  };

  typedef OverlapType &OverlapType_out;

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:39

  extern TAO_Time_Export ::CORBA::TypeCode_ptr const _tc_OverlapType;

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_exception/exception_ch.cpp:43

  class TAO_Time_Export TimeUnavailable : public ::CORBA::UserException
  {
  public:
    
    TimeUnavailable (void);
    TimeUnavailable (const TimeUnavailable &);
    ~TimeUnavailable (void);

    TimeUnavailable &operator= (const TimeUnavailable &);

    static void _tao_any_destructor (void *);

    static TimeUnavailable *_downcast ( ::CORBA::Exception *);
    static const TimeUnavailable *_downcast ( ::CORBA::Exception const *);

    static ::CORBA::Exception *_alloc (void);

    virtual ::CORBA::Exception *_tao_duplicate (void) const;

    virtual void _raise (void) const;

    virtual void _tao_encode (TAO_OutputCDR &cdr) const;
    virtual void _tao_decode (TAO_InputCDR &cdr);
    

    virtual ::CORBA::TypeCode_ptr _tao_type (void) const;
  };

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:39

  extern TAO_Time_Export ::CORBA::TypeCode_ptr const _tc_TimeUnavailable;

  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:784

#if !defined (_COSTIME_TIO__VAR_OUT_CH_)
#define _COSTIME_TIO__VAR_OUT_CH_

  class TIO;
  typedef TIO *TIO_ptr;

  typedef
    TAO_Objref_Var_T<
        TIO
      >
    TIO_var;
  
  typedef
    TAO_Objref_Out_T<
        TIO
      >
    TIO_out;

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:784

#if !defined (_COSTIME_UTO__VAR_OUT_CH_)
#define _COSTIME_UTO__VAR_OUT_CH_

  class UTO;
  typedef UTO *UTO_ptr;

  typedef
    TAO_Objref_Var_T<
        UTO
      >
    UTO_var;
  
  typedef
    TAO_Objref_Out_T<
        UTO
      >
    UTO_out;

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:45

  class TAO_Time_Export UTO
    : public virtual ::CORBA::Object
  {
  public:
    friend class TAO::Narrow_Utils<UTO>;

    // TAO_IDL - Generated from
    // .\be\be_type.cpp:307
    
    typedef UTO_ptr _ptr_type;
    typedef UTO_var _var_type;
    typedef UTO_out _out_type;

    static void _tao_any_destructor (void *);

    // The static operations.
    static UTO_ptr _duplicate (UTO_ptr obj);

    static void _tao_release (UTO_ptr obj);

    static UTO_ptr _narrow (::CORBA::Object_ptr obj);
    static UTO_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static UTO_ptr _nil (void);

    virtual ::TimeBase::TimeT time (
      void);

    virtual ::TimeBase::InaccuracyT inaccuracy (
      void);

    virtual ::TimeBase::TdfT tdf (
      void);

    virtual ::TimeBase::UtcT utc_time (
      void);

    virtual ::CosTime::UTO_ptr absolute_time (
      void);

    virtual ::CosTime::TimeComparison compare_time (
      ::CosTime::ComparisonType comparison_type,
      ::CosTime::UTO_ptr otu);

    virtual ::CosTime::TIO_ptr time_to_interval (
      ::CosTime::UTO_ptr otu);

    virtual ::CosTime::TIO_ptr interval (
      void);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:156

    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  private:
    TAO::Collocation_Proxy_Broker *the_TAO_UTO_Proxy_Broker_;
  
  protected:
    // Concrete interface only.
    UTO (void);

    // These methods traverse the inheritance tree and set the
    // parents piece of the given class in the right mode.
    virtual void CosTime_UTO_setup_collocation (void);

    // Concrete non-local interface only.
    UTO (
        ::IOP::IOR *ior,
        TAO_ORB_Core *orb_core);
    
    // Non-local interface only.
    UTO (
        TAO_Stub *objref,
        ::CORBA::Boolean _tao_collocated = false,
        TAO_Abstract_ServantBase *servant = 0,
        TAO_ORB_Core *orb_core = 0);

    virtual ~UTO (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    UTO (const UTO &);

    void operator= (const UTO &);
  };

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:39

  extern TAO_Time_Export ::CORBA::TypeCode_ptr const _tc_UTO;

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:45

  class TAO_Time_Export TIO
    : public virtual ::CORBA::Object
  {
  public:
    friend class TAO::Narrow_Utils<TIO>;

    // TAO_IDL - Generated from
    // .\be\be_type.cpp:307
    
    typedef TIO_ptr _ptr_type;
    typedef TIO_var _var_type;
    typedef TIO_out _out_type;

    static void _tao_any_destructor (void *);

    // The static operations.
    static TIO_ptr _duplicate (TIO_ptr obj);

    static void _tao_release (TIO_ptr obj);

    static TIO_ptr _narrow (::CORBA::Object_ptr obj);
    static TIO_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static TIO_ptr _nil (void);

    virtual ::TimeBase::IntervalT time_interval (
      void);

    virtual ::CosTime::OverlapType spans (
      ::CosTime::UTO_ptr time,
      ::CosTime::TIO_out overlap);

    virtual ::CosTime::OverlapType overlaps (
      ::CosTime::TIO_ptr interval,
      ::CosTime::TIO_out overlap);

    virtual ::CosTime::UTO_ptr time (
      void);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:156

    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  private:
    TAO::Collocation_Proxy_Broker *the_TAO_TIO_Proxy_Broker_;
  
  protected:
    // Concrete interface only.
    TIO (void);

    // These methods traverse the inheritance tree and set the
    // parents piece of the given class in the right mode.
    virtual void CosTime_TIO_setup_collocation (void);

    // Concrete non-local interface only.
    TIO (
        ::IOP::IOR *ior,
        TAO_ORB_Core *orb_core);
    
    // Non-local interface only.
    TIO (
        TAO_Stub *objref,
        ::CORBA::Boolean _tao_collocated = false,
        TAO_Abstract_ServantBase *servant = 0,
        TAO_ORB_Core *orb_core = 0);

    virtual ~TIO (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    TIO (const TIO &);

    void operator= (const TIO &);
  };

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:39

  extern TAO_Time_Export ::CORBA::TypeCode_ptr const _tc_TIO;

  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:784

#if !defined (_COSTIME_TIMESERVICE__VAR_OUT_CH_)
#define _COSTIME_TIMESERVICE__VAR_OUT_CH_

  class TimeService;
  typedef TimeService *TimeService_ptr;

  typedef
    TAO_Objref_Var_T<
        TimeService
      >
    TimeService_var;
  
  typedef
    TAO_Objref_Out_T<
        TimeService
      >
    TimeService_out;

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:45

  class TAO_Time_Export TimeService
    : public virtual ::CORBA::Object
  {
  public:
    friend class TAO::Narrow_Utils<TimeService>;

    // TAO_IDL - Generated from
    // .\be\be_type.cpp:307
    
    typedef TimeService_ptr _ptr_type;
    typedef TimeService_var _var_type;
    typedef TimeService_out _out_type;

    static void _tao_any_destructor (void *);

    // The static operations.
    static TimeService_ptr _duplicate (TimeService_ptr obj);

    static void _tao_release (TimeService_ptr obj);

    static TimeService_ptr _narrow (::CORBA::Object_ptr obj);
    static TimeService_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static TimeService_ptr _nil (void);

    virtual ::CosTime::UTO_ptr universal_time (
      void);

    virtual ::CosTime::UTO_ptr secure_universal_time (
      void);

    virtual ::CosTime::UTO_ptr new_universal_time (
      ::TimeBase::TimeT time,
      ::TimeBase::InaccuracyT inaccuracy,
      ::TimeBase::TdfT tdf);

    virtual ::CosTime::UTO_ptr uto_from_utc (
      const ::TimeBase::UtcT & utc);

    virtual ::CosTime::TIO_ptr new_interval (
      ::TimeBase::TimeT lower,
      ::TimeBase::TimeT upper);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:156

    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  private:
    TAO::Collocation_Proxy_Broker *the_TAO_TimeService_Proxy_Broker_;
  
  protected:
    // Concrete interface only.
    TimeService (void);

    // These methods traverse the inheritance tree and set the
    // parents piece of the given class in the right mode.
    virtual void CosTime_TimeService_setup_collocation (void);

    // Concrete non-local interface only.
    TimeService (
        ::IOP::IOR *ior,
        TAO_ORB_Core *orb_core);
    
    // Non-local interface only.
    TimeService (
        TAO_Stub *objref,
        ::CORBA::Boolean _tao_collocated = false,
        TAO_Abstract_ServantBase *servant = 0,
        TAO_ORB_Core *orb_core = 0);

    virtual ~TimeService (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    TimeService (const TimeService &);

    void operator= (const TimeService &);
  };

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_typecode/typecode_decl.cpp:39

  extern TAO_Time_Export ::CORBA::TypeCode_ptr const _tc_TimeService;

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_module/module_ch.cpp:70

} // module CosTime

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
  class Arg_Traits< ::CosTime::TimeComparison>
    : public
        Basic_Arg_Traits_T<
            ::CosTime::TimeComparison,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:898

  template<>
  class Arg_Traits< ::CosTime::ComparisonType>
    : public
        Basic_Arg_Traits_T<
            ::CosTime::ComparisonType,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:898

  template<>
  class Arg_Traits< ::CosTime::OverlapType>
    : public
        Basic_Arg_Traits_T<
            ::CosTime::OverlapType,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:147

#if !defined (_COSTIME_TIO__ARG_TRAITS_)
#define _COSTIME_TIO__ARG_TRAITS_

  template<>
  class  Arg_Traits< ::CosTime::TIO>
    : public
        Object_Arg_Traits_T<
            ::CosTime::TIO_ptr,
            ::CosTime::TIO_var,
            ::CosTime::TIO_out,
            TAO::Objref_Traits<CosTime::TIO>,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:147

#if !defined (_COSTIME_UTO__ARG_TRAITS_)
#define _COSTIME_UTO__ARG_TRAITS_

  template<>
  class  Arg_Traits< ::CosTime::UTO>
    : public
        Object_Arg_Traits_T<
            ::CosTime::UTO_ptr,
            ::CosTime::UTO_var,
            ::CosTime::UTO_out,
            TAO::Objref_Traits<CosTime::UTO>,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:147

#if !defined (_COSTIME_TIMESERVICE__ARG_TRAITS_)
#define _COSTIME_TIMESERVICE__ARG_TRAITS_

  template<>
  class  Arg_Traits< ::CosTime::TimeService>
    : public
        Object_Arg_Traits_T<
            ::CosTime::TimeService_ptr,
            ::CosTime::TimeService_var,
            ::CosTime::TimeService_out,
            TAO::Objref_Traits<CosTime::TimeService>,
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
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_root/root_ch.cpp:204

extern TAO_Time_Export
TAO::Collocation_Proxy_Broker *
(*CosTime__TAO_UTO_Proxy_Broker_Factory_function_pointer) (
    ::CORBA::Object_ptr obj);

extern TAO_Time_Export
TAO::Collocation_Proxy_Broker *
(*CosTime__TAO_TIO_Proxy_Broker_Factory_function_pointer) (
    ::CORBA::Object_ptr obj);

extern TAO_Time_Export
TAO::Collocation_Proxy_Broker *
(*CosTime__TAO_TimeService_Proxy_Broker_Factory_function_pointer) (
    ::CORBA::Object_ptr obj);

// TAO_IDL - Generated from
// .\be\be_visitor_traits.cpp:62


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Traits specializations.
namespace TAO
{

#if !defined (_COSTIME_UTO__TRAITS_)
#define _COSTIME_UTO__TRAITS_

  template<>
  struct TAO_Time_Export Objref_Traits< ::CosTime::UTO>
  {
    static ::CosTime::UTO_ptr duplicate (
        ::CosTime::UTO_ptr p);
    static void release (
        ::CosTime::UTO_ptr p);
    static ::CosTime::UTO_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::CosTime::UTO_ptr p,
        TAO_OutputCDR & cdr);
  };

#endif /* end #if !defined */

#if !defined (_COSTIME_TIO__TRAITS_)
#define _COSTIME_TIO__TRAITS_

  template<>
  struct TAO_Time_Export Objref_Traits< ::CosTime::TIO>
  {
    static ::CosTime::TIO_ptr duplicate (
        ::CosTime::TIO_ptr p);
    static void release (
        ::CosTime::TIO_ptr p);
    static ::CosTime::TIO_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::CosTime::TIO_ptr p,
        TAO_OutputCDR & cdr);
  };

#endif /* end #if !defined */

#if !defined (_COSTIME_TIMESERVICE__TRAITS_)
#define _COSTIME_TIMESERVICE__TRAITS_

  template<>
  struct TAO_Time_Export Objref_Traits< ::CosTime::TimeService>
  {
    static ::CosTime::TimeService_ptr duplicate (
        ::CosTime::TimeService_ptr p);
    static void release (
        ::CosTime::TimeService_ptr p);
    static ::CosTime::TimeService_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::CosTime::TimeService_ptr p,
        TAO_OutputCDR & cdr);
  };

#endif /* end #if !defined */
}
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_enum/any_op_ch.cpp:43

#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace CosTime
{
  

  TAO_Time_Export void operator<<= (::CORBA::Any &, ::CosTime::TimeComparison);
  TAO_Time_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, ::CosTime::TimeComparison &);
}

#else



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



TAO_Time_Export void operator<<= (::CORBA::Any &, CosTime::TimeComparison);
TAO_Time_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, CosTime::TimeComparison &);
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




#endif

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_enum/any_op_ch.cpp:43

#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace CosTime
{
  

  TAO_Time_Export void operator<<= (::CORBA::Any &, ::CosTime::ComparisonType);
  TAO_Time_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, ::CosTime::ComparisonType &);
}

#else



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



TAO_Time_Export void operator<<= (::CORBA::Any &, CosTime::ComparisonType);
TAO_Time_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, CosTime::ComparisonType &);
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




#endif

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_enum/any_op_ch.cpp:43

#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace CosTime
{
  

  TAO_Time_Export void operator<<= (::CORBA::Any &, ::CosTime::OverlapType);
  TAO_Time_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, ::CosTime::OverlapType &);
}

#else



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



TAO_Time_Export void operator<<= (::CORBA::Any &, CosTime::OverlapType);
TAO_Time_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, CosTime::OverlapType &);
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




#endif

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_exception/any_op_ch.cpp:44

#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace CosTime
{
  

  TAO_Time_Export void operator<<= (::CORBA::Any &, const ::CosTime::TimeUnavailable &); // copying version
  TAO_Time_Export void operator<<= (::CORBA::Any &, ::CosTime::TimeUnavailable*); // noncopying version
  TAO_Time_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, ::CosTime::TimeUnavailable *&); // deprecated
TAO_Time_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const ::CosTime::TimeUnavailable *&);
}

#else



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



TAO_Time_Export void operator<<= (::CORBA::Any &, const CosTime::TimeUnavailable &); // copying version
TAO_Time_Export void operator<<= (::CORBA::Any &, CosTime::TimeUnavailable*); // noncopying version
TAO_Time_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, CosTime::TimeUnavailable *&); // deprecated
TAO_Time_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const CosTime::TimeUnavailable *&);
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




#endif

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/any_op_ch.cpp:46



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace CosTime
{
  TAO_Time_Export void operator<<= ( ::CORBA::Any &, UTO_ptr); // copying
  TAO_Time_Export void operator<<= ( ::CORBA::Any &, UTO_ptr *); // non-copying
  TAO_Time_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, UTO_ptr &);
}

#else



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_Time_Export void operator<<= (::CORBA::Any &, CosTime::UTO_ptr); // copying
TAO_Time_Export void operator<<= (::CORBA::Any &, CosTime::UTO_ptr *); // non-copying
TAO_Time_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, CosTime::UTO_ptr &);
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




#endif

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/any_op_ch.cpp:46



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace CosTime
{
  TAO_Time_Export void operator<<= ( ::CORBA::Any &, TIO_ptr); // copying
  TAO_Time_Export void operator<<= ( ::CORBA::Any &, TIO_ptr *); // non-copying
  TAO_Time_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, TIO_ptr &);
}

#else



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_Time_Export void operator<<= (::CORBA::Any &, CosTime::TIO_ptr); // copying
TAO_Time_Export void operator<<= (::CORBA::Any &, CosTime::TIO_ptr *); // non-copying
TAO_Time_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, CosTime::TIO_ptr &);
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




#endif

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/any_op_ch.cpp:46



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace CosTime
{
  TAO_Time_Export void operator<<= ( ::CORBA::Any &, TimeService_ptr); // copying
  TAO_Time_Export void operator<<= ( ::CORBA::Any &, TimeService_ptr *); // non-copying
  TAO_Time_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, TimeService_ptr &);
}

#else



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_Time_Export void operator<<= (::CORBA::Any &, CosTime::TimeService_ptr); // copying
TAO_Time_Export void operator<<= (::CORBA::Any &, CosTime::TimeService_ptr *); // non-copying
TAO_Time_Export ::CORBA::Boolean operator>>= (const ::CORBA::Any &, CosTime::TimeService_ptr &);
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




#endif

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_enum/cdr_op_ch.cpp:40



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_Time_Export ::CORBA::Boolean operator<< (TAO_OutputCDR &strm, CosTime::TimeComparison _tao_enumerator);
TAO_Time_Export ::CORBA::Boolean operator>> (TAO_InputCDR &strm, CosTime::TimeComparison &_tao_enumerator);

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_enum/cdr_op_ch.cpp:40



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_Time_Export ::CORBA::Boolean operator<< (TAO_OutputCDR &strm, CosTime::ComparisonType _tao_enumerator);
TAO_Time_Export ::CORBA::Boolean operator>> (TAO_InputCDR &strm, CosTime::ComparisonType &_tao_enumerator);

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_enum/cdr_op_ch.cpp:40



TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_Time_Export ::CORBA::Boolean operator<< (TAO_OutputCDR &strm, CosTime::OverlapType _tao_enumerator);
TAO_Time_Export ::CORBA::Boolean operator>> (TAO_InputCDR &strm, CosTime::OverlapType &_tao_enumerator);

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_exception/cdr_op_ch.cpp:43

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



TAO_Time_Export ::CORBA::Boolean operator<< (TAO_OutputCDR &, const CosTime::TimeUnavailable &);
TAO_Time_Export ::CORBA::Boolean operator>> (TAO_InputCDR &, CosTime::TimeUnavailable &);

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/cdr_op_ch.cpp:47


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_Time_Export ::CORBA::Boolean operator<< (TAO_OutputCDR &, const CosTime::UTO_ptr );
TAO_Time_Export ::CORBA::Boolean operator>> (TAO_InputCDR &, CosTime::UTO_ptr &);

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/cdr_op_ch.cpp:47


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_Time_Export ::CORBA::Boolean operator<< (TAO_OutputCDR &, const CosTime::TIO_ptr );
TAO_Time_Export ::CORBA::Boolean operator>> (TAO_InputCDR &, CosTime::TIO_ptr &);

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/cdr_op_ch.cpp:47


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_Time_Export ::CORBA::Boolean operator<< (TAO_OutputCDR &, const CosTime::TimeService_ptr );
TAO_Time_Export ::CORBA::Boolean operator>> (TAO_InputCDR &, CosTime::TimeService_ptr &);

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// .\be\be_codegen.cpp:1581


TAO_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "TimeServiceC.inl"
#endif /* defined INLINE */

#endif /* ifndef */

