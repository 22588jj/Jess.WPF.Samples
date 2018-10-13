// Tab2Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "360Demo.h"
#include "Tab2Dlg.h"




// CTab2Dlg �Ի���

IMPLEMENT_DYNAMIC(CTab2Dlg, CDialog)

CTab2Dlg::CTab2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTab2Dlg::IDD, pParent)
	, m_pListView(NULL)
{

}

CTab2Dlg::~CTab2Dlg()
{
}

void CTab2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTab2Dlg, CDialog)
	ON_WM_CREATE()
	ON_MESSAGE(DUISM_LBUTTONUP,OnSMLButtonUp)
END_MESSAGE_MAP()


// CTab2Dlg ��Ϣ�������

int CTab2Dlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	m_pDirectUI = (IDirectUI*)theApp.m_pDUIRes->CreateDirectUI(L"FillHole",HandleToLong(m_hWnd));
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_pDirectUI = (IDirectUI*)theApp.m_pDUIRes->CreateDirectUI(L"FillHole",HandleToLong(m_hWnd));
	m_pListView = (IDUIListView*)DIRECTUI_GETCONTROL(L"CheckReport");

	m_pListView->InsertColumn(0,L"���س̶�",80);
	m_pListView->InsertColumn(1,L"΢������",80);
	m_pListView->InsertColumn(2,L"��������",150);
	m_pListView->InsertColumn(3,L"����ʱ��",100);
	m_pListView->InsertColumn(4,L"״̬",60);

	for (int nLoop = 0; nLoop < 3; ++nLoop) 
	{
		// ����Item����
		m_pListView->InsertItem(0 + nLoop * 4, L"����", FALSE);	
		m_pListView->InsertItem(1 + nLoop * 4, L"�е�", FALSE);		
		m_pListView->InsertItem(2 + nLoop * 4, L"����", FALSE);
		m_pListView->InsertItem(3 + nLoop * 4, L"������", FALSE);
	}

	// ���õ�һ�еĶ��뷽ʽ
	IDUILVColumn* pColItem = m_pListView->GetColumn(0);
	pColItem->SetAlignMode(UNITITEM_HORZ_CENTER,UNITITEM_VERT_CENTER);

	for (int nLoop = 0; nLoop < 12; ++nLoop) 
	{
		m_pListView->SetItemText(nLoop, 1, L"KB942288", FALSE);

		m_pListView->AppendItemText(nLoop, 2, L"Windows ���³���", L"", FALSE);

		m_pListView->AppendItemText(nLoop, 3, L"2010-02-02", L"", FALSE);
		// ���ó������İ�
		m_pListView->AppendItemText(nLoop, 4, L"��װ����", L"mailto:uipower@uipower.com", FALSE);
	}

	m_pHideBtn = (IDUICheckBox*)DIRECTUI_GETCONTROL(L"CheckHideBtn");

	m_pRightForm = (IUIFormObj*)DIRECTUI_GETCONTROL(L"RightForm");
	m_pLeftForm =  (IUIFormObj*)DIRECTUI_GETCONTROL(L"CheckReport");

	m_pSplitBar =  (IDUISplitter*)DIRECTUI_GETCONTROL(L"SplitterBar1");


	return 0;
}
LRESULT CTab2Dlg::OnSMLButtonUp(WPARAM wParam,LPARAM lParam)
{
	IDUIControlBase *pControlBase = (IDUIControlBase*)wParam;
	LONG nValue = 0;

	static int nRight = 0;

	if (pControlBase)
	{	
		if (pControlBase == (IDUIControlBase*)m_pHideBtn)
		{
			nValue = m_pHideBtn->GetValue();

			if (nValue == DUICHECKBOX_CHECKED)
			{
				IDUIPos* pPos = NULL;
				DUIPosition pos;
				pPos = (IDUIPos*)m_pLeftForm->GetPosition();
				pos = pPos->GetPosStruct();
				nRight = pos.horzPos.nWidth_Height;
		 
				pos.horzPos.nWidth_Height = 8;
				pPos->SetPosStruct(pos);
				m_pLeftForm->SetPosition((IDUIPos*)pPos);

				pPos = (IDUIPos*)m_pSplitBar->GetPosition();
				pos = pPos->GetPosStruct();
				pos.horzPos.nRight_Bottom = 0;
				pPos->SetPosStruct(pos);
				m_pSplitBar->SetPosition((IDUIPos*)pPos);

				m_pSplitBar->SetSplitterHorzMin(20,0);

				m_pRightForm->SetVisible(FALSE, TRUE, FALSE);
				m_pDirectUI->ResizeThis();
				m_pDirectUI->DirectDraw(TRUE);
			}
			else
			{
				IDUIPos* pPos = NULL;
				DUIPosition pos;

				pPos = (IDUIPos*)m_pSplitBar->GetPosition();
				pos = pPos->GetPosStruct();
				pos.horzPos.nRight_Bottom = nRight - 8;
				pPos->SetPosStruct(pos);
				m_pSplitBar->SetPosition((IDUIPos*)pPos);
				m_pSplitBar->SetSplitterHorzMin(20,20);

				pPos = (IDUIPos*)m_pLeftForm->GetPosition();
				pos = pPos->GetPosStruct();
				pos.horzPos.nWidth_Height = nRight;
				//pos.horzPos.nAlignType = PHAT_RIGHT;
				pPos->SetPosStruct(pos);

				m_pLeftForm->SetPosition((IDUIPos*)pPos);

				m_pRightForm->SetVisible(TRUE, TRUE, FALSE);

				m_pDirectUI->ResizeThis();
				m_pDirectUI->DirectDraw(TRUE);
			}
		}
	

	return 0;
}