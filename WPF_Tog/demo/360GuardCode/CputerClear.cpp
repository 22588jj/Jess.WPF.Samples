// CputerClear.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "360DEMO.h"
#include "CputerClear.h"


// CCputerClear �Ի���

IMPLEMENT_DYNAMIC(CCputerClear, CDialog)

CCputerClear::CCputerClear(CWnd* pParent /*=NULL*/)
	: CDialog(CCputerClear::IDD, pParent)
{
	m_pBtnStartClear = NULL;
	m_pListView = NULL;
	m_pBtnSel = NULL;
	m_pBtnNoSel = NULL;
	m_pBtnPart = NULL;
	m_pBtnBegainScan = NULL;
	m_pBtnCancel = NULL;
	m_pStaticRemind1 = NULL;
	m_pStaticRemind2 = NULL;
	m_pBtnRescan = NULL;
	m_iItemHight = 0;
	m_nProgressBarPos = 0;
	m_nShowCount = 0;
	m_nItemCount = -1;
	m_pSScanItem = NULL;
}

CCputerClear::~CCputerClear()
{
}

void CCputerClear::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CCputerClear, CDialog)
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_MESSAGE(DUISM_LBUTTONUP,OnDUILButtonUp)
END_MESSAGE_MAP()


// CCputerClear ��Ϣ�������

int CCputerClear::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	// TODO:  �ڴ������ר�õĴ�������
	
	m_pIDirectUI = (IDirectUI*)theApp.m_pDUIRes->CreateDirectUI(_T("ComputerClear"),(long)HandleToLong(GetSafeHwnd()));
    m_pBtnStartClear = (ICmdButton*)m_pIDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("StartBtn"),TRUE);
	m_pListView = (IDUIListView*)m_pIDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("ListView4"),TRUE);
	m_pBtnSel = (ICmdButton*)m_pIDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("BtnSel"),TRUE);
	m_pBtnNoSel = (ICmdButton*)m_pIDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("BtnNoSel"),TRUE);
	m_pBtnPart = (ICmdButton*)m_pIDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("BtnExport"),TRUE);
	m_pBtnCancel = (ICmdButton*)m_pIDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("CancelBtn"),TRUE);
    m_pBtnBegainScan = (ICmdButton*)m_pIDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("StartBtn"),TRUE);
	m_pProgreesBar = (IDUIProgressbar*)m_pIDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("ProgressBar3"),TRUE);
	m_pStaticRemind1 = (IDUIStatic*)m_pIDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("Text41"),TRUE);
	m_pStaticRemind2 = (IDUIStatic*)m_pIDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("Text42"),TRUE);
	m_pBtnRescan = (ICmdButton*)m_pIDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("AginBtn"),TRUE);
	m_pSScanItem = (IDUIStatic*)m_pIDirectUI->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("Static71"),TRUE);
    AddList();
	return 0;
}
//����б�
void CCputerClear::AddList( )
{
	int ItemCount;
	ItemCount = m_pListView->InsertItem(0,_T("1"),false);
	IDUITVItem* pItem = (IDUITVItem*)m_pListView->GetAt(ItemCount);
	setItem(pItem,_T("windowsϵͳ�����ļ�"),_T("��������ϵͳ�е������ļ�����ϵͳ���и�����"),true,true);
	Clone(pItem,_T("��Ч�Ŀ�ݷ�ʽ"),1);
	Clone(pItem,_T("����ͼת���ļ�"),2);
	Clone(pItem,_T("�ڴ�ת���ļ�"),3);
	Clone(pItem,_T("Windows���󱨸�"),4);
	Clone(pItem,_T("ϵͳ�Զ�����ʱ���µĲ���"),5);
	Clone(pItem,_T("ϵͳ�򲹶�ʱ���µ�ж����Ϣ"),6);
	Clone(pItem,_T("WindowsԤ��ȡ�ļ�"),7);
	Clone(pItem,_T("�����صĳ����ļ�"),8);
	Clone(pItem,_T("��־�ļ�"),9);
	Clone(pItem,_T("�������վ"),10);
	Clone(pItem,_T("�����ش�����ָ�����͵������ļ�"),11);
	pItem->SetHeight(40+m_iItemHight,false);
	m_vecItemHight.push_back(m_iItemHight);
    
	ItemCount = m_pListView->InsertItem(1,_T("2"),false);
	pItem = (IDUITVItem*)m_pListView->GetAt(ItemCount);
	setItem(pItem,_T("windows������������������ļ�"),_T("�����������ʱ�����������ļ������Լӿ������ٶ�"),true,true);
	Clone(pItem,_T("IE����������ļ�"),1);
	Clone(pItem,_T("Chrome����������ļ�"),2);
	Clone(pItem,_T("Firefox����������ļ�"),3);
	Clone(pItem,_T("Opera����������ļ�"),4);
	pItem->SetHeight(40+m_iItemHight,false);
	m_vecItemHight.push_back(m_iItemHight);

	ItemCount = m_pListView->InsertItem(2,_T("3"),false);
	pItem = (IDUITVItem*)m_pListView->GetAt(ItemCount);
	setItem(pItem,_T("windowsע��������ļ�"),_T("�������õ�ע����ֵ���Ż�ע���ṹ�����ϵͳ����"),true,true);
	Clone(pItem,_T("����Ķ�̬���ӿ�"),1);
	Clone(pItem,_T("��Ч�����"),2);
	Clone(pItem,_T("��Ч�İ�װ����"),3);
	Clone(pItem,_T("��Ч��ж�س���"),4);
	Clone(pItem,_T("��Ч�İ���"),5);
	pItem->SetHeight(40+m_iItemHight,false);
	m_vecItemHight.push_back(m_iItemHight);

	ItemCount = m_pListView->InsertItem(3,_T("4"),false);
	pItem = (IDUITVItem*)m_pListView->GetAt(ItemCount);
	setItem(pItem,_T("windowsӦ�ó��������ļ�"),_T("�����������������������ļ�����Լ���̿ռ�"),true,true);
	Clone(pItem,_T("Office��װ�ļ�"),1);
	pItem->SetHeight(40+m_iItemHight,false);
	m_vecItemHight.push_back(m_iItemHight);
    m_pListView->RefreshView();
}
//��ѡ����޸�
void CCputerClear::setItem(IDUITVItem* pItem,wstring str1,wstring str2,BOOL bCheckIcon,BOOL BShow)
{
	IUIFormObj* pFormObj = (IUIFormObj*) pItem->GetCustomObj();
	IDUICheckBox* pStaCheck = (IDUICheckBox*)pFormObj->GetObjectByCaption(DUIOBJTYPE_PLUGIN, _T("IconCheckBox"), TRUE);
	if (bCheckIcon)
	{
		pStaCheck->SetValue(DUICHECKBOX_CHECKED);
	}
	IDUIStatic* pStaStatic = (IDUIStatic*)pFormObj->GetObjectByCaption(DUIOBJTYPE_PLUGIN, _T("Text89"), TRUE);
	pStaStatic->SetText(str1);
	pStaStatic = (IDUIStatic*)pFormObj->GetObjectByCaption(DUIOBJTYPE_PLUGIN, _T("Text90"), TRUE);
	pStaStatic->SetText(str2);
	pStaCheck =(IDUICheckBox*) pFormObj->GetObjectByCaption(DUIOBJTYPE_PLUGIN, _T("CheckBox6"), TRUE);
}
LRESULT CCputerClear::OnDUILButtonUp(WPARAM wparam,LPARAM lparam)
{
	IDUIControlBase* pCtrol = (IDUIControlBase*)wparam;
	//��ʼɨ��
	if (pCtrol == (IDUIControlBase*)m_pBtnBegainScan)
	{
		m_vecCloneCheckBox.clear();
		m_pListView->DeleteAllItems();
		m_pBtnBegainScan->SetVisible(false,true,false);
		m_pBtnCancel->SetVisible(true,true,false);
		SetTimer(TIMER_SCAN,TIMER_CLEAR_SCAN_TIME,NULL);
	}
	//ȡ��ɨ��
	else if (pCtrol == (IDUIControlBase*)m_pBtnCancel)
	{
		m_nProgressBarPos = 0;
		m_pProgreesBar->SetVisible(false,true,false);
		m_nItemCount = -1;
		m_nShowCount = 0;
		m_pSScanItem->SetVisible(false,true,false);
		m_pStaticRemind1->SetText(_T("ɨ������ɣ���������ɰ�����ʡ33.66MBӲ�̿ռ䡣"));
		m_pStaticRemind1->SetVisible(true,true,false);
		m_pStaticRemind1->SetText(_T("��ɨ���468�������ļ�"));
		m_pStaticRemind2->SetVisible(true,true,false);
		m_pBtnCancel->SetVisible(false,true,false);
		m_pBtnRescan->SetVisible(true,false,true);
		KillTimer(TIMER_SCAN);
	}
	else if (pCtrol == (IDUIControlBase*)m_pBtnRescan)
	{
		m_vecCloneCheckBox.clear();
		m_pListView->DeleteAllItems();
		m_pBtnBegainScan->SetVisible(false,true,false);
		m_pBtnCancel->SetVisible(true,true,false);
		m_pBtnRescan->SetVisible(false,true,false);
		SetTimer(TIMER_SCAN,TIMER_CLEAR_SCAN_TIME,NULL);

	}
	//ȫѡ��ť
	else if (pCtrol == (IDUIControlBase*)m_pBtnSel)
	{
		vector<IDUICheckBox*>::iterator it = m_vecCloneCheckBox.begin();
		for (; it != m_vecCloneCheckBox.end(); ++it)
		{
		   IDUICheckBox* pBox = *it;
		   pBox->SetValue(DUICHECKBOX_CHECKED);
		}
	}
	//ȫ��ѡ��ť
	else if (pCtrol == (IDUIControlBase*)m_pBtnNoSel)
	{
		vector<IDUICheckBox*>::iterator it = m_vecCloneCheckBox.begin();
		for (; it != m_vecCloneCheckBox.end(); ++it)
		{
			IDUICheckBox* pBox = *it;
			pBox->SetValue(DUICHECKBOX_UNCHECKED);
		}
	}
	//�Ƽ�ѡ��ť
	else if (pCtrol == (IDUIControlBase*)m_pBtnPart)
	{
		vector<IDUICheckBox*>::iterator it = m_vecCloneCheckBox.begin();
		for (; it<m_vecCloneCheckBox.end();)
		{
			
			IDUICheckBox* pBox = *it++;
			pBox->SetValue(DUICHECKBOX_UNCHECKED);
			if (it<m_vecCloneCheckBox.end())
			{
				IDUICheckBox* pBox1 = *(it++);
				pBox1->SetValue(DUICHECKBOX_CHECKED);
			}
		}
	}
	//��ѡ��չ��
	CString strCtrlName = pCtrol->GetName().c_str();
	if (strCtrlName == _T("CheckBox6"))
	{
		CString strName = pCtrol->GetParent()->GetName().c_str();//�ڴ���ʱ���Ѿ���Item��name�洢��checkbox��
		int nCount = m_pListView->GetItemCount();
		for (int nLoop = 0; nLoop < nCount; ++nLoop)
		{
			IDUITVItem* pItem = (IDUITVItem* )m_pListView->GetAt(nLoop);
			if (pItem)
			{
				if (pItem->GetText().c_str() == strName)
				{
					int i = pItem->GetIndex();
					IUIFormObj* pItemForm = (IUIFormObj*) pItem->GetCustomObj();
					IDUICheckBox*  pCheckItem = (IDUICheckBox*)pItemForm->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("CheckBox6"),true);
					DUICHECKBOX_VALUE evalue = pCheckItem->GetValue();
					if (evalue == DUICHECKBOX_CHECKED)
					{
					
						pItem->SetHeight(40, TRUE);
						m_pListView->RefreshView();

					}
					else if (evalue == DUICHECKBOX_UNCHECKED)
					{
						for (int i=0;i<4;i++)
						{
							if (pItem->GetIndex() == i)
							{
							   pItem->SetHeight(40+m_vecItemHight[i], TRUE);
							   m_pListView->RefreshView();
							}
					
						}
					}
				}
			}
		}
	}

	return true;
}
//��ѡ��Ŀ�¡
void CCputerClear::Clone(IDUITVItem* pItem, wstring str,int count)
{
	IUIFormObj* pUIForm = (IUIFormObj*)pItem->GetCustomObj();
	IDUIStatic* pText = (IDUIStatic*)pUIForm->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("Static93"),TRUE);
	IDUICheckBox* pIcon = (IDUICheckBox*)pUIForm->GetObjectByCaption(DUIOBJTYPE_PLUGIN,_T("IconCheckBox1"),TRUE);
	IDUIStatic* pNewText =(IDUIStatic*) pText->Clone(pText->GetParent()); //��¡��̬�ı�
	IDUICheckBox* pNewIcon = (IDUICheckBox*)pIcon->Clone(pIcon->GetParent());//��¡��ѡ��
	m_vecCloneCheckBox.push_back(pNewIcon);
	// ����ÿ�������λ��
	IDUIPos*  psText = pNewText->GetPosition();
	IDUIPos*  psIcon = pNewIcon->GetPosition();
	psText->top = psText->top+(count-1)*psText->height;
	pNewText->SetPosition(psText);
	pNewText->SetText(str);
	psIcon->top = psIcon->top+(count-1)*psText->height;
	pNewIcon->SetPosition(psIcon);
	//����ÿ��Item�ĸ߶�
	m_iItemHight =(1+count)*psText->height;

}
void CCputerClear::OnTimer(UINT_PTR nIDEvent)
{
	m_pStaticRemind1->SetVisible(false,true,false);
	m_pStaticRemind2->SetVisible(false,true,false);

    m_nProgressBarPos =m_nProgressBarPos+rand()%5;
	m_pProgreesBar->SetVisible(true,false,false);
	m_pProgreesBar->SetPos(m_nProgressBarPos);
	m_pSScanItem->SetVisible(true,true,false);

	static int ItemCount = 0;
	ItemCount++;
	if (ItemCount%10 == 1)
	{
		m_pSScanItem->SetText(_T("����ɨ�裺QQ���Թܼ���������"));
	}
	else if (ItemCount%10 == 2)
	{
		m_pSScanItem->SetText(_T("����ɨ�裺����ӵ�ϵͳ�������Desktop TipsStub Class"));
	}
	else if (ItemCount%10 ==3)
	{
		m_pSScanItem->SetText(_T("����ɨ�裺IE�Ҽ��δ������е�����"));
	}
	else if (ItemCount%10 == 4)
	{
		m_pSScanItem->SetText(_T("����ɨ�裺����ӵ�Activex�ؼ���Qzone���ֲ������ؼ�"));
	}
	else if (ItemCount%10 == 5)
	{
		m_pSScanItem->SetText(_T("����ɨ�裺����ӵ�Activex�ؼ���Adobe Flash�ؼ�"));
	}
	else if (ItemCount%10 == 6)
	{
		m_pSScanItem->SetText(_T("����ɨ�裺Ѹ�׿���������"));
	}
	else if (ItemCount%10 == 7)
	{
		m_pSScanItem->SetText(_T("����ɨ�裺360����ǽ����ģ��"));
	}
	else if (ItemCount%10 == 8)
	{
		m_pSScanItem->SetText(_T("����ɨ�裺΢��칫�����ؿؼ�"));
	}
	////���ListView��̬Ч��
	if (m_nItemCount == -1)
   {
	  m_nItemCount = m_pListView->InsertItem(0,_T("1"),false);
   }
	m_nShowCount++;
	IDUITVItem* pItem = (IDUITVItem*)m_pListView->GetAt(m_nItemCount);
    switch(m_nShowCount)
	{
		m_pListView->RefreshView();
        case 1:
			setItem(pItem,_T("windowsϵͳ�����ļ�"),_T("��������ϵͳ�е������ļ�����ϵͳ���и�����"),true,true);
			break;
		case 2:
			Clone(pItem,_T("��Ч�Ŀ�ݷ�ʽ"),1);
		
			break;
		case 3:
			Clone(pItem,_T("����ͼת���ļ�"),2);
			break;
		case 4:
			Clone(pItem,_T("�ڴ�ת���ļ�"),3);
			break;
		case 6:
			Clone(pItem,_T("Windows���󱨸�"),4);
			break;
		case 8:
			Clone(pItem,_T("ϵͳ�Զ�����ʱ���µĲ���"),5);
			break;
		case 10:
			Clone(pItem,_T("ϵͳ�򲹶�ʱ���µ�ж����Ϣ"),6);
			break;
		case 12:
			Clone(pItem,_T("WindowsԤ��ȡ�ļ�"),7);
			break;
		case 15:
			Clone(pItem,_T("�����صĳ����ļ�"),8);
			break;
		case 17:
			Clone(pItem,_T("��־�ļ�"),9);
			break;
		case 20:
			Clone(pItem,_T("�������վ"),10);
			break;
		case 22:
			Clone(pItem,_T("�����ش�����ָ�����͵������ļ�"),11);
			break;
		case 23:
			pItem->SetHeight(40+m_iItemHight,false);
			m_vecItemHight.push_back(m_iItemHight);
			break;
		case 24:
			m_nItemCount = m_pListView->InsertItem(1,_T("2"),false);
			pItem = (IDUITVItem*)m_pListView->GetAt(m_nItemCount);
			setItem(pItem,_T("windows������������������ļ�"),_T("�����������ʱ�����������ļ������Լӿ������ٶ�"),true,true);
			break;
		case 26:
			Clone(pItem,_T("IE����������ļ�"),1);
			break;
		case 28:
			Clone(pItem,_T("Chrome����������ļ�"),2);
			break;
		case 33:
			Clone(pItem,_T("Firefox����������ļ�"),3);
			break;
		case 37:
			Clone(pItem,_T("Opera����������ļ�"),4);
			pItem->SetHeight(40+m_iItemHight,false);
			m_vecItemHight.push_back(m_iItemHight);
			break;
		case 40:
			m_nItemCount = m_pListView->InsertItem(2,_T("3"),false);
			pItem = (IDUITVItem*)m_pListView->GetAt(m_nItemCount);
			setItem(pItem,_T("windowsע��������ļ�"),_T("�������õ�ע����ֵ���Ż�ע���ṹ�����ϵͳ����"),true,true);
			break;
		case 50:
			Clone(pItem,_T("����Ķ�̬���ӿ�"),1);
			Clone(pItem,_T("��Ч�����"),2);
			Clone(pItem,_T("��Ч�İ�װ����"),3);
			Clone(pItem,_T("��Ч��ж�س���"),4);
			Clone(pItem,_T("��Ч�İ���"),5);
			pItem->SetHeight(40+m_iItemHight,false);
			m_vecItemHight.push_back(m_iItemHight);
			break;
		case 58:
			m_nItemCount = m_pListView->InsertItem(3,_T("4"),false);
			pItem = (IDUITVItem*)m_pListView->GetAt(m_nItemCount);
			setItem(pItem,_T("windowsӦ�ó��������ļ�"),_T("�����������������������ļ�����Լ���̿ռ�"),true,true);
			Clone(pItem,_T("Office��װ�ļ�"),1);
			pItem->SetHeight(40+m_iItemHight,false);
			m_vecItemHight.push_back(m_iItemHight);
			break;
   }
   m_pListView->RefreshView();
   if (m_nProgressBarPos>100)
	{
		
		m_pProgreesBar->SetPos(100);
		m_nProgressBarPos = 0;
		m_pSScanItem->SetVisible(false,true,false);
		m_pProgreesBar->SetVisible(false,true,false);
		m_pStaticRemind1->SetText(_T("ɨ������ɣ���������ɰ�����ʡ33.66MBӲ�̿ռ䡣"));
		m_pStaticRemind1->SetVisible(true,true,false);
		m_pStaticRemind1->SetText(_T("��ɨ���468�������ļ�"));
		m_pStaticRemind2->SetVisible(true,true,false);
		m_pBtnCancel->SetVisible(false,true,false);
		m_pBtnRescan->SetVisible(true,false,true);
		m_nItemCount = -1;
		m_nShowCount = 0;

		KillTimer(TIMER_SCAN);
   }
CDialog::OnTimer(nIDEvent);
}
void CCputerClear::OnOK()
{

}
void CCputerClear::OnCancel()
{

}
