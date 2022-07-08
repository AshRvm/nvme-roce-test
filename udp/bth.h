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
struct bth {
	u8			opcode;
	u8			flags;
	__be16			pkey;
	__be32			qpn;
	__be32			apsn;
}__attribute__((packed));

#define BTH_TVER			(0)
#define BTH_DEF_PKEY		(0xffff)
#define BTH_SE_MASK			(0x80)
#define BTH_MIG_MASK		(0x40)
#define BTH_PAD_MASK		(0x30)
#define BTH_TVER_MASK		(0x0f)
#define BTH_FECN_MASK		(0x80000000)
#define BTH_BECN_MASK		(0x40000000)
#define BTH_RESV6A_MASK		(0x3f000000)
#define BTH_QPN_MASK		(0x00ffffff)
#define BTH_ACK_MASK		(0x80000000)
#define BTH_RESV7_MASK		(0x7f000000)
#define BTH_PSN_MASK		(0x00ffffff)

/******************************************************************************
 * RDMA Extended Transport Header
 ******************************************************************************/
struct reth {
	__be64			va;
	__be32			rkey;
	__be32			len;
}__attribute__((packed));

/******************************************************************************
 * Ack Extended Transport Header
 ******************************************************************************/
struct rxe_aeth {
	__be32			smsn;
};

/******************************************************************************
 * Invalid Extended Transport Header
 ******************************************************************************/
struct rxe_ieth {
	__be32			rkey;
};

#endif