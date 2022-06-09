#!/usr/bin/python3
# from staslib import stas
import stas_copy as stas

if __name__ == "__main__":
    cid = {
        'transport': 'rdma',
        'traddr': '10.197.155.169',
        'subsysnqn': 'nqn.1988-11.com.dell:SFSS:2:20220208134025e8',
        'trsvcid': '4420',
        'host-traddr': '10.197.155.35',
        'host-iface': 'wlp0s20f3'
    }

    tid = stas.TransportId(cid)
    cnf = stas.NvmeOptions()

    print(str(tid))