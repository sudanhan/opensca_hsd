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


#include "UShortSeqC.h"
#include "tao/CDR.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from 
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_CORBA_USHORTSEQ_CS_)
#define _CORBA_USHORTSEQ_CS_

CORBA::UShortSeq::UShortSeq (void)
{}

CORBA::UShortSeq::UShortSeq (
    ::CORBA::ULong max)
  : ::TAO::unbounded_value_sequence<
        ::CORBA::UShort
      > (max)
{}

CORBA::UShortSeq::UShortSeq (
    ::CORBA::ULong max,
    ::CORBA::ULong length,
    ::CORBA::UShort * buffer,
    ::CORBA::Boolean release
  )
  : ::TAO::unbounded_value_sequence<
        ::CORBA::UShort
      >
    (max, length, buffer, release)
{}

CORBA::UShortSeq::UShortSeq (
    const UShortSeq &seq)
  : ::TAO::unbounded_value_sequence<
        ::CORBA::UShort
      > (seq)
{}

CORBA::UShortSeq::~UShortSeq (void)
{}

void CORBA::UShortSeq::_tao_any_destructor (
    void * _tao_void_pointer)
{
  UShortSeq * _tao_tmp_pointer =
    static_cast<UShortSeq *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_sequence/cdr_op_cs.cpp:90
#if !defined _TAO_CDR_OP_CORBA_UShortSeq_CPP_
#define _TAO_CDR_OP_CORBA_UShortSeq_CPP_


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CORBA::UShortSeq &_tao_sequence)
{
  return TAO::marshal_sequence(strm, _tao_sequence);
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CORBA::UShortSeq &_tao_sequence)
{
  return TAO::demarshal_sequence(strm, _tao_sequence);
}


TAO_END_VERSIONED_NAMESPACE_DECL


TAO_BEGIN_VERSIONED_NAMESPACE_DECL


#endif /* _TAO_CDR_OP_CORBA_UShortSeq_CPP_ */


TAO_END_VERSIONED_NAMESPACE_DECL

