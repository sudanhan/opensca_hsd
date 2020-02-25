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


#include "ServantActivatorC.h"
#include "tao/CDR.h"
#include "ace/OS_NS_string.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// c:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_cs.cpp:53

// Traits specializations for PortableServer::ServantActivator.

PortableServer::ServantActivator_ptr
TAO::Objref_Traits<PortableServer::ServantActivator>::duplicate (
    PortableServer::ServantActivator_ptr p)
{
  return PortableServer::ServantActivator::_duplicate (p);
}

void
TAO::Objref_Traits<PortableServer::ServantActivator>::release (
    PortableServer::ServantActivator_ptr p)
{
  ::CORBA::release (p);
}

PortableServer::ServantActivator_ptr
TAO::Objref_Traits<PortableServer::ServantActivator>::nil (void)
{
  return PortableServer::ServantActivator::_nil ();
}

::CORBA::Boolean
TAO::Objref_Traits<PortableServer::ServantActivator>::marshal (
    const PortableServer::ServantActivator_ptr p,
    TAO_OutputCDR & cdr)
{
  return ::CORBA::Object::marshal (p, cdr);
}

PortableServer::ServantActivator::ServantActivator (void)
{}

PortableServer::ServantActivator::~ServantActivator (void)
{}

PortableServer::ServantActivator_ptr
PortableServer::ServantActivator::_narrow (
    ::CORBA::Object_ptr _tao_objref)
{
  return ServantActivator::_duplicate (
      dynamic_cast<ServantActivator_ptr> (_tao_objref)
    );
}

PortableServer::ServantActivator_ptr
PortableServer::ServantActivator::_unchecked_narrow (
    ::CORBA::Object_ptr _tao_objref)
{
  return ServantActivator::_duplicate (
      dynamic_cast<ServantActivator_ptr> (_tao_objref)
    );
}

PortableServer::ServantActivator_ptr
PortableServer::ServantActivator::_nil (void)
{
  return 0;
}

PortableServer::ServantActivator_ptr
PortableServer::ServantActivator::_duplicate (ServantActivator_ptr obj)
{
  if (! ::CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  
  return obj;
}

void
PortableServer::ServantActivator::_tao_release (ServantActivator_ptr obj)
{
  ::CORBA::release (obj);
}

::CORBA::Boolean
PortableServer::ServantActivator::_is_a (const char *value)
{
  if (
      ACE_OS::strcmp (
          value,
          "IDL:omg.org/PortableServer/ServantManager:2.3"
        ) == 0 ||
      ACE_OS::strcmp (
          value,
          "IDL:omg.org/PortableServer/ServantActivator:2.3"
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

const char* PortableServer::ServantActivator::_interface_repository_id (void) const
{
  return "IDL:omg.org/PortableServer/ServantActivator:2.3";
}

::CORBA::Boolean
PortableServer::ServantActivator::marshal (TAO_OutputCDR & /* cdr */)
{
  return false;
}


TAO_END_VERSIONED_NAMESPACE_DECL


