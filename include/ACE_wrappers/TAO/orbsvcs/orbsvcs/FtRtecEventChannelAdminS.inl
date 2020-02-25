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
// .\be\be_interface.cpp:2223

ACE_INLINE
void
POA_FtRtecEventChannelAdmin::EventChannelFacade::push_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant)
{
  POA_FtRtecEventComm::PushConsumer * const impl =
    static_cast<POA_FtRtecEventChannelAdmin::EventChannelFacade *> (servant);
  POA_FtRtecEventComm::PushConsumer::push_skel (
      server_request,
      servant_upcall,
      impl);
}

// TAO_IDL - Generated from
// .\be\be_interface.cpp:2223

ACE_INLINE
void
POA_FtRtecEventChannelAdmin::EventChannel::for_consumers_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant)
{
  POA_RtecEventChannelAdmin::EventChannel * const impl =
    static_cast<POA_FtRtecEventChannelAdmin::EventChannel *> (servant);
  POA_RtecEventChannelAdmin::EventChannel::for_consumers_skel (
      server_request,
      servant_upcall,
      impl);
}

// TAO_IDL - Generated from
// .\be\be_interface.cpp:2223

ACE_INLINE
void
POA_FtRtecEventChannelAdmin::EventChannel::for_suppliers_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant)
{
  POA_RtecEventChannelAdmin::EventChannel * const impl =
    static_cast<POA_FtRtecEventChannelAdmin::EventChannel *> (servant);
  POA_RtecEventChannelAdmin::EventChannel::for_suppliers_skel (
      server_request,
      servant_upcall,
      impl);
}

// TAO_IDL - Generated from
// .\be\be_interface.cpp:2223

ACE_INLINE
void
POA_FtRtecEventChannelAdmin::EventChannel::destroy_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant)
{
  POA_RtecEventChannelAdmin::EventChannel * const impl =
    static_cast<POA_FtRtecEventChannelAdmin::EventChannel *> (servant);
  POA_RtecEventChannelAdmin::EventChannel::destroy_skel (
      server_request,
      servant_upcall,
      impl);
}

// TAO_IDL - Generated from
// .\be\be_interface.cpp:2223

ACE_INLINE
void
POA_FtRtecEventChannelAdmin::EventChannel::append_observer_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant)
{
  POA_RtecEventChannelAdmin::EventChannel * const impl =
    static_cast<POA_FtRtecEventChannelAdmin::EventChannel *> (servant);
  POA_RtecEventChannelAdmin::EventChannel::append_observer_skel (
      server_request,
      servant_upcall,
      impl);
}

// TAO_IDL - Generated from
// .\be\be_interface.cpp:2223

ACE_INLINE
void
POA_FtRtecEventChannelAdmin::EventChannel::remove_observer_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant)
{
  POA_RtecEventChannelAdmin::EventChannel * const impl =
    static_cast<POA_FtRtecEventChannelAdmin::EventChannel *> (servant);
  POA_RtecEventChannelAdmin::EventChannel::remove_observer_skel (
      server_request,
      servant_upcall,
      impl);
}

// TAO_IDL - Generated from
// .\be\be_interface.cpp:2223

ACE_INLINE
void
POA_FtRtecEventChannelAdmin::EventChannel::push_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant)
{
  POA_FtRtecEventComm::PushConsumer * const impl =
    static_cast<POA_FtRtecEventChannelAdmin::EventChannel *> (servant);
  POA_FtRtecEventComm::PushConsumer::push_skel (
      server_request,
      servant_upcall,
      impl);
}

// TAO_IDL - Generated from
// .\be\be_interface.cpp:2223

ACE_INLINE
void
POA_FtRtecEventChannelAdmin::EventChannel::connect_push_consumer_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant)
{
  POA_FtRtecEventChannelAdmin::EventChannelFacade * const impl =
    static_cast<POA_FtRtecEventChannelAdmin::EventChannel *> (servant);
  POA_FtRtecEventChannelAdmin::EventChannelFacade::connect_push_consumer_skel (
      server_request,
      servant_upcall,
      impl);
}

// TAO_IDL - Generated from
// .\be\be_interface.cpp:2223

ACE_INLINE
void
POA_FtRtecEventChannelAdmin::EventChannel::connect_push_supplier_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant)
{
  POA_FtRtecEventChannelAdmin::EventChannelFacade * const impl =
    static_cast<POA_FtRtecEventChannelAdmin::EventChannel *> (servant);
  POA_FtRtecEventChannelAdmin::EventChannelFacade::connect_push_supplier_skel (
      server_request,
      servant_upcall,
      impl);
}

// TAO_IDL - Generated from
// .\be\be_interface.cpp:2223

ACE_INLINE
void
POA_FtRtecEventChannelAdmin::EventChannel::disconnect_push_supplier_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant)
{
  POA_FtRtecEventChannelAdmin::EventChannelFacade * const impl =
    static_cast<POA_FtRtecEventChannelAdmin::EventChannel *> (servant);
  POA_FtRtecEventChannelAdmin::EventChannelFacade::disconnect_push_supplier_skel (
      server_request,
      servant_upcall,
      impl);
}

// TAO_IDL - Generated from
// .\be\be_interface.cpp:2223

ACE_INLINE
void
POA_FtRtecEventChannelAdmin::EventChannel::disconnect_push_consumer_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant)
{
  POA_FtRtecEventChannelAdmin::EventChannelFacade * const impl =
    static_cast<POA_FtRtecEventChannelAdmin::EventChannel *> (servant);
  POA_FtRtecEventChannelAdmin::EventChannelFacade::disconnect_push_consumer_skel (
      server_request,
      servant_upcall,
      impl);
}

// TAO_IDL - Generated from
// .\be\be_interface.cpp:2223

ACE_INLINE
void
POA_FtRtecEventChannelAdmin::EventChannel::suspend_push_supplier_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant)
{
  POA_FtRtecEventChannelAdmin::EventChannelFacade * const impl =
    static_cast<POA_FtRtecEventChannelAdmin::EventChannel *> (servant);
  POA_FtRtecEventChannelAdmin::EventChannelFacade::suspend_push_supplier_skel (
      server_request,
      servant_upcall,
      impl);
}

// TAO_IDL - Generated from
// .\be\be_interface.cpp:2223

ACE_INLINE
void
POA_FtRtecEventChannelAdmin::EventChannel::resume_push_supplier_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant)
{
  POA_FtRtecEventChannelAdmin::EventChannelFacade * const impl =
    static_cast<POA_FtRtecEventChannelAdmin::EventChannel *> (servant);
  POA_FtRtecEventChannelAdmin::EventChannelFacade::resume_push_supplier_skel (
      server_request,
      servant_upcall,
      impl);
}

// TAO_IDL - Generated from
// .\be\be_interface.cpp:2223

ACE_INLINE
void
POA_FtRtecEventChannelAdmin::EventChannel::set_update_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant)
{
  POA_FTRT::Updateable * const impl =
    static_cast<POA_FtRtecEventChannelAdmin::EventChannel *> (servant);
  POA_FTRT::Updateable::set_update_skel (
      server_request,
      servant_upcall,
      impl);
}

// TAO_IDL - Generated from
// .\be\be_interface.cpp:2223

ACE_INLINE
void
POA_FtRtecEventChannelAdmin::EventChannel::oneway_set_update_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant)
{
  POA_FTRT::Updateable * const impl =
    static_cast<POA_FtRtecEventChannelAdmin::EventChannel *> (servant);
  POA_FTRT::Updateable::oneway_set_update_skel (
      server_request,
      servant_upcall,
      impl);
}

// TAO_IDL - Generated from
// .\be\be_interface.cpp:2223

ACE_INLINE
void
POA_FtRtecEventChannelAdmin::EventChannel::replica_crashed_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant)
{
  POA_FTRT::FaultListener * const impl =
    static_cast<POA_FtRtecEventChannelAdmin::EventChannel *> (servant);
  POA_FTRT::FaultListener::replica_crashed_skel (
      server_request,
      servant_upcall,
      impl);
}

// TAO_IDL - Generated from
// .\be\be_interface.cpp:2223

ACE_INLINE
void
POA_FtRtecEventChannelAdmin::EventChannel::start_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant)
{
  POA_FTRT::ObjectGroupManager * const impl =
    static_cast<POA_FtRtecEventChannelAdmin::EventChannel *> (servant);
  POA_FTRT::ObjectGroupManager::start_skel (
      server_request,
      servant_upcall,
      impl);
}

// TAO_IDL - Generated from
// .\be\be_interface.cpp:2223

ACE_INLINE
void
POA_FtRtecEventChannelAdmin::EventChannel::create_group_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant)
{
  POA_FTRT::ObjectGroupManager * const impl =
    static_cast<POA_FtRtecEventChannelAdmin::EventChannel *> (servant);
  POA_FTRT::ObjectGroupManager::create_group_skel (
      server_request,
      servant_upcall,
      impl);
}

// TAO_IDL - Generated from
// .\be\be_interface.cpp:2223

ACE_INLINE
void
POA_FtRtecEventChannelAdmin::EventChannel::join_group_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant)
{
  POA_FTRT::ObjectGroupManager * const impl =
    static_cast<POA_FtRtecEventChannelAdmin::EventChannel *> (servant);
  POA_FTRT::ObjectGroupManager::join_group_skel (
      server_request,
      servant_upcall,
      impl);
}

// TAO_IDL - Generated from
// .\be\be_interface.cpp:2223

ACE_INLINE
void
POA_FtRtecEventChannelAdmin::EventChannel::add_member_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant)
{
  POA_FTRT::ObjectGroupManager * const impl =
    static_cast<POA_FtRtecEventChannelAdmin::EventChannel *> (servant);
  POA_FTRT::ObjectGroupManager::add_member_skel (
      server_request,
      servant_upcall,
      impl);
}

// TAO_IDL - Generated from
// .\be\be_interface.cpp:2223

ACE_INLINE
void
POA_FtRtecEventChannelAdmin::EventChannel::remove_member_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant)
{
  POA_FTRT::ObjectGroupManager * const impl =
    static_cast<POA_FtRtecEventChannelAdmin::EventChannel *> (servant);
  POA_FTRT::ObjectGroupManager::remove_member_skel (
      server_request,
      servant_upcall,
      impl);
}

// TAO_IDL - Generated from
// .\be\be_interface.cpp:2223

ACE_INLINE
void
POA_FtRtecEventChannelAdmin::EventChannel::set_state_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant)
{
  POA_FTRT::ObjectGroupManager * const impl =
    static_cast<POA_FtRtecEventChannelAdmin::EventChannel *> (servant);
  POA_FTRT::ObjectGroupManager::set_state_skel (
      server_request,
      servant_upcall,
      impl);
}


TAO_END_VERSIONED_NAMESPACE_DECL


