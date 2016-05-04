// NILayer.h: interface for the CNILayer class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#include "BaseLayer.h"
#include <pcap.h>
#include <Packet32.h>

class CNILayer 
	: public CBaseLayer
{
protected:
	pcap_t			*m_AdapterObject;
	
public:
	BOOL			m_thrdSwitch;
	unsigned char*  m_ppayload;

	void			PacketStartDriver();

	pcap_if_t 		*GetAdapterObject(int iIndex);
	void			SetAdapterNumber(int iNum);
	void			SetAdapterList(LPADAPTER *plist);
	CString			GetNICardAddress(char* adapter_name);
	
	static UINT		ReadingThread(LPVOID pParam);

	BOOL			Receive( unsigned char *ppayload ) ;
	BOOL			Send( unsigned char *ppayload, int nlength );

	CNILayer( char* pName, LPADAPTER *pAdapterObject = NULL, int iNumAdapter = 0 );
	virtual ~CNILayer();

protected:
	int			m_iNumAdapter;
	pcap_if_t	*m_pAdapterList[NI_COUNT_NIC];
};
