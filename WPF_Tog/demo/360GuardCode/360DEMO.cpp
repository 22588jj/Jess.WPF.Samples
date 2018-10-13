// 360DEMO.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "360DEMO.h"
#include "360DEMODlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy360DEMOApp

BEGIN_MESSAGE_MAP(CMy360DEMOApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CMy360DEMOApp ����

CMy360DEMOApp::CMy360DEMOApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
	m_pDUIRes = NULL;
}


// Ψһ��һ�� CMy360DEMOApp ����

CMy360DEMOApp theApp;


// CMy360DEMOApp ��ʼ��

BOOL CMy360DEMOApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();
	//m_pDUIRes->OpenSkin(_T("360DEMO.dui"),_T("Default.skn"));
	m_pDUIRes = OpenSkin(_T("360DEMO.dui"), _T("Default.skn"));



	AfxEnableControlContainer();

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	CMy360DEMODlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˴����ô����ʱ�á�ȷ�������ر�
		//  �Ի���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ�á�ȡ�������ر�
		//  �Ի���Ĵ���
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}
int CMy360DEMOApp::ExitInstance(void)
{
	FreeSkin();
	return CWinApp::ExitInstance();

}

