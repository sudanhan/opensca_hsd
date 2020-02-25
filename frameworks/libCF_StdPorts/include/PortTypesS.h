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

#ifndef _TAO_IDL_PORTTYPESS_EUYQR1_H_
#define _TAO_IDL_PORTTYPESS_EUYQR1_H_


#include "PortTypesC.h"
#include "tao/PortableServer/Basic_SArguments.h"
#include "tao/PortableServer/Special_Basic_SArguments.h"
#include "tao/PortableServer/Fixed_Size_SArgument_T.h"
#include "tao/PortableServer/Var_Size_SArgument_T.h"
#include "tao/PortableServer/UB_String_SArguments.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


// TAO_IDL - Generated from
// .\be\be_visitor_arg_traits.cpp:68

TAO_BEGIN_VERSIONED_NAMESPACE_DECL


// Arg traits specializations.
namespace TAO
{

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:679

  template<>
  class SArg_Traits< ::PortTypes::WstringSequence>
    : public
        Var_Size_SArg_Traits_T<
            ::PortTypes::WstringSequence,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:679

  template<>
  class SArg_Traits< ::PortTypes::BooleanSequence>
    : public
        Var_Size_SArg_Traits_T<
            ::PortTypes::BooleanSequence,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:679

  template<>
  class SArg_Traits< ::PortTypes::CharSequence>
    : public
        Var_Size_SArg_Traits_T<
            ::PortTypes::CharSequence,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:679

  template<>
  class SArg_Traits< ::PortTypes::DoubleSequence>
    : public
        Var_Size_SArg_Traits_T<
            ::PortTypes::DoubleSequence,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:679

  template<>
  class SArg_Traits< ::PortTypes::LongDoubleSequence>
    : public
        Var_Size_SArg_Traits_T<
            ::PortTypes::LongDoubleSequence,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:679

  template<>
  class SArg_Traits< ::PortTypes::LongLongSequence>
    : public
        Var_Size_SArg_Traits_T<
            ::PortTypes::LongLongSequence,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:679

  template<>
  class SArg_Traits< ::PortTypes::LongSequence>
    : public
        Var_Size_SArg_Traits_T<
            ::PortTypes::LongSequence,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:679

  template<>
  class SArg_Traits< ::PortTypes::ShortSequence>
    : public
        Var_Size_SArg_Traits_T<
            ::PortTypes::ShortSequence,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:679

  template<>
  class SArg_Traits< ::PortTypes::UlongLongSequence>
    : public
        Var_Size_SArg_Traits_T<
            ::PortTypes::UlongLongSequence,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:679

  template<>
  class SArg_Traits< ::PortTypes::UlongSequence>
    : public
        Var_Size_SArg_Traits_T<
            ::PortTypes::UlongSequence,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:679

  template<>
  class SArg_Traits< ::PortTypes::UshortSequence>
    : public
        Var_Size_SArg_Traits_T<
            ::PortTypes::UshortSequence,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:679

  template<>
  class SArg_Traits< ::PortTypes::WcharSequence>
    : public
        Var_Size_SArg_Traits_T<
            ::PortTypes::WcharSequence,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // .\be\be_visitor_arg_traits.cpp:679

  template<>
  class SArg_Traits< ::PortTypes::FloatSequence>
    : public
        Var_Size_SArg_Traits_T<
            ::PortTypes::FloatSequence,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };
}

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_module/module_sh.cpp:41

namespace POA_PortTypes
{
  

// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_module/module_sh.cpp:72

} // module PortTypes
#if defined (__ACE_INLINE__)
#include "PortTypesS.inl"
#endif /* defined INLINE */

#endif /* ifndef */

