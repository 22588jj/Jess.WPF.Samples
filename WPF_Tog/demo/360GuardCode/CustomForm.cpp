// CustomForm.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "360DEMO.h"
#include "CustomForm.h"
#include "360DEMODlg.h"
#include <stdlib.h>
#include <time.h>


// CCustomForm �Ի���

IMPLEMENT_DYNAMIC(CCustomForm, CDialog)

CCustomForm::CCustomForm(CWnd* pParent /*=NULL*/)
	: CDialog(CCustomForm::IDD, pParent)
{
	 m_pIDirectUI = NULL;
	 m_pMainDlg = NULL;
     m_pListView = NULL;
	 m_pBtnStop = NULL;
	 m_pBtnSuspend = NULL;
	 m_pBtnContinue = NULL;
	 m_pIcon = NULL;
	 m_pStaticText = NULL;
     m_pBtnBack = NULL;
	 m_pBtnWep = NULL;
	 m_pUIFormOutKill = NULL;
	 m_iProgressBarPos = 0;
	 m_icount = 0;
	 m_bDestroy = false;

}

CCustomForm::~CCustomForm()
{
}

void CCustomForm::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CCustomForm, CDialog)
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_WM_SIZE()
	ON_MESSAGE(DUISM_LBUTTONUP,OnDUILButtonUp)
END_MESSAGE_MAP()


// CCustomForm ��Ϣ�������

int CCustomForm::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	m_pIDirectUI = (IDirectUI*) theApp.m_pDUIRes->CreateDirectUI(_T("CustomForm"),(long)HandleToLong(GetSafeHwnd()));
	m_pMainDlg = (CMy360DEMODlg*)theApp.m_pMainWnd;
    m_pUIFormOutKill = (IUIFormObj*)m_pIDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("UIFormOut"),TRUE);
    m_pListView = (IDUIListView*)m_pIDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("ListView2"),TRUE);
    m_pTextStyle = (IDUITextStyle*)theApp.m_pDUIRes->GetResObject(DUIOBJTYPE_TEXTSTYLE,_T("ComtumTextStyle"),NULL,FALSE);
	m_pProgressBar = (IDUIProgressbar*)m_pIDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("ProgressBar1"),TRUE);
	m_pIcon = (IDUIStatic*)m_pIDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("Icon25"),TRUE);
	m_pStaticText= (IDUIStatic*)m_pIDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("Text78"),TRUE);
	m_pBtnStop = (ICmdButton*)m_pIDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("BtnStop"),TRUE);
	m_pBtnStop->SetVisible(true,true,false);
	m_pBtnSuspend= (ICmdButton*)m_pIDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("BtnSuspend"),TRUE);
	m_pBtnSuspend->SetVisible(true,true,false);
	m_pBtnContinue =  (ICmdButton*)m_pIDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("BtnContinue"),TRUE);
	m_pBtnContinue->SetVisible(false,true,false);
	m_pBtnBack = (ICmdButton*)m_pIDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("BtnBack"),TRUE);
	m_pBtnBack->SetVisible(false,true,false);
	m_pBtnWep= (ICmdButton*)m_pIDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("Button97"),TRUE);
	
	m_pListView->InsertColumn(0,_T("����ɨ�����Ŀ"),500);
	m_pListView->InsertColumn(1,_T("ɨ��ͳ��"),200);
	m_pListView->InsertColumn(2,_T("ɨ����"),300);
	for (int nLoop = 0; nLoop < 50; ++nLoop)
	{
		m_pListView->InsertItem(nLoop, L"", FALSE);
		IDUIUnitItem* pItem = m_pListView->GetUnitItem(nLoop, 0);
		pItem->SetAlignMode(UNITITEM_HORZ_LEFT, UNITITEM_VERT_CENTER);
		m_pListView->SetItemData(nLoop, (OLE_HANDLE)nLoop);
		m_pListView->AppendItemText(nLoop, 0, _T("Ĭ�ϼ��ؿ�"), _T(""), FALSE);
		m_pListView->AppendItemText(nLoop, 1, _T("�ȴ�ɨ�衭��"), _T(""), FALSE);
	}
	m_pListView->RefreshView();
	m_bDestroy = true;
	SetTimer(TIMER_SCAN,TIMER_SCAN_TIME,NULL);
	return 0;
}

void CCustomForm::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (nIDEvent == TIMER_SCAN)
	{
		m_pIcon->SetVisible(true,true,false);
		m_pStaticText->SetVisible(true,true,false);
		m_pProgressBar->SetVisible(true,false,false);
		m_pBtnStop->SetVisible(true,false,false);
		m_pListView->SetVisible(true,false,false);
		time_t t;
		srand((unsigned)time(&t));
		//����ɨ���ļ�����Ч��
	
		if (m_icount<50)
		{
			CString str;
			str.Format(_T("����ɨ��%d��"),rand());
			wstring str1 = str;
			m_pStaticText->SetText(str1);
			m_pListView->SetItemText(m_icount,1,str1,FALSE);
			m_pListView->SetItemText(m_icount, 2, _T("��ȫ"), FALSE);
			m_pListView->GetUnitItem(m_icount,2)->SetTextStyle(m_pTextStyle,DUILVI_STATE_NORMAL);
			m_pListView->GetUnitItem(m_icount,2)->SetTextStyle(m_pTextStyle,DUILVI_STATE_HOT);
			m_pListView->GetUnitItem(m_icount,2)->SetTextStyle(m_pTextStyle,DUILVI_STATE_SELECTED);
			m_pListView->RefreshView();
			m_icount++;
		}
		//���ý�����
		m_iProgressBarPos = m_iProgressBarPos+ rand()%4;
		m_pProgressBar->SetPos(m_iProgressBarPos);
	
		if (m_iProgressBarPos>100)
		{
			m_iProgressBarPos = 100;
			m_pProgressBar->SetPos(m_iProgressBarPos);
		}
		if (m_iProgressBarPos%10 == 1)
		{
			m_pStaticText->SetText(_T("����ɨ��ϵͳ�ؼ�Ŀ¼��WINDOWS\system32\adsld.dll"));
		}
		else if (m_iProgressBarPos%10 == 2)
		{
			m_pStaticText->SetText(_T("����ɨ��ϵͳ�ؼ�Ŀ¼��WINDOWS\system32\append.ll"));
		}
		else if (m_iProgressBarPos%10 ==3)
		{
			m_pStaticText->SetText(_T("����ɨ��ϵͳ�ؼ�Ŀ¼��WINDOWS\system32\spoll\drivers"));
		}
		else if (m_iProgressBarPos%10 == 4)
		{
			m_pStaticText->SetText(_T("����ɨ���ݷ�ʽ��\Program Files\360\360safe\360safe.exe")); 
		}
		else if (m_iProgressBarPos%10 == 5)
		{
			m_pStaticText->SetText(_T("���п�ܳ�������C\Program Files\NT"));
		}
		else if (m_iProgressBarPos%10 == 6)
		{
			m_pStaticText->SetText(_T("���п�ܳ�������C\Program Files\Micorsoft Office\OFFICE11"));
		}
		else if (m_iProgressBarPos%10 == 7)
		{
			m_pStaticText->SetText(_T("����ɨ��ϵͳ�ؼ�Ŀ¼��WINDOWS\system32\adsld"));
		}
		else if (m_iProgressBarPos%10 == 8)
		{
			m_pStaticText->SetText(_T("����ɨ��ϵͳ�ؼ�Ŀ¼��WINDOWS\system32\adsld"));
		}
	
        //����ɨ��
		if ((m_iProgressBarPos == 100)&&(m_icount == 50))
		{
			CString str;
			str.Format(_T("ɨ����ɣ�û�з���Σ�����ɨ��%d���ļ���%d��ע������ʱ %d ��"),rand(),rand()%rand(),m_icount);
			wstring str1 = str;
			m_pStaticText->SetText(str1);
			m_pUIFormOutKill->SetVisible(true,true,false);
			m_pBtnBack->SetVisible(true,true,false);
			m_pIcon->SetVisible(false,true,false);
			m_pProgressBar->SetVisible(false,true,false);
			m_pBtnStop->SetVisible(false,true,false);
			m_pBtnSuspend->SetVisible(false,true,false);
			m_pBtnContinue->SetVisible(false,true,false);
			m_pListView->SetVisible(false,true,false);
			m_icount = 0;
			m_iProgressBarPos = 0;

			KillTimer(TIMER_SCAN);
		}
		CDialog::OnTimer(nIDEvent);
	}
}
LRESULT CCustomForm::OnDUILButtonUp(WPARAM wparam,LPARAM lparam)
{
    IDUIControlBase*  pCtrol = (IDUIControlBase*)wparam;

	if (pCtrol == m_pBtnStop)  //ֹͣ��ɱ��ť
	{
		KillTimer(TIMER_SCAN);
	
		CString str;
		str.Format(_T("ɨ�豻��ֹ��û�з���Σ�����ɨ��%d���ļ���%d��ע������ʱ %d ��"),rand(),rand()%rand(),m_icount);
		m_iProgressBarPos = 0;
		m_icount = 0;
		wstring str1 = str;
		m_pStaticText->SetText(str1);
		m_pBtnStop->SetVisible(false,true,false);
		m_pBtnSuspend->SetVisible(false,true,false);
		m_pBtnContinue->SetVisible(false,true,false);
		m_pIcon->SetVisible(false,true,false);
		m_pProgressBar->SetVisible(false,false,true);
		m_pListView->DeleteAllItems();
		m_pListView->SetVisible(false,true,false);
		m_pUIFormOutKill->SetVisible(true,true,false);
		m_pBtnBack->SetVisible(true,true,false);
		m_bDestroy = false;
	}
	else if (pCtrol == m_pBtnSuspend)  //��ͣɨ�谴ť
	{
		KillTimer(TIMER_SCAN);
		m_pStaticText->SetText(_T("ɨ������ͣ"));
		m_pBtnSuspend->SetVisible(false,true,false);
		m_pBtnContinue->SetVisible(true,true,false);
	
	}
	else if (pCtrol == m_pBtnContinue)  //����ɨ�谴ť
	{
		SetTimer(TIMER_SCAN,TIMER_SCAN_TIME,NULL);
		m_pBtnContinue->SetVisible(false,true,false);
		m_pBtnSuspend->SetVisible(true,false,true);
	}
	else if (pCtrol == m_pBtnBack)  //���ذ�ť�����ٴ���
	{
	
		m_pUIFormOutKill->SetVisible(false,true,false);
		m_pIDirectUI = NULL;
		KillTimer(TIMER_SCAN);
		m_pMainDlg->m_pHwndObjBody->Attach((OLE_HANDLE)HandleToLong(m_pMainDlg->m_KillHorse.GetSafeHwnd()));
		m_pMainDlg->m_pHwndObjBody->ShowWindow((OLE_HANDLE)HandleToLong(m_pMainDlg->m_KillHorse.GetSafeHwnd()));
		this->DestroyWindow();
	}
	else if (pCtrol == m_pBtnWep)  //�����Ӱ�ť
	{
		CString strURL = _T("www.360.cn");
		ShellExecute(NULL, _T("open"), strURL, NULL, NULL, SW_SHOW);
	}

	return TRUE;
}
void CCustomForm::OnSize(UINT nType, int cx, int cy)
{
	if (m_pIDirectUI != NULL)
	{
		if (this->GetParent()->IsZoomed())
		{

			m_pListView->GetColumn(0)->SetColumnWidth(1000);
			m_pListView->GetColumn(1)->SetColumnWidth(200);
			m_pListView->GetColumn(2)->SetColumnWidth(300);
		}
		else
		{
			m_pListView->GetColumn(0)->SetColumnWidth(500);
			m_pListView->GetColumn(1)->SetColumnWidth(200);
			m_pListView->GetColumn(2)->SetColumnWidth(300);
		}
	}


}
void CCustomForm::OnOK()
{

}
void CCustomForm::OnCancel()
{

}
