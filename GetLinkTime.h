// GetLinkTime.h : main header file for the GETLINKTIME application
//

#if !defined(AFX_GETLINKTIME_H__F4576AD7_D964_4EA3_BB69_9A8290356F3F__INCLUDED_)
#define AFX_GETLINKTIME_H__F4576AD7_D964_4EA3_BB69_9A8290356F3F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGetLinkTimeApp:
// See GetLinkTime.cpp for the implementation of this class
//

class CGetLinkTimeApp : public CWinApp
{
public:
	CGetLinkTimeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetLinkTimeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGetLinkTimeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETLINKTIME_H__F4576AD7_D964_4EA3_BB69_9A8290356F3F__INCLUDED_)
