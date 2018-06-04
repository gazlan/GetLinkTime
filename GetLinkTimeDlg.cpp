#include "stdafx.h"

#include "GetLinkTime.h"
#include "GetLinkTimeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

const char* const GetLinkTime()
{
   // MakePtr is a macro that allows you to easily add to values (including
   // pointers) together without dealing with C's pointer arithmetic.  It
   // essentially treats the last two parameters as DWORDs.  The first
   // parameter is used to typecast the result to the appropriate pointer type.
   #define MakePtr(cast,ptr,addValue)  (cast)((DWORD)(ptr) + (addValue))

   static char    pszTemp[MAX_PATH + 1];

   HMODULE  hModule = GetModuleHandle(NULL);

   if (!hModule)
   {	
      // Error !
      ASSERT(0);
      return NULL;
   }

   PIMAGE_DOS_HEADER    pDosHeader = (PIMAGE_DOS_HEADER)hModule;

   if (pDosHeader->e_magic != IMAGE_DOS_SIGNATURE)
   {
      // Error !
      ASSERT(0);
      return NULL;
   }
         
   PIMAGE_NT_HEADERS    pNT = MakePtr(PIMAGE_NT_HEADERS,pDosHeader,pDosHeader->e_lfanew);

   if (!pNT || IsBadReadPtr(pNT,sizeof(PIMAGE_NT_HEADERS)))
   {
      // Error !
      ASSERT(0);
      return NULL;
   }

   DWORD    dwTimestamp = pNT->FileHeader.TimeDateStamp;

   // If timer represents a date before midnight, January 1, 1970, gmtime returns NULL
   struct tm*     pTS = gmtime((long*)(&dwTimestamp));

   if (!pTS)
   {	
      // Error !
      ASSERT(0);
      return NULL;
   }

   wsprintf(pszTemp,"   *   %04d-%02d-%02d | %02d:%02d:%02d",pTS->tm_year + 1900,pTS->tm_mon + 1,pTS->tm_mday,pTS->tm_hour,pTS->tm_min,pTS->tm_sec);

   return pszTemp;
}

CGetLinkTimeDlg::CGetLinkTimeDlg(CWnd* pParent /*=NULL*/)
:  CDialog(CGetLinkTimeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGetLinkTimeDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGetLinkTimeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGetLinkTimeDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CGetLinkTimeDlg, CDialog)
	//{{AFX_MSG_MAP(CGetLinkTimeDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CGetLinkTimeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	CenterWindow();

   SetWindowText(GetLinkTime());

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
// to draw the icon.  For MFC applications using the document/view model,
// this is automatically done for you by the framework.

void CGetLinkTimeDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
// the minimized window.
HCURSOR CGetLinkTimeDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
