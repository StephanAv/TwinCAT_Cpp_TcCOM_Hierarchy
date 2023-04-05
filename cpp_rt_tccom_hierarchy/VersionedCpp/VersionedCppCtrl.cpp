// VersionedCppCtrl.cpp : Implementation of CTcVersionedCppCtrl
#include "TcPch.h"
#pragma hdrstop

#include "VersionedCppW32.h"
#include "VersionedCppCtrl.h"

/////////////////////////////////////////////////////////////////////////////
// CVersionedCppCtrl

CVersionedCppCtrl::CVersionedCppCtrl() 
	: ITcOCFCtrlImpl<CVersionedCppCtrl, CVersionedCppClassFactory>() 
{
}

CVersionedCppCtrl::~CVersionedCppCtrl()
{
}

