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

#ifndef _TAO_PIDL_RTSCHEDULERC_B4SUN3_H_
#define _TAO_PIDL_RTSCHEDULERC_B4SUN3_H_

#ifndef TAO_RTSCHEDULER_SAFE_INCLUDE
#error You should not include RTSchedulerC.h, use tao/RTScheduling/RTScheduler.h
#endif /* TAO_RTSCHEDULER_SAFE_INCLUDE */

#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#include /**/ "tao/RTScheduling/rtscheduler_export.h"
#include "tao/SystemException.h"
#include "tao/UserException.h"
#include "tao/Basic_Types.h"
#include "tao/ORB_Constants.h"
#include "tao/Object.h"
#include "tao/AnyTypeCode/TypeCode.h"
#include "tao/AnyTypeCode/TypeCode_Constants.h"
#include "tao/String_Manager_T.h"
#include "tao/Sequence_T.h"
#include "tao/Objref_VarOut_T.h"
#include "tao/Seq_Var_T.h"
#include "tao/Seq_Out_T.h"
#include "tao/VarOut_T.h"
#include "tao/Arg_Traits_T.h"
#include "tao/Basic_Arguments.h"
#include "tao/Special_Basic_Arguments.h"
#include "tao/Any_Insert_Policy_T.h"
#include "tao/Basic_Argument_T.h"
#include "tao/Fixed_Size_Argument_T.h"
#include "tao/Var_Size_Argument_T.h"
#include "tao/Object_Argument_T.h"
#include "tao/UB_String_Arguments.h"
#include /**/ "tao/Version.h"
#include /**/ "tao/Versioned_Namespace.h"

#include "tao/RTCORBA/RTCORBA_includeC.h"
#include "tao/PortableServer/PortableServer_includeC.h"
#include "tao/PI/PI_includeC.h"
#include "tao/PI/PIForwardRequestC.h"
#include "tao/PI_Server/ServerRequestInfoC.h"
#include "tao/PortableInterceptorC.h"

#if TAO_MAJOR_VERSION != 2 || TAO_MINOR_VERSION != 0 || TAO_BETA_VERSION != 4
#error This file should be regenerated with TAO_IDL from version 2.0a
#endif

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_RTScheduler_Export

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_module/module_ch.cpp:41

namespace CORBA
{

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_native/native_ch.cpp:46

  typedef void *VoidData;
  

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_module/module_ch.cpp:70

} // module CORBA

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_module/module_ch.cpp:41

namespace RTScheduling
{

  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:784

#if !defined (_RTSCHEDULING_THREADACTION__VAR_OUT_CH_)
#define _RTSCHEDULING_THREADACTION__VAR_OUT_CH_

  class ThreadAction;
  typedef ThreadAction *ThreadAction_ptr;

  typedef
    TAO_Objref_Var_T<
        ThreadAction
      >
    ThreadAction_var;
  
  typedef
    TAO_Objref_Out_T<
        ThreadAction
      >
    ThreadAction_out;

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:45

  class TAO_RTScheduler_Export ThreadAction
    : public virtual ::CORBA::Object
  {
  public:

    // TAO_IDL - Generated from
    // .\be\be_type.cpp:307
    
    typedef ThreadAction_ptr _ptr_type;
    typedef ThreadAction_var _var_type;
    typedef ThreadAction_out _out_type;

    // The static operations.
    static ThreadAction_ptr _duplicate (ThreadAction_ptr obj);

    static void _tao_release (ThreadAction_ptr obj);

    static ThreadAction_ptr _narrow (::CORBA::Object_ptr obj);
    static ThreadAction_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static ThreadAction_ptr _nil (void);

    virtual void _cxx_do (
      ::CORBA::VoidData data) = 0;

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:156

    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Abstract or local interface only.
    ThreadAction (void);

    

    virtual ~ThreadAction (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    ThreadAction (const ThreadAction &);

    void operator= (const ThreadAction &);
  };

  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:784

#if !defined (_RTSCHEDULING_DISTRIBUTABLETHREAD__VAR_OUT_CH_)
#define _RTSCHEDULING_DISTRIBUTABLETHREAD__VAR_OUT_CH_

  class DistributableThread;
  typedef DistributableThread *DistributableThread_ptr;

  typedef
    TAO_Objref_Var_T<
        DistributableThread
      >
    DistributableThread_var;
  
  typedef
    TAO_Objref_Out_T<
        DistributableThread
      >
    DistributableThread_out;

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:45

  class TAO_RTScheduler_Export DistributableThread
    : public virtual ::CORBA::Object
  {
  public:

    // TAO_IDL - Generated from
    // .\be\be_type.cpp:307
    
    typedef DistributableThread_ptr _ptr_type;
    typedef DistributableThread_var _var_type;
    typedef DistributableThread_out _out_type;

    // The static operations.
    static DistributableThread_ptr _duplicate (DistributableThread_ptr obj);

    static void _tao_release (DistributableThread_ptr obj);

    static DistributableThread_ptr _narrow (::CORBA::Object_ptr obj);
    static DistributableThread_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static DistributableThread_ptr _nil (void);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_enum/enum_ch.cpp:47

    enum DT_State
    {
      ACTIVE,
      CANCELLED
    };

    typedef DT_State &DT_State_out;

    virtual void cancel (
      void) = 0;

    virtual ::RTScheduling::DistributableThread::DT_State state (
      void) = 0;

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:156

    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Abstract or local interface only.
    DistributableThread (void);

    

    virtual ~DistributableThread (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    DistributableThread (const DistributableThread &);

    void operator= (const DistributableThread &);
  };

  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:784

#if !defined (_RTSCHEDULING_CURRENT__VAR_OUT_CH_)
#define _RTSCHEDULING_CURRENT__VAR_OUT_CH_

  class Current;
  typedef Current *Current_ptr;

  typedef
    TAO_Objref_Var_T<
        Current
      >
    Current_var;
  
  typedef
    TAO_Objref_Out_T<
        Current
      >
    Current_out;

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:45

  class TAO_RTScheduler_Export Current
    : public virtual ::RTCORBA::Current
  
  {
  public:

    // TAO_IDL - Generated from
    // .\be\be_type.cpp:307
    
    typedef Current_ptr _ptr_type;
    typedef Current_var _var_type;
    typedef Current_out _out_type;

    // The static operations.
    static Current_ptr _duplicate (Current_ptr obj);

    static void _tao_release (Current_ptr obj);

    static Current_ptr _narrow (::CORBA::Object_ptr obj);
    static Current_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static Current_ptr _nil (void);

    virtual ::RTScheduling::DistributableThread_ptr spawn (
      ::RTScheduling::ThreadAction_ptr start,
      ::CORBA::VoidData data,
      const char * name,
      ::CORBA::Policy_ptr sched_param,
      ::CORBA::Policy_ptr implicit_sched_param,
      ::CORBA::ULong stack_size,
      ::RTCORBA::Priority base_priority) = 0;

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_exception/exception_ch.cpp:43

    class TAO_RTScheduler_Export UNSUPPORTED_SCHEDULING_DISCIPLINE : public ::CORBA::UserException
    {
    public:
      
      UNSUPPORTED_SCHEDULING_DISCIPLINE (void);
      UNSUPPORTED_SCHEDULING_DISCIPLINE (const UNSUPPORTED_SCHEDULING_DISCIPLINE &);
      ~UNSUPPORTED_SCHEDULING_DISCIPLINE (void);

      UNSUPPORTED_SCHEDULING_DISCIPLINE &operator= (const UNSUPPORTED_SCHEDULING_DISCIPLINE &);

      static UNSUPPORTED_SCHEDULING_DISCIPLINE *_downcast ( ::CORBA::Exception *);
      static const UNSUPPORTED_SCHEDULING_DISCIPLINE *_downcast ( ::CORBA::Exception const *);

      static ::CORBA::Exception *_alloc (void);

      virtual ::CORBA::Exception *_tao_duplicate (void) const;

      virtual void _raise (void) const;

      virtual void _tao_encode (TAO_OutputCDR &cdr) const;
      virtual void _tao_decode (TAO_InputCDR &cdr);
      
    };

    virtual void begin_scheduling_segment (
      const char * name,
      ::CORBA::Policy_ptr sched_param,
      ::CORBA::Policy_ptr implicit_sched_param) = 0;

    virtual void update_scheduling_segment (
      const char * name,
      ::CORBA::Policy_ptr sched_param,
      ::CORBA::Policy_ptr implicit_sched_param) = 0;

    virtual void end_scheduling_segment (
      const char * name) = 0;

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_sequence/sequence_ch.cpp:100

#if !defined (_RTSCHEDULING_CURRENT_IDTYPE_CH_)
#define _RTSCHEDULING_CURRENT_IDTYPE_CH_

    class IdType;

    typedef
      ::TAO_FixedSeq_Var_T<
          IdType
        >
      IdType_var;

    typedef
      ::TAO_Seq_Out_T<
          IdType
        >
      IdType_out;

    class TAO_RTScheduler_Export IdType
      : public
          ::TAO::unbounded_value_sequence<
              ::CORBA::Octet
            >
    {
    public:
      IdType (void);
      IdType ( ::CORBA::ULong max);
      IdType (
        ::CORBA::ULong max,
        ::CORBA::ULong length,
        ::CORBA::Octet* buffer, 
        ::CORBA::Boolean release = false);
      IdType (const IdType &);
      virtual ~IdType (void);
      

      // TAO_IDL - Generated from
      // .\be\be_type.cpp:307
      
      typedef IdType_var _var_type;
      typedef IdType_out _out_type;

      

#if (TAO_NO_COPY_OCTET_SEQUENCES == 1)
      IdType (
          ::CORBA::ULong length,
          const ACE_Message_Block* mb
        )
        : ::TAO::unbounded_value_sequence< ::CORBA::Octet> (length, mb) {}
#endif /* TAO_NO_COPY_OCTET_SEQUENCE == 1 */
    };

#endif /* end #if !defined */

    virtual ::RTScheduling::Current::IdType * id (
      void) = 0;

    virtual ::RTScheduling::DistributableThread_ptr lookup (
      const ::RTScheduling::Current::IdType & id) = 0;

    virtual ::CORBA::Policy_ptr scheduling_parameter (
      void) = 0;

    virtual ::CORBA::Policy_ptr implicit_scheduling_parameter (
      void) = 0;

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_sequence/sequence_ch.cpp:100

#if !defined (_RTSCHEDULING_CURRENT_NAMELIST_CH_)
#define _RTSCHEDULING_CURRENT_NAMELIST_CH_

    class NameList;

    typedef
      ::TAO_VarSeq_Var_T<
          NameList
        >
      NameList_var;

    typedef
      ::TAO_Seq_Out_T<
          NameList
        >
      NameList_out;

    class TAO_RTScheduler_Export NameList
      : public
          ::TAO::unbounded_basic_string_sequence<char>
    {
    public:
      NameList (void);
      NameList ( ::CORBA::ULong max);
      NameList (
        ::CORBA::ULong max,
        ::CORBA::ULong length,
        ::CORBA::Char ** buffer, 
        ::CORBA::Boolean release = false);
      NameList (const NameList &);
      virtual ~NameList (void);
      

      // TAO_IDL - Generated from
      // .\be\be_type.cpp:307
      
      typedef NameList_var _var_type;
      typedef NameList_out _out_type;
    };

#endif /* end #if !defined */

    virtual ::RTScheduling::Current::NameList * current_scheduling_segment_names (
      void) = 0;

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:156

    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Abstract or local interface only.
    Current (void);

    

    virtual ~Current (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    Current (const Current &);

    void operator= (const Current &);
  };

  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:784

#if !defined (_RTSCHEDULING_RESOURCEMANAGER__VAR_OUT_CH_)
#define _RTSCHEDULING_RESOURCEMANAGER__VAR_OUT_CH_

  class ResourceManager;
  typedef ResourceManager *ResourceManager_ptr;

  typedef
    TAO_Objref_Var_T<
        ResourceManager
      >
    ResourceManager_var;
  
  typedef
    TAO_Objref_Out_T<
        ResourceManager
      >
    ResourceManager_out;

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:45

  class TAO_RTScheduler_Export ResourceManager
    : public virtual ::RTCORBA::Mutex
  
  {
  public:

    // TAO_IDL - Generated from
    // .\be\be_type.cpp:307
    
    typedef ResourceManager_ptr _ptr_type;
    typedef ResourceManager_var _var_type;
    typedef ResourceManager_out _out_type;

    // The static operations.
    static ResourceManager_ptr _duplicate (ResourceManager_ptr obj);

    static void _tao_release (ResourceManager_ptr obj);

    static ResourceManager_ptr _narrow (::CORBA::Object_ptr obj);
    static ResourceManager_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static ResourceManager_ptr _nil (void);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:156

    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Abstract or local interface only.
    ResourceManager (void);

    

    virtual ~ResourceManager (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    ResourceManager (const ResourceManager &);

    void operator= (const ResourceManager &);
  };

  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:784

#if !defined (_RTSCHEDULING_SCHEDULER__VAR_OUT_CH_)
#define _RTSCHEDULING_SCHEDULER__VAR_OUT_CH_

  class Scheduler;
  typedef Scheduler *Scheduler_ptr;

  typedef
    TAO_Objref_Var_T<
        Scheduler
      >
    Scheduler_var;
  
  typedef
    TAO_Objref_Out_T<
        Scheduler
      >
    Scheduler_out;

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:45

  class TAO_RTScheduler_Export Scheduler
    : public virtual ::CORBA::Object
  {
  public:

    // TAO_IDL - Generated from
    // .\be\be_type.cpp:307
    
    typedef Scheduler_ptr _ptr_type;
    typedef Scheduler_var _var_type;
    typedef Scheduler_out _out_type;

    // The static operations.
    static Scheduler_ptr _duplicate (Scheduler_ptr obj);

    static void _tao_release (Scheduler_ptr obj);

    static Scheduler_ptr _narrow (::CORBA::Object_ptr obj);
    static Scheduler_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static Scheduler_ptr _nil (void);

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_exception/exception_ch.cpp:43

    class TAO_RTScheduler_Export INCOMPATIBLE_SCHEDULING_DISCIPLINES : public ::CORBA::UserException
    {
    public:
      
      INCOMPATIBLE_SCHEDULING_DISCIPLINES (void);
      INCOMPATIBLE_SCHEDULING_DISCIPLINES (const INCOMPATIBLE_SCHEDULING_DISCIPLINES &);
      ~INCOMPATIBLE_SCHEDULING_DISCIPLINES (void);

      INCOMPATIBLE_SCHEDULING_DISCIPLINES &operator= (const INCOMPATIBLE_SCHEDULING_DISCIPLINES &);

      static INCOMPATIBLE_SCHEDULING_DISCIPLINES *_downcast ( ::CORBA::Exception *);
      static const INCOMPATIBLE_SCHEDULING_DISCIPLINES *_downcast ( ::CORBA::Exception const *);

      static ::CORBA::Exception *_alloc (void);

      virtual ::CORBA::Exception *_tao_duplicate (void) const;

      virtual void _raise (void) const;

      virtual void _tao_encode (TAO_OutputCDR &cdr) const;
      virtual void _tao_decode (TAO_InputCDR &cdr);
      
    };

    virtual ::CORBA::PolicyList * scheduling_policies (
      void) = 0;

    virtual void scheduling_policies (
      const ::CORBA::PolicyList & scheduling_policies) = 0;

    virtual ::CORBA::PolicyList * poa_policies (
      void) = 0;

    virtual char * scheduling_discipline_name (
      void) = 0;

    virtual ::RTScheduling::ResourceManager_ptr create_resource_manager (
      const char * name,
      ::CORBA::Policy_ptr scheduling_parameter) = 0;

    virtual void set_scheduling_parameter (
      ::PortableServer::Servant & resource,
      const char * name,
      ::CORBA::Policy_ptr scheduling_parameter) = 0;

    virtual void begin_new_scheduling_segment (
      const ::RTScheduling::Current::IdType & guid,
      const char * name,
      ::CORBA::Policy_ptr sched_param,
      ::CORBA::Policy_ptr implicit_sched_param) = 0;

    virtual void begin_nested_scheduling_segment (
      const ::RTScheduling::Current::IdType & guid,
      const char * name,
      ::CORBA::Policy_ptr sched_param,
      ::CORBA::Policy_ptr implicit_sched_param) = 0;

    virtual void update_scheduling_segment (
      const ::RTScheduling::Current::IdType & guid,
      const char * name,
      ::CORBA::Policy_ptr sched_param,
      ::CORBA::Policy_ptr implicit_sched_param) = 0;

    virtual void end_scheduling_segment (
      const ::RTScheduling::Current::IdType & guid,
      const char * name) = 0;

    virtual void end_nested_scheduling_segment (
      const ::RTScheduling::Current::IdType & guid,
      const char * name,
      ::CORBA::Policy_ptr outer_sched_param) = 0;

    virtual void send_request (
      ::PortableInterceptor::ClientRequestInfo_ptr ri) = 0;

    virtual void receive_request (
      ::PortableInterceptor::ServerRequestInfo_ptr ri,
      ::RTScheduling::Current::IdType_out guid,
      ::CORBA::String_out name,
      ::CORBA::Policy_out sched_param,
      ::CORBA::Policy_out implicit_sched_param) = 0;

    virtual void send_reply (
      ::PortableInterceptor::ServerRequestInfo_ptr ri) = 0;

    virtual void send_exception (
      ::PortableInterceptor::ServerRequestInfo_ptr ri) = 0;

    virtual void send_other (
      ::PortableInterceptor::ServerRequestInfo_ptr ri) = 0;

    virtual void send_poll (
      ::PortableInterceptor::ClientRequestInfo_ptr ri) = 0;

    virtual void receive_reply (
      ::PortableInterceptor::ClientRequestInfo_ptr ri) = 0;

    virtual void receive_exception (
      ::PortableInterceptor::ClientRequestInfo_ptr ri) = 0;

    virtual void receive_other (
      ::PortableInterceptor::ClientRequestInfo_ptr ri) = 0;

    virtual void cancel (
      const ::RTScheduling::Current::IdType & guid) = 0;

    // TAO_IDL - Generated from
    // c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ch.cpp:156

    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Abstract or local interface only.
    Scheduler (void);

    

    virtual ~Scheduler (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    Scheduler (const Scheduler &);

    void operator= (const Scheduler &);
  };

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_module/module_ch.cpp:70

} // module RTScheduling

// TAO_IDL - Generated from
// .\be\be_visitor_arg_traits.cpp:68


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL


// Arg traits specializations.
namespace TAO
{
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

#if !defined (_RTSCHEDULING_THREADACTION__TRAITS_)
#define _RTSCHEDULING_THREADACTION__TRAITS_

  template<>
  struct TAO_RTScheduler_Export Objref_Traits< ::RTScheduling::ThreadAction>
  {
    static ::RTScheduling::ThreadAction_ptr duplicate (
        ::RTScheduling::ThreadAction_ptr p);
    static void release (
        ::RTScheduling::ThreadAction_ptr p);
    static ::RTScheduling::ThreadAction_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::RTScheduling::ThreadAction_ptr p,
        TAO_OutputCDR & cdr);
  };

#endif /* end #if !defined */

#if !defined (_RTSCHEDULING_DISTRIBUTABLETHREAD__TRAITS_)
#define _RTSCHEDULING_DISTRIBUTABLETHREAD__TRAITS_

  template<>
  struct TAO_RTScheduler_Export Objref_Traits< ::RTScheduling::DistributableThread>
  {
    static ::RTScheduling::DistributableThread_ptr duplicate (
        ::RTScheduling::DistributableThread_ptr p);
    static void release (
        ::RTScheduling::DistributableThread_ptr p);
    static ::RTScheduling::DistributableThread_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::RTScheduling::DistributableThread_ptr p,
        TAO_OutputCDR & cdr);
  };

#endif /* end #if !defined */

#if !defined (_RTSCHEDULING_CURRENT__TRAITS_)
#define _RTSCHEDULING_CURRENT__TRAITS_

  template<>
  struct TAO_RTScheduler_Export Objref_Traits< ::RTScheduling::Current>
  {
    static ::RTScheduling::Current_ptr duplicate (
        ::RTScheduling::Current_ptr p);
    static void release (
        ::RTScheduling::Current_ptr p);
    static ::RTScheduling::Current_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::RTScheduling::Current_ptr p,
        TAO_OutputCDR & cdr);
  };

#endif /* end #if !defined */

#if !defined (_RTSCHEDULING_RESOURCEMANAGER__TRAITS_)
#define _RTSCHEDULING_RESOURCEMANAGER__TRAITS_

  template<>
  struct TAO_RTScheduler_Export Objref_Traits< ::RTScheduling::ResourceManager>
  {
    static ::RTScheduling::ResourceManager_ptr duplicate (
        ::RTScheduling::ResourceManager_ptr p);
    static void release (
        ::RTScheduling::ResourceManager_ptr p);
    static ::RTScheduling::ResourceManager_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::RTScheduling::ResourceManager_ptr p,
        TAO_OutputCDR & cdr);
  };

#endif /* end #if !defined */

#if !defined (_RTSCHEDULING_SCHEDULER__TRAITS_)
#define _RTSCHEDULING_SCHEDULER__TRAITS_

  template<>
  struct TAO_RTScheduler_Export Objref_Traits< ::RTScheduling::Scheduler>
  {
    static ::RTScheduling::Scheduler_ptr duplicate (
        ::RTScheduling::Scheduler_ptr p);
    static void release (
        ::RTScheduling::Scheduler_ptr p);
    static ::RTScheduling::Scheduler_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::RTScheduling::Scheduler_ptr p,
        TAO_OutputCDR & cdr);
  };

#endif /* end #if !defined */
}
TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// .\be\be_codegen.cpp:1581


TAO_END_VERSIONED_NAMESPACE_DECL

#endif /* ifndef */

