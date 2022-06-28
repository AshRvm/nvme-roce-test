#ifndef BTH_H
#define BTH_H

typedef __UINT8_TYPE__ u8;
typedef __UINT16_TYPE__ u16;
typedef __UINT32_TYPE__ u32;
typedef __UINT64_TYPE__ u64;

typedef __UINT16_TYPE__ __be16;
typedef __UINT32_TYPE__ __be32;
typedef __UINT64_TYPE__ __be64;

/******************************************************************************
 * Base Transport Header
 ******************************************************************************/
struct rxe_bth {
	u8			opcode;
	u8			flags;
	__be16			pkey;
	__be32			qpn;
	__be32			apsn;
}__attribute__((packed));


/******************************************************************************
 * RDMA Extended Transport Header
 ******************************************************************************/
struct rxe_reth {
	__be64			va;
	__be32			rkey;
	__be32			len;
}__attribute__((packed));

#endif