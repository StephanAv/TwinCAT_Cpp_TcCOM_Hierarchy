///////////////////////////////////////////////////////////////////////////////
// ChildModule.cpp
#include "TcPch.h"
#pragma hdrstop

#include "ChildModule.h"
#include "VersionedCppVersion.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
DEFINE_THIS_FILE()

///////////////////////////////////////////////////////////////////////////////
// Collection of interfaces implemented by module CChildModule
BEGIN_INTERFACE_MAP(CChildModule)
	INTERFACE_ENTRY_ITCOMOBJECT()
	INTERFACE_ENTRY(IID_ITcADI, ITcADI)
	INTERFACE_ENTRY(IID_ITcWatchSource, ITcWatchSource)
///<AutoGeneratedContent id="InterfaceMap">
	INTERFACE_ENTRY(IID_I_ChildIncrement, I_ChildIncrement)
///</AutoGeneratedContent>
END_INTERFACE_MAP()

IMPLEMENT_IPERSIST_LIB(CChildModule, VID_VersionedCpp, CID_VersionedCppCChildModule)
IMPLEMENT_ITCOMOBJECT(CChildModule)
IMPLEMENT_ITCOMOBJECT_SETSTATE_LOCKOP2(CChildModule)
IMPLEMENT_ITCADI(CChildModule)
IMPLEMENT_ITCWATCHSOURCE(CChildModule)

///////////////////////////////////////////////////////////////////////////////
// Set parameters of CChildModule 
BEGIN_SETOBJPARA_MAP(CChildModule)
	SETOBJPARA_DATAAREA_MAP()
///<AutoGeneratedContent id="SetObjectParameterMap">
///</AutoGeneratedContent>
END_SETOBJPARA_MAP()

///////////////////////////////////////////////////////////////////////////////
// Get parameters of CChildModule 
BEGIN_GETOBJPARA_MAP(CChildModule)
	GETOBJPARA_DATAAREA_MAP()
///<AutoGeneratedContent id="GetObjectParameterMap">
///</AutoGeneratedContent>
END_GETOBJPARA_MAP()

///////////////////////////////////////////////////////////////////////////////
// Get watch entries of CChildModule
BEGIN_OBJPARAWATCH_MAP(CChildModule)
	OBJPARAWATCH_DATAAREA_MAP()
///<AutoGeneratedContent id="ObjectParameterWatchMap">
///</AutoGeneratedContent>
END_OBJPARAWATCH_MAP()

///////////////////////////////////////////////////////////////////////////////
// Get data area members of CChildModule
BEGIN_OBJDATAAREA_MAP(CChildModule)
///<AutoGeneratedContent id="ObjectDataAreaMap">
	OBJDATAAREA_VALUE(ADI_ChildModuleOutputs, m_Outputs)
///</AutoGeneratedContent>
END_OBJDATAAREA_MAP()


///////////////////////////////////////////////////////////////////////////////
// Constructor
CChildModule::CChildModule()
{
///<AutoGeneratedContent id="MemberInitialization">
	memset(&m_Outputs, 0, sizeof(m_Outputs));
///</AutoGeneratedContent>
}

///////////////////////////////////////////////////////////////////////////////
// Destructor
CChildModule::~CChildModule() 
{
}

///////////////////////////////////////////////////////////////////////////////
// State Transitions 
///////////////////////////////////////////////////////////////////////////////
IMPLEMENT_ITCOMOBJECT_SETOBJSTATE_IP_PI(CChildModule)

///////////////////////////////////////////////////////////////////////////////
// State transition from PREOP to SAFEOP
//
// Initialize input parameters 
// Allocate memory
HRESULT CChildModule::SetObjStatePS(PTComInitDataHdr pInitData)
{
	HRESULT hr = S_OK;
	IMPLEMENT_ITCOMOBJECT_EVALUATE_INITDATA(pInitData);
	return hr;
}

///////////////////////////////////////////////////////////////////////////////
// State transition from SAFEOP to OP
//
// Register with other TwinCAT objects
HRESULT CChildModule::SetObjStateSO()
{
	HRESULT hr = S_OK;
	if(m_parentObjId)
	{
		I_ParentRegisterPtr spParentRegister = m_parentObjId;

		if (SUCCEEDED_DBG(hr = m_spSrv->TcQuerySmartObjectInterface(spParentRegister)))
		{
			hr = spParentRegister->Register(THIS_CAST(ITComObject));
		}
	}
	return hr;
}

///////////////////////////////////////////////////////////////////////////////
// State transition from OP to SAFEOP
HRESULT CChildModule::SetObjStateOS()
{
	HRESULT hr = S_OK;
	return hr;
}

///////////////////////////////////////////////////////////////////////////////
// State transition from SAFEOP to PREOP
HRESULT CChildModule::SetObjStateSP()
{
	HRESULT hr = S_OK;
	return hr;
}

///<AutoGeneratedContent id="ImplementationOf_I_ChildIncrement">
HRESULT CChildModule::Increment()
{
	HRESULT hr = S_OK;
	m_Outputs.nCnt++;
	return hr;
}
///</AutoGeneratedContent>
