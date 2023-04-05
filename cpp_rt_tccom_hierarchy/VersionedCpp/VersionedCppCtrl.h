///////////////////////////////////////////////////////////////////////////////
// VersionedCppCtrl.h

#ifndef __VERSIONEDCPPCTRL_H__
#define __VERSIONEDCPPCTRL_H__

#include <atlbase.h>
#include <atlcom.h>


#include "resource.h"       // main symbols
#include "VersionedCppW32.h"
#include "TcBase.h"
#include "VersionedCppClassFactory.h"
#include "TcOCFCtrlImpl.h"

class CVersionedCppCtrl 
	: public CComObjectRootEx<CComMultiThreadModel>
	, public CComCoClass<CVersionedCppCtrl, &CLSID_VersionedCppCtrl>
	, public IVersionedCppCtrl
	, public ITcOCFCtrlImpl<CVersionedCppCtrl, CVersionedCppClassFactory>
{
public:
	CVersionedCppCtrl();
	virtual ~CVersionedCppCtrl();

DECLARE_REGISTRY_RESOURCEID(IDR_VERSIONEDCPPCTRL)
DECLARE_NOT_AGGREGATABLE(CVersionedCppCtrl)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CVersionedCppCtrl)
	COM_INTERFACE_ENTRY(IVersionedCppCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl2)
END_COM_MAP()

};

#endif // #ifndef __VERSIONEDCPPCTRL_H__
