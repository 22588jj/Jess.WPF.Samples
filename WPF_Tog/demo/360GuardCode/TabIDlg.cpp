// TabIDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "360Demo.h"
#include "TabIDlg.h"


// CTabIDlg �Ի���

IMPLEMENT_DYNAMIC(CTabIDlg, CDialog)

CTabIDlg::CTabIDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTabIDlg::IDD, pParent)
{

}

CTabIDlg::~CTabIDlg()
{
}

void CTabIDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTabIDlg, CDialog)
	ON_WM_CREATE()
END_MESSAGE_MAP()


// CTabIDlg ��Ϣ�������

int CTabIDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

     // TODO:  �ڴ������ר�õĴ�������

    m_pDirectUI = (IDirectUI*)theApp.m_pDUIRes->CreateDirectUI(L"HealCheck",HandleToLong(m_hWnd));


	return 0;
}
