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
// .\be\be_codegen.cpp:375


#include "IOPC.h"
#include "tao/CDR.h"
#include "tao/ORB_Core.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from 
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_structure/structure_cs.cpp:58

void 
IOP::TaggedProfile::_tao_any_destructor (
    void *_tao_void_pointer)
{
  TaggedProfile *_tao_tmp_pointer =
    static_cast<TaggedProfile *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

// TAO_IDL - Generated from 
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_IOP_TAGGEDPROFILESEQ_CS_)
#define _IOP_TAGGEDPROFILESEQ_CS_

IOP::TaggedProfileSeq::TaggedProfileSeq (void)
{}

IOP::TaggedProfileSeq::TaggedProfileSeq (
    ::CORBA::ULong max)
  : ::TAO::unbounded_value_sequence<
        TaggedProfile
      > (max)
{}

IOP::TaggedProfileSeq::TaggedProfileSeq (
    ::CORBA::ULong max,
    ::CORBA::ULong length,
    IOP::TaggedProfile * buffer,
    ::CORBA::Boolean release
  )
  : ::TAO::unbounded_value_sequence<
        TaggedProfile
      >
    (max, length, buffer, release)
{}

IOP::TaggedProfileSeq::TaggedProfileSeq (
    const TaggedProfileSeq &seq)
  : ::TAO::unbounded_value_sequence<
        TaggedProfile
      > (seq)
{}

IOP::TaggedProfileSeq::~TaggedProfileSeq (void)
{}

void IOP::TaggedProfileSeq::_tao_any_destructor (
    void * _tao_void_pointer)
{
  TaggedProfileSeq * _tao_tmp_pointer =
    static_cast<TaggedProfileSeq *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

#endif /* end #if !defined */

// TAO_IDL - Generated from 
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_structure/structure_cs.cpp:58

void 
IOP::IOR::_tao_any_destructor (
    void *_tao_void_pointer)
{
  IOR *_tao_tmp_pointer =
    static_cast<IOR *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

// TAO_IDL - Generated from 
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_structure/structure_cs.cpp:58

void 
IOP::TaggedComponent::_tao_any_destructor (
    void *_tao_void_pointer)
{
  TaggedComponent *_tao_tmp_pointer =
    static_cast<TaggedComponent *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

// TAO_IDL - Generated from 
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_IOP_MULTIPLECOMPONENTPROFILE_CS_)
#define _IOP_MULTIPLECOMPONENTPROFILE_CS_

IOP::MultipleComponentProfile::MultipleComponentProfile (void)
{}

IOP::MultipleComponentProfile::MultipleComponentProfile (
    ::CORBA::ULong max)
  : ::TAO::unbounded_value_sequence<
        TaggedComponent
      > (max)
{}

IOP::MultipleComponentProfile::MultipleComponentProfile (
    ::CORBA::ULong max,
    ::CORBA::ULong length,
    IOP::TaggedComponent * buffer,
    ::CORBA::Boolean release
  )
  : ::TAO::unbounded_value_sequence<
        TaggedComponent
      >
    (max, length, buffer, release)
{}

IOP::MultipleComponentProfile::MultipleComponentProfile (
    const MultipleComponentProfile &seq)
  : ::TAO::unbounded_value_sequence<
        TaggedComponent
      > (seq)
{}

IOP::MultipleComponentProfile::~MultipleComponentProfile (void)
{}

void IOP::MultipleComponentProfile::_tao_any_destructor (
    void * _tao_void_pointer)
{
  MultipleComponentProfile * _tao_tmp_pointer =
    static_cast<MultipleComponentProfile *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

#endif /* end #if !defined */

// TAO_IDL - Generated from 
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_IOP_TAGGEDCOMPONENTSEQ_CS_)
#define _IOP_TAGGEDCOMPONENTSEQ_CS_

IOP::TaggedComponentSeq::TaggedComponentSeq (void)
{}

IOP::TaggedComponentSeq::TaggedComponentSeq (
    ::CORBA::ULong max)
  : ::TAO::unbounded_value_sequence<
        TaggedComponent
      > (max)
{}

IOP::TaggedComponentSeq::TaggedComponentSeq (
    ::CORBA::ULong max,
    ::CORBA::ULong length,
    IOP::TaggedComponent * buffer,
    ::CORBA::Boolean release
  )
  : ::TAO::unbounded_value_sequence<
        TaggedComponent
      >
    (max, length, buffer, release)
{}

IOP::TaggedComponentSeq::TaggedComponentSeq (
    const TaggedComponentSeq &seq)
  : ::TAO::unbounded_value_sequence<
        TaggedComponent
      > (seq)
{}

IOP::TaggedComponentSeq::~TaggedComponentSeq (void)
{}

void IOP::TaggedComponentSeq::_tao_any_destructor (
    void * _tao_void_pointer)
{
  TaggedComponentSeq * _tao_tmp_pointer =
    static_cast<TaggedComponentSeq *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

#endif /* end #if !defined */

// TAO_IDL - Generated from 
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_structure/structure_cs.cpp:58

void 
IOP::ServiceContext::_tao_any_destructor (
    void *_tao_void_pointer)
{
  ServiceContext *_tao_tmp_pointer =
    static_cast<ServiceContext *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

// TAO_IDL - Generated from 
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_IOP_SERVICECONTEXTLIST_CS_)
#define _IOP_SERVICECONTEXTLIST_CS_

IOP::ServiceContextList::ServiceContextList (void)
{}

IOP::ServiceContextList::ServiceContextList (
    ::CORBA::ULong max)
  : ::TAO::unbounded_value_sequence<
        ServiceContext
      > (max)
{}

IOP::ServiceContextList::ServiceContextList (
    ::CORBA::ULong max,
    ::CORBA::ULong length,
    IOP::ServiceContext * buffer,
    ::CORBA::Boolean release
  )
  : ::TAO::unbounded_value_sequence<
        ServiceContext
      >
    (max, length, buffer, release)
{}

IOP::ServiceContextList::ServiceContextList (
    const ServiceContextList &seq)
  : ::TAO::unbounded_value_sequence<
        ServiceContext
      > (seq)
{}

IOP::ServiceContextList::~ServiceContextList (void)
{}

void IOP::ServiceContextList::_tao_any_destructor (
    void * _tao_void_pointer)
{
  ServiceContextList * _tao_tmp_pointer =
    static_cast<ServiceContextList *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_structure/cdr_op_cs.cpp:52


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const IOP::TaggedProfile &_tao_aggregate)
{
  return
    (strm << _tao_aggregate.tag) &&
    (strm << _tao_aggregate.profile_data);
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    IOP::TaggedProfile &_tao_aggregate)
{
  return
    (strm >> _tao_aggregate.tag) &&
    (strm >> _tao_aggregate.profile_data);
}

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_sequence/cdr_op_cs.cpp:90
#if !defined _TAO_CDR_OP_IOP_TaggedProfileSeq_CPP_
#define _TAO_CDR_OP_IOP_TaggedProfileSeq_CPP_


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const IOP::TaggedProfileSeq &_tao_sequence)
{
  return TAO::marshal_sequence(strm, _tao_sequence);
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    IOP::TaggedProfileSeq &_tao_sequence)
{
  return TAO::demarshal_sequence(strm, _tao_sequence);
}


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL


#endif /* _TAO_CDR_OP_IOP_TaggedProfileSeq_CPP_ */

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_structure/cdr_op_cs.cpp:52


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const IOP::IOR &_tao_aggregate)
{
  return
    (strm << _tao_aggregate.type_id.in ()) &&
    (strm << _tao_aggregate.profiles);
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    IOP::IOR &_tao_aggregate)
{
  return
    (strm >> _tao_aggregate.type_id.out ()) &&
    (strm >> _tao_aggregate.profiles);
}

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_structure/cdr_op_cs.cpp:52


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const IOP::TaggedComponent &_tao_aggregate)
{
  return
    (strm << _tao_aggregate.tag) &&
    (strm << _tao_aggregate.component_data);
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    IOP::TaggedComponent &_tao_aggregate)
{
  return
    (strm >> _tao_aggregate.tag) &&
    (strm >> _tao_aggregate.component_data);
}

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_sequence/cdr_op_cs.cpp:90
#if !defined _TAO_CDR_OP_IOP_MultipleComponentProfile_CPP_
#define _TAO_CDR_OP_IOP_MultipleComponentProfile_CPP_


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const IOP::MultipleComponentProfile &_tao_sequence)
{
  return TAO::marshal_sequence(strm, _tao_sequence);
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    IOP::MultipleComponentProfile &_tao_sequence)
{
  return TAO::demarshal_sequence(strm, _tao_sequence);
}


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL


#endif /* _TAO_CDR_OP_IOP_MultipleComponentProfile_CPP_ */

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_sequence/cdr_op_cs.cpp:90
#if !defined _TAO_CDR_OP_IOP_TaggedComponentSeq_CPP_
#define _TAO_CDR_OP_IOP_TaggedComponentSeq_CPP_


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const IOP::TaggedComponentSeq &_tao_sequence)
{
  return TAO::marshal_sequence(strm, _tao_sequence);
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    IOP::TaggedComponentSeq &_tao_sequence)
{
  return TAO::demarshal_sequence(strm, _tao_sequence);
}


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL


#endif /* _TAO_CDR_OP_IOP_TaggedComponentSeq_CPP_ */

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_structure/cdr_op_cs.cpp:52


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const IOP::ServiceContext &_tao_aggregate)
{
  return
    (strm << _tao_aggregate.context_id) &&
    (strm << _tao_aggregate.context_data);
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    IOP::ServiceContext &_tao_aggregate)
{
  return
    (strm >> _tao_aggregate.context_id) &&
    (strm >> _tao_aggregate.context_data);
}

TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL




// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_sequence/cdr_op_cs.cpp:90
#if !defined _TAO_CDR_OP_IOP_ServiceContextList_CPP_
#define _TAO_CDR_OP_IOP_ServiceContextList_CPP_


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const IOP::ServiceContextList &_tao_sequence)
{
  return TAO::marshal_sequence(strm, _tao_sequence);
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    IOP::ServiceContextList &_tao_sequence)
{
  return TAO::demarshal_sequence(strm, _tao_sequence);
}


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL


#endif /* _TAO_CDR_OP_IOP_ServiceContextList_CPP_ */


TAO_END_VERSIONED_NAMESPACE_DECL


