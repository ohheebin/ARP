// EthernetLayer.h: interface for the CEthernetLayer class.
//
//////////////////////////////////////////////////////////////////////

#pragma once


#include "BaseLayer.h"

class CEthernetLayer 
: public CBaseLayer
{
private:
	inline void		ResetHeader( );

public:
	BOOL			Receive( unsigned char* ppayload ) ;
	BOOL			Send( unsigned char* ppayload, int nlength );

	void			SetEnetDstAddress( unsigned char* pAddress );
	void			SetEnetSrcAddress( unsigned char* pAddress );
	unsigned char*	GetEnetDstAddress( );
	unsigned char*	GetEnetSrcAddress( );

	CEthernetLayer( char* pName );
	virtual ~CEthernetLayer(); 

private:
	// Ethernet Address
	typedef struct _ETHERNET_ADDR
	{
		union {
			struct { unsigned char e0, e1, e2, e3, e4, e5; } s_un_byte ;
			unsigned char s_ether_addr[6] ;
		} S_un ;
	#define addr0 S_un.s_un_byte.e0
	#define addr1 S_un.s_un_byte.e1
	#define addr2 S_un.s_un_byte.e2
	#define addr3 S_un.s_un_byte.e3
	#define addr4 S_un.s_un_byte.e4
	#define addr5 S_un.s_un_byte.e5
	#define addrs S_un.s_ether_addr
	} ETHERNET_ADDR, *LPETHERNET_ADDR ;

	// Ethernet Header
	typedef struct _ETHERNET_HEADER {
		ETHERNET_ADDR	enet_dstaddr;		// destination address of ethernet layer
		ETHERNET_ADDR	enet_srcaddr;		// source address of ethernet layer
		unsigned short	enet_frametype;		// type of ethernet layer
		unsigned char	enet_data[ETHER_MAX_DATA_SIZE]; // frame data
	} ETHERNET_HEADER, *PETHERNET_HEADER ;

protected:
	ETHERNET_HEADER	m_sHeader ;
};

