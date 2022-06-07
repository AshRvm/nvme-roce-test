#!/usr/bin/python3
from staslib import stas

if __name__ == '__main__':

    class Test():
        '''Unit test for class TransportId'''

        TRANSPORT    = 'tcp'
        TRADDR       = '10.10.10.10'
        SUBSYSNQN    = 'nqn.1988-11.com.dell:SFSS:2:20220208134025e8'
        TRSVCID      = '8009'
        HOST_TRADDR  = '1.2.3.4'
        HOST_IFACE   = 'wlp0s20f3'

        def __init__(self):
            self.cid = {
                'transport':   Test.TRANSPORT,
                'traddr':      Test.TRADDR,
                'subsysnqn':   Test.SUBSYSNQN,
                'trsvcid':     Test.TRSVCID,
                'host-traddr': Test.HOST_TRADDR,
                'host-iface':  Test.HOST_IFACE,
            }

            self.tid = stas.TransportId(self.cid)

        def test_key(self):
            '''Check that a key exists'''
            self.assertIsInstance(self.tid.key, tuple)

        def test_hash(self):
            '''Check that a hash exists'''
            self.assertIsInstance(self.tid.hash, int)

        def test_transport(self):
            '''Check that transport is set'''
            self.assertEqual(self.tid.transport, Test.TRANSPORT)

        def test_traddr(self):
            '''Check that traddr is set'''
            self.assertEqual(self.tid.traddr, Test.TRADDR)

        def test_trsvcid(self):
            '''Check that trsvcid is set'''
            self.assertEqual(self.tid.trsvcid, Test.TRSVCID)

        def test_host_traddr(self):
            '''Check that host_traddr is set'''
            self.assertEqual(self.tid.host_traddr, Test.HOST_TRADDR)

        def test_host_iface(self):
            '''Check that host_iface is set'''
            self.assertEqual(self.tid.host_iface, Test.HOST_IFACE)

        def test_subsysnqn(self):
            '''Check that subsysnqn is set'''
            self.assertEqual(self.tid.subsysnqn, Test.SUBSYSNQN)

        def test_as_dict(self):
            '''Check that a TransportId can be converted back to the original Dict it was created with'''
            self.assertDictEqual(self.tid.as_dict(), self.cid)

        def test_str(self):
            '''Check that a TransportId can be represented as a string'''
            self.assertTrue(str(self.tid).startswith(f'({Test.TRANSPORT},'))

    A = Test()
    print(f'{A.test_key()}, {A.test_hash()}, {A.test_transport()}')