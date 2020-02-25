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


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ci.cpp:65

ACE_INLINE
FTRT::FaultListener::FaultListener (
    TAO_Stub *objref,
    ::CORBA::Boolean _tao_collocated,
    TAO_Abstract_ServantBase *servant,
    TAO_ORB_Core *oc)
  : ::CORBA::Object (objref, _tao_collocated, servant, oc),
    the_TAO_FaultListener_Proxy_Broker_ (0)
{
  this->FTRT_FaultListener_setup_collocation ();
}

ACE_INLINE
FTRT::FaultListener::FaultListener (
    ::IOP::IOR *ior,
    TAO_ORB_Core *oc)
  : ::CORBA::Object (ior, oc)
    , the_TAO_FaultListener_Proxy_Broker_ (0)
{
}

// TAO_IDL - Generated from
// e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ci.cpp:65

ACE_INLINE
FTRT::AMI_FaultListenerHandler::AMI_FaultListenerHandler (
    TAO_Stub *objref,
    ::CORBA::Boolean _tao_collocated,
    TAO_Abstract_ServantBase *servant,
    TAO_ORB_Core *oc)
  : ::CORBA::Object (objref, _tao_collocated, servant, oc),
    the_TAO_AMI_FaultListenerHandler_Proxy_Broker_ (0)
{
  this->FTRT_AMI_FaultListenerHandler_setup_collocation ();
}

ACE_INLINE
FTRT::AMI_FaultListenerHandler::AMI_FaultListenerHandler (
    ::IOP::IOR *ior,
    TAO_ORB_Core *oc)
  : ::CORBA::Object (ior, oc)
    , the_TAO_AMI_FaultListenerHandler_Proxy_Broker_ (0)
{
}

// TAO_IDL - Generated from
// e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ci.cpp:65

ACE_INLINE
FTRT::ObjectGroupManager::ObjectGroupManager (
    TAO_Stub *objref,
    ::CORBA::Boolean _tao_collocated,
    TAO_Abstract_ServantBase *servant,
    TAO_ORB_Core *oc)
  : ::CORBA::Object (objref, _tao_collocated, servant, oc),
    the_TAO_ObjectGroupManager_Proxy_Broker_ (0)
{
  this->FTRT_ObjectGroupManager_setup_collocation ();
}

ACE_INLINE
FTRT::ObjectGroupManager::ObjectGroupManager (
    ::IOP::IOR *ior,
    TAO_ORB_Core *oc)
  : ::CORBA::Object (ior, oc)
    , the_TAO_ObjectGroupManager_Proxy_Broker_ (0)
{
}

// TAO_IDL - Generated from
// e:\sca\ace_diab\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_ci.cpp:65

ACE_INLINE
FTRT::AMI_ObjectGroupManagerHandler::AMI_ObjectGroupManagerHandler (
    TAO_Stub *objref,
    ::CORBA::Boolean _tao_collocated,
    TAO_Abstract_ServantBase *servant,
    TAO_ORB_Core *oc)
  : ::CORBA::Object (objref, _tao_collocated, servant, oc),
    the_TAO_AMI_ObjectGroupManagerHandler_Proxy_Broker_ (0)
{
  this->FTRT_AMI_ObjectGroupManagerHandler_setup_collocation ();
}

ACE_INLINE
FTRT::AMI_ObjectGroupManagerHandler::AMI_ObjectGroupManagerHandler (
    ::IOP::IOR *ior,
    TAO_ORB_Core *oc)
  : ::CORBA::Object (ior, oc)
    , the_TAO_AMI_ObjectGroupManagerHandler_Proxy_Broker_ (0)
{
}


TAO_END_VERSIONED_NAMESPACE_DECL


