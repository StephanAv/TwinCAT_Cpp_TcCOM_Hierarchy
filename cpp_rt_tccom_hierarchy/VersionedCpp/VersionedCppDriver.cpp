///////////////////////////////////////////////////////////////////////////////
// VersionedCppDriver.cpp
#include "TcPch.h"
#pragma hdrstop

#include "VersionedCppDriver.h"
#include "VersionedCppClassFactory.h"

DECLARE_GENERIC_DEVICE(VERSIONEDCPPDRV)

IOSTATUS CVersionedCppDriver::OnLoad( )
{
	TRACE(_T("CObjClassFactory::OnLoad()\n") );
	m_pObjClassFactory = new CVersionedCppClassFactory();

	return IOSTATUS_SUCCESS;
}

VOID CVersionedCppDriver::OnUnLoad( )
{
	delete m_pObjClassFactory;
}

unsigned long _cdecl CVersionedCppDriver::VERSIONEDCPPDRV_GetVersion( )
{
	return( (VERSIONEDCPPDRV_Major << 8) | VERSIONEDCPPDRV_Minor );
}

