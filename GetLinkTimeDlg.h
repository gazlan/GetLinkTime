#if !defined(AFX_GETLINKTIMEDLG_H__566F869E_2648_4C9E_8BBC_331B195414A9__INCLUDED_)
#define AFX_GETLINKTIMEDLG_H__566F869E_2648_4C9E_8BBC_331B195414A9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CGetLinkTimeDlg : public CDialog
{
// Construction
public:
	CGetLinkTimeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CGetLinkTimeDlg)
	enum { IDD = IDD_GETLINKTIME };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetLinkTimeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGetLinkTimeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETLINKTIMEDLG_H__566F869E_2648_4C9E_8BBC_331B195414A9__INCLUDED_)
