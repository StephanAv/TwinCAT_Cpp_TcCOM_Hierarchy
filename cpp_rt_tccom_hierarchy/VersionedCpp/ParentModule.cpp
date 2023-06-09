///////////////////////////////////////////////////////////////////////////////
// ParentModule.cpp
#include "TcPch.h"
#pragma hdrstop

#include "ParentModule.h"
#include "VersionedCppVersion.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
DEFINE_THIS_FILE()

///////////////////////////////////////////////////////////////////////////////
// CParentModule
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Collection of interfaces implemented by module CParentModule
BEGIN_INTERFACE_MAP(CParentModule)
	INTERFACE_ENTRY_ITCOMOBJECT()
	INTERFACE_ENTRY(IID_ITcADI, ITcADI)
	INTERFACE_ENTRY(IID_ITcWatchSource, ITcWatchSource)
///<AutoGeneratedContent id="InterfaceMap">
	INTERFACE_ENTRY(IID_ITcCyclic, ITcCyclic)
	INTERFACE_ENTRY(IID_I_ParentRegister, I_ParentRegister)
///</AutoGeneratedContent>
END_INTERFACE_MAP()

IMPLEMENT_IPERSIST_LIB(CParentModule, VID_VersionedCpp, CID_VersionedCppCParentModule)
IMPLEMENT_ITCOMOBJECT(CParentModule)
IMPLEMENT_ITCOMOBJECT_SETSTATE_LOCKOP2(CParentModule)
IMPLEMENT_ITCADI(CParentModule)
IMPLEMENT_ITCWATCHSOURCE(CParentModule)

///////////////////////////////////////////////////////////////////////////////
// Set parameters of CParentModule 
BEGIN_SETOBJPARA_MAP(CParentModule)
	SETOBJPARA_DATAAREA_MAP()
///<AutoGeneratedContent id="SetObjectParameterMap">
	SETOBJPARA_VALUE(PID_TcTraceLevel, m_TraceLevelMax)
	SETOBJPARA_ITFPTR(PID_Ctx_TaskOid, m_spCyclicCaller)
///</AutoGeneratedContent>
END_SETOBJPARA_MAP()

///////////////////////////////////////////////////////////////////////////////
// Get parameters of CParentModule 
BEGIN_GETOBJPARA_MAP(CParentModule)
	GETOBJPARA_DATAAREA_MAP()
///<AutoGeneratedContent id="GetObjectParameterMap">
	GETOBJPARA_VALUE(PID_TcTraceLevel, m_TraceLevelMax)
	GETOBJPARA_ITFPTR(PID_Ctx_TaskOid, m_spCyclicCaller)
///</AutoGeneratedContent>
END_GETOBJPARA_MAP()

///////////////////////////////////////////////////////////////////////////////
// Get watch entries of CParentModule
BEGIN_OBJPARAWATCH_MAP(CParentModule)
	OBJPARAWATCH_DATAAREA_MAP()
///<AutoGeneratedContent id="ObjectParameterWatchMap">
///</AutoGeneratedContent>
END_OBJPARAWATCH_MAP()

///////////////////////////////////////////////////////////////////////////////
// Get data area members of CParentModule
BEGIN_OBJDATAAREA_MAP(CParentModule)
///<AutoGeneratedContent id="ObjectDataAreaMap">
///</AutoGeneratedContent>
END_OBJDATAAREA_MAP()


///////////////////////////////////////////////////////////////////////////////
CParentModule::CParentModule()
	: m_Trace(m_TraceLevelMax, m_spSrv)
	, m_counter(0)
{
///<AutoGeneratedContent id="MemberInitialization">
	m_TraceLevelMax = tlAlways;
///</AutoGeneratedContent>
}

///////////////////////////////////////////////////////////////////////////////
CParentModule::~CParentModule() 
{
}


///////////////////////////////////////////////////////////////////////////////
// State Transitions 
///////////////////////////////////////////////////////////////////////////////
IMPLEMENT_ITCOMOBJECT_SETOBJSTATE_IP_PI(CParentModule)

///////////////////////////////////////////////////////////////////////////////
// State transition from PREOP to SAFEOP
//
// Initialize input parameters 
// Allocate memory
HRESULT CParentModule::SetObjStatePS(PTComInitDataHdr pInitData)
{
	m_Trace.Log(tlVerbose, FENTERA);

	HRESULT hr = S_OK;
	IMPLEMENT_ITCOMOBJECT_EVALUATE_INITDATA(pInitData);

	m_Trace.Log(tlVerbose, FLEAVEA "hr=0x%08x", hr);
	return hr;
}

///////////////////////////////////////////////////////////////////////////////
// State transition from SAFEOP to OP
//
// Register with other TwinCAT objects
HRESULT CParentModule::SetObjStateSO()
{
	m_Trace.Log(tlVerbose, FENTERA);
	HRESULT hr = S_OK;

	// TODO: Add any additional initialization


	// If following call is successful the CycleUpdate method will be called, 
	// possibly even before this method has been left.
	hr = FAILED(hr) ? hr : AddModuleToCaller(); 

	// Cleanup if transition failed at some stage
	if ( FAILED(hr) )
	{
		RemoveModuleFromCaller(); 
	}
	m_Trace.Log(tlVerbose, FLEAVEA "hr=0x%08x", hr);
	return hr;
}

///////////////////////////////////////////////////////////////////////////////
// State transition from OP to SAFEOP
HRESULT CParentModule::SetObjStateOS()
{
	m_Trace.Log(tlVerbose, FENTERA);
	HRESULT hr = S_OK;

	RemoveModuleFromCaller(); 

	m_Trace.Log(tlVerbose, FLEAVEA "hr=0x%08x", hr);
	return hr;
}

///////////////////////////////////////////////////////////////////////////////
// State transition from SAFEOP to PREOP
HRESULT CParentModule::SetObjStateSP()
{
	m_Trace.Log(tlVerbose, FENTERA);
	HRESULT hr = S_OK;

	m_Trace.Log(tlVerbose, FLEAVEA "hr=0x%08x", hr);
	return hr;
}

///<AutoGeneratedContent id="ImplementationOf_ITcCyclic">
HRESULT CParentModule::CycleUpdate(ITcTask* ipTask, ITcUnknown* ipCaller, ULONG_PTR context)
{
	HRESULT hr = S_OK;

	for (auto& child : m_vChildIncrement)
	{
		child->Increment();
	}
	m_counter++;

	return hr;
}
///</AutoGeneratedContent>

///////////////////////////////////////////////////////////////////////////////
HRESULT CParentModule::AddModuleToCaller()
{
	m_Trace.Log(tlVerbose, FENTERA);
	HRESULT hr = S_OK;
	if ( m_spCyclicCaller.HasOID() )
	{
		if ( SUCCEEDED_DBG(hr = m_spSrv->TcQuerySmartObjectInterface(m_spCyclicCaller)) )
		{
			if ( FAILED(hr = m_spCyclicCaller->AddModule(m_spCyclicCaller, THIS_CAST(ITcCyclic))) )
			{
				m_spCyclicCaller = NULL;
			}
		}
	}
	else
	{
		hr = ADS_E_INVALIDOBJID; 
		SUCCEEDED_DBGT(hr, "Invalid OID specified for caller task");
	}
	m_Trace.Log(tlVerbose, FLEAVEA "hr=0x%08x", hr);
	return hr;
}

///////////////////////////////////////////////////////////////////////////////
VOID CParentModule::RemoveModuleFromCaller()
{
	m_Trace.Log(tlVerbose, FENTERA);
	if ( m_spCyclicCaller )
	{
		m_spCyclicCaller->RemoveModule(m_spCyclicCaller);
	}
	m_spCyclicCaller	= NULL;
	m_Trace.Log(tlVerbose, FLEAVEA);
}


///<AutoGeneratedContent id="ImplementationOf_I_ParentRegister">
HRESULT CParentModule::Register(ITComObject* iPtrChild)
{
	HRESULT hr = S_OK;
	if (iPtrChild) {
		OTCID idChild = 0;

		if ( FAILED( hr = iPtrChild->TcGetObjectId(idChild) ))
		{
			return hr;
		}

		I_ChildIncrementPtr spChildIncrement = idChild;

		char objectName[50];

		if (FAILED(hr = iPtrChild->TcGetObjectName(objectName, sizeof(objectName))))
		{
			m_Trace.Log(tlWarning, FNAMEA "Cannot retrieve object name");
		}


		if (FAILED(hr = m_spSrv->TcQuerySmartObjectInterface(spChildIncrement)))
		{
			m_Trace.Log(tlWarning, FNAMEA "%s Does not implement I_ChildIncrement", objectName);
			return hr;
		}
		else {
			m_Trace.Log(tlInfo, FNAMEA "%s successfully registered", objectName);
			m_vChildIncrement.push_back(spChildIncrement);
		}
	}
	return hr;
}
///</AutoGeneratedContent>