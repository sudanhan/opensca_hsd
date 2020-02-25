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
// .\be\be_interface.cpp:2223

ACE_INLINE
void
POA_CosTypedEventChannelAdmin::TypedProxyPushConsumer::push_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant)
{
  POA_CosEventComm::PushConsumer * const impl =
    static_cast<POA_CosTypedEventChannelAdmin::TypedProxyPushConsumer *> (servant);
  POA_CosEventComm::PushConsumer::push_skel (
      server_request,
      servant_upcall,
      impl);
}

// TAO_IDL - Generated from
// .\be\be_interface.cpp:2223

ACE_INLINE
void
POA_CosTypedEventChannelAdmin::TypedProxyPushConsumer::disconnect_push_consumer_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant)
{
  POA_CosEventComm::PushConsumer * const impl =
    static_cast<POA_CosTypedEventChannelAdmin::TypedProxyPushConsumer *> (servant);
  POA_CosEventComm::PushConsumer::disconnect_push_consumer_skel (
      server_request,
      servant_upcall,
      impl);
}

// TAO_IDL - Generated from
// .\be\be_interface.cpp:2223

ACE_INLINE
void
POA_CosTypedEventChannelAdmin::TypedProxyPushConsumer::connect_push_supplier_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant)
{
  POA_CosEventChannelAdmin::ProxyPushConsumer * const impl =
    static_cast<POA_CosTypedEventChannelAdmin::TypedProxyPushConsumer *> (servant);
  POA_CosEventChannelAdmin::ProxyPushConsumer::connect_push_supplier_skel (
      server_request,
      servant_upcall,
      impl);
}

// TAO_IDL - Generated from
// .\be\be_interface.cpp:2223

ACE_INLINE
void
POA_CosTypedEventChannelAdmin::TypedProxyPushConsumer::get_typed_consumer_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant)
{
  POA_CosTypedEventComm::TypedPushConsumer * const impl =
    static_cast<POA_CosTypedEventChannelAdmin::TypedProxyPushConsumer *> (servant);
  POA_CosTypedEventComm::TypedPushConsumer::get_typed_consumer_skel (
      server_request,
      servant_upcall,
      impl);
}

// TAO_IDL - Generated from
// .\be\be_interface.cpp:2223

ACE_INLINE
void
POA_CosTypedEventChannelAdmin::TypedProxyPullSupplier::pull_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant)
{
  POA_CosEventComm::PullSupplier * const impl =
    static_cast<POA_CosTypedEventChannelAdmin::TypedProxyPullSupplier *> (servant);
  POA_CosEventComm::PullSupplier::pull_skel (
      server_request,
      servant_upcall,
      impl);
}

// TAO_IDL - Generated from
// .\be\be_interface.cpp:2223

ACE_INLINE
void
POA_CosTypedEventChannelAdmin::TypedProxyPullSupplier::try_pull_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant)
{
  POA_CosEventComm::PullSupplier * const impl =
    static_cast<POA_CosTypedEventChannelAdmin::TypedProxyPullSupplier *> (servant);
  POA_CosEventComm::PullSupplier::try_pull_skel (
      server_request,
      servant_upcall,
      impl);
}

// TAO_IDL - Generated from
// .\be\be_interface.cpp:2223

ACE_INLINE
void
POA_CosTypedEventChannelAdmin::TypedProxyPullSupplier::disconnect_pull_supplier_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant)
{
  POA_CosEventComm::PullSupplier * const impl =
    static_cast<POA_CosTypedEventChannelAdmin::TypedProxyPullSupplier *> (servant);
  POA_CosEventComm::PullSupplier::disconnect_pull_supplier_skel (
      server_request,
      servant_upcall,
      impl);
}

// TAO_IDL - Generated from
// .\be\be_interface.cpp:2223

ACE_INLINE
void
POA_CosTypedEventChannelAdmin::TypedProxyPullSupplier::connect_pull_consumer_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant)
{
  POA_CosEventChannelAdmin::ProxyPullSupplier * const impl =
    static_cast<POA_CosTypedEventChannelAdmin::TypedProxyPullSupplier *> (servant);
  POA_CosEventChannelAdmin::ProxyPullSupplier::connect_pull_consumer_skel (
      server_request,
      servant_upcall,
      impl);
}

// TAO_IDL - Generated from
// .\be\be_interface.cpp:2223

ACE_INLINE
void
POA_CosTypedEventChannelAdmin::TypedProxyPullSupplier::get_typed_supplier_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant)
{
  POA_CosTypedEventComm::TypedPullSupplier * const impl =
    static_cast<POA_CosTypedEventChannelAdmin::TypedProxyPullSupplier *> (servant);
  POA_CosTypedEventComm::TypedPullSupplier::get_typed_supplier_skel (
      server_request,
      servant_upcall,
      impl);
}

// TAO_IDL - Generated from
// .\be\be_interface.cpp:2223

ACE_INLINE
void
POA_CosTypedEventChannelAdmin::TypedSupplierAdmin::obtain_push_consumer_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant)
{
  POA_CosEventChannelAdmin::SupplierAdmin * const impl =
    static_cast<POA_CosTypedEventChannelAdmin::TypedSupplierAdmin *> (servant);
  POA_CosEventChannelAdmin::SupplierAdmin::obtain_push_consumer_skel (
      server_request,
      servant_upcall,
      impl);
}

// TAO_IDL - Generated from
// .\be\be_interface.cpp:2223

ACE_INLINE
void
POA_CosTypedEventChannelAdmin::TypedSupplierAdmin::obtain_pull_consumer_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant)
{
  POA_CosEventChannelAdmin::SupplierAdmin * const impl =
    static_cast<POA_CosTypedEventChannelAdmin::TypedSupplierAdmin *> (servant);
  POA_CosEventChannelAdmin::SupplierAdmin::obtain_pull_consumer_skel (
      server_request,
      servant_upcall,
      impl);
}

// TAO_IDL - Generated from
// .\be\be_interface.cpp:2223

ACE_INLINE
void
POA_CosTypedEventChannelAdmin::TypedConsumerAdmin::obtain_push_supplier_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant)
{
  POA_CosEventChannelAdmin::ConsumerAdmin * const impl =
    static_cast<POA_CosTypedEventChannelAdmin::TypedConsumerAdmin *> (servant);
  POA_CosEventChannelAdmin::ConsumerAdmin::obtain_push_supplier_skel (
      server_request,
      servant_upcall,
      impl);
}

// TAO_IDL - Generated from
// .\be\be_interface.cpp:2223

ACE_INLINE
void
POA_CosTypedEventChannelAdmin::TypedConsumerAdmin::obtain_pull_supplier_skel (
    TAO_ServerRequest & server_request,
    void * servant_upcall,
    void * servant)
{
  POA_CosEventChannelAdmin::ConsumerAdmin * const impl =
    static_cast<POA_CosTypedEventChannelAdmin::TypedConsumerAdmin *> (servant);
  POA_CosEventChannelAdmin::ConsumerAdmin::obtain_pull_supplier_skel (
      server_request,
      servant_upcall,
      impl);
}

