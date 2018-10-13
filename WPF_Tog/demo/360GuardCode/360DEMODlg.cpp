// 360DEMODlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "360DEMO.h"
#include "360DEMODlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CMy360DEMODlg �Ի���




CMy360DEMODlg::CMy360DEMODlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy360DEMODlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pDirectUI = NULL;
	m_pBtnClose = NULL;
	m_pCheckMax = NULL;
	m_pBtnMin = NULL;
	m_pBtnMenu = NULL;
	m_pBtnSkin = NULL;
	m_pHwndObjBody = NULL;
	m_pBtnIcon = NULL;
	m_pMenuMainMenu = NULL;

	m_pRadioHealCheck = NULL;
	m_pRadioKillHorse = NULL;
	m_pRadioClearCard = NULL;
	m_pRadioFillHole = NULL;
	m_pRadioSysRepair = NULL;
	m_pRadioComputeClear = NULL;
	m_pRadioFunction = NULL;
	m_pButtonOptatient = NULL;


}

void CMy360DEMODlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy360DEMODlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_CREATE()
	ON_MESSAGE(DUISM_LBUTTONUP, OnDUILButtonUP)
	ON_MESSAGE(DUISM_LBUTTONDBCLICK,OnDUILButtonDBClick)
	
END_MESSAGE_MAP()


// CMy360DEMODlg ��Ϣ�������

BOOL CMy360DEMODlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMy360DEMODlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMy360DEMODlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ��������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù����ʾ��
//
HCURSOR CMy360DEMODlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


int CMy360DEMODlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������

	//ϵͳ��ť�ļ���
	m_pDirectUI = (IDirectUI*)theApp.m_pDUIRes->CreateDirectUI(_T("Main"),(long)HandleToLong(GetSafeHwnd()));
	m_pBtnClose = (ICmdButton*)m_pDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("CloseBtn"),TRUE);
	m_pBtnMin = (ICmdButton*)m_pDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("MinBtn"),TRUE);
	m_pCheckMax = (IDUICheckBox*)m_pDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("MaxBx"),TRUE);
	m_pBtnIcon = (ICmdButton*)m_pDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("IconBtn"),TRUE);
	m_pBtnSkin = (ICmdButton*)m_pDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("SkillBtn"),TRUE);
	m_pBtnMenu = (ICmdButton*)m_pDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("MenuBtn"),TRUE);
    //���ܰ�ť�ļ���
    m_pRadioHealCheck =(RadioBox*)m_pDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("CheckRadio"),TRUE);
    m_pRadioKillHorse=(RadioBox*)m_pDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("CockRadio"),TRUE);
    m_pRadioClearCard=(RadioBox*)m_pDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("ClearRadio"),TRUE);
    m_pRadioFillHole=(RadioBox*)m_pDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("RehabRadio"),TRUE);
    m_pRadioSysRepair=(RadioBox*)m_pDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("RepairRadio"),TRUE);
    m_pRadioComputeClear=(RadioBox*)m_pDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("ComClear"),TRUE);
    m_pRadioFunction=(RadioBox*)m_pDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("FunctionRadio"),TRUE);
    m_pButtonOptatient=(ICmdButton*)m_pDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("ButtonOptatient"),TRUE);
   //�������ܰ�ť��Ӧ�Ľ������
	m_HealCheck.Create(CHealCheck::IDD,this);
	m_KillHorse.Create(CKillHorse::IDD,this);
	m_ClearCard.Create(CClearCard::IDD,this);
	m_FillHole.Create(CFillHole::IDD,this);
	m_SysRepair.Create(CRepair::IDD,this);
	m_CputerClear.Create(CCputerClear::IDD,this);
	m_Function.Create(CFunction::IDD,this);
	m_ReplaceSkin.Create(CReplaceSkin::IDD,this);
	
	//��HWNDOBJ����
	m_pHwndObjBody = (IDUIHwndObj*)m_pDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("HwndObjBody"),TRUE);
	m_pHwndObjBody->Attach((OLE_HANDLE)HandleToLong(m_HealCheck.GetSafeHwnd()));
 	m_pHwndObjBody->Attach((OLE_HANDLE)HandleToLong(m_KillHorse.GetSafeHwnd()));
	m_pHwndObjBody->Attach((OLE_HANDLE)HandleToLong(m_ClearCard.GetSafeHwnd()));
	m_pHwndObjBody->Attach((OLE_HANDLE)HandleToLong(m_FillHole.GetSafeHwnd()));
	m_pHwndObjBody->Attach((OLE_HANDLE)HandleToLong(m_SysRepair.GetSafeHwnd()));
	m_pHwndObjBody->Attach((OLE_HANDLE)HandleToLong(m_CputerClear.GetSafeHwnd()));
	m_pHwndObjBody->Attach((OLE_HANDLE)HandleToLong(m_Function.GetSafeHwnd()));
	m_pHwndObjBody->Attach((OLE_HANDLE)HandleToLong(m_Custom.GetSafeHwnd()));
	m_pHwndObjBody->ShowWindow((OLE_HANDLE)HandleToLong(m_HealCheck.GetSafeHwnd()));

	m_pMenuMainMenu = (IDUIPopupMenu*)theApp.m_pDUIRes->GetResObject(DUIOBJTYPE_PLUGIN,_T("MainMenu"),NULL,true);
	m_pMenuMainMenu->SetUseStandardMenu(true);
	SetWindowText(_T("360��ȫ��ʿ"));

	

	return 0;
}
LRESULT CMy360DEMODlg::OnDUILButtonUP(WPARAM wparam,LPARAM lparam)
{
	
	/*m_ReplaceSkin.ShowWindow(SW_HIDE);*/

	IDUIControlBase* pCtrol =  (IDUIControlBase*) wparam;
	if (pCtrol == NULL)
	{
		return 0;
	}
	else if (pCtrol == m_pBtnClose)
	{
		OnCancel();
	}
	else if (pCtrol == m_pBtnMin)
	{
		ShowWindow(SW_MINIMIZE);
	}
	else if (pCtrol == m_pCheckMax)
	{
		DUICHECKBOX_VALUE evalue=m_pCheckMax->GetValue();
		if (evalue == DUICHECKBOX_CHECKED)
		{
			ShowWindow(SW_MAXIMIZE);
		}
		else 
		{
			ShowWindow(SW_RESTORE);
		}
	}
	else if (pCtrol == (IDUIControlBase*)m_pBtnSkin)
	{
// 		IDUIRect*  IDUIrc;
// 		IDUIrc = m_pBtnSkin->GetRect();
// 		IDUIrc->bottom;
// 		CRect rc;
// 		m_ReplaceSkin.GetWindowRect(&rc);	
// 		m_ReplaceSkin.SetWindowPos(NULL,IDUIrc->right-rc.WIDth(),IDUIrc->bottom,0,0,SWP_NOSIZE);
// 		m_ReplaceSkin.ShowWindow(SW_SHOW);
	}
	else if (pCtrol == (IDUIControlBase*)m_pBtnIcon)
	{
		CString strURL = _T("www.360.cn");
		ShellExecute(NULL, _T("open"), strURL, NULL, NULL, SW_SHOW);
	}
    else if (pCtrol == (IDUIControlBase*)m_pBtnMenu)
    {
		IDUIRect *pDUIRect = pCtrol->GetRect();
		CPoint pt(pDUIRect->left,pDUIRect->bottom);
		::ClientToScreen(m_hWnd,&pt);
		m_pMenuMainMenu->TrackPopupMenu(DUI_TPM_LEFTALIGN,pt.x,pt.y,(OLE_HANDLE)HandleToLong(m_hWnd));
    }

	else if (pCtrol == (IDUIControlBase*)m_pRadioHealCheck)
	{
		m_pHwndObjBody->ShowWindow((OLE_HANDLE)HandleToLong(m_HealCheck.GetSafeHwnd()));
	   
	}
	
 	else if (pCtrol ==(IDUIControlBase*)m_pRadioKillHorse)
 	{
		if (!m_KillHorse.m_bCustomCreat )
		{
			   	m_pHwndObjBody->ShowWindow((OLE_HANDLE)HandleToLong(m_KillHorse.GetSafeHwnd()));
		}
		else if (m_KillHorse.m_bCustomCreat)
		{
			m_pHwndObjBody->ShowWindow((OLE_HANDLE)HandleToLong(m_KillHorse.m_Custom.GetSafeHwnd()));
		}
	}
	else if (pCtrol ==(IDUIControlBase*) m_pRadioClearCard)
	{
		m_pHwndObjBody->ShowWindow((OLE_HANDLE)HandleToLong(m_ClearCard.GetSafeHwnd()));
	}
	else if (pCtrol == (IDUIControlBase*)m_pRadioFillHole)
	{
		m_pHwndObjBody->ShowWindow((OLE_HANDLE)HandleToLong(m_FillHole.GetSafeHwnd()));
		m_FillHole.BeginFillHole();
	}
	else if (pCtrol == (IDUIControlBase*)m_pRadioSysRepair)
	{
		m_pHwndObjBody->ShowWindow((OLE_HANDLE)HandleToLong(m_SysRepair.GetSafeHwnd()));
	}
	else if (pCtrol == (IDUIControlBase*)m_pRadioComputeClear)
	{
		m_pHwndObjBody->ShowWindow((OLE_HANDLE)HandleToLong(m_CputerClear.GetSafeHwnd()));
	}
	else if (pCtrol == (IDUIControlBase*)m_pRadioFunction)
	{
		m_pHwndObjBody->ShowWindow((OLE_HANDLE)HandleToLong(m_Function.GetSafeHwnd()));
	
	}
	else if (pCtrol  == (IDUIControlBase*)m_pButtonOptatient)
	{
	
	}

	return true;
}
LRESULT CMy360DEMODlg::OnDUILButtonDBClick(WPARAM wparam,LPARAM lparam)
{
    IDUIControlBase* pCtrol = (IDUIControlBase*)wparam;
	if (pCtrol->IsDragabled())
	{
		if (this->IsZoomed())
		{
			ShowWindow(SW_NORMAL);
			m_pCheckMax->SetValue(DUICHECKBOX_UNCHECKED);
		}
		else
		{
			ShowWindow(SW_MAXIMIZE);
			m_pCheckMax->SetValue(DUICHECKBOX_CHECKED);
		}
		
	}

	return true;
	

}