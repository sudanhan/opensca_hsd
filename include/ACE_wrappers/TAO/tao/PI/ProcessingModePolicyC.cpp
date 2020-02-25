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


#include "tao/PI/PI.h"
#include "tao/CDR.h"
#include "ace/OS_NS_string.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_cs.cpp:53

// Traits specializations for PortableInterceptor::ProcessingModePolicy.

PortableInterceptor::ProcessingModePolicy_ptr
TAO::Objref_Traits<PortableInterceptor::ProcessingModePolicy>::duplicate (
    PortableInterceptor::ProcessingModePolicy_ptr p)
{
  return PortableInterceptor::ProcessingModePolicy::_duplicate (p);
}

void
TAO::Objref_Traits<PortableInterceptor::ProcessingModePolicy>::release (
    PortableInterceptor::ProcessingModePolicy_ptr p)
{
  ::CORBA::release (p);
}

PortableInterceptor::ProcessingModePolicy_ptr
TAO::Objref_Traits<PortableInterceptor::ProcessingModePolicy>::nil (void)
{
  return PortableInterceptor::ProcessingModePolicy::_nil ();
}

::CORBA::Boolean
TAO::Objref_Traits<PortableInterceptor::ProcessingModePolicy>::marshal (
    const PortableInterceptor::ProcessingModePolicy_ptr p,
    TAO_OutputCDR & cdr)
{
  return ::CORBA::Object::marshal (p, cdr);
}

PortableInterceptor::ProcessingModePolicy::ProcessingModePolicy (void)
{}

PortableInterceptor::ProcessingModePolicy::~ProcessingModePolicy (void)
{}

PortableInterceptor::ProcessingModePolicy_ptr
PortableInterceptor::ProcessingModePolicy::_narrow (
    ::CORBA::Object_ptr _tao_objref)
{
  return ProcessingModePolicy::_duplicate (
      dynamic_cast<ProcessingModePolicy_ptr> (_tao_objref)
    );
}

PortableInterceptor::ProcessingModePolicy_ptr
PortableInterceptor::ProcessingModePolicy::_unchecked_narrow (
    ::CORBA::Object_ptr _tao_objref)
{
  return ProcessingModePolicy::_duplicate (
      dynamic_cast<ProcessingModePolicy_ptr> (_tao_objref)
    );
}

PortableInterceptor::ProcessingModePolicy_ptr
PortableInterceptor::ProcessingModePolicy::_nil (void)
{
  return 0;
}

PortableInterceptor::ProcessingModePolicy_ptr
PortableInterceptor::ProcessingModePolicy::_duplicate (ProcessingModePolicy_ptr obj)
{
  if (! ::CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
PortableInterceptor::ProcessingModePolicy::_tao_release (ProcessingModePolicy_ptr obj)
{
  ::CORBA::release (obj);
}

::CORBA::Boolean
PortableInterceptor::ProcessingModePolicy::_is_a (const char *value)
{
  if (
      ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/Policy:1.0"
        ) == 0 ||
      ACE_OS::strcmp (
          value,
          "IDL:PortableInterceptor/ProcessingModePolicy:1.0"
        ) == 0 ||
      ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/LocalObject:1.0"
        ) == 0 ||
      ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/Object:1.0"
        ) == 0
    )
    {
      return true; // success using local knowledge
    }
  else
    {
      return false;
    }
}

const char* PortableInterceptor::ProcessingModePolicy::_interface_repository_id (void) const
{
  return "IDL:PortableInterceptor/ProcessingModePolicy:1.0";
}

::CORBA::Boolean
PortableInterceptor::ProcessingModePolicy::marshal (TAO_OutputCDR & /* cdr */)
{
  return false;
}


TAO_END_VERSIONED_NAMESPACE_DECL


