/**
 * @file RTServer_Setup.inl
 *
 * $Id: RTServer_Setup.inl 14 2007-02-01 15:49:12Z mitza $
 *
 * @author Carlos O'Ryan <coryan@uci.edu>
 */

ACE_INLINE PortableServer::POA_ptr
RTServer_Setup::poa (void)
{
  return PortableServer::POA::_duplicate (this->poa_.in ());
}
