// Function.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "360DEMO.h"
#include "Function.h"
#include <atlimage.h>
#include <Windows.h>


// CFunction �Ի���

IMPLEMENT_DYNAMIC(CFunction, CDialog)

CFunction::CFunction(CWnd* pParent /*=NULL*/)
	: CDialog(CFunction::IDD, pParent)
{
	m_pHwndObj = NULL;
	m_pFormEdit = NULL;
	m_pFormTop = NULL;
	m_pFormBody = NULL;
	m_hBitmap0 = NULL;
	m_hBitmap1 = NULL;
	m_hBitmap2 = NULL;
	m_hBitmap3 = NULL;
	m_hBitmap4 = NULL;
	m_hBitmap5 = NULL;
	m_hBitmap6 = NULL;
	m_hBitmap7 = NULL;
	m_hBitmap8 = NULL;
	m_hBitmap9 = NULL;
	m_hBitmap10 = NULL;
	m_hBitmap11 = NULL;
	m_hBitmap12 = NULL;
	m_hBitmap13 = NULL;
	m_hBitmap14 = NULL;
	m_hBitmap15 = NULL;
	m_hBitmap16 = NULL;
	m_hBitmap17 = NULL;
	m_hBitmap18 = NULL;
	m_hBitmap19 = NULL;

}

CFunction::~CFunction()
{
	if(m_hBitmap0)
	{
		DeleteObject(m_hBitmap0);
		m_hBitmap0 = NULL;
	}
	if(m_hBitmap1)
	{
		DeleteObject(m_hBitmap1);
		m_hBitmap1 = NULL;
	}
	if(m_hBitmap2)
	{
		DeleteObject(m_hBitmap2);
		m_hBitmap2 = NULL;
	}
	if(m_hBitmap3)
	{
		DeleteObject(m_hBitmap3);
		m_hBitmap3 = NULL;
	}
	if(m_hBitmap4)
	{
		DeleteObject(m_hBitmap4);
		m_hBitmap4 = NULL;
	}
	if(m_hBitmap5)
	{
		DeleteObject(m_hBitmap0);
		m_hBitmap5 = NULL;
	}
	if(m_hBitmap6)
	{
		DeleteObject(m_hBitmap6);
		m_hBitmap6= NULL;
	}
	if(m_hBitmap7)
	{
		DeleteObject(m_hBitmap7);
		m_hBitmap7 = NULL;
	}
	if(m_hBitmap8)
	{
		DeleteObject(m_hBitmap8);
		m_hBitmap8 = NULL;
	}
	if(m_hBitmap9)
	{
		DeleteObject(m_hBitmap9);
		m_hBitmap9 = NULL;
	}
	if(m_hBitmap10)
	{
		DeleteObject(m_hBitmap10);
		m_hBitmap10 = NULL;
	}
	if(m_hBitmap11)
	{
		DeleteObject(m_hBitmap11);
		m_hBitmap11 = NULL;
	}
	if(m_hBitmap12)
	{
		DeleteObject(m_hBitmap12);
		m_hBitmap12 = NULL;
	}
	if(m_hBitmap13)
	{
		DeleteObject(m_hBitmap13);
		m_hBitmap13 = NULL;
	}
	if(m_hBitmap14)
	{
		DeleteObject(m_hBitmap14);
		m_hBitmap14 = NULL;
	}
	if(m_hBitmap15)
	{
		DeleteObject(m_hBitmap15);
		m_hBitmap15 = NULL;
	}
	if(m_hBitmap16)
	{
		DeleteObject(m_hBitmap16);
		m_hBitmap16 = NULL;
	}
	if(m_hBitmap17)
	{
		DeleteObject(m_hBitmap17);
		m_hBitmap17 = NULL;
	}
	if(m_hBitmap18)
	{
		DeleteObject(m_hBitmap18);
		m_hBitmap18 = NULL;
	}
	if(m_hBitmap19)
	{
		DeleteObject(m_hBitmap19);
		m_hBitmap19 = NULL;
	}
}

void CFunction::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CFunction, CDialog)
	ON_WM_CREATE()
	ON_MESSAGE(DUISM_LBUTTONUP,OnDUILButtonUp)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


// CFunction ��Ϣ�������

int CFunction::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	m_pDirectUI = (IDirectUI*)theApp.m_pDUIRes->CreateDirectUI(_T("Functions"),(long)HandleToLong(GetSafeHwnd()));
	m_pFormBody = (IUIFormObj*)m_pDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("UIForm2"),TRUE);
	m_pFormTop = (IUIFormObj*)m_pDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("TopForm"),TRUE);
	m_pFormEdit = (IUIFormObj*)m_pDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("SearchArea"),TRUE);
	m_pHwndObj = (IDUIHwndObj*)m_pDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("HwndSearch"),TRUE);
	m_rEdit.Create(WS_CHILD|ES_AUTOHSCROLL,CRect(0,0,10,10), this, IDC_RDSEARCH_EDIT);
	m_pHwndObj->Attach((OLE_HANDLE)HandleToLong(m_rEdit.GetSafeHwnd()));

	CImage image;
	image.Load(_T("res\\Icon_01.png"));
	m_hBitmap0 = image.Detach();
	image.Load(_T("res\\Icon_02.png"));
	m_hBitmap1 = image.Detach();
	image.Load(_T("res\\Icon_03.png"));
	m_hBitmap2 = image.Detach();
	image.Load(_T("res\\Icon_04.png"));
	m_hBitmap3 = image.Detach();
	image.Load(_T("res\\Icon_05.png"));
	m_hBitmap4 = image.Detach();
	image.Load(_T("res\\Icon_06.png"));
	m_hBitmap5 = image.Detach();
	image.Load(_T("res\\Icon_07.png"));
	m_hBitmap6 = image.Detach();
	image.Load(_T("res\\Icon_08.png"));
	m_hBitmap7 = image.Detach();
	image.Load(_T("res\\Icon_09.png"));
	m_hBitmap8 = image.Detach();
	image.Load(_T("res\\Icon_10.png"));
	m_hBitmap9 = image.Detach();
	image.Load(_T("res\\Icon_11.png"));
	m_hBitmap10 = image.Detach();
	image.Load(_T("res\\Icon_12.png"));
	m_hBitmap11 = image.Detach();
	image.Load(_T("res\\Icon_13.png"));
	m_hBitmap12 = image.Detach();
	image.Load(_T("res\\Icon_14.png"));
	m_hBitmap13= image.Detach();
	image.Load(_T("res\\Icon_15.png"));
	m_hBitmap14 = image.Detach();
	image.Load(_T("res\\Icon_16.png"));
	m_hBitmap15 = image.Detach();
	//m_pListView = (IDUIListView*)m_pDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("ListViewk"),false);
	m_pListView = (IDUIListView*)DIRECTUI_GETCONTROL(L"ListView8");
	IDUITVItemGroup* pGroup = (IDUITVItemGroup*)m_pListView->AddGroup(0,_T("�¹����Ƽ�"));
	pGroup->AppendItem(0,_T("���߷�����"))->SetGraphics( DUILVI_STATE_NORMAL, (OLE_HANDLE)m_hBitmap0);
	pGroup->AppendItem(1,_T("360����ɳĮ"))->SetGraphics( DUILVI_STATE_NORMAL, (OLE_HANDLE)m_hBitmap1);
	pGroup->AppendItem(2,_T("360��������"))->SetGraphics( DUILVI_STATE_NORMAL, (OLE_HANDLE)m_hBitmap2);
	pGroup->AppendItem(3,_T("ϵͳ���ڼӹ�"))->SetGraphics( DUILVI_STATE_NORMAL, (OLE_HANDLE)m_hBitmap3);
	pGroup->AppendItem(4,_T("360���氲ȫ"))->SetGraphics( DUILVI_STATE_NORMAL, (OLE_HANDLE)m_hBitmap4);
	pGroup->SetExpand(true);
	pGroup = (IDUITVItemGroup*)m_pListView->AddGroup(1,_T("�ȶ��Ƽ�"));
	pGroup->AppendItem(0,_T("��������"))->SetGraphics( DUILVI_STATE_NORMAL, (OLE_HANDLE)m_hBitmap5);
	pGroup->AppendItem(1,_T("ǿ��ж�����"))->SetGraphics( DUILVI_STATE_NORMAL, (OLE_HANDLE)m_hBitmap6);
	pGroup->AppendItem(2,_T("360����ܼ�"))->SetGraphics( DUILVI_STATE_NORMAL, (OLE_HANDLE)m_hBitmap7);
	pGroup->AppendItem(3,_T("360ѹ��"))->SetGraphics( DUILVI_STATE_NORMAL, (OLE_HANDLE)m_hBitmap8);
	pGroup->AppendItem(4,_T("΢����ʿ"))->SetGraphics( DUILVI_STATE_NORMAL, (OLE_HANDLE)m_hBitmap9);
    pGroup->AppendItem(5,_T("360���Լ�ʦ"))->SetGraphics( DUILVI_STATE_NORMAL, (OLE_HANDLE)m_hBitmap10);
	pGroup->AppendItem(6,_T("360Ӳ����ʦ"))->SetGraphics( DUILVI_STATE_NORMAL, (OLE_HANDLE)m_hBitmap11);
	pGroup->SetExpand(true);

	pGroup = (IDUITVItemGroup*)m_pListView->AddGroup(2,_T("�����Ż�"));
 	pGroup->AppendItem(0,_T("���̹�����"))->SetGraphics( DUILVI_STATE_NORMAL, (OLE_HANDLE)m_hBitmap12);
	pGroup->AppendItem(1,_T("ϵͳ����״̬"))->SetGraphics( DUILVI_STATE_NORMAL, (OLE_HANDLE)m_hBitmap13);
    pGroup->AppendItem(2,_T("Ĭ���������"))->SetGraphics( DUILVI_STATE_NORMAL, (OLE_HANDLE)m_hBitmap14);
	pGroup->AppendItem(3,_T("�ļ������"))->SetGraphics( DUILVI_STATE_NORMAL, (OLE_HANDLE)m_hBitmap15);
	pGroup->SetExpand(true);
	m_pListView->RefreshView();
	return 0;
}
LRESULT CFunction::OnDUILButtonUp(WPARAM wparam,LPARAM lparam)
{  
	POINT   pt ;
	GetCursorPos(&pt);
	::ScreenToClient(GetSafeHwnd(),&pt);
	IDUIRect*   DUIrcEdit;
	DUIrcEdit = m_pFormEdit->GetRect();
	CRect   rcEdit;
	rcEdit.left = DUIrcEdit->left;
	rcEdit.top = DUIrcEdit->top;
	rcEdit.right = DUIrcEdit->right;
	rcEdit.bottom = DUIrcEdit->bottom;
	if (rcEdit.PtInRect(pt))
	{
		m_rEdit.ShowWindow(SW_SHOW);
	}
	return TRUE;
}
void CFunction::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
    
	CString str;
	m_rEdit.GetWindowText(str);
    POINT   pt ;
	GetCursorPos(&pt);
	::ScreenToClient(GetSafeHwnd(),&pt);
	IDUIRect*   DUIrcTop;
	DUIrcTop= m_pFormTop->GetRect();
	CRect   rcTop;
	rcTop.left = DUIrcTop->left;
	rcTop.top = DUIrcTop->top;
	rcTop.right = DUIrcTop->right;
	rcTop.bottom = DUIrcTop->bottom;
    if (!rcTop.PtInRect(pt)&&str == "")
	{
		m_rEdit.ShowWindow(SW_HIDE);
		m_rEdit.Clear();
		
	}
	CDialog::OnMouseMove(nFlags, point);
}
void CFunction::OnOK()
{
	//����ϵͳ��ONOK��Ϣ
}
void CFunction::OnCancel()
{

}
