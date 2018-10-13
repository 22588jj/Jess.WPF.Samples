// KillHorse.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "360DEMO.h"
#include "KillHorse.h"
#include "Patient.h"
#include "360DEMODlg.h"
#include "KillHorse.h"


// CKillHorse �Ի���

IMPLEMENT_DYNAMIC(CKillHorse, CDialog)

CKillHorse::CKillHorse(CWnd* pParent /*=NULL*/)
	: CDialog(CKillHorse::IDD, pParent)
{
   m_pIDirectUI = NULL;
   m_pBtnQiuckScan = NULL;
   m_pBtnAllScan = NULL;
   m_pBtnCustomScan = NULL;
   m_pMainDlg = NULL;
   m_bCustomCreat = false;
}

CKillHorse::~CKillHorse()
{
}

void CKillHorse::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CKillHorse, CDialog)
	ON_WM_CREATE()
    ON_MESSAGE(DUISM_LBUTTONUP,OnDUILButtonUp)
END_MESSAGE_MAP()


// CKillHorse ��Ϣ�������

int CKillHorse::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	m_pIDirectUI =(IDirectUI*) theApp.m_pDUIRes->CreateDirectUI(_T("KillHorse"),(long)HandleToLong(GetSafeHwnd()));
	m_pBtnStart = (ICmdButton*)m_pIDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("StarBtn"),TRUE);
	m_pBtnQiuckScan = (ICmdButton*)m_pIDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("ShortScanBtn"),TRUE);
	m_pBtnAllScan = (ICmdButton*)m_pIDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("ScanBtn"),TRUE);
	m_pBtnCustomScan = (ICmdButton*)m_pIDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("CustomBtn"),TRUE);
	m_pMainDlg = (CMy360DEMODlg*)theApp.m_pMainWnd;
	m_pKillHorse =(CKillHorse*) GetSafeHwnd();
	return 0;
}
LRESULT CKillHorse::OnDUILButtonUp(WPARAM wparam,LPARAM lparam)
{
	IDUIControlBase* pCtrol = (IDUIControlBase*)wparam;
	if (pCtrol == m_pBtnStart) //�������￪ʼ��ť
	{
		if (m_Otpatient.GetSafeHwnd()==NULL)
		{
			m_Otpatient.Create(CPatient::IDD,GetDesktopWindow());
			m_Otpatient.ShowWindow(SW_SHOW);
		}
		else
		{
			m_Otpatient.DestroyWindow();
			m_Otpatient.Create(CPatient::IDD,GetDesktopWindow());
			m_Otpatient.ShowWindow(SW_SHOW);
		}
	
	}
	else if (pCtrol == m_pBtnQiuckScan) //���ٲ�ɱ��ť
	{
 		m_Custom.Create(CCustomForm::IDD,this->GetParent());
 		m_pMainDlg->m_pHwndObjBody->Attach((OLE_HANDLE)HandleToLong(m_Custom.GetSafeHwnd()));
 		m_pMainDlg->m_pHwndObjBody->ShowWindow((OLE_HANDLE)HandleToLong(m_Custom.GetSafeHwnd()));
		m_bCustomCreat = true;
	}
	else if (pCtrol == m_pBtnAllScan)//ȫ�̲�ɱ��ť
	{
 		m_Custom.Create(CCustomForm::IDD,this->GetParent());
 		m_pMainDlg->m_pHwndObjBody->Attach((OLE_HANDLE)HandleToLong(m_Custom.GetSafeHwnd()));
 		m_pMainDlg->m_pHwndObjBody->ShowWindow((OLE_HANDLE)HandleToLong(m_Custom.GetSafeHwnd()));
		m_bCustomCreat = true;
	}
	else if (pCtrol == m_pBtnCustomScan)//�Զ����ɱ��ť
	{
 		m_Custom.Create(CCustomForm::IDD,this->GetParent());
 		m_pMainDlg->m_pHwndObjBody->Attach((OLE_HANDLE)HandleToLong(m_Custom.GetSafeHwnd()));
 		m_pMainDlg->m_pHwndObjBody->ShowWindow((OLE_HANDLE)HandleToLong(m_Custom.GetSafeHwnd()));
		m_bCustomCreat = true;
	}
	return TRUE;

}
void CKillHorse::OnOK()
{

}
void CKillHorse::OnCancel()
{

}
