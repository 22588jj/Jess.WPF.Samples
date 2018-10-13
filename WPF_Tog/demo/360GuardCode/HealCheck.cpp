// HealCheck.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "360DEMO.h"
#include "HealCheck.h"
#include <stdlib.h>
#include <time.h>


// CHealCheck �Ի���

IMPLEMENT_DYNAMIC(CHealCheck, CDialog)

CHealCheck::CHealCheck(CWnd* pParent /*=NULL*/)
	: CDialog(CHealCheck::IDD, pParent)
	, m_bIsExpand(false)
{
	m_pDirectUI = NULL;
	m_pBtnStart = NULL;
	m_pCheckForm = NULL;
	m_pPreCheckForm = NULL;
	m_pProgressBarCheck = NULL;
	m_pStaticIssueCount = NULL;
	m_pStaticItemCount = NULL;	
	m_pstaticPreScor = NULL;
	m_pstaticScore= NULL;
	m_pstaticPreRemind = NULL; 
	m_pstaticNewRemind = NULL;
	m_pListVist = NULL;
	m_pBtnGhost = NULL;
	m_pStaticCheckState = NULL;
	m_pstaticNewScore = NULL;
	m_pBtnRecheck = NULL;
	m_pScaningCount = NULL;
	m_pScaningItem = NULL;
	m_pItmeStyle = NULL;
	m_pStaticStyle = NULL;
	m_iProgressBarPos = 0;
	m_nCheckItemCount = 0;
	m_iIssueItemcount = 0;
	m_nNewScore = 100;
	m_nSafeCount = 0;
	m_bGhost = false;
	
}

CHealCheck::~CHealCheck()
{
}

void CHealCheck::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CHealCheck, CDialog)
	ON_WM_CREATE()
	ON_MESSAGE(DUISM_LBUTTONUP,OnDUILButtonUP)
	ON_WM_TIMER()
	ON_WM_SIZE()
END_MESSAGE_MAP()
// CHealCheck ��Ϣ�������

int CHealCheck::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
    // TODO:  �ڴ������ר�õĴ�������
	m_pDirectUI = (IDirectUI*)theApp.m_pDUIRes->CreateDirectUI(_T("HealCheck"),(long)HandleToLong(GetSafeHwnd()));
	m_pPreCheckForm = (IUIFormObj*)m_pDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("UIForm5"),TRUE);
	m_pCheckForm = (IUIFormObj*)m_pDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("TestForm"),TRUE);
	m_pBtnStart = (ICmdButton*)m_pDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("MustBtn"),TRUE);
	m_pProgressBarCheck = (IDUIProgressbar*)m_pDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("ProgressBar2"),TRUE);
	m_pStaticItemCount = (IDUIStatic*)m_pDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("Static47"),TRUE);
	m_pStaticIssueCount = (IDUIStatic*)m_pDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("Static48"),TRUE);
	m_pstaticScore = (IDUIStatic*)m_pDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("Text91"),TRUE);
	m_pstaticNewRemind = (IDUIStatic*)m_pDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("Text93"),TRUE);
	m_pListVist = (IDUIListView*)m_pDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("HealListView"),TRUE);
	m_pBtnGhost = (ICmdButton*)m_pDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("Ghost"),TRUE);
	m_pStaticCheckState = (IDUIStatic*)m_pDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("Text92"),TRUE);
	m_pstaticNewScore = (IDUIStatic*)m_pDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("Static20"),TRUE);
	m_pBtnRecheck = (ICmdButton*)m_pDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("Text94"),TRUE);
	m_pBtnCancel = (ICmdButton*)m_pDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("Button63"),TRUE);
	m_pBtnServe = (ICmdButton*)m_pDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("TextBtn3"),TRUE);
	m_pScaningText = (IDUIStatic*)m_pDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("Text93-Copy"),TRUE);
	m_pScaningCount =  (IDUIStatic*)m_pDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("StaticCount"),TRUE);
	m_pScaningItem =  (IDUIStatic*)m_pDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("Static25"),TRUE);
	//m_pItmeStyle = (IDUITextStyle*)m_pDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("FillHoleBtnPress"),TRUE);
	m_pItmeStyle = (IDUITextStyle*)theApp.m_pDUIRes->GetResObject(DUIOBJTYPE_TEXTSTYLE,_T("TextTemp"),NULL,FALSE);
	m_pStaticStyle = (IDUITextStyle*)theApp.m_pDUIRes->GetResObject(DUIOBJTYPE_TEXTSTYLE,_T("Text90"),NULL,FALSE);
	return 0;
}
LRESULT CHealCheck ::OnDUILButtonUP(WPARAM wparam,LPARAM lparam)
{
	IDUIControlBase* pCtol = (IDUIControlBase*)wparam;
	//��ʼ��ť
	if (pCtol== (IDUIControlBase*)m_pBtnStart)
	{ 
		m_bIsExpand = true;
		m_pListVist->SetVisible(true,false,false);
	   m_pstaticNewScore->SetVisible(true,true,false);
       m_pstaticNewScore->SetText(_T("100"));
	   
	   m_pBtnStart->SetVisible(false,true,false);
		SetTimer(TIMER_PROGRESS,TIMER_PROGRESS_TIME,NULL);
	}
	//��������ȡ�����
	else if (pCtol == m_pBtnCancel)
	{
			
		KillTimer(TIMER_PROGRESS);
		CString str;
		str.Format(_T("%d"),m_iIssueItemcount);
		m_pStaticIssueCount->SetText(str.GetBuffer(0));
		m_pProgressBarCheck->SetVisible(false,true,false);
		m_pBtnCancel->SetVisible(false,true,false);
		m_pScaningItem->SetVisible(false,true,false);
		m_pScaningText->SetVisible(false,true,false);
		m_pStaticCheckState->SetVisible(true,true,false);
		m_pBtnRecheck->SetVisible(true,true,false);
		m_pstaticNewRemind->SetVisible(true,true,false);
		m_iProgressBarPos = 0;
		m_nCheckItemCount = 0;
		m_iIssueItemcount = 0;
		m_nSafeCount = 0;
		if (m_bGhost == false)
		{
			m_pBtnGhost->SetVisible(true,true,false);
		}

	
	}
	//������찴ť
	else if (pCtol == m_pBtnRecheck)
	{
		m_pBtnCancel->SetVisible(true,true,false);
		m_pBtnGhost->SetVisible(false,true,false);
		m_pstaticNewScore->SetText(_T("100"));
	    m_pStaticCheckState->SetVisible(false,true,false);
		m_pProgressBarCheck->SetPos(0);
		m_pProgressBarCheck->SetVisible(true,true,false);
		m_pBtnRecheck->SetVisible(false,true,false);
		if (m_bGhost == false)
		{
			m_pGroupDenger->RemoveAllItems();
		}
		m_pGroupSafe->RemoveAllItems();
		SetTimer(TIMER_PROGRESS,TIMER_PROGRESS_TIME,NULL);
	}
	else if (pCtol == m_pBtnGhost)
	{
        m_bGhost = true;
		
		m_pBtnGhost->SetVisible(false,true,false);
		m_pBtnCancel->SetVisible(true,true,false);
		m_pstaticNewScore->SetText(_T("100"));
		m_pStaticCheckState->SetVisible(false,true,false);
		m_pStaticCheckState->SetText(_T("���ĵ��Ժܽ�������������֡�"));
		m_pStaticCheckState->SetTextStyle(DUI_STATIC_ACTIVE,m_pStaticStyle);
		m_pStaticCheckState->SetTextStyle(DUI_STATIC_INACTIVE,m_pStaticStyle);
		m_pProgressBarCheck->SetPos(0);
		m_pProgressBarCheck->SetVisible(true,true,false);
		m_pBtnRecheck->SetVisible(false,true,false);
		m_pBtnGhost->SetVisible(false,true,false);
		m_pListVist->RemoveAllGroup();
		SetTimer(TIMER_PROGRESS,TIMER_PROGRESS_TIME,NULL);
	}
	//������
	else if (pCtol == m_pBtnServe)
	{
		CString strURL = _T("http://bbs,360.cn");
		ShellExecute(NULL, _T("open"), strURL, NULL, NULL, SW_SHOW);
	}
	return TRUE;
}

void  CHealCheck::AddListView(IDUITVItemGroup* pItemGroup, int ID)
{
	if (pItemGroup == m_pGroupDenger)
	{
		
		if (ID == 1)
		{
			CString str;
			str.Format(_T("�Ż���Ŀ��%d��"),1);
			m_pGroupDenger->SetText((wstring)str,false);
		
			IDUITVItem* pItem = (IDUITVItem*)pItemGroup->AppendItem(ID++,_T("Item1"));
			SetItem(  pItem,_T("����27��δ���п���ľ��ɨ����"),_T("�ѿ���"),FALSE,TRUE,_T("ɨ��"));
			m_nNewScore = 95;
			m_iIssueItemcount = 1;
		}
		else if (ID == 23)
		{
			CString str;
			str.Format(_T("�Ż���Ŀ��%d��"),2);
			m_pGroupDenger->SetText((wstring)str,false);
			IDUITVItem* pItem = (IDUITVItem*)pItemGroup->AppendItem(ID++,_T("Item1"));
			SetItem(  pItem,_T("���������������ϵͳ����"),_T("�ѿ���"),FALSE,TRUE,_T("�鿴"));
			m_nNewScore = 92;
			m_iIssueItemcount = 2;

			pItem = (IDUITVItem*)pItemGroup->AppendItem(ID++,_T("Item1"));
			IUIFormObj* pFormTemp =(IUIFormObj*) pItem->GetCustomObj();
			IDUIStatic* pIcon1 = (IDUIStatic*)pFormTemp->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("Static21_Icon1"),true);
			pIcon1->SetVisible(false,false,false);
			IDUIStatic* pIcon2= (IDUIStatic*)pFormTemp->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("Static21_Icon2"),true);
			pIcon2->SetVisible(false,false,false);
			IDUIStatic* pStItemName= (IDUIStatic*)pFormTemp->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("Static_Text"),true);
			pStItemName->SetText(_T("ϵͳ��ʱ�ļ���210���ļ�����320MB)"));
			pStItemName->SetTextStyle(DUI_STATIC_ACTIVE,m_pItmeStyle);
			pStItemName->SetTextStyle(DUI_STATIC_INACTIVE,m_pItmeStyle);
			IDUIStatic* pStState= (IDUIStatic*)pFormTemp->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("Static21-Copy"),true);
            pStState->SetVisible(false,false,false);
			ICmdButton* pBtnOperate= (ICmdButton*)pFormTemp->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("Button29"),true);
			pBtnOperate->SetVisible(false,false,false);

			pItem = (IDUITVItem*)pItemGroup->AppendItem(ID++,_T("Item1"));
			pFormTemp =(IUIFormObj*) pItem->GetCustomObj();
		    pIcon1 = (IDUIStatic*)pFormTemp->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("Static21_Icon1"),true);
			pIcon1->SetVisible(false,false,false);
			pIcon2= (IDUIStatic*)pFormTemp->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("Static21_Icon2"),true);
			pIcon2->SetVisible(false,false,false);
			pStItemName= (IDUIStatic*)pFormTemp->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("Static_Text"),true);
			pStItemName->SetText(_T("IE�����ļ���9116���ļ�����212.0MB)"));
			pStItemName->SetTextStyle(DUI_STATIC_ACTIVE,m_pItmeStyle);
			pStItemName->SetTextStyle(DUI_STATIC_INACTIVE,m_pItmeStyle);
		    pStState= (IDUIStatic*)pFormTemp->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("Static21-Copy"),true);
			pStState->SetVisible(false,false,false);
			 pBtnOperate= (ICmdButton*)pFormTemp->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("Button29"),true);
			pBtnOperate->SetVisible(false,false,false);
			m_pListVist->RefreshView();
		}
		else if (ID == 45)
		{
			CString str;
			str.Format(_T("�Ż���Ŀ��%d��"),3);
			m_pGroupDenger->SetText((wstring)str,false);
			IDUITVItem* pItem = (IDUITVItem*)pItemGroup->AppendItem(ID++,_T("Item1"));
			SetItem(  pItem,_T("�������������Ҫ����"),_T("�ѿ���"),FALSE,TRUE,_T("����"));
		    m_nNewScore = 88;
			m_iIssueItemcount = 3;
		}
        CString str;
		str.Format(_T("%d"),m_nNewScore);
		wstring str1;
		str1 = str;
		m_pstaticNewScore->SetText(str1);
		pItemGroup->SetExpand(TRUE);
		m_pListVist->RefreshView();
	}
	else
	{
		m_pListVist->EnableRedraw(FALSE);
        IDUITVItem* pItem = (IDUITVItem*)pItemGroup->AppendItem(ID++,_T("Item2"));
		SetItem(  pItem,_T("����Ƿ�����ȫ��ʿ�Զ�����"),_T("�ѿ���"),TRUE,FALSE,_T(""));
		pItem = (IDUITVItem*)pItemGroup->AppendItem(ID++,_T("Item3"));
		SetItem(  pItem,_T("����Ƿ�����ҵ����ǽ"),_T("�ѿ���"),TRUE,FALSE,_T(""));
		pItem = (IDUITVItem*)pItemGroup->AppendItem(ID++,_T("Item3"));
		SetItem(  pItem,_T("����Ƿ���U�̷���ǽ"),_T("�ѿ���"),TRUE,FALSE,_T(""));
		pItem = (IDUITVItem*)pItemGroup->AppendItem(ID++,_T("Item3"));
		SetItem(  pItem,_T("ϵͳ��ȫ���"),_T("���账��"),TRUE,FALSE,_T(""));
		pItem = (IDUITVItem*)pItemGroup->AppendItem(ID++,_T("Item3"));
		SetItem(  pItem,_T("��⶯̬������"),_T("�ѿ���"),TRUE,FALSE,_T(""));
		pItem = (IDUITVItem*)pItemGroup->AppendItem(ID++,_T("Item3"));
		SetItem(  pItem,_T("���Windows��������"),_T("δ���ַ���"),TRUE,FALSE,_T(""));
		pItem = (IDUITVItem*)pItemGroup->AppendItem(ID++,_T("Item3"));
		SetItem(  pItem,_T("�������Ĭ��ͼ��"),_T("δ���ַ���"),TRUE,FALSE,_T(""));
		pItem = (IDUITVItem*)pItemGroup->AppendItem(ID++,_T("Item3"));
		SetItem(  pItem,_T("��������ݷ�ʽ"),_T("δ���ַ���"),TRUE,FALSE,_T(""));
		pItem = (IDUITVItem*)pItemGroup->AppendItem(ID++,_T("Item3"));
		SetItem(  pItem,_T("������������"),_T("δ���ַ���"),TRUE,FALSE,_T(""));
		pItem = (IDUITVItem*)pItemGroup->AppendItem(ID++,_T("Item3"));
		SetItem(  pItem,_T("���������ղؼ�"),_T("δ���ַ���"),TRUE,FALSE,_T(""));
		pItem = (IDUITVItem*)pItemGroup->AppendItem(ID++,_T("Item3"));
		SetItem(  pItem,_T("�����ҳ�����Ŀ"),_T("δ���ַ���"),TRUE,FALSE,_T(""));
		pItemGroup->SetExpand(TRUE);
		m_pListVist->EnableRedraw(TRUE);
		m_pListVist->RefreshView();
	}
}

void  CHealCheck::SetItem(IDUITVItem* pItem,wstring str1,wstring str2,BOOL SafeIconView,BOOL BtnVisiable,wstring str3)//������Ƶ�б�����
{ 
	//pTtem:����б��str1:�б������� str2:�б���״̬ SafeIconView���б���ͼ�� BtnVisiable���Ƿ���ʾ��ť��
	//�б���ͼ��



	IUIFormObj *pItemForm = (IUIFormObj*) pItem->GetCustomObj();
	IDUIStatic* pSta = (IDUIStatic*)pItemForm->GetObjectByCaption(DUIOBJTYPE_PLUGIN, _T("Static21_Icon1"), FALSE);
	if (SafeIconView)
    {
		pSta->SetVisible(TRUE,FALSE,FALSE);
    }
	else
	{
		IDUIStatic* pSta = (IDUIStatic*)pItemForm->GetObjectByCaption(DUIOBJTYPE_PLUGIN, _T("Static21_Icon2"), FALSE);
		pSta->SetVisible(TRUE,FALSE,FALSE);
	}
	//�б�������
	pSta = (IDUIStatic*)pItemForm->GetObjectByCaption(DUIOBJTYPE_PLUGIN, _T("Static_Text"), TRUE);
	pSta->SetText(str1);
    //��ť��״̬�л�
	ICmdButton* pSta1 = (ICmdButton*)pItemForm->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("Button29"),TRUE);
	if (BtnVisiable)
	{
         pSta1->SetVisible(TRUE,FALSE,FALSE);
		 pSta1->SetText(str3);
		 pSta = (IDUIStatic*)pItemForm->GetObjectByCaption(DUIOBJTYPE_PLUGIN, _T("Static21-Copy"), TRUE);
		 pSta->SetVisible(FALSE,FALSE,FALSE);
	}
	else
	{
		pSta1->SetVisible(FALSE,FALSE,FALSE);
		pSta = (IDUIStatic*)pItemForm->GetObjectByCaption(DUIOBJTYPE_PLUGIN, _T("Static21-Copy"), TRUE);
		pSta->SetText(str2);
		pSta->SetVisible(TRUE,FALSE,TRUE);
	}
}
void  CHealCheck::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
    
	if (m_bGhost == false)//δһ���޸������Ż���Ŀ��ʾ
	{
		m_pGroupDenger = (IDUITVItemGroup*)m_pListVist->AddGroup(100,_T("�Ż���Ŀ"));
	}
	m_pGroupSafe = (IDUITVItemGroup*)m_pListVist->AddGroup(200,_T("��ȫ��Ŀ"));
	if (nIDEvent == TIMER_PROGRESS)
	{   
		
	    if (m_nSafeCount == 0)
	    {
			m_pstaticScore->SetVisible(true,true,false);
			m_pProgressBarCheck->SetVisible(true,true,false);
			m_pScaningText->SetVisible(true,true,false);
			m_pScaningItem->SetVisible(true,true,false);
			m_pstaticNewRemind->SetVisible(false,true,false);
			m_pPreCheckForm->SetVisible(false,true,false);
	    }



		//�����б�̬���Ч��

		CString str;
		str.Format(_T("��ȫ��Ŀ��%d��"),m_nSafeCount);
		m_pGroupSafe->SetText((wstring)str,false);
		if (m_nSafeCount%10 == 0)
		{
			AddListView(m_pGroupSafe,m_nSafeCount);
		
		}
		else
		{
			if (m_bGhost == false)//δ�޸����Ż��б������ʾ
			{
				AddListView(m_pGroupDenger,m_nSafeCount);
				
			}
		}
		//��������չ������Ч��
		m_nSafeCount++;
	
		IDUIPos* pPs;
		DUIPosition pos;
		static int formPos = 420;
		pPs = m_pCheckForm->GetPosition();
		
		pos = pPs->GetPosStruct();
		pos.horzPos.nSpaceType = PHST_RIGHTWIDTH;
		formPos -=130;
		if (m_bGhost == false)//δ�޸�����������չ��Ч��
		{
			if (20<formPos)
			{
				pos.horzPos.nWidth_Height = formPos;
				pPs->SetPosStruct(pos);
				m_pCheckForm->SetPosition((IDUIPos*)pPs);
				m_pDirectUI->ResizeThis();
				m_pDirectUI->DirectDraw(TRUE);
			}
			else
			{
				formPos = 20;
				pos.horzPos.nWidth_Height = formPos;
				pPs->SetPosStruct(pos);
				m_pCheckForm->SetPosition((IDUIPos*)pPs);
				m_pstaticNewScore->SetVisible(true,true,false);
				m_pBtnCancel->SetVisible(TRUE,TRUE,FALSE);
				m_pDirectUI->ResizeThis();
				m_pDirectUI->DirectDraw(TRUE);
			}
		}
 
		//���ý���������Ч��
		time_t t;
	    srand((unsigned)time(&t));
		m_nCheckItemCount = m_nCheckItemCount + rand()%30;
	
		str.Format(_T("%d"),m_nCheckItemCount);
        m_pStaticItemCount->SetText(str.GetBuffer(0));
		m_pScaningCount->SetText(str.GetBuffer(0));
	   	if (m_nCheckItemCount%10 == 1)
		{
			m_pScaningItem->SetText(_T("ϵͳ�ؼ�Ŀ¼��WINDOWS\system32\adsld.dll"));
		}
		else if (m_nCheckItemCount%10 == 2)
		{
			m_pScaningItem->SetText(_T("ϵͳ�ؼ�Ŀ¼��WINDOWS\system32\append.ll"));
		}
		else if (m_nCheckItemCount%10 ==3)
		{
			m_pScaningItem->SetText(_T("ϵͳ�ؼ�Ŀ¼��WINDOWS\system32\spoll\drivers"));
		}
		else if (m_nCheckItemCount%10 == 4)
		{
			m_pScaningItem->SetText(_T("��ݷ�ʽ��\Program Files\360\360safe\360safe.exe"));
		}
		else if (m_nCheckItemCount%10 == 5)
		{
			m_pScaningItem->SetText(_T("���п�ܳ�������C\Program Files\NT"));
		}
		else if (m_nCheckItemCount%10 == 6)
		{
			m_pScaningItem->SetText(_T("���п�ܳ�������C\Program Files\Micorsoft Office\OFFICE11"));
		}
		else if (m_nCheckItemCount%10 == 7)
		{
			m_pScaningItem->SetText(_T("ϵͳ�ؼ�Ŀ¼��WINDOWS\system32\adsld"));
		}
		else if (m_nCheckItemCount%10 == 8)
		{
			m_pScaningItem->SetText(_T("ϵͳ�ؼ�Ŀ¼��WINDOWS\system32\adsld"));
		}
		m_iProgressBarPos += rand()%4;
		if (m_iProgressBarPos<= 100)
		{
			m_pProgressBarCheck->SetPos(m_iProgressBarPos);
		}
		else if (m_iProgressBarPos>=100)
		{
			m_pProgressBarCheck->SetPos(100);
			if (m_pProgressBarCheck->GetPos() == 100)
			{		
				str.Format(_T("%d"),m_iIssueItemcount);
				m_pStaticIssueCount->SetText((wstring)str);
				m_pProgressBarCheck->SetVisible(false,true,false);
				m_pBtnCancel->SetVisible(false,true,false);
				m_pScaningText->SetVisible(false,true,false);
				m_pScaningItem->SetVisible(false,true,false);
				m_pStaticCheckState->SetVisible(true,true,false);
				if (m_bGhost == false)//δ�޸���һ���޸���ť�ɼ�
				{
						m_pBtnGhost->SetVisible(true,true,false);
				}
			
				m_pBtnRecheck->SetVisible(true,true,false);
				m_pstaticNewRemind->SetVisible(true,true,false);
			
				m_iProgressBarPos =0; 
				m_nCheckItemCount = 0;
				m_iIssueItemcount = 0;
				formPos = 20;
			    m_nSafeCount = 0;
			}
			KillTimer(TIMER_PROGRESS);
		}
	}

	CDialog::OnTimer(nIDEvent);
}

void CHealCheck::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);
	// TODO: �ڴ˴������Ϣ����������
}
void CHealCheck::OnOK()
{
}

void CHealCheck::OnCancel()
{
	// TODO: �ڴ����ר�ô����/����û���
}
