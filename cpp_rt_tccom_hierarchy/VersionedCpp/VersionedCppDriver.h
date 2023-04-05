///////////////////////////////////////////////////////////////////////////////
// VersionedCppDriver.h

#ifndef __VERSIONEDCPPDRIVER_H__
#define __VERSIONEDCPPDRIVER_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TcBase.h"

#define VERSIONEDCPPDRV_NAME        "VERSIONEDCPP"
#define VERSIONEDCPPDRV_Major       1
#define VERSIONEDCPPDRV_Minor       0

#define DEVICE_CLASS CVersionedCppDriver

#include "ObjDriver.h"

class CVersionedCppDriver : public CObjDriver
{
public:
	virtual IOSTATUS	OnLoad();
	virtual VOID		OnUnLoad();

	//////////////////////////////////////////////////////
	// VxD-Services exported by this driver
	static unsigned long	_cdecl VERSIONEDCPPDRV_GetVersion();
	//////////////////////////////////////////////////////
	
};

Begin_VxD_Service_Table(VERSIONEDCPPDRV)
	VxD_Service( VERSIONEDCPPDRV_GetVersion )
End_VxD_Service_Table


#endif // ifndef __VERSIONEDCPPDRIVER_H__